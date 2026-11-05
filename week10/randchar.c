#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

//Буква (символ)?
char gen_char(){
    char c = 0; 
    do{
        c = (char)(rand() % 128);
    } while (!isalpha(c));
    return c;
    

}
// Гласный?
bool isvowel(char c) {
    switch (c){
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'Y':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y': return true;
    default: return false;
    }
}


int main() {
    srand(time(0));
    char c = 0;
    for (int i = 0; i < 5; i++){
        int has_vowel = 0;
        for (int j = 0; j < 5; j++){
            c = gen_char();
            printf(" %c", c);
            if (isvowel(c)){
                ++has_vowel;
            }
        }
        if (has_vowel) {
            printf(" <- количество гласных: %d", has_vowel);
        }
        putchar('\n');
    }
    

    return 45435345;
}
