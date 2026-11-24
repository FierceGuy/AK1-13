#include <stdio.h>
#include <string.h>
#include <locale.h>

// Структура для хранения данных о пассажире
typedef struct {
    char fam[50];
    float ves;
    int veshey;
    float doplata;
} Pass;

int main() {
    // Включаем русский язык в консоли
    setlocale(LC_ALL, "Russian");

    int n;
    float A, tarif; // A - бесплатный вес, tarif - цена за 1 кг перевеса

    printf("Введите разрешенный бесплатный вес (A кг): ");
    scanf("%f", &A);
    printf("Введите стоимость доплаты за 1 кг сверхнормативного веса (руб): ");
    scanf("%f", &tarif);
    printf("Введите количество пассажиров: ");
    scanf("%d", &n);

    Pass p[n], m1[n], m2[n];
    int c1 = 0, c2 = 0; // Счетчики для массивов m1 и m2

    // Ввод данных
    for (int i = 0; i < n; i++) {
        printf("\nПассажир %d:\n", i + 1);
        printf("Фамилия: "); scanf("%s", p[i].fam);
        printf("Вес багажа: "); scanf("%f", &p[i].ves);
        printf("Кол-во вещей: "); scanf("%d", &p[i].veshey);

        // Вычисление доплаты
        if (p[i].ves > A) {
            p[i].doplata = (p[i].ves - A) * tarif;
        } else {
            p[i].doplata = 0;
        }

        // Формирование первого массива (вес > A)
        if (p[i].ves > A) m1[c1++] = p[i];
        
        // Формирование второго массива (вещей > 2)
        if (p[i].veshey > 2) m2[c2++] = p[i];
    }

    // Сортировка массива m1 по фамилии (метод пузырька)
    for (int i = 0; i < c1 - 1; i++) {
        for (int j = 0; j < c1 - i - 1; j++) {
            if (strcmp(m1[j].fam, m1[j+1].fam) > 0) {
                Pass temp = m1[j]; m1[j] = m1[j+1]; m1[j+1] = temp;
            }
        }
    }

    // Сортировка массива m2 по фамилии
    for (int i = 0; i < c2 - 1; i++) {
        for (int j = 0; j < c2 - i - 1; j++) {
            if (strcmp(m2[j].fam, m2[j+1].fam) > 0) {
                Pass temp = m2[j]; m2[j] = m2[j+1]; m2[j+1] = temp;
            }
        }
    }

    // Вывод результатов на экран (стилизовано под ваш пример)
    printf("\n--------------------------------------------------\n");
    printf("Пассажиры с весом багажа больше %.1f кг:\n", A);
    for (int i = 0; i < c1; i++) {
        printf("Фамилия: %-10s | Вес: %5.1f | Вещей: %d | Доплата: %.2f руб.\n", 
               m1[i].fam, m1[i].ves, m1[i].veshey, m1[i].doplata);
    }

    printf("\n--------------------------------------------------\n");
    printf("Пассажиры, имеющие более 2 вещей:\n");
    for (int i = 0; i < c2; i++) {
        printf("Фамилия: %-10s | Вес: %5.1f | Вещей: %d | Доплата: %.2f руб.\n", 
               m2[i].fam, m2[i].ves, m2[i].veshey, m2[i].doplata);
    }
    printf("--------------------------------------------------\n");

    return 0;
}