#include <stdio.h>
#include <math.h>

int main(){
    float x, a, z, y;
    printf("Введите значение аргумента: ");
    scanf("%f", &x);

    a = fabs(x+2);
    z = fabs(x-2);

    if (x < -1)
        y = a;
    else if (x >= -1 && x <= 1)
        y = 1;
    else
        y = z;

    printf("y=%f\n", y);
    /*float x, a, z, y;
    printf("Введите значение аргумента: ");
    scanf("%f", &x);

    //Вычисление абсолютного значения х
    a = fabs(x);

    if (x > 0)
        z = 1.0;
    else if (x == 0)
        z = 0;
    else if (x < 0)
        z = -1.0;
    
    // 1) вычисление у без применения логических операций
    if (a >=3)
        printf("функция не определена. \n");
    else
    {
        if (a <= 1.0)
            y = z * (1 - a);
        else if (a < 2.0)
            y = z;
        else 
            y = -z;
    }
    printf("y=%f\n", y);

    // 2) вычисление у с применением логических операций
    if (a >= 3)
        printf("функция не определена. \n");
    if (a <= 1)
        printf("y =%f\n", y = z * (1 - a));
    if (a > 1 && a < 2)
        printf("y =%f\n", y=z);
    if (a >= 2 && a < 3)
        printf("y =%f\n", y =- z);*/


    return 0;
}







