#include <stdio.h>

void printBitsChar( char n )
{
	unsigned char mask= 1 << 7;
	int i;
	for( i= 7; i >= 0; i-- )
	{
		if ( n & mask )
			printf( "1" );
		else
			printf( "0" );
		if ( i == 4 )
			printf( " " ); // print a space between nibbles
		mask >>= 1;
	}	
}

int main()
{
	unsigned char a, b, c;
	a= 0xD3; // 1101 0011
	printf( "    a = 0x%.2hhX (", a );
	printBitsChar( a );
	printf( ")\n" );
	b= 0x23; // 0010 0011
	printf( "    b = 0x%.2hhX (", b );
	printBitsChar( b );
	printf( ")\n" );
	c= ~a; // 0010 1100 = 0x2C	
	printf( "   ~a = 0x%.2hhX (", c );
	printBitsChar( c );
	printf( ")\n" );
	c= a & b;
	printf( "a & b = 0x%.2hhX (", c ); // 0000 0011 = 0x03
	printBitsChar( c );
	printf( ")\n" );
	c= a | b;
	printf( "a | b = 0x%.2hhX (", c ); // 1111 0011 = 0xF3
	printBitsChar( c );
	printf( ")\n" );
	c= a ^ b;
	printf( "a ^ b = 0x%.2hhX (", c ); // 1111 0000 = 0xF0
	printBitsChar( c );
	printf( ")\n" );
}
