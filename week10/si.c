#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define L 4 //Количество строк L <= 15
#define M 5 //Количество столбцов M <= 22

int main() {
    char V[L][M];
    char arr[L * M]; 
    int non_letter[M]; 
    
    srand(time(0));
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < M; ++j) {
            V[i][j] = 33 + rand() % 94; 
        }
    }

    printf("Исходная матрица:\n\n");
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("      %c", V[i][j]);
        }
        printf("\n\n");
    }

    int k = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < M; ++j) {
            arr[k++] = V[i][j];
        }
    }

    //Создаём новый одномерный массив для перетасовки элементов в нём: 
    //сначала небуквенные, затем буквенные
    char temp[L * M];
    int idx = 0;
    

    for (int i = 0; i < L * M; ++i) {
        if (!isalpha(arr[i])) {
            temp[idx++] = arr[i];
        }
    }

    for (int i = 0; i < L * M; ++i) {
        if (isalpha(arr[i])) {
            temp[idx++] = arr[i];
        }
    }

    for (int i = 0; i < L * M; ++i) {
        arr[i] = temp[i];
    }


    k = 0; //Обнуляем индекс, чтобы снова идти сначала
    for (int j = 0; j < M; ++j) {    
        for (int i = 0; i < L; ++i) {
            V[i][j] = arr[k++];
        }
    }

    for (int j = 0; j < M; ++j) {
        non_letter[j] = 0;
        for (int i = 0; i < L; ++i) {
            if (!isalpha(V[i][j])) {
                non_letter[j]++;
            }
        }
    }

    printf("Преобразованная матрица:\n\n");
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("      %c", V[i][j]);
        }
        printf("\n\n");
    }

    printf("Количество небуквенных символов под столбцами:\n");
    for (int j = 0; j < M; ++j) {
        printf("      %d", non_letter[j]);
    }
    printf("\n");

    return 0;
}