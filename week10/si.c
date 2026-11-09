#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#define M 5
#define N 10

char gen() {
 char c = 0;
 do{
  c = (char)(rand() % 128);
 } while (!isalpha(c));
 return c;
}

bool tru(char c) {
 switch (c) {
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
  case 'y': return 0;
  default: return 1;
 }
}

int main() {
 char C[M][N];
 srand(time(NULL));

 printf ("\nИсходная матрица:\n\n");
 for (int i = 0; i < M; ++i) {
  for (int j = 0; j < N; ++j) {
   C[i][j]= gen();
   printf ("%c ", C[i][j]);
  }
 printf ("\n\n");
 }

 char D[52];
 for (int q = 0; q < 26; ++q) {
  D[q * 2] = (char)(65 + q);
  D[(q * 2) + 1] = (char)(97 + q);
 }
 
 printf("Отсутствующие согласные:\n\n");
 for (int q = 0; q < 52; ++q){
  int g = 0;
  for (int i = 0; i < M; ++i) {
   for (int j = 0; j < N; ++j) {
    if (C[i][j] == D[q] || tru(D[q]) != 1) {
     g += 1;
    }
   }
  }
  if (g == 0){
   printf("%c ", D[q]);
  }
 }
 return 0;
}