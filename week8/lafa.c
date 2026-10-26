#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

#define DEL_MAX 25

int main(){
    int D[DEL_MAX];
    int n;
    printf("Введите n:");
    scanf("%d", &n);
    if (n > 25){
        printf("Задание не такое");
        return 0;
    }
	for(int i=0; i<n; i++) {
		scanf("%d", &D[i]);
	}	 
    for(int i=0; i<n; i++)
        printf("%d ", D[i]);
    putchar('\n');

    int Mx = 0, v = 0;

    for (int i = 0; i<n; i++)
    {
        if (i != n-1 && D[i]*D[i+1] > Mx) {
            Mx = D[i]*D[i+1];
            v = i + 1;
        }
        if (i==n-1 && Mx < D[0]*D[i]){
            Mx = D[0]*D[i];
            v = n;
        }
    }
    
    printf("%d", v);
    putchar('\n');
    printf("%d", Mx);

    return 0;
}