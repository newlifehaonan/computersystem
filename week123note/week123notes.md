* Size     
  1 bit    
  1 nibble = 4bits    
  1 byte = 8 bits   
  `_ _ _ _ | _ _ _ _`    
  `8 4 2 1`

* Decimal & Hexdecimal & Binary Conversion
  * Decimal <-> Hexdecimal
  * Hexdeciaml <-> Binary     
    `0xff` = `1 1 1 1 | 1 1 1 1`    
    one binary number count 1 bit     
    one Hexdeciaml number count 1 nibble


* Register file


Type   | accumulator|base|counter|data|source index|destination index |stack pointer|base pointer                                         
:-----:|  :-----:|:-----:|:----:|:---------:|:-------:|:------:|:------:|:---:
64bits |  %rax | %rbx|  %rcx | %rdx | %rsi | %rdi | %rsp | &rbp
32bits |  %eax | %ebx|  %ecx | %edx | %esi | %edi | %esp | &ebp
16bits |  %ax  | %bx |  %cx  | %dx  | %si  | %di  | %sp  | &bp
8bitsh |  %ah  | %bh |  %ch  | %dh  | ---- | ---  | ---  | ---                      
8bitsl |  %al  | %bl |  %cl  | %dl  | ---- | ---  | ---  | ---                


* Data size     
  C Defaul seting is signed number, using `unsigned` to convert sign to unsigne

Byte  | bits | C | Assembly | Register
:---: |:---:|:--:|:---------:|:-------:
1     |8|char|b|.h/.l
2     |16|short|w|no suffix
4     |32|int|l|%e..
4     |32 |float|---|---
8     |64|long|q|%r..
8     |64 |double|---|---

* Bit ordering    
  0x12345678
  * big endian    
  12 34 56 78
  * little endian    
  78 56 34 12

* Bit operator
  * `==` ：`!(x^y)`
  * ``（a^b)^a = b``
  * `a | (c & d) = (a | c) & (a | d)`
  * `a & (c | d) = (a & c) | (a & d)`

operator | a | b | result
:--: | :--: | :--: | :--:
~ | 1001| --- |0110
& | 1001| 0011 |0001
&#124;| 1001| 0011 |1011
^ | 1001| 0011 |1010


* Logic operator  

operator | a | b | result
:--: | :--: | :--: | :--:
! | 0x00|----|1
&&| 0x11 |0x00|0
&#124;&#124;|0x11 |0x00|0

* Shift operator

operator | sign | unsign
:--: | :--: | :--: | :--:
&gt;&gt;|preserve sign bit |0
&lt;&lt;|0|0		


* Integer repressentation
  * negetive Integer repressentation   
    ``-x = ~x + 1``
  * value range(k is the word size)     
    sign: ``-2^(k-1) ---- 2^(k-1) -1``      
    unsign: `0 ---- 2^k -1`

data type     | bit   | Min |Min(Hex)| Max | Max(Hex)
:---:         | :---: |:---:|:---:|:---:|:---:
char          |8      |-128 |0x80|127|0xff
unsigned  char|8      |0    |0|255|0x7f
short         |16     |-2^15|0x8000|-2^15 - 1|0x7fff
unsigned  char|16     |0    |0|2^16 -1|0xffff
int           |32     |-2^31|0x80000000|-2^31 - 1|0x7fffffff
unsigned      |32     |0    |0|2^32 -1|0xffffffff
long          |64     |-2^61|0x8000000000000000|-2^61 - 1|0x7fffffffffffffff
unsigned  long|64     |0    |0|2^64 -1|0xffffffffffffffff

* Conversion between different datatype   
  **In C, if you compare different datatype, C will cast the datatype implicitly**
  * Binary to Unsigned
  $$B2U_4([1011]) = 2^3 + 2^1 + 2^0 = 11$$
  * Binary to 2 complement encoding
  $$B2T_4([1011]) = -2^3 + 2^1 + 2^0 = -5$$
  * Unsign to sign
  $$U2T_4([1011]) = 2^3 + 2^1 + 2^0 -2^4 = -5$$
  $$U2T_4([0011]) = 2^1 + 2^0 = 3$$
  * sign to Unsign
  $$T2U_4([1011]) = -2^3 + 2^1 + 2^0 +2^4 =11$$
  $$T2U_4([0011]) =  2^1 + 2^0 = 3$$

* Comparation between sign and unsign      
  Defaul change sign to unsign and then compare

* Convert small size to large size
  * zero extension     
  Used for Unsigned datatype      
  `(unsigned short)[1001] =[0000 1001] = 9`
  * sign extension
  Used for signed datatype    
  ``(short)[1001] =[1111 1001] =-7``


* Overflow
  * unsigned Overflow      
  ``[1111] + [0001] = [1 | 0000] = [0000]`` =`15 + 1 = 0` =`15 + 1 - 16 = 0`
  * signed Overflow
    * positive Overflow     
    `[0111] + [0001] = [1000] ` = `7 + 1 = -8` = `7 + 1 -16 = -8`
    * negetive Overflow      
    `[1000] + [1111] = [1|0111] ` = `-8 + (-1) = 7 ` = `-8 + (-1) + 16 = 7`



* floatpoint
  * normalized: ``E = e - Bias``
  * denormalized : ``E = 1 - Bias``
  * infinity : `E = 0xff & M = 0`
  * NaN: `E = 0xff & M != 0`
  * float: ``(s)1 + (e)8 + (m)23``
  * double:``(s)1 + (e)11 + (m)52``
$$ X= (-1)^S*2^E*M$$     
$$ NormalizedbiasE = e - (2^{(k-1)}-1)$$
$$ DenomalbiasE = 1- (2^{(k-1)}-1)$$

8 bits float range
Bias: 2^3-1 = 7

Binary      | e   | E    | 2^E | M        | Decimal     |Special
:-----:     |:---:|:---: |:---:|:---:     |:-----:      |:-----:
[1 1111 000]|...  |...   |...  |...       |...          |negetive infinity
[1 0111 000]|7    |7-7=0 |2^0=1|1.0       |-512/512=1   |-1
...         |...  |...   |...  |...       |...          |
[1 0000 000]|0    |1-7=-6|1/64 |0.0       |0.0          |-0
[0 0000 000]|0    |1-7=-6|1/64 |0.0       |0.0          |+0
[0 0000 001]|0    |1-7=-6|1/64 |1/8       |1/512        |smallest denormalized
[0 0000 010]|0    |1-7=-6|1/64 |2/8       |2/512=1/256  |
...         |...  |...   |...  |...       |...          |
[0 0000 111]|0    |1-7=-6|1/64 |7/8       |7/512        |Largest denormalized
[0 0001 000]|1    |1-7=-6|1/64 |1.0=8/8   |8/512 =1/64  |smallest normalized
[0 0001 001]|1    |1-7=-6|1/64 |1.125=9/8 |9/512        |
...         |...  |...   |...  |...       |...          |
[0 0110 111]|6    |6-7=-1|1/2  |1.875=15/8|480/512=15/16|
[0 0111 000]|7    |7-7=0 |2^0=1|1.0       |512/512=1    |1
[0 0111 001]|7    |7-7   |1    |1.125=9/8 |9/8          |
...         |...  |...   |...  |...       |...          |
[0 1110 111]|14   |14-7=7|2^7  |15/8      |1920/8=240   |largest normalized
[0 1111 000]|...  |...   |...  |...       |...          |positive infinity
[0 1111 001]|...  |...   |...  |...       |...          |not a number  


* round
  * round to even    
  10.101 = 10.625 	&asymp; 10.62
  * round to zero    
  10.101 = 10.625   &asymp; 10.62
  * round down     
  10.101 = 10.625   &asymp; 10.62
  * round up     
  10.101 = 10.625   &asymp; 10.63
