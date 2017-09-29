# Week2 Note     
## Overflow    
1.  **overflow is the word size can not hold the value**    
2.  **negetive overflow is equal to underflow**    
*example*    
unsigned: 255 + 1 =0     
unsigned: 1 - 2 = 255      
signed: 127 + 1 = -128       
signed" -128 -1 = 127      

floating point numbers
------------

* FP have integral portion and a fractional portion    
* any number can be repressent as scientific notation      
* the number in fraction repressent 2^-1 2^-2 2^-3 ...       .
* 1 bit are sign bit, next 8 is exponent bits, the last 23 bits are used for signficand. (32 bits) single precision               
* 1, 11, 52 (64 bits) double precision       
* How does computer repressent single and double float value ?          
* suffix in assembly-code    

char	Byte	b	1    
short	word	w	2     
int	d-word	l	4    
long	q-word	q	8    
char*	q-word	q	8    
float	s-p	s	4    
double	d-p	l	8    

* registra name
a accumulator    
c counter    
d data    
b base     
si sourse : where is the position of the source      
di disgnator        

assembly commmand
-----------
* movq         
