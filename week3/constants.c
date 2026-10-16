#include <stdio.h>
#include <math.h>

int main () {
    // константы
    const double g = 9.81, pi = acos(-1);
    // дано
    printf("Угол, град: ");
    double a = 0.0, v = 0.0, h = 0.0;
    scanf("%lf", &a);
    // Переводим в радианы
    a = a / 180.0 * pi;
    printf("Скорость, м/сек: ");
    scanf("%lf", &v);
    // Проекции на оси координат
    const double v_x = v * cos(a);
    const double v_y = v * sin(a);
    printf("Шаг, сек: ");
    scanf("%lf", &h);

    double t=0.0, x = 0.0, y = 0.0;

    puts("  t       x       y");

    //for (int i = 0; i < 10; ++i) {
    //    const double t = h * i;
    //    const double x = v_x * t;
    //    const double y = v_y * t - g * t * t / 2.0;
    //    printf("%7.3lf: %7.3lf %7.3lf\n", t, x, y);
    //}

    do {
        x = v_x * t;
        y = v_y * t - g * t * t / 2.0;
        printf("%7.3lf: %7.3lf %7.3lf\n", t, x, y);
        t += h;
    } while ( y >= 0.0 );

    return 0;
}
