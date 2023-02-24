#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * cette fonction permet me pemettre de trouver le nombre
 * de repétition de chaque nombre de la serie s et retourne le nombre d'élement distinct
*/
int frequency(int *s, int n, int fq[][2]){
    // Je suppose que s est trié
    int i = 0;
    int j = 0;

    while ( i < n)
    {
        fq[j][0] = s[i];
        fq[j][1] = 1;
        while (s[i] == s[i+1]) {
            fq[j][1]++;
            i++;
        }
        i++;
        j++;
    }

    return j;
}


/**
 * Permet de trouver le nombre le plus fréquent grace aux freéquence trouvée avec frequency
 * */
int max_fq(int fq[][2], int n) {
    int max = -1;
    int mode = 0;
    for (int i = 0; i < n; i++)
    {
        if (fq[i][1] > max)
        {
            mode = fq[i][0];
            max = fq[i][1];
        }
    }

    return mode;
}

/** La fotion Mode en question*/
int mode(int *s, int n){
    int fq[n][2];
    int mn = frequency(s, n, fq);
    return max_fq(fq, mn);
}



double moy_arith(int *s, int n){
    
    double moy = 0;
    
    for (int i = 0; i < n; i++)
    {
        moy += s[i];
    }

    moy = (double)(moy/n);

    return moy;
    
}

double ecart_moy(int *s, int n) {
    
    double moy = moy_arith(s, n);
    double moy_ecart = 0;

    for (int i = 0; i < n; i++)
    {
        moy_ecart += fabs(s[i] - moy);
    }

    return (double)(moy_ecart/n);
    
}

double variance(int *s, int n) {
    double moy = moy_arith(s, n);
    double variance_ = 0;

    for (int i = 0; i < n; i++)
    {
        variance_ += pow((s[i] - moy), 2);
    }

    return (double)(variance_/n);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int main(int argc, char const *argv[])
{
    int s[15] = {1, 8, 19, 4, 8, 5, 6, 4, 6, 1, 8, 4, 8, 1, 11};
    int fq[15][2];
    
    qsort(s, 15, sizeof(int), cmpfunc);
    
    //for (int i = 0; i < 15; i++)
    //{
    //    printf("%i  ", s[i]);
    //}
    //printf("\n");
    //printf("%D\n", moy_arith(s, 15));
    //printf("%i\n", mode(s, 14));
    
    return 0;
}

