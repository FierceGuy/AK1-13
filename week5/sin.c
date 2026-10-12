#include <stdio.h>
#include <math.h>

int main() {

    const double pi = atan(1.0) * 4.0;

    for (int i=0; i<10; i++) {
        x1 = x0 + i*dx;
        y1 = sin(x1 * pi / 180.0);
    }
}