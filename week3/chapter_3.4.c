//пример главы 3.4, №1
#include <stdio.h>
#include <math.h>

int main()
{
    float x, a, z, y;
    printf("Введите значение аргумента: ");
    scanf("%f", &x);

    //Вычисление абсолютного значения x
    a = fabs(x);

    //Вычисление z
    if (x > 0)
        z = 1.0;
    else if (x == 0)
        z = 0;
    else if (x < 0)
        z = -1.0;

    // 1) Вычисление y без применения логических операций
    if (a >= 3)
        printf("Функция не определена.\n");
    else
    {
        if (a <= 1.0)
            y = z * (1 - a);
        else if (a < 2.0)
            y = z;
        else
            y = -z;
    }
    printf("y = %f\n", y);

    // 2) Вычисление y с применением логических операций
    if (a >= 3)
        printf("Функция не определена.\n");
    if (a <= 1)
        printf("y = %f\n", y = z * (1 - a));
    if (a > 1 && a < 2)
        printf("y = %f\n", y = z);
    if (a >= 2 && a < 3)
        printf("y = %f\n", y = -z);

    return 0;
}
