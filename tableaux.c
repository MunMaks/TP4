#include <stdio.h>
#include <string.h>
//#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 21

void initArea(int t[], int taille, int max);

int position(int t[], int taille, int x);

void Histogramme(int Note[], int Histo[], int taille);

void histogramme(int tab[][N], int nb_tab, int taille, int n_max, int histo[]);

void sommeTab(int A[], int B[], int Resultat[], int taille);

void sommeTab_V2(int tab[][N], int Resultat[], int taille, int nb_tab);


int main(void){
    srand(time(NULL));
    /*
    int rand_int;
    for (int i=0; i < 20; ++i){
        rand_int = rand();
        //printf("%d\n", rand_int);
    }

    int t[N];

    //initArea(t, N, 100000);
    
    initArea(t, N, 100);
    printf("Initialized Array: \n");
    for (int i = 0; i < N; ++i) {
        printf("t[%d]: %d \n", i, t[i]);}

    int pos = position(t, N, 75);
    printf("Positon of 75: %d\n", pos);
    */

    int graine = 5;
    int nb_tab = 3;
    int A[N];
    int B[N];
    int C[N];
    initArea(A, N, graine);
    initArea(B, N, graine);
    initArea(C, N, graine);
    int tab_test[3][N] = {0};

    for (int i = 0; i < N; ++i){
        tab_test[0][i] = A[i];
        tab_test[1][i] = B[i]; 
        tab_test[2][i] = C[i]; 
    }
    int Resultat[N] = {0};
    int histo[N] = {0};

    sommeTab_V2(tab_test, Resultat, N, nb_tab);
    /*
    for (int i = 0; i < nb_tab; ++i){
        for (int j = 0; j < N; ++j){
            printf("%d ", tab_test[i][j]);
        }
        printf("\n");
    }*/

    histogramme(tab_test, nb_tab, N, 21, histo);
    

    /*sommeTab(A, B, Resultat, N);*/
    
    for (int i = 0; i < N; ++i){
        printf("%d ", histo[i]);
    }
    printf("\n\n");
    
    return 0;
}

void initArea(int t[], int taille, int max){
    for (int i = 0; i < taille; ++i){
        t[i] = rand() % max;
    }
}

int position(int t[], int taille, int elt){
    for (int i = 0; i < taille; ++i)
        if (t[i] == elt) { return i; }
    return -1;
}

void Histogramme(int Note[], int Histo[N], int taille){
    initArea(Note, N, 20);
    for (int i = 0; i < 21; ++i){
        Histo[i] = Note[i];
        printf("Histo[%d] = %d et Note[%d] = %d\n", i, Histo[i], i, Note[i]);
    }
}

void sommeTab(int A[], int B[], int Resultat[], int taille){
    for (int i = 0; i < taille; ++i){
        Resultat[i] = A[i] + B[i];
    }
}

void sommeTab_V2(int tab[][N], int Resultat[N], int taille, int nb_tab){
    int temp = 0;
    for (int i = 0; i < taille; ++i){
        temp = 0;
        for (int j = 0; j < nb_tab; ++j)
            temp += tab[j][i]; 
        Resultat[i] += temp;
    }
}

void histogramme(int tab[][N], int nb_tab, int taille, int n_max, int histo[]){
    int Res[N] = {0};
    sommeTab_V2(tab, Res, N, nb_tab);

    for (int i = 0; i < n_max; ++i){
        for (int j = 0; j < taille; ++j){
            if (Res[j] == i) { ++histo[i]; }
        }
    }
}