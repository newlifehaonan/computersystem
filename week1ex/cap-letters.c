#include <stdio.h>
#include <string.h>

int main()
{
	char str[]= "Hello";
	int i, length= strlen( str ), shift= 'a' - 'A';
	for( i= 0; i < length; i++ )
	{
		if ( str[i] >= 'a' && str[i] <= 'z' )
			str[i] -= shift;
	}
	printf( "%s\n", str );
}
