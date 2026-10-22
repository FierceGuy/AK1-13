#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> 

int main(){
    const int Nmax = 20; 
    const float Nmin = 1e30;
    float x[Nmax], max, min, s, p;
    int N, iMax, iMin, i;

    //Ввод исходных данных
    //Ввод кол-ва элементов

    do
    {
        printf("Введите кол-во элементов: (1..%d)", Nmax);
        if (scanf("%d", &N) != 1){
            printf("Ошибка ввода кол-ва элементов\n");
            return 1;
        }
        
    } while (N < 1 || N > Nmax);

    printf("Введите элементы массива:\n");
    for (i = 0; i < N; i++)
    {
        printf("Введите элемент %2d:", i+1);
        if (scanf("%f", &x[i]) != 1)
        {
            printf("Ошибка ввода элемента\n");
            return 2;
        }
    }

    for (i = 0; i < N; i++)
    {
        printf("%6.2f", x[i]);
    }

    //Нахождение мин., макс., суммы и произведения
    s = 0;
    p = 1;
    max = Nmin;
    min = -Nmin;

    for (i = 0; i < N; i++)
    {
        if (x[i] < 0){
            s += x[i];
            if (x[i] > max){
                min = x[i];
                iMax = i;
            }
        }else if(x[i] > 0) {
            p *= x[i];
            if (x[i] < min){
                min = x[i];
                iMin = i;
            }
        }
    }
    

    //Проверка наличия отриц. элементов 

    if (s=0)
        printf("\n Отриц. элементов нет");
    else {
        x[iMax] = s;
        printf("\n s = %6.2f  max = %6.2f   iMax = %d  ", s, max, iMax);
    }

    //Проверка наличия положит элементов
    if (min == Nmin)
        printf("Положительных элементов нет!\n");
    else {
        x[iMin] = p;
        printf("\n p = %6.2f min = %6.2f iMin = %d", p, min , iMin);
    }

    //Проверка наличия отриц. элемнтов
    if (s ==0)
        printf("\nОтрицательных элементов нет!");
    else {
        x[iMin] = s;
        printf("\n s = %6.2f max = %6.2f iMan = %d", s, max , iMax);
    }
    
    //Преобразованный массив
    printf("Преобразованный массив:\n");
    for (i = 0; i < N; i++)
    {

        printf("%6.2f", x[i]);
    }

    return 0;
}