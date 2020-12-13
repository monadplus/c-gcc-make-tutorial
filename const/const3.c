#include <stdio.h>

int main(void)
{

  int i = 10;
  int j = 20;
  /* constant pointer to integer */
  int *const ptr = &i;

  printf("ptr: %d\n", *ptr);

  *ptr = 100; /* valid */
  printf("ptr: %d\n", *ptr);

  ptr = &j;	 /* error */

  return 0;
}
