#include <stdio.h>

int main(){
    char c[2] = {'A', 'B'};
    printf("c[0] = '%c', c[1] = '%c'\n", c[0], c[1]);
    char *pC = c;
    //char *pC = &c[0];
    printf("pC = %p\n", pC);
    *pC = 'B';
    printf("c[0] = '%c', c[1] = '%c'\n", c[0], c[1]);
    pC = pC + 1;
    printf("pC = %p\n", pC);
    *pC = 'c';
    printf("c[0] = '%c', c[1] = '%c'\n", c[0], c[1]);
    return 0;
}