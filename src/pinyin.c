/**
 * pinyin.c
 *
 * Copyright (c) 2005, 2006, 2008, 2012-2014
 *      libchewing Core Team. See ChangeLog for details.
 *
 * See the file "COPYING" for information on usage and redistribution
 * of this file.
 */

/* @(#)pinyin.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "global-private.h"
#include "pinyin-private.h"
#include "bopomofo-private.h"
#include "private.h"

void TerminatePinyin(ChewingData *pgdata)
{
    free(pgdata->static_data.hanyuInitialsMap);
    free(pgdata->static_data.hanyuFinalsMap);
}

int InitPinyin(ChewingData *pgdata, const char *prefix)
{
    char filename[PATH_MAX];
    int i;
    FILE *fd;
    int ret;

    sprintf(filename, "%s" PLAT_SEPARATOR "%s", prefix, PINYIN_TAB_NAME);

    fd = fopen(filename, "r");

    if (!fd)
        return 0;

    ret = fscanf(fd, "%d", &pgdata->static_data.HANYU_INITIALS);
    if (ret != 1) {
        goto fail;
    }
    ++pgdata->static_data.HANYU_INITIALS;
    pgdata->static_data.hanyuInitialsMap = ALC(keymap, pgdata->static_data.HANYU_INITIALS);
    for (i = 0; i < pgdata->static_data.HANYU_INITIALS - 1; i++) {
        ret = fscanf(fd, "%s %s",
                     pgdata->static_data.hanyuInitialsMap[i].pinyin, pgdata->static_data.hanyuInitialsMap[i].bopomofo);
        if (ret != 2) {
            goto fail;
        }
    }

    ret = fscanf(fd, "%d", &pgdata->static_data.HANYU_FINALS);
    if (ret != 1) {
        goto fail;
    }
    ++pgdata->static_data.HANYU_FINALS;
    pgdata->static_data.hanyuFinalsMap = ALC(keymap, pgdata->static_data.HANYU_FINALS);
    for (i = 0; i < pgdata->static_data.HANYU_FINALS - 1; i++) {
        ret = fscanf(fd, "%s %s",
                     pgdata->static_data.hanyuFinalsMap[i].pinyin, pgdata->static_data.hanyuFinalsMap[i].bopomofo);
        if (ret != 2) {
            goto fail;
        }
    }

    fclose(fd);
    return 1;

fail:
    fclose(fd);
    return 0;
}

/**
 * Map pinyin key-sequence to Bopomofo key-sequence.
 * Caller should allocate char bopomofo[4].
 *
 * Non-Zero: Fail to fully convert
 *
 * @retval 0 Success
 */
int PinyinToBopomofo(ChewingData *pgdata, const char *pinyinKeySeq, char *bopomofoKeySeq, char *bopomofoKeySeqAlt)
{
    const char *p, *cursor = NULL;
    const char *initial = 0;
    const char *final = 0;
    const char *seq = 0;
    int i;

    /* special cases for WG */
    if (!strcmp(pinyinKeySeq, "tzu")) {
        seq = "y yj";           /* ???|?????? */
    } else if (!strcmp(pinyinKeySeq, "ssu") || !strcmp(pinyinKeySeq, "szu")) {
        seq = "n n";            /* ???|?????? */
    }

    /* common multiple mapping */
    if (!strcmp(pinyinKeySeq, "e")) {
        seq = "k ,";            /* ???|??? */
    } else if (!strcmp(pinyinKeySeq, "ch")) {
        seq = "t f";            /* ???|??? */
    } else if (!strcmp(pinyinKeySeq, "sh")) {
        seq = "g v";            /* ???|??? */
    } else if (!strcmp(pinyinKeySeq, "c")) {
        seq = "h f";            /* ???|??? */
    } else if (!strcmp(pinyinKeySeq, "s")) {
        seq = "n v";            /* ???|??? */
    } else if (!strcmp(pinyinKeySeq, "nu")) {
        seq = "sj sm";          /* ??????|?????? */
    } else if (!strcmp(pinyinKeySeq, "lu")) {
        seq = "xj xm";          /* ??????|?????? */
    } else if (!strcmp(pinyinKeySeq, "luan")) {
        seq = "xj0 xm0";        /* ?????????|????????? */
    } else if (!strcmp(pinyinKeySeq, "niu")) {
        seq = "su. sm";         /* ?????????|?????? */
    } else if (!strcmp(pinyinKeySeq, "liu")) {
        seq = "xu. xm";         /* ?????????|?????? */
    } else if (!strcmp(pinyinKeySeq, "jiu")) {
        seq = "ru. rm";         /* ?????????|?????? */
    } else if (!strcmp(pinyinKeySeq, "chiu")) {
        seq = "fu. fm";         /* ?????????|?????? */
    } else if (!strcmp(pinyinKeySeq, "shiu")) {
        seq = "vu. vm";         /* ?????????|?????? */
    } else if (!strcmp(pinyinKeySeq, "ju")) {
        seq = "rm 5j";          /* ??????|?????? */
    } else if (!strcmp(pinyinKeySeq, "juan")) {
        seq = "rm0 5j0";        /* ?????????|????????? */
    }

    /* multiple mapping for each kbtype */
    switch (pgdata->bopomofoData.kbtype) {
    case KB_HANYU_PINYIN:
        if (!strcmp(pinyinKeySeq, "chi")) {
            seq = "t fu";       /* ???|?????? */
        } else if (!strcmp(pinyinKeySeq, "shi")) {
            seq = "g vu";       /* ???|?????? */
        } else if (!strcmp(pinyinKeySeq, "ci")) {
            seq = "h fu";       /* ???|?????? */
        } else if (!strcmp(pinyinKeySeq, "si")) {
            seq = "n vu";       /* ???|?????? */
        }
        break;
    case KB_THL_PINYIN:
        if (!strcmp(pinyinKeySeq, "chi")) {
            seq = "fu t";       /* ??????|??? */
        } else if (!strcmp(pinyinKeySeq, "shi")) {
            seq = "vu g";       /* ??????|??? */
        } else if (!strcmp(pinyinKeySeq, "ci")) {
            seq = "fu h";       /* ??????|??? */
        } else if (!strcmp(pinyinKeySeq, "si")) {
            seq = "vu n";       /* ??????|??? */
        }
        break;
    case KB_MPS2_PINYIN:
        if (!strcmp(pinyinKeySeq, "chi")) {
            seq = "fu t";       /* ??????|??? */
        } else if (!strcmp(pinyinKeySeq, "shi")) {
            seq = "vu g";       /* ??????|??? */
        } else if (!strcmp(pinyinKeySeq, "ci")) {
            seq = "fu h";       /* ??????|??? */
        } else if (!strcmp(pinyinKeySeq, "si")) {
            seq = "vu n";       /* ??????|??? */
        } else if (!strcmp(pinyinKeySeq, "niu")) {
            seq = "sm su.";     /* ??????|????????? */
        } else if (!strcmp(pinyinKeySeq, "liu")) {
            seq = "xm xu.";     /* ??????|????????? */
        } else if (!strcmp(pinyinKeySeq, "jiu")) {
            seq = "rm ru.";     /* ??????|????????? */
        } else if (!strcmp(pinyinKeySeq, "chiu")) {
            seq = "fm fu.";     /* ??????|????????? */
        } else if (!strcmp(pinyinKeySeq, "shiu")) {
            seq = "vm vu.";     /* ??????|????????? */
        } else if (!strcmp(pinyinKeySeq, "ju")) {
            seq = "5j rm";      /* ??????|?????? */
        } else if (!strcmp(pinyinKeySeq, "juan")) {
            seq = "5j0 rm0";    /* ?????????|????????? */
        } else if (!strcmp(pinyinKeySeq, "juen")) {
            seq = "5jp 5jp";    /* ?????????|????????? */
        } else if (!strcmp(pinyinKeySeq, "tzu")) {
            seq = "yj y";       /* ??????|??? */
        }
        break;
    }
    if (seq != NULL) {
        char s[BOPOMOFO_SIZE * 2 + 1];

        strcpy(s, seq);
        initial = strtok(s, " ");
        strcpy(bopomofoKeySeq, initial);
        initial = strtok(NULL, " ");
        strcpy(bopomofoKeySeqAlt, initial);
        return 0;
    }


    for (i = 0; i < pgdata->static_data.HANYU_INITIALS; i++) {
        p = strstr(pinyinKeySeq, pgdata->static_data.hanyuInitialsMap[i].pinyin);
        if (p == pinyinKeySeq) {
            initial = pgdata->static_data.hanyuInitialsMap[i].bopomofo;
            cursor = pinyinKeySeq + strlen(pgdata->static_data.hanyuInitialsMap[i].pinyin);
            break;
        }
    }
    if (i == pgdata->static_data.HANYU_INITIALS) {
        /* No initials. might be ????????? */
        /* XXX: I NEED Implementation
           if(finalsKeySeq[0] != ) {
           }
         */
        return 1;
    }

    if (cursor) {
        for (i = 0; i < pgdata->static_data.HANYU_FINALS; i++) {
            if (strcmp(cursor, pgdata->static_data.hanyuFinalsMap[i].pinyin) == 0) {
                final = pgdata->static_data.hanyuFinalsMap[i].bopomofo;
                break;
            }
        }
        if (i == pgdata->static_data.HANYU_FINALS) {
            return 2;
        }
    }


    /* THL empty rime
     * we use '=' in pinyin.tab as empty rime, restore it to ''
     */
    if (!strcmp(final, "=")) {
        final = "";
    }

    /* Hanyu empty rime
     * ???/???/???/???/???/???/??? + -i, -i is empty rime, not ???
     * */
    if (!strcmp(final, "u")) {
        if (!strcmp(initial, "5") ||
            !strcmp(initial, "t") ||
            !strcmp(initial, "g") ||
            !strcmp(initial, "b") || !strcmp(initial, "y") || !strcmp(initial, "h") || !strcmp(initial, "n")) {
            final = "";
        }
    }

    /* Hanyu uan/un/u :
     * ???/???/??? + -uan, -uan is ??????, not ??????
     * ???/???/??? + -un,  -un is ??????, not ??????
     * ???/???/??? + -u,   -u is ???, not ???
     */
    if (!strcmp(initial, "f") || !strcmp(initial, "r") || !strcmp(initial, "v")) {
        if (!strcmp(final, "j0")) {
            final = "m0";
        } else if (!strcmp(final, "jp")) {
            final = "mp";
        } else if (!strcmp(final, "j")) {
            final = "m";
        }

    }

    /* THL/MPS2 s/sh/c/ch/j :
     * s-  + ???/???, s-  is ???, not ??? (THL/Tongyong)
     * sh- + ???/???, sh- is ???, not ??? (MPS2)
     * c-  + ???/???, c-  is ???, not ??? (Tongyong)
     * ch- + ???/???, ch- is ???, not ??? (THL)
     * j-  + other than ???/???, j-  is ???, not ??? (MPS2)
     */

    if (final == strstr(final, "u") || final == strstr(final, "m")) {
        if (!strcmp(initial, "n")) {
            initial = "v";
        } else if (!strcmp(initial, "g")) {
            initial = "v";
        } else if (!strcmp(initial, "h")) {
            initial = "f";
        } else if (!strcmp(initial, "t")) {
            initial = "f";
        }
    } else {
        if (!strcmp(initial, "r")) {
            initial = "5";
        }
    }

    /* THL supplemental set
     * ???/???/???/??? + -??????, -?????? is another reading of -???
     * ???/???/???/??? + -??????, -?????? is another reading of -???
     */
    if (!strcmp(initial, "1") || !strcmp(initial, "q") || !strcmp(initial, "a") || !strcmp(initial, "z")) {

        if (!strcmp(final, "ji")) {
            final = "i";
        } else if (!strcmp(final, "j/")) {
            final = "/";
        }

    }

    sprintf(bopomofoKeySeq, "%s%s", initial, final);
    strcpy(bopomofoKeySeqAlt, bopomofoKeySeq);
    return 0;
}
