* Assembly code
  * repressentation
    * constant `$0X12345678`
    * Register `%rax` `%eax` `%ax` `%al`
    * memory address `(%rax) the` : memory that the ragister pointed to
    * inside the paranthsis should always be %r__ cause we use 64bits   system today!!
  * data transfer
    * Move from register to register     
      ``movq %rax %rbs``
    * Move from register to memory      
      `movq %rax (%rdx)`
    * move from memory to register      
      `movq (%rax) %rdx`
    * Move a constant to memory     
      `movq $0x5566 (%rdx)`
    * Move a constant to register      
      `movq $0x8899 (%rax)`
  * change value of register file
    * `movabsq $0x0011223344556677 %rax`    
      %rax 0x0011223344556677     
      `movb $-1 %al`     
      %rax 0x00112233445566ff
      `movw $-1 %ax`     
      %rax 0x001122334455ffff      
      `movl $-1 %eax`
      %rax ox00000000ffffffff
      `movq $-1 %rax`
      %rax oxffffffffffffffff
    * zero out higher bits      
      `movzbw`     
      `movzbl`     
      `movzbq`       
      `movzwl`      
      `movzwq`     
      `movzwl`       
      `movzlq` == `movq %eax %rax`
    * sign out higher bits     
      `movsbw`     
      `movsbl`     
      `movsbq`       
      `movswl`      
      `movswq`     
      `movswl`       
      `movslq` == `cltq`
  * Princple of moving data
    * momory address should be your system register word size
      `movb $0xF (%eax)`
    * Can't move from memory to memory       
      `movb (%rax) (%rbx)`
    * operand should match the word size of register file     
      `movw %eax %rbx`
    * name of register file should be legal      
      `movb %sl %rax`
    * can't move to a constant      
      `movb %al $0x123456`
    * can't move from large register to small register      
      `movw %ax %al`
  *
