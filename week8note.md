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
  Step to understand procedure.

  * Control transfer

  1. `call P()`: push return address of function P(). register `%rsp` point to the address of next instruction.

  2. `ret`: pop the return address and execute.
  * Data transfer

  1. Passing argument to the function being called.      

     **if:argument less or equals than 6**   

     save them to `rdi`,`rsi`,`rdx`,`rcx`,`r8`,`r9`

     **if:argument greater than 6**

     create extra space on runtime stack by doing move to `8(%rsp)`,`16(%rsp)` ....(each address occupied 64bits)

  * Local variable on stack
  1. By doing `sub $32, %rsp` to create enough space to hold local variable of the function

  2. before return the result, deallocate the stack frame by doing `add $32, %rsp`

  * Local storage on register     
  What if the callee function use the same argument as in the caller function?
  1. by `push` `%rbx`,`%rbp`,`%r12`,`%r13`,`%r14`,`%r15` onto the stack to preserve the value of caller's argument while passing new value to the callee function.

  2. if it's not enough, create space on stack to hold the value.

  3. after callee function done use the register, restore them by doing `pop %register`.

* recursion function       
  * recursion function implicitly create a runtime stack. at each step of recursion, system push a stack frame on the main function frame.

  * when the recursion hit the base case, it return the value back to the previous recursion function while erase it's stack frame.
  
