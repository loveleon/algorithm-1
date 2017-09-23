#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int* pi = NULL;

	int a   = 1;
	int &ra = a;
	pi = &a;

	printf("the pointer: %llx, the var: %lld,  the reference: %llx.\n", pi, a, &ra); 
	
	return 0;
}
