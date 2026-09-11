#include <stdio.h>
#include <math.h>

int main(){
	printf("Задай x");
	double x;
	scanf("%lf", &x);
	double y= ((-3.3*0.0001)*
		tan(x)*log10(x * x - 5)*
		sqrt(fabs(tan(x))))/
		((cbrt(x * x - 5)*x*exp(-2*x)));
	printf("y = %lf\n", y);
	return 0;
}
