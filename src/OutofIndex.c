//
// Created by sure on 2022-07-22.
//

#include "OutofIndex.h"
/*******************************************************************************
 *
 *  llista 2, ex 4
 * Joan Núñez Corbacho
 *
 *****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


/*************************** DECLARACIÓ DE FUNCIONS **********************/

void init_pol(double *p, int n, char nom);
int prodpol(int n, double *p, int m, double *q, double *pq);
void print_pol(double *p, int n, char nom);


/********************************* FUNCIÓ MAIN ***************************/

int main(void) {
    double *p, *q, *pq;
    int n, m, i;


    /* Demanem els graus de p i q */
    do {
        printf("Introdueix el grau del polinomi p: ");
        scanf("%d", &n);
    } while (n<0);

    do {
        printf("Introdueix el grau del polinomi q: ");
        scanf("%d", &m);
    } while (m<0);

    /* reservem memoria pels polinomis */
    p = (double*) calloc(n, sizeof(double));
    q = (double*) calloc(m, sizeof(double));
    pq = (double*) calloc(n+m, sizeof(double));

    /* initzialitzem els polinomis per input */
    init_pol(p, n, 'p');
    init_pol(q, m, 'q');

    print_pol(p, n, 'p');
    print_pol(q, m, 'q');

    /* calculem el producte de pq */
    prodpol(n, p, m, q, pq);

    print_pol(pq, n+m, 'r');

    /***************************************************** ERROR?! ******************************************
    free(p);
    free(q);
    free(pq);
    **********************************************************************************************************/

    return 0;
}



/************************ DEFINICIÓ DE FUNCIONS **************************/

int prodpol(int n, double *p, int m, double *q, double *pq) {
    /* calcula el producte del polinomi p de grau n amb el polinomi q de grau m, el guarda a pq, i retorna el grau */
    int i, j;
    double *x, *y;

    /* cream vectors còpia de p i q de longitud igual, n+m */
    x = (double*) calloc(n+m, sizeof(double));
    y = (double*) calloc(n+m, sizeof(double));


    /* copiam p i q a x i y i deixam 0s a les components que sobren */
    for (i= 0; i<= n; i++) {
        x[i] = p[i];
    }

    for (i= 0; i<= m; i++) {
        y[i] = q[i];
    }

    /* calculam el producte */
    for (i=0; i<= n+m; i++) {
        for (j=0; j<=i; j++) {
            pq[i] += (x[j] * y[i-j]);
        }
    }

    /************************************************************* ERROR?! *********************************************************
    free(x);
    free(y);
    *******************************************************************************************************************************/

    return n+m;
}

void init_pol(double *p, int n, char nom) {
    /* initialitza el polinomi p de grau n anomenat nom amb input */
    int i;
    for (i=0; i<=n; i++) {
        do {
            printf("Introdueix el coeficient %c%d (recorda que %c%d no pot ser 0): ", nom, i, nom, n);
            scanf("%lf", p+i);
        } while ( i==n && p[i] == 0);
    }
}

void print_pol(double *p, int n, char nom) {
    /* imprimeix el polinomi p de grau n */
    int i;

    printf("%c(x) = %lf + %lf · x", nom, p[0], p[1]);
    for (i=2; i<= n; i++) {
        printf(" + %lfx^%d", p[i], i);
    }
    printf("\n");
}