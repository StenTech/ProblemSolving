


int mode(int *s, int n) {
    int i, j, k, cont = 0;
    int tab[n][2];
    for(i=0; i < n; i++){
        cont = 1;
        for(j=i; j<n; j++){
            if(s[i] == s[j]) {
                cont++;
            }else{
                break;

            }
        }
        tab[k][0] = s[i];
        tab[k][1] = cont;
        k++;
        i=j;
    }
}