(! rsum '(
	  main
	  (irmovl stack %esp);
	  (irmovl stack %ebp);
	  (irmovl ele1 %edi);
	  (pushl %edi);
	  (call sm);
	  (popl %edi);
	  (halt);
	  
	  sm
	  (pushl %ebp);
	  (rrmovl %esp %ebp);
	  (pushl %ebx);
	  (mrmovl 8(%ebp) %ecx);
	  (xorl %eax %eax);
	  (andl %ecx %ecx);	
	  (je end1);
	 
	  (mrmovl 0(%ecx) %ebx);
	  (mrmovl 4(%ecx) %ecx);
	  (pushl %ecx);
	  (call sm); 
	  (popl %ecx); 
	  (addl %ebx %eax);

	  end1
	  (popl %ebx);
	  (rrmovl %ebp %esp);
	  (popl %ebp);
	  (ret);  

	  ele1
	  (dword 7)
	  (dword ele2)
	  ele2
	  (dword 12)
	  (dword ele3)
	  ele3
	  (dword 17)
	  (dword 0)
	  end  
	  
	  (pos 8192)
	  stack
))

(y86-prog (@ rsum))               ; Code OK?                                           
(! location 0)
(! symbol-table
   (hons-shrink-alist
    (y86-symbol-table (@ rsum)    ; The sum-1-to-n program                              
                      (@ location)    ; Beginning program location                          
                      'symbol-table)  ; Name of this symbol table                           
    'shrunk-symbol-table))            ; Name of reversed, compressed symbol table   

(! init-mem
   (hons-shrink-alist
    (y86-asm (@ rsum)      ; The same, sum-1-to-n program                               
             (@ location)      ; Same beginning program location                            
             (@ symbol-table)  ; The contents of our symbol table                           
             'sum-ele1-to-elen)      ; Name of the assembler output                               
    'shrunk-sum-ele1-to-elen))       ; Name of reversed, compressed assembler output    

(! init-pc 0)
(! y86-status nil)   ; Initial value for the Y86 status register           

(init-y86-state
 (@ y86-status)  ; Y86 status                                                               
 (@ init-pc)     ; Initial program counter                                                  
 nil             ; Initial registers, if NIL, then registers set to zero                    
 nil             ; Initial flags, if NIL, then flags set zero                               
 (@ init-mem)    ; Initialize memory with the assembler output                              
 x86-32          ; Name for the entire Y86 processor state                                  
 )

(y86 x86-32 10000000)                 ; Step ISA 100 steps or to HALT                            
(m32-get-regs-and-flags x86-32)  ; Show the registers    
