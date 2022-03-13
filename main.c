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

typedef struct Tetris{
    int resultado;
    char nome[16];
}Tetris;

int cmp_tetris(const void *a, const void *b){
    const struct Tetris *x = a, *y = b;

    if((*x).resultado > (*y).resultado){
        return -1;
    }
    if((*x).resultado < (*y).resultado){
        return 1;
    }
    return strcmp(x ->nome, y->nome);

}

int desafio2250(){
    int n;

    scanf("%d", &n);

    struct Tetris tetris[n];

    for (int i = 0; i < n; ++i) {
        int menor = 999999, maior = 0, soma = 0, jogo;
        scanf("%s", tetris[i].nome);
        for (int j = 0; j < 12; ++j) {
            scanf("%d", &jogo);
            soma+=jogo;
            if(maior<jogo){
                maior = jogo;
            }
            if(menor > jogo){
                menor = jogo;
            }
        }
        soma = soma - (maior + menor);
        tetris[i].resultado = soma;
    }
    for (int i = 0; i < n; ++i) {
        printf("%s %d\n", tetris[i].nome, tetris[i].resultado);
    }

    qsort(tetris, n, sizeof(tetris[0]), cmp_tetris);
    for (int i = 0; i < n; ++i) {
        printf("%d %s %d\n", (i + 1),tetris[i].nome, tetris[i].resultado);
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

typedef struct Time{
    int abilidade;
    char nomes[16];
}Time;

int desafio2370(){
    int nomes, time;

    scanf("%d %d", &nomes, &time);


    return 0;
}

#define MAX_N 200
#define MAX_M 200

int grade[MAX_N + 1][MAX_M + 1], n, m;

int vizinhanca[8][2] = {
        {-1, +0},
        {+1, +0},
        {+0, -1},
        {+0, +1},
        {-1, +1},
        {+1, -1},
        {+1, +1},
        {-1, -1},
};

int pinta(int x, int y){
    grade[x][y] = 2;

    int qtd_pintados = 1;

    int a,b;

    for (int i = 0; i < 8; ++i) {
        a = x + vizinhanca[i][0];
        b = y + vizinhanca[i][1];

        if((a >= 1 && a <= n && b >=1 && b<=m) && grade[a][b] == 0){
            qtd_pintados += pinta(a, b);
        }
    }
    return qtd_pintados;
}

int aula_09_03(){
    int x,y,k,a,b;

    scanf("%d%d%d%d%d", &n, &m, &x, &y, &k);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            grade[i][j] = 0;
        }
    }

    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &a, &b);

        grade[a][b] = 1;
    }

    int total_pintados = pinta(x, y);

    printf("%d\n", total_pintados);

    return 0;
}

#define MAX_N2 (51234)

int qtd_vizinhos[MAX_N2];

int* vizinhos[MAX_N2];

int pintado[MAX_N2];

void pinta_2(int a){
    pintado[a] = 1;

    int b;

    for (int i = 0; i < qtd_vizinhos[a]; ++i) {
        int b = vizinhos[a][i];

        if(pintado[b] == 0){
            pinta_2(b);
        }
    }
}

int aula_09_03_p2(){
    int x, y;

    scanf("%d%d", &x,&y);

    for (int i = 0; i < m; ++i) {
        int a, b;

        scanf("%d %d", &a, &b);

        vizinhos[a] = realloc(vizinhos[a], (qtd_vizinhos[a] + 1) * sizeof(i));
        vizinhos[a] = realloc(vizinhos[b], (qtd_vizinhos[b] + 1) * sizeof(i));

        vizinhos[a][qtd_vizinhos[a]] = b;
        vizinhos[b][qtd_vizinhos[b]] = a;

        ++qtd_vizinhos[a];
        ++qtd_vizinhos[b];
    }

    int qtd_familias = 0;

    for (int i = 1; i <= n; ++i) {
        if(!pintado[i]){
            ++qtd_familias;
            pinta_2(i);
        }
    }
    printf("%d\n", qtd_familias);

    for (int i = 0; i < n; ++i) {
        if(vizinhos[i] != NULL){
            free(vizinhos[i]);
        }
    }

    return 0;
}

int main() {
    aula_09_03_p2();


    return 0;
}
