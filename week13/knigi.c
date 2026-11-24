#include <stdio.h>
#include <stdbool.h>


#define nn 20 //максимальное количество книг

  

struct kniga
{
	char fam[30];   // фамилия автора
	char nazv[30]; // название книги
	int shkaf;      // номер шкафа
	int polka;      // номер полки
	int ryad;       // номер ряда на полке
};


void wwod( int *n, int *shkaf, struct kniga a[]);
void wiwod( int n, struct kniga a[]);
void upor( int n, struct kniga a[]);
void poisk( int n, struct kniga a[]);



int main() {

	int n, shkaf;
	struct kniga a[nn];

	wwod(&n, &shkaf, a);

	upor(n, a);

	printf("\nКниги шкафа %d, упорядоченные по номеру полки:\n", shkaf);
	wiwod(n, a);

	poisk(n, a);

	while(getchar() != '\n');
	getchar();
	return 0;
}

// функция ввода
void wwod( int *n, int *shkaf, struct kniga a[]){

		printf("Введите номер шкафа: ");
		scanf("%d", shkaf);

		printf("Введите количество книг в шкафу (не более %d): ", nn);
		scanf("%d", n);

		while(getchar() != '\n');

		for ( int i = 0; i < *n; i++) {
			printf("\n Книга %d\n", i + 1);

			printf(" Введите фамилию автора: ");
			scanf("%s", a[i].fam);

			printf(" Введите название книги: ");
			scanf("%30s", a[i].nazv); // название может быть из нескольких слов

			printf(" Введите номер полки: ");
			scanf("%d", &a[i].polka);

			printf(" Введите номер ряда: ");
			scanf("%d", &a[i].ryad);

			a[i].shkaf = *shkaf; // все книги в одном, заданном шкафу
		}
}

//Функция вывода
void wiwod( int n, struct kniga a[]){

	for(int i = 0; i < n; i++) {

		printf("Автор: %s\n", a[i].fam);
		printf("Название: %s\n", a[i].nazv);
		printf("Шкаф: %d\n", a[i].shkaf);
		printf("Полка: %d\n", a[i].polka);
		printf("Ряд: %d\n", a[i].ryad);
		printf("----------------------\n");

	}
}

// Функция сортировки по возрастанию номера полки
void upor(int n, struct kniga a[]){

	int k = 0;
	bool flag;

	struct kniga b; 


	do {
		flag = false;
		k++;
		for(int i = 0; i < n-k; i++){
			if(a[i].polka > a[i + 1].polka){
				b = a[i];
				a[i] = a[i + 1];
				a[i + 1] = b;
				flag = true;

			}
		}
	}while(flag);

}

// Функция поиска книг с фамилией автора от А до К
void poisk( int n, struct kniga a[]){

	int kol = 0; // сколько нашли

	printf("\nКниги, фамилии авторов которых начинаются с А по К:\n");

	for ( int i = 0; i < n; i++) {
		// В UTF-8 русская буква - это 2 байта. Первый байт у А...п одинаковый (0xD0),
		// а вторая половина (второй байт) у А...К лежит в диапазоне 0x90...0x9A
		unsigned char b1 = a[i].fam[0];
		unsigned char b2 = a[i].fam[1];

		if (b1 == 0xD0 && b2 >= 0x90 && b2 <= 0x9A) {
			kol++;
			printf("Автор: %s\n", a[i].fam);
			printf("Название: %s\n", a[i].nazv);
			printf("Шкаф: %d\n", a[i].shkaf);
			printf("Полка: %d\n", a[i].polka);
			printf("Ряд: %d\n", a[i].ryad);
			printf("----------------------\n");
		}
	}

	if (kol == 0) {
		printf("Таких книг нет\n");
	}
}