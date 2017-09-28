#include <stdio.h>

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
	// create a mask that will reveal the values of only those two bits:
	char mask= 0x3; /* binary '0000 0011' */
	// the value is contained in the variable x:
	char x= 86; /* binary '0101 0110' */
	// apply the mask to the value:
	char result= x & mask;
	printf( "result: %#hhx\n", result ); /* prints 'result: 0x2', which in binary is '0000 0010' */
	
	// create a mask for bytes 0 and 2 of an int
	unsigned int num= 0x87654321;
	unsigned int imask= (0xff << 16) | 0xff;
	printf( "bits: " );
	printBitsUInt( imask );
	printf( "\n" );
	printf( "uint: %#x; masked uint: %#x\n", num,num & imask );	
}
