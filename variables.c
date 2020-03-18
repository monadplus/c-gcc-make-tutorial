#include <stdio.h>

// Can be access at any place by other files.
extern int a, b;
extern int c;
extern float f;

int fun() {
   int a, b;
   int c;
   float f;

   a = 10;
   b = 20;

   c = a + b;
   printf("value of c : %d \n", c);

   f = 70.0/3.0;
   printf("value of f : %f \n", f);

   return c;
}


int main () {
  int r = fun();

  printf("value of r : %d \n", r);

  return 0;
}
