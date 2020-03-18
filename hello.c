#include <stdio.h>

int max(int x, int y) {
  return (x <= y) ? x : y;
}

int main() {
   printf("Hello, World! \n");
   printf("max 1 2 : %d \n", max(1,2));
   return 0;
}
