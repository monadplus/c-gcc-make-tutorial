#include <stdio.h>

int main(void)
{
	/* i is stored in read only area*/
	int const i = 10;
	int j = 20;

	/* types are matching no issue */
	int const *ptr = &i;

	/* error */
	*ptr = 100;

	/* Qualification. The type of &j is "int *" and is implicitly up qualified by the compiler to "const int *" */
	ptr = &j;

  /* Down qualification (dont) */

	int *ptr2 = &j;

  /* warning */
	ptr2 = &i;
}
