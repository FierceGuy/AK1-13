#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int x;
    float f;
    for(int i = 0; i < 5; ++i) {
        x = rand();
        f = (float)x / RAND_MAX;
        printf("x_%d = %10d, "
            "f_%d = %10f\n",
            i, x,
            i, f);
    }
    return 0;
}