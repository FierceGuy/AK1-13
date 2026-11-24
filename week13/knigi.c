#include <stdio.h>
#include <stdbool.h>


#define nn 20 //максимальное количество книг в шкафу


struct kniga
{
	char fam[40];   // фамилия автора
	char nazv[80];  // название книги
	int shkaf;      // номер шкафа
	int polka;      // номер полки
	int ryad;       // номер ряда на полке
};


void wwod( int *n, int *shkaf, struct kniga a[]);
void wiwod( int n, struct kniga a[]);
void upor( int n, struct kniga a[]);
bool a_k( const char *s);
int poisk( int n, struct kniga a[], struct kniga b[]);



int main() {

	int n, m, shkaf;
	struct kniga a[nn];
	struct kniga b[nn]; // сюда попадут книги с фамилиями на буквы А-К

	wwod(&n, &shkaf, a);

	upor(n, a);

	printf("\nКниги шкафа №%d, упорядоченные по номеру полки:\n ", shkaf);
	wiwod(n, a);

	m = poisk(n, a, b);

	if (m > 0) {
		printf("\nКниги, фамилии авторов которых начинаются с буквы от А до К:\n ");
		wiwod(m, b);
	}
	else {
		printf("\nКниг с фамилиями авторов на буквы от А до К нет\n");
	}

	while(getchar() != '\n');
	getchar();
	return 0;
}

// функция ввода
void wwod( int *n, int *shkaf, struct kniga a[]){

		printf("Введите номер шкафа: ");
		scanf("%d", shkaf);

		do {
			printf("Введите количество книг в этом шкафу (от 1 до %d): ", nn);
			scanf("%d", n);
		} while (*n < 1 || *n > nn);

		while(getchar() != '\n');

		printf("\n Введите данные о книгах \n ");
		for ( int i = 0; i < *n; i++) {
			printf("\n Книга %d\n", i + 1);

			printf(" Введите фамилию автора: ");
			scanf("%39s", a[i].fam);

			printf(" Введите название книги: ");
			scanf(" %79[^\n]", a[i].nazv); // читаем строку с пробелами до конца строки

			printf(" Введите номер полки: ");
			scanf("%d", &a[i].polka);

			printf(" Введите номер ряда на полке: ");
			scanf("%d", &a[i].ryad);

			a[i].shkaf = *shkaf; // шкаф у всех книг один - заданный
		}
}

// Функция вывода
void wiwod( int n, struct kniga a[]){

	for(int i = 0; i < n; i++) {

		printf("Автор: %s\n", a[i].fam);
		printf("Название: %s\n", a[i].nazv);
		printf("Шкаф: %2d\n", a[i].shkaf);
		printf("Полка: %2d\n", a[i].polka);
		printf("Ряд: %2d\n", a[i].ryad);
		printf("----------------------\n");

	}
}

// Функция сортировки по возрастанию номера полки
void upor(int n, struct kniga a[]){

	int k = 0;
	bool flag;

	struct kniga b; // Временная структура для обмена


	do {
		flag = false;
		k++;
		for(int i = 0; i < n-k; i++){
			// Если номер полки текущей книги БОЛЬШЕ следующей
			if(a[i].polka > a[i + 1].polka){
				// Меняем их местами
				b = a[i];
				a[i] = a[i + 1];
				a[i + 1] = b;
				flag = true;// Был обмен, нужно продолжить

			}
		}
	}while(flag);// Если обменов не было - массив отсортирован

}

// Проверка: начинается ли строка с русской буквы от А до К (UTF-8)
bool a_k( const char *s){

	unsigned char c1 = (unsigned char)s[0];

	if (c1 != 0xD0 && c1 != 0xD1) {
		return false; // первый байт не из кириллицы
	}

	unsigned char c2 = (unsigned char)s[1];

	if (c1 == 0xD0) {
		if (c2 >= 0x90 && c2 <= 0x9A) return true; // заглавные А..К
		if (c2 >= 0xB0 && c2 <= 0xBA) return true; // строчные  а..к
		if (c2 == 0x81)               return true; // Ё (стоит между Е и Ж)
	}
	else { // c1 == 0xD1
		if (c2 == 0x91)               return true; // ё
	}

	return false;
}

// Функция поиска книг, фамилия автора которых начинается с А..К
int poisk( int n, struct kniga a[], struct kniga b[]){

	int m = 0; // количество найденных книг

	for ( int i = 0; i < n; i++) {
		if (a_k(a[i].fam)) {
			b[m] = a[i]; // копируем найденную книгу в массив b
			m++;
		}
	}

	return m;
}
