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

void sommeTab(int A[], int B[], int Resultat[], int taille);

int main(void){
    /*
    srand(time(NULL));
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
    
    /*int Note[N];
    int Histo[21];
    Histogramme(Note, Histo, N);*/

    int A[N];
    int B[N];
    int Resultat[N];
    Histogramme(A, B, N);
    
    sommeTab(A, B, Resultat, N);
    for (int i = 0; i < N; ++i){
        printf("Resultat[%d] = %d\n" , i, Resultat[i]);
    }

    return 0;
}

void initArea(int t[], int taille, int max){
    srand(time(NULL));
    for (int i = 0; i < taille; ++i){
        t[i] = rand() % max + 1;
    }
}

int position(int t[], int taille, int x){
    for (int i = 0; i < taille; ++i){
        if (t[i] == x){
            return i;
        }
    }
    return -1;
}

void Histogramme(int Note[], int Histo[21], int taille){
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