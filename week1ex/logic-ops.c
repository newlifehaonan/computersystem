#include <stdio.h>

int main()
{
	int a, b, c;
	a= 1;
	b= 0;
	printf( "a = %d, b = %d\n", a, b );
	if ( a && b )
		printf( "'a AND b' is true\n" );
	else
		printf( "'a AND b' is false\n" );
	if ( a || b )
		printf( "'a OR b' is true\n" );
	else
		printf( "'a OR b' is false\n" );
	c= !a;
	printf( "!a = %d\n", c );
	c= !b;
	printf( "!b = %d\n", c );	
}
