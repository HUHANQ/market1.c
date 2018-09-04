#include <stdio.h>

int main()

{
	long a= 3;
	int b[2];
	b[2] = 10;
	printf("i = %d",a);
	printf("%p %p",&a,&b);
	return 0;
}
