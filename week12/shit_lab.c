#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define nn 20 //количество спортсменов


struct sport 
{
	char fam[30] ; // фамилия
	char stran[30]; // страна
	int k; // количество оценок
	float oc[5];// массив оценок не более 5
	float sr; //средняя оценка
	

};


// Результарующая структура
struct res 
{
	char stran[30];
	float s; //сумма средних оценок 	
};


void wwod( int *n, struct sport a[]);
void wiwod( int n, struct sport a[]);
void upor( int n, struct sport a[]);
void pobed( int n, struct sport a[],struct res *max);



int main() {

	int n;
	struct sport a[nn];
	struct res max;

	wwod(&n,a);

	upor(n,a);

	printf("Упорядоченные структуры:\n ");
	wiwod(n,a);

	pobed(n,a,&max);
	
	printf("\n\nСтрана победителя - %s\n",max.stran);
	printf("Средняя оценка победителя %6.2f \n", max.s);


	while(getchar() != '\n');
	getchar();
	return 0;
}
// функция ввода
void wwod( int *n, struct sport a[]){
		printf("Введите количество структур: ");
		scanf("%d", n);

		while(getchar() != '\n');

		printf("\n Введите данные в структуры \n ");
		for ( int i = 0; i < *n; i++) {
			printf("\n Введите фамилия : ");
			scanf("%s",a[i].fam);

			printf("\n Введите страну");
			scanf("%s",a[i].stran);

			printf("\n Введите количество оценок: ");
			scanf("%d",&a[i].k);

			printf("\n Введите оценки: ");
			a[i].sr = 0; // обнуляем				     
			for( int j = 0; j < a[i].k; j++) 
			{
				scanf("%f", &a[i].oc[j]);
				a[i].sr += a[i].oc[j];

			}
			a[i].sr /= a[i].k;// Вычисляем среднюю оценку
			
		}
}

// Функция вывода
void wiwod( int n, struct sport a[]){

	for(int i = 0; i < n; i++) {

		printf("Фамилия: %s\n",a[i].fam);
		printf("Страна: %s\n",a[i].stran);
		printf("Количество оценок: %2d\n",a[i].k);
		printf("Оценки: \n");
		for(int j =0; j < a[i].k; j++) {

			printf("%6.2f ", a[i].oc[j]);
		}
		printf("\nСредняя оценка: %6.2f\n ", a[i].sr);
		printf("----------------------\n");

	}
}

// Функция сортировки 
void upor(int n, struct sport a[]){

	int k = 0;
	bool flag;

	struct sport b; // Временная структура для обмена
	

	do {
		flag = false;
		k++;
		for(int i = 0; i < n-k; i++){
			// Если текущий элемент меньше следующего 
			if(a[i].sr < a[i + 1].sr){
				// Меняем их местами
				b = a[i];
				a[i] = a[i + 1];
				a[i + 1] = b;
				flag = true;// Был обмен, нужно продолжить
					    
			}
		}
	}while(flag);// Если обменов не было - массив отсортирован 

}

// Функция поиска страны-победителя

void pobed( int n, struct sport a[],struct res *max){

	int kol = -1;//Индекс последней добавленной страны в массив b
	struct res b[nn];
	bool flag;

	//1. Формируем массив уникальных стран и суммируем их баллы
	for ( int i =0;i < n; i++) {
		int j = 0;
		flag = true; // флаг: true, означает что страна еще НЕ найденп в массиве b
	// ищем страну уже в массиве b
	while((j <= kol) && flag)
	{ 
		if( strcmp(a[i].stran, b[j].stran) == 0)
		{
			flag = false;
			b[j].s += a[i].sr; // прибавяем балл спортсмена к общ сумме страны

		}
		else {
			j++; // ищем дальше

		}
	} //если цикл закончилсяа флаг все еще true то такой страны в массиве нету 
	 if (flag) {
	 	kol++;
		strcpy(b[kol].stran, a[i].stran);
		b[kol].s = a[i].sr; // записываем первый балл
	 }
		
	}
	//ищем страну с максимальной суммой баллов
	max->s = -1; // оценки не могут быть меньше нуля
	for(int i = 0; i <= kol; i++) 
	{
		if(b[i].s > max->s)
		{
			*max = b[i]; // копируем структуру победителя в макс
		}
	}
	// выводим сумму по всем странам
	for (int i = 0; i <= kol; i++) {
		printf("\n страна - %s, сумма средних оценок = %6.2f", b[i].stran, b[i].s);
	}
}



