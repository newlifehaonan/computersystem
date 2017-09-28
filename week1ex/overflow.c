#include <stdio.h>

int main()
{
	unsigned char uc1, uc2, uc3;
	signed char sc1, sc2, sc3;
	
	// UNSIGNED:
	// 255 + 1
	uc1= 255;
	uc2= 1;
	uc3= uc1 + uc2;
	printf( "uc1: %hhu, uc2: %hhu, uc1 + uc2: %hhu\n", uc1, uc2, uc3 );
	
	// 1 - 2
	uc1= 1;
	uc2= 2;
	uc3= uc1 - uc2;
	printf( "uc1: %hhu, uc2: %hhu, uc1 - uc2: %hhu\n", uc1, uc2, uc3 );
	
	// SIGNED:
	// 127 + 1
	sc1= 127;
	sc2= 1;
	sc3= sc1 + sc2;
	printf( "sc1: %hhd, sc2: %hhd, sc1 + sc2: %hhd\n", sc1, sc2, sc3 );
	
	// -128 - 1
	sc1= -128;
	sc2= 1;
	sc3= sc1 - sc2;
	printf( "sc1: %hhd, sc2: %hhd, sc1 - sc2: %hhd\n", sc1, sc2, sc3 );	
}
