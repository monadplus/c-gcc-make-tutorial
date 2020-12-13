#include <stdio.h>

int main(void)
{
	int i = 10;
	int j = 20;
	const int *ptr = &i;

  /* valid */
	ptr = &j;

	/* error: object pointed cannot be modified using the pointer ptr */
	*ptr = 100;

	return 0;
}
