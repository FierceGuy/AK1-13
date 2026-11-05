#include <stdio.h>
#include <string.h>


int main() {
    char s[64];
    //char s[] = "hello world";
    //char s[] = {'h', 'e','l','l','o',' ','w','o','r','l','d', '\0'};
    puts("Введите строку");
    //gets(s);
    scanf("%s", s);
    printf("s = \"%s\"\n", s);


    return 99;
}
