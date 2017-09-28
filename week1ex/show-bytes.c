#include <stdio.h>

typedef unsigned char * byte_pointer;

void show_bytes( byte_pointer start, size_t len ) {
	int i;
	for( i= 0; i < len; i++ )
		printf( " %.2x", start[i] );
	printf( "\n" );
}

void show_int( int x ) {
	printf( "      int: " );
	show_bytes( (byte_pointer) &x, sizeof(int) );
}

void show_longlong( long long int x ) {
	printf( "long long: " );
	show_bytes( (byte_pointer) &x, sizeof(long long int) );
}

void show_float( float x ) {
	printf( "    float: " );
	show_bytes( (byte_pointer) &x, sizeof(float) );
}

void show_pointer( void * x ) {
	printf( "   void *: " );
	show_bytes( (byte_pointer) &x, sizeof(void *) );
}

void test_show_bytes( int val ) {
	int ival= val;
	long long int llval= ival;
	float fval= (float) ival;
	int * pval= &ival;
	show_int( ival );
	show_longlong( llval );
	show_float( fval );
	show_pointer( pval );
}

int main()
{
	test_show_bytes( 12345 );
}
