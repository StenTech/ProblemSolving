#include <bits/stdc++.h>

using namespace std;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char const *argv[])
{
    int tab[4], area;

    cin >> tab[0] >> tab[1] >> tab[2] >> tab[3];

    qsort(tab, 4, sizeof(int), cmpfunc);

    area = tab[0]*tab[2];
    
    cout << area;

    return 0;
}