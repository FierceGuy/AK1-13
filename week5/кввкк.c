int main(){
const double pi = 3.14;
double h = 1.0;
double a = 40;
double b = 50;

double f1, x, y, p, p1, c, d, ex, s;

int i;

a = pi * a/180;
h = pi * h/180;
b = pi * b/180 + h/2;

printf("\n %3s %6s %10s %8s %12s %16s", "#".
;("x)", '"p", '"pi","f1)ע" ,"א",

= a;
i= 0:

while(x < b)

//увеличение значения счётчика
i = i +1;
//ввод доп переменных
c = x*x;
d = 10*x;
ex = exp(-c);
s = sin(d);

//вычисл .:
//у(х) знач функции

y = ex * s/x;
p = ex * (d *

p1=(x*(exp(-x*x)*10*cos(10*x)-2*x*exp(-x*x)*sin(10*x))-exp(-x*x)*sin(10*x))/x/x;

f1=(exp(-(x+5e-9)*(x+5e-9)*sin(10*(x+5e-9)) / (x+5e-9) - exp(x -5e-9)*(x-5e-9)) * sin(10*(x-5e-9)) / (x-5e-9)) / 1e-8;
printf("\n %3d %8.21f %10.51F %11.51f %16.101f", i, (x * 180/pi), y, p, p1, f1);

x = x + h;

printf("\n");

cos(d)- s * (1 + 2*c)) / c;

return 0;