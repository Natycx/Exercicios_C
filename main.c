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

int fib_rec(int n) {
    if (n == 0 || n == 1) // (n <= 1)
        return n;

    return fib_rec(n-1) + fib_rec(n-2);
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
    int x;
    scanf("%d", &x);

    ull y = fib_loop(x);
    printf("%llu\n", y);

    return 0;
}


int main() {
    aula02_02();


    return 0;
}
