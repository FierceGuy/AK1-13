#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//объявление макро-переменных
#define MAX_ROWS 20   // строк
#define MAX_COLS 40 //столбцов

int main() {
    float M[MAX_ROWS][MAX_COLS];
    size_t m, n;
    m = n = 0;
    do {
        printf("Задай число строк [1;%zu]; ", MAX_ROWS);

        if(scanf("%zu", &m) != 1) {
            printf("Ошибка ввода числа строк!");
            return 1;
        }
    } while (m == 0 || m > MAX_ROWS);
    printf("число строк: %zu\n", m);

    do {
        printf("Задай число столбцов [1;%zu]; ", MAX_COLS);

        if(scanf("%zu", &n) != 1) {
            printf("Ошибка ввода числа столбцов!");
            return 1;
        }
    } while (n == 0 || n > MAX_COLS);
    printf("число столбцов: %zu\n", n);

    srand(time(NULL));
    for(int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            M[i][j]= -10.0f + (float)rand() / RAND_MAX * 20.0f;
            printf(" %6.2f", M[i][j]);
        }
        putchar('\n');
    }

    return 0;
}