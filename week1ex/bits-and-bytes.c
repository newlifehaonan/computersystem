#include <stdio.h>

typedef unsigned char * byte_pointer;

void show_bytes( byte_pointer start, size_t len ) {
	int i;
	for( i= 0; i < len; i++ )
		printf( " %.2x", start[i] );
	printf( "\n" );
}

void show_int( int x ) {
	//printf( "int: " );
	show_bytes( (byte_pointer) &x, sizeof(int) );
}

void show_uint( unsigned int x ) {
	//printf( "uint: " );
	show_bytes( (byte_pointer) &x, sizeof(unsigned int) );
}

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
		mask >>= 1;
	}	
}

void printBitsUInt( unsigned int n )
{
	unsigned int mask= 1;
	mask <<= 31; // a 1 followed by 31 0's
	int i;
	for( i= 31; i >= 0; i-- )
	{
		if ( mask & n )
			printf( "1" );
		else
			printf( "0" );
		if ( (i % 8) == 0 )
			printf( " " ); // print a space between bytes
		mask >>= 1;
	}	
}

int main()
{
	unsigned int x;
	x= 0xa5b6c7d8 ; // 10100101 ...
	//x= 3623000000;
	printf( "x = %x\n", x );
	printf( "Bits: " );
	printBitsUInt( x );
	printf( "\n" );
	printf( "Bytes: " );
	show_uint( x );
}
