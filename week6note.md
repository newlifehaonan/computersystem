* 3.9 p195
generate assembly code of the following c code      
%rdi holds x , %rsi holds n
```
long shift_left4_rightn(long x, long y){
  x<< =4;
  x>>=n;
  return x;
}
```

shift instructor only allowed 32bits datatype     

```
shift_left4_rightn:
  movq %rdi, %rax;
  salq $4, %rax;
  movl %esi, %ecx; //that's the reason why we don't use movq//
  sarq %cl %rax;
```

* 3.10


* flag register       
  `ZF`: Zero flag (a==b)     
  `OF`: Overflow flag (used to test unsigned overflow)     
  `SF`: Sign flag (negative)     
  `CF`: Carry flag (used to test signed overflow)      
* cmp operand       
  Use to compare A and B : `cmp A, B` means B-A
* test operand      
  Use to text whether A is zero :`text %rax, %rax` means %rax & %rax if rax == 0 then return 0 others return 1

| operand     | Base    | description
| :------------- | :------------- |:-------:
| cmpb A, B     |   B-A    | compare byte
| cmpw A, B     | B-A      | compare word
| cmpl A, B     | B-A      | compare double words
| cmpq A, B     | B-A      | compare quad words
| testb A,A     | A & A    | compare byte
| ....          |....      |.....

* set operand
  * isEqual ? isNegative ?     
  `sete` : if a - b = 0 which means a==b, set `ZF `    
  `setne`: if a - b != 0 which means a != b, set ``~ZF``  
  `sets`: if a - b < 0 which mean a < b, set `SF`     
  `setns`: if a -b >0 which mean a > b, set `~SF`
  * compare

a - b = a + (-b)     
signed : max = 7 ; min = -8      
unsigned: max = 15; min = 0

|type|arithmatic| a | b    | -b|result | cf | zf |sf |of | compare
|:---|:--- |:------------- | :----|:------------- |:--- |:---|:----|:----|:----- |:-----
|signed|a+(-b)| 0 1 1 1       | 0 1 1 1  | 1 0 0 1 |(1) 0 0 0 0| 1 | 1 | 0 | 0 | a=b (7-7)
|signed|a+(-b)|0 1 0 1       | 0 0 1 0  | 1 1 1 0 |(1) 0 0 1 1| 1 | 0 | 0 | 0 | a > b (5-2)
|signed|a+(-b)| 0 0 1 0       | 0 1 0 1  | 1 0 1 1 | 1 1 0 1 |0 | 0 | 1 | 0 | a < b (2-5)
|signed|a+(-b)| 0 1 1 1       | 1 1 1 1  | 0 0 0 1 | 1 0 0 0 |0 | 0 | 1 | 1 | a > b (7-(-1))
|signed|a+(-b)| 1 0 0 0       | 0 0 0 1  | 1 1 1 1 | (1) 0 1 1 1 |1 | 0 | 0 | 1 | a < b (-8-1)
|- |-| -| -| -| -| -| -|- |- |-
|unsigned|a-b| 0 0 0 1     | 0 0 0 1  |---------| 0 0 0 0 |0 | 1 | 0 | 0 | a=b (1-1)
|unsigned|a-b| 0 0 1 0     | 0 0 0 1  | ------- | 0 0 0 1 |0 | 0 | 0 | 0 | a>b (2-1)
|unsigned|a-b| 1 1 1 1     | 0 0 0 1  | --------| 1 1 1 0 |0 | 0 | 1 | 0 | a>b (15-1)
|unsigned|a-b| 1 1 1 0     | 1 1 1 1  |---------| 1 1 1 1 |1 | 0 | 1 | 1 | a<b (14-15)

**<center>from above table we can find the rule of comparable operand</center>**

for signed number:      
`setl` : `sf^of`       
`setle`: `sf^of | zf`       
`setge`: `~(sf^of)`       
`setg` : `~(sf^of)&(~zf)`       
for unsigned number     
`setb`: `cf`     
`setbe`: `cf |zf`    
`seta`: ``~cf & ~zf``    
`setae`: `~cf`     

* jump operand      
jump to a different address for the next instruction to be execute !       
  * jump Lable       
  direct jump: `jump L1`;      
  indirect jump: `jump \*%rax`;      
  * conditional jump
  conditional jump can only be direct !      
  `jump label`: jump unconditionally       
  `je`: jump when equal      
  `jne`: jump when not equal      
  `js`: jump when negative      
  `jns`: jump when nonegative     
  `jg` : jump when greater      
  `jge`: jump when greater and equal       
  `jl` : jump when lower       
  `jle`: jump when lower and equal       
  `jb` : jump when below     
  `jbe`: jump when below and equal      
  `ja` : jump when above     
  `jae`: jump when above and equal     
