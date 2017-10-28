* If & else  (unconditional move)   
  * general goto version of if else
  ```
  x = test_exp;
  if(!x)
    goto false
  then statement
  goto done
  false:
    else statement
  done:
  ```

C code
```c
lt_count = 0;
ge_count = 0;
long absdiff(long a, long b) {
  long result
  if (a > b){
    result = a - b;
    ge_count ++
  }
  else{
    result = b - a;
    lt_count ++
  }
  return result;
}
```

Goto version
```goto version
long absdiff(long a, long b){
  long result;
  if (a <=b)
    goto a_lt_b;
  ge_count ++
  result = a - b
a_lt_b:
  lt_count ++
  result = b-a;
}
```

assembly code     
a in %rdi, b in %rsi, ret %rax
```
absdiff:
  cmpq %rsi, %rdi
  jle .L2
  incq ge_count(rip)
  movq %rdi,%rax
  subq %rsi,%rax
  ret
.L2
  incq lt_count(%rip)
  movq %rsi,%rax
  subq %rdi,%rax
  ret
```

* v = x ? y : z ( conditional move)

C code
```c
long conditionalassign(long y, long z){
  long v;
  if(!x){
    v=z;
  }
  else{
    v=y;
  }
}
```

Goto Version
```
long v;
if(!x)
  goto false
v = y;
goto done
false:
  v=z;
done:
```

Example code of absdiff
x in %rdi, y in %rsi
```
absdiff:
  movq %rdi, %rax
  subq %rsi, %rax //x-y//
  movq %rsi, %rdx
  subq %rdi, %rdx //y-x//
  cmpq %rsi, %rdi //x<y//
  cmovle %rdx, %rax
  ret

```

* loops
  * do-while         
  general version of do-while
  ```
  loop:
    x= expression;
    t = text_exp
    if(t)
      goto loop;
  ```

  C Code       
  ```c
  //only works for n>0//
  long fact_do(long n){
    long result =1;
    do{
      result = result * n;
      n--;
    } while(n>1);
    return result;
  }
  ```

  Goto version
  ```
  long fact_do(long n){
    long result = 1;
  loop:
    result = result * n;
    n--;
    if(n>1)
      goto loop;
    return result;
  }
  ```

  Assembly code            
  n in %rdi          
  ```
  fact_do:
      moveq $1, %rax
    .Loop:
      imulq %rdi,%rax
      decq %rdi
      cmpq $1,%rdi
      jg .Loop
      ret;
  ```

  * while         
  general version of while
  ```
    goto test;
  .loop:
    body_statment;
  .test:
    t = text_exp
    if(t)
      goto loop;
  ```

  C code
  ```c
  //works for n = 0//
  long fact_while(long n){
    long result =1;
    while (n>1) {
      result = result * n;
      n--
    }
    return result;
  }
  ```

  goto version

  ```
  long fact_while(long n){
      long result =1;
      goto test
    loop:
      result = result * n;
      n--
    test:
      if(n>1)
        goto loop
      return result
  ```

  assembly code
  n in %rdi
  ```
  fact_while:
      movq $1 %rax
      jmp .test
    .Loop:
      imulq %rdi, %rax
      decq %rdi
    .test:
      cmpq $1, %rdi
      jg .Loop
      ret;
  ```
  * for(initial; test; update) loop         
  general version for for loop

  ```
    initial
    goto test
  .loop
    body_statement
    update
  .test
    t = test-expre
    if(t)
      goto loop
  ```

  C code
  ```c
  long fact_for(long n){
    long i =2;
    long result = 1;
    for(i = 2; i<=n; i++){
      result = result * i;
    }
      return result;
  }
  ```

  goto version         
  ```
  long fact_for(long n){
      long i =2;
      long result = 1;
      goto test
    .loop
      result = result * i
      i ++ ;
    .test:
      if(i<=n)
      goto loop
      ret
  }
  ```

  assembly code         
  i in %rdi        
  ```
  fact_for:
      movq $1, %rax
      movq $2, %rdx
      goto test:
    .loop
      imulq %rdx,%rax
      incq %rdx
    .test:
      cmpq %rdi,%rdx
      jle .loop
      ret
  ```

* switch statement       
  use jump table in C

  c code
  ```c
  long switch_ex(long x, long n, long *des){
    long val = x;
    switch(n){
      case 100:
        val * =13;
        break;
      case 102:
        val +=10;
      case 103:
        val +=11;
      case 104:
      case 106:
        val * = val;
        break
      defaul:
        val =0;  
    }
    \*des = val;
  }
  ```

  goto version
  ```
  long switch_ex(long x, long n, long *des){
    long val ;
    index = n - 100;

    static void \*jt[7] = {.L0,.L_default,.L_2,.L_3,.L4,.L_default,.L_4};

    if(index > 6)
      goto .L_default
    goto \*jt[idex]

    .L_default:
      val = 0;
    .L_0:
      val = x * 13
      goto done;
    .L_2:
      x = x + 10;
    .L_3:
      val = x + 11;
    .L_4:
      val = x * x;
      goto done;
    done:
      *des = val;
  }
  ```

  assembly code
  x in %rdi, n in %rsi, dest in %rdx
  ```
  switch_ex:
    .L4:
      .quard .L0  //.quard is address, which occupies 8 bytes//
      .quard .Ldefault  //L4 +8//
      .quard .L2  //L4 +16//
      .quard .L3  //L4 +24//
      .quard .L4  //...//
      .quard .Ldefault
      .quard .L4

      subq $100, %rsi
      cmpq $6, %rsi
      jg .Ldefault
      jmp *L4(,%rsi,8)
    .Ldefault:
      movq $0, %rdi
      jmp .LR
    .LR:
      movq %rdi, (%rdx)
      ret
    .L0:
      imulq $13, %rdi
      jp .LR
    .L2:
      addq $10, %rdi
    .L3:
      addq $11, %rdi
      jmp .LR
    .L4:
      imulq %rdi, %rdi
      jmp .LR    
  ```
