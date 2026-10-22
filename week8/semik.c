#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    const int nn = 30;
    float y[nn]; //массив
    float s, //сумма значений элементов массива
        p,     //произведение значений массива
        srarif, //ср афим
        srgeom; //ср геом

    int i, n; // кол-во элементов

    do
    {
        printf(" Введите значение n (1..%d)", nn);
        if (scanf("%d", &n) !=1) // проверка ввода правильного значения
        {
            printf("Ошибка ввода кол-ва элементов\n");
            return 1;
        }
    } while (n < 1 || n > nn);

    for (i = 0; i < n; i++){
        printf("Введите элемент %2d: ", i +1);
        if (scanf("%f", &y[i]) != 1)
            {
                printf("Ошибка ввода элемента! \n");
                return 2;
            }
    }
       
    s = 0;
    p = 1;

    for (i = 0; i < n; i++)
    {
        s += y[i];
        p *= y[i];
    }

    printf("Сумма = %6.2f   Произведение = %6.2f\n", s, p);
    srarif = s / n;

    // Проверка на корень из отриц. числа
    if (p < 0)
    {
        printf("Ср. арифм = %6.2f    Ср. геом. - не определено (произведение < 0)\n", srarif);
    }
    else {
            srgeom = pow(p, (float)1 /n);
            printf("Ср. арифм = %6.2f    Ср. геом. = %6.2f \n", srarif, srgeom);

    }

    return 0;
}