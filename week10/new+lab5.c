#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

const int NN = 15;

void vvod(int nn, int *m, int *n, char *a);
void vivod(int nn, int m, int n, char *a);
bool simmetr(char *a, int n);

int main(){
    const int MM = 10;
    char a[MM][NN];
    int m, n, i, j;
    vvod(NN, &m, &n, &a[0][0]);
    vivod(NN, m, n, &a[0][0]);
    //вывод строк с проверкой на симметрию
    printf("Вывод строк матрицы с пояснением:\n");
    for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
            putchar(a[i][j]);
        }
        if (simmetr(a[i], n)){
            printf("   симметрично \n");}
        else
            printf("   не симметрично \n");
    }
    return 678;
}

void vvod(int nn, int *m, int *n, char *a){
    int i, j;
    printf("Введите число строк и столбцов матрицы: \n");
    while (scanf("%d %d", m, n) != 2 || *m < 1 || *m > 10 || *n < 1 || *n > nn)
    {
        printf("Ошибка, введите 2 числа: строки (1-10) и столбы (1-%d): ", nn);
        while (getchar() != '\n');    
    }

    while (getchar() != '\n');
    printf("Введите матрицу - набирайте ровно %d символов в строке:\n", *n);
    for(int i=0; i< *m; i++) {
		for(int j=0; j< *n; j++) {
            //обращаемся к элементу [i][j] через одномерный индекс: i*nn -прыжок чрез i полных строк,
            // +j - сдвиг внутри строки
            a[i * nn + j] = getchar(); 
        }
        while (getchar() != '\n'); 
    }

}

void vivod(int nn, int m, int n, char *a){
    int i, j;
    printf("число строк и столбцов матрицы: %d %d\n", m, n);
    printf("Матрица:\n");
    for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
            putchar(a[i * nn + j]);
        }
        printf("\n");
    }
}

bool simmetr(char *a, int n){
    int i = 0;
    //Идём с начала (a[i]) и с конца (a[n - i -1]) навстречу друг другу,
    // условие i <= n/2 на дает выйти за середину строки
    while (a[i] == a[n - i - 1] && i <= n/2)
        i++;

        //если мы остановились до того, как дошли до середины (i <= n/2),
        // значит символы не совпали и строка не симметрична 
    if (i <= n/2)
        return false;
    
}
