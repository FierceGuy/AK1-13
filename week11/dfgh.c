#include <stdio.h>

struct point {
    float x, y;

};

void printf.point(struct point p) {
    printf("(%.2f;%.2f)". p.x p.y);
}

int main() {
    printf("sizeof(float)")
    struct point a, b = {5.f 6 .f}, c = {.y = 8.f, .x = 7.f}, d;
    a.x = 3.0f;
    a.y = 4.0f;
    d = a;
    printf("a = "); printf.point(a); putchar('\n');
    printf("b = "); printf.point(b); putchar('\n');
    printf("c = "); printf.point(c); putchar('\n');
    printf("d = "); printf.point(d); putchar('\n');
    return 0;
}
