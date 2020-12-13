#include <stdio.h>

#define max(a,b) (((a)>(b))?(a):(b))

int min(int x, int y) {
  return (x <= y) ? x : y;
}

int main() {
   printf("Hello, World! \n");
   printf("min 1 2 : %d \n", min(1,2));
   printf("max 1 2 : %d \n", max(1,2));
   return 0;
}
