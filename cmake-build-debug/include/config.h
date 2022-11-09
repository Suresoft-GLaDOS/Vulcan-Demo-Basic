#define HAVE_SYS_TYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_STRTOK_R 1
#define HAVE_ASPRINTF 1
#define HAVE_UNISTD_H 1
/* #undef CURSES_HAVE_CURSES_H */
/* #undef CURSES_HAVE_NCURSES_H */
/* #undef CURSES_HAVE_NCURSES_NCURSES_H */
/* #undef CURSES_HAVE_NCURSES_CURSES_H */
/* #undef WORDS_BIGENDIAN */
#define WITH_SQLITE3 1

/* Change cmake curses macro name to autotools curses macro name */
#ifdef CURSES_HAVE_CURSES_H
#define HAVE_CURSES_H 1
#endif

#ifdef CURSES_HAVE_NCURSES_H
#define HAVE_NCURSES_H 1
#endif

#ifdef CURSES_HAVE_NCURSES_NCURSES_H
#define HAVE_NCURSES_NCURSES_H
#endif

#ifdef CURSES_HAVE_NCURSES_CURSES_H
#define HAVE_NCURSES_CURSES_H 1
#endif

/* For autotools cross-compilation compatibility */
#define HAVE_MALLOC 1
