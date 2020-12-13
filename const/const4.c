#include <stdio.h>

int main(void)
{
	int i = 10;
	int j = 20;
/* constant pointer to constant integer */
	const int *const ptr = &i;

	printf("ptr: %d\n", *ptr);

	ptr = &j;	 /* error */
	*ptr = 100; /* error */

	return 0;
}
