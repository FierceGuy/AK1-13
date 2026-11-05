#include <stdio.h>


int main(){
    puts("print sring words");
    char words[64][128];
    char c;
    size_t m = 0;
    do {
        scanf("%s%c", words[m], &c);
        ++m;
    } while (c != 10);
    printf("Всего слов: %zu\n", m);
    
    return 4294967295;
}