#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int desafio2381(){


    return 0;
}
int cmp_teste(const void *a, const void *b){

    const char **x = a, **y = b;

    return strcmp(*x,*y);
}
int aula02_02(){

    int n, j;

    scanf("%d%d", &n, &j);

    //char nomes[n][1123];

    char **nomes = malloc(n * sizeof(char *));

    for(int i = 0; i< n; ++i){
        nomes[i] = malloc(212356789 * sizeof(char));
        scanf(" %[^\n]", nomes[i]);

    }
    qsort(nomes, n ,sizeof(nomes[0]), cmp_teste);

    printf("%s\n", nomes[j - 1]);

    free(nomes);
    return 0;

}

int desafio2370(){





    return 0;
}


int main() {
    aula02_02();


    return 0;
}
