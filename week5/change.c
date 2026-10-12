#include <stdio.h>
#include <math.h>

int main() {
    double x;

    // Ввод значения X с клавиатуры
    printf("Введите значение X: ");
    scanf("%lf", &x);

    // а) Вычисление точного значения производной Y'
    
    // 1. С использованием дополнительных переменных 
    double cs = cos(x);
    double sn = sin(x);
    double p2x = pow(2.0, x);
    double cos1 = (1.0 + cs);
    
    double drop1 = -sn / (cos1 * (p2x + 1.0));
    double drop2 = (log(cos1) * p2x * log(2)) / ((p2x + 1.0) * (p2x + 1.0));
    double answer0 = drop1 - drop2;

    // 2. Без использования дополнительных переменных
    double answer1 = -sin(x) / ((1.0 + cos(x)) * (pow(2.0, x) + 1.0)) - 
                             (log(1.0 + cos(x)) * pow(2.0, x) * log(2.0)) / 
                             ((pow(2.0, x) + 1.0) * (pow(2.0, x) + 1.0));

    
    printf("\nТочное значение производной:\n");
    printf("С доп. переменными:    %lf\n", answer0);
    printf("Без доп. переменных:   %lf\n", answer1);

    //  б) Цикл по DX и вывод таблицы результатов
    
    // Шапка таблицы (выравнивание по ширине столбцов)
    printf("DX\t\tDY\t\tDY/DX\t\tAbs_Error\tDel_error");

    // Значение функции Y(X) в исходной точке
    double y_x = log(1.0 + cos(x)) / (pow(2.0, x) + 1.0);

    double dx;
    
    for (dx = 1e-2; dx >= 1e-6; dx /= 10.0  ) {
        
        // Значение функции в смещенной точке Y(X + DX)
        double y_x_dx = log(1.0 + cos(x + dx)) / (pow(2.0, x + dx) + 1.0);
        
        // Приращение функции DY
        double dy = y_x_dx - y_x;
        
        // Приближенное значение производной
        double y_approx = dy / dx;
        
        // Абсолютная ошибка приближенного значения
        double abs_error = fabs(y_approx - answer1);

        // Относительная погрешность

        double del_error = (abs_error/y_x);
        
        // Вывод строки таблицы
        printf("\n%lf\t%lf\t%lf\t%lf\t%lf", dx, dy, y_approx, abs_error, del_error);
    }
    
    printf("");
    return 0;
}
