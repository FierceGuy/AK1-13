#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    printf("Начало диапазона: ");
    float a = 0.0f;
    scanf("%f", &a);
    printf("Окончание диапазона: ");
    float b = 0.0f;
    scanf("%f", &b);

    float x = (float)rand() / RAND_MAX;
    x *= b - a;
    x += a;
    printf("Случайное число: %f\n", x);

    return 0;
}