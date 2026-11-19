































#include <stdlib.h>
#include <stdio.h>

typedef struct memory
{
    float x, y;
} point;

void type point

int main(){
    printf("Задать количесвво элементов: ");
    size_t n = 0u;
    if (scanf("%zu", &n) != 1) {
        return 5;
    }
    //Выделение памяти
    point *pa = realloc(p, na * sizeof(point));
    if (pa == NULL) {
        free(p);
        p = NULL;
        return 99;
    } else {
        p = pa;
        pa = NULL
    }
    //ввод значений
    type points(p, n, na);
    //Освобождение
    free(p);
    p = NULL;

    return 0;
}
