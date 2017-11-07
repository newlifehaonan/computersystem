* Homework 5
  * 3.14
  * 3.16 (p && a > \*p)
  * 3.18 (nested if statement)
  * 3.20 (x OP 8, conditional move, divided operand round issue)
  * 3.21 (conditional move)
  * 3.23 (pointer in assembly)
  * 3.31 (switch and jump table)

* Array structure
  * basic structure
  1. base address(%rdx)
  2. index counter(%rcx)
  3. element size     
  `(base, index, size)`
  * pointer arithmetic     
  EX: suppose we have a array with element size 2 bytes, and want to store the value to %rax          

  | Expression     | assembly    |
  | :------------- | :------------- |
  | S+1       | leaq 2(%rdx),%rax       |
  | S[3]       | movw 6(%rdx),%ax       |
  | &S[i]       | leaq (%rdx,%rcx,2), %rax       |
  | S[4*i+1]       | movq 2(%rdx,%rcx,8),%ax       |
  | S+i-5       | leaq -10(%rdx,%rcx,2),%rax       |
  * two dimensional Array     
  `Int A[5][3]`:
  1. The array has 5 rows and 3 columns
  2. if you want the address of A[i][j], following the equation : `base + 4(3i+j)`
* procedure    
  `example: Procedure P calls Procedure Q`        
  * Procedure should contain address of Procedure Q
  * Before calling Q, P should pass one or more parameters to Q and Q must be able to return a value back to P
  * Q may need extra memory to hold local value, and it must be able to free the storage after return value.

* runtime stack
  * call Q, push %rsp at the top of stack to store the address in order to resume execution of P
  * function Q should store the return value in register %rax for P to use further.

* data transfer convention
  * Up to six integral parameter can be passed through register        
  `%rdi`,`%rsi`,`rdx`,`rcx`,`r8`,`r9`
  * argument more than 6 will be passed on stack      
  `8(%rsp)`,`16(%rsp)`...

* local storage on stack
  * passing argument to function: using stack
  ```
  P:
    sub $32, %rsp
    movq $1, 24(%rsp)
    movq $2, 16(%rsp)
    movq $3, 8(%rsp)
    movq $4, (%rsp)
    leaq 24(%rsp), %rdi
    leaq 16(%rsp), %rsi
    leaq 8(%rsp), %rdx
    leaq (%rsp), %rcx
    movq $1, %r8
    movq $2, %r9
    movq $3, 8(%rsp)
    call Q;
  ```
* local storage on register
  * callee register      
  `%rbx`,`%rbp`,`%r12~%r15`
  * preserve argument and save result
  ```
  P:
    pushq %rbx
    pushq %rbp
    ...
    ...
    Call Q
    Call Q
    ...
    popq %rbp
    popq %rbx
  ```
