#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){
    const char **x = a, **y =b;

    return strcmp(*x, *y);
}


int desafio2381(){
    int n, m;
    for(;;){
        scanf("%d %d", &n, &m);
        if(n >=1 && n <=100 && m>=1 && m<=100){
            break;
        }
    }


    char **nomes = malloc(n * sizeof(char *));

    for(int i = 0; i < n; ++i){
        nomes[i] = malloc(1123 * sizeof(char));
        scanf(" %[^\n]", nomes[i]);
    }

    qsort(nomes, n, sizeof(nomes[0]), cmp);

    printf("%s\n", nomes[m - 1]);

    free(nomes);

    return 0;
}


int desafio2250(){
    int n;

    char **nomes = malloc(n * sizeof(char ));

    for (int i = 0; i < n; ++i) {
        scanf(" %[^\n]",nomes[i]);

    }




    return 0;
}


int fatorial(int a){
    if(a == 0){
        return 1;
    }else{
        return a * fatorial(a - 1);
    }
}

int desafio1153()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", fatorial(n));

    return 0;
}

// 0! = 1
// n! = n * (n-1)!

// fib(0) = 0, fib(1) = 1
// fib(n) = fib(n-1) + fib(n-2)

int numero_chamadas = 0;

int memoria_fib[100];


int fib_memo(int n) {
    printf("Calculando: %d", &n);
    if (memoria_fib[n] != -1){
        return memoria_fib[n];
    }
    if (n == 0 || n == 1){
        memoria_fib[n] = n;
        return n;
    }
    int ret =  fib_memo(n-1) + fib_memo(n-2);

    memoria_fib[n] = ret;

    return ret;

}

int fib_rec(int n) {
    //printf("Calculando: %d", &n);
    if (n == 0 || n == 1) // (n <= 1)
        return n;

    int ret =  fib_rec(n-1) + fib_rec(n-2);
    //printf("Respondendo: %d\n", n);

    return ret;

}

//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, ..., fib(20)

// 0, 1
// 1, 0+1=1
// 1, 1+1 = 2
// 2, 2+1 = 3
// 3, 2+3 = 5
// 5, 3+5 = 8
// ...

typedef unsigned long long ull;

ull fib_loop(int n) {
    ull v[n+1];

    v[0] = 0;
    v[1] = 1;

    for(int i = 2; i <= n; ++i)
        v[i] = v[i-1] + v[i-2];

    return v[n];
}

int aula14_02() {

    for(int  i = 0; i < 100; ++i){
        memoria_fib[i] = -1;
    }

    int x;
    scanf("%d", &x);

    ull y = fib_memo(x);
    printf("%llu\n", y);
    printf("numero_chamadas: %d\n", numero_chamadas);

    return 0;
}


int main() {
    desafio2381();


    return 0;
}
