* arithmetic operand

| instruction   | effect     |description
| :-------------: | :-------------: | :---------:
| Leaq  S,D    | &S(address) --->D       |load effective address
| addq  S,D    | S + D --> D  | add source to destination
| subq  S,D    | D - S --> D  | substract source from destination
| imulq S,D    | D*S--> D     | mutiple destination by source
| xor S,D      | D ^ S --> D  | destination exclusive-or source
| or S,D       | D | S --> D  | destination or source
| and S,D      | D & S --> D  | destination and source
| incq D       | D +1 -->D    | destination plus 1
| decq D       | D -1 -->D    | destination minus 1
| neg D        | -D--> D      | destination negate itself
| not D        | ~D--> D      | destination complement itself
| sal k,D      | D << k --->D | destination arithmetic left Shift k
| shl k,D      | D << k --->D | destination Logic left Shift k
| sar k,D      | D >> k --->D | destination arithmetic right  Shift k
| shr k,D      | D >> k --->D | destination logic right Shift k

* 3.1 p138 p325

address | value |register | value
:---: | :---: | :----:|:----:
0x100 |0xFF |%rax |0x100
0x104 |0xAB |%rcx |0x1
0x108 |0x13 |%rdx |0x3
0x10C |0x11

`%rax`: 0x100          
`0x104` : 0xAB         
``$0x108``: $0x108         
``(%rax)``: 0xFF        
`4(%rax)`: (0x100 + 4)=(0x104)=0xAB        
`9(%rax,%rdx)`: (0x100+0x3+9)=(0x10C)=0x11       
`260(%rcx,%rdx)`=(0x1+0x3+00x104)=(0x108)=0x13      
`0xFC(,%rcx,4)`=(4*0x1+0xFC)=(0x100)=0xFF        
`(%rax,%rdx,4)`=(0x100+4*0x3)=(0x10C)=0x11        

* 3.2 p185 p325

`mov_` %eax,(%rsp) : l       
`mov_` (%rax),%dx :w       
`mov_` $0xFF, %b1 :b       
`mov_` (%rsp,%rdx,4), %dl :b       
`mov_` (%rdx),%rax : q       
`mov_` %dx,(%rax):w       

* 3.3 p186 p326
1. movb $0xF,(%ebx)     
memory datasize is not enough     
2. movl %rax,(%rsp)     
l should be q
3. movw (%rax),4(%rsp)      
can't move from memory to memory     
4. movb %al,%sl      
no sl register    
5. movq %rax,$0x123     
can't move to a constant     
6. movl %eax,%dx       
can't move larger to smaller register     
7. movb %si,8(%rbp)       
b should be w       

* 3.4 p187 p326     
move from memory from temp register first,move temp into des memory second.        
destination (%rsi)     
source (%rdi)
1. move long to long      
movq (%rdi), %rax      
movq %rax, (%rsi)     
2. move char to int       
movsbl (%rdi),%eax      
movl %eax,(%rsi)     
3. move char to unsigned      
movsbl (%rdi),%eax       
movl %eax,(%rsi)      
4. move unsigned char to long          
movzbq (%rdi),%rax     
movq %rax,(%rsi)       
5. move int to char        
movl (%rdi), %eax      
movb %al,(%rsi)         
6. move unsigned to unsigned char
movl (%rdi),%eax      
movb %al,(%rsi)         
7. move char to short         
movsbw (%rdi) %ax        
movw %ax,(%rsi)         

* 3.5 p189 p327  
API `decode(long *xp, long *yp,long * zp)`
xp in %rdi, yp in %rsi, zp in %rdx;   
tranlate following assembly code to c code        
```assembly
decode1:
  movq (%rdi), %r8
  movq (%rsi), %rcx
  movq (%rdx), %rax
  movq %r8, (%rsi)
  movq %rcx,(%rdx)
  movq %rax,(%rdi)
  ret
```
```
void decode(long *xp,long *yp, long *zp){
  long X = *xp ;
  long Y = *yp ;
  long Z = *zp ;
  *yp = X;
  *zp = y;
  *xp = Z;
}
```

* 3.6 p192 p328      
tranlate code into math formular        
%rax holds value x, %rcx holds value y         
`leaq 6(%rax),%rdx`: x + 6        
`leaq (%rax,%rcx),%rdx`: x + y      
`leaq (%rax,%rcx,4)`: x + 4 * y       
`leaq 7*(%rax,%rax,8),%rdx`: 7 + 9*x       
`leaq 0xA(,%rcx,4),%rdx`: 10 + 4y      
`leaq 9(%rax,%rcx,2),%rdx`: 9 + x + 2y  

* 3.7 p193 p328       
%rdi holds x, %rsi holds y ,%rdx holds z     
what does the following code return         
```
scale2:
  leaq (%rdi,%rdi,4),%rax
  leaq (%rax,%rsi,2),%rax
  leaq (%rax,%rdx,8),%rax
```
x + 4x -->5*x +2*y --> (5x+2y)+8y       

* 3.8 p194 p328

address | value |register | value
:---: | :---: | :----:|:----:
0x100 |0xFF |%rax |0x100
0x108 |0xAB |%rcx |0x1
0x110 |0x13 |%rdx |0x3
0x118 |0x11     

`addq %rcx,(%rax)` : (%rax) = 0x1 + 0xFF = 0x100       
`subq %rdx,8(%rax)`: 0x108 = 0xAB + 0x3 =0xA8         
`imulq $16,(%rax,%rdx,8)`: 0x118 = 16 * 0x11 =0x110          
`incq 16(%rax)`: 0x110 = 0x14       
`decq %rcx`: %rcx = 0x1 -1 = 0x0       
`subq %rdx,%rax`:%rax = 0x100 - 0x3 =0xFD     

* 3.9 p195
