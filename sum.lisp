(! sum '(
	  main
	  (irmovl stack %esp);
	  (irmovl stack %ebp);
	  (irmovl ele1 %ecx);
	  (pushl %ecx)
	  (call sum_list);
	  (popl %ecx);
	  (halt);
	  
	  sum_list
	  (pushl %ebp);
	  (rrmovl %esp %ebp);
	  (mrmovl 8(%ebp) %ecx);
	  (irmovl 0 %eax);
	  
	  loop
	  (andl %ecx %ecx);
	  (je end);
	  (mrmovl 0(%ecx) %esi);
	  (addl %esi %eax);
	  (mrmovl 4(%ecx) %ecx);
	  (jmp loop);
	  
	  end
	  (rrmovl %ebp %esp);
	  (popl %ebp);
	  (ret);
	  
	  ;Sample linked list
	  (align 4);
	  ele1;
	  (dword 7);
	  (dword ele2);
	  ele2;
	  (dword 12);
	  (dword ele3);
	  ele3;
	  (dword 17);
	  (dword 0);
	  end  
	  
	  (pos 8192)
	  stack
))

(y86-prog (@ sum))               ; Code OK?
(! location 0)
(! symbol-table
   (hons-shrink-alist
    (y86-symbol-table (@ sum)    ; The sum-1-to-n program
                      (@ location)    ; Beginning program location
                      'symbol-table)  ; Name of this symbol table
    'shrunk-symbol-table))            ; Name of reversed, compressed symbol table

; The function Y86-ASM assembles a program into a memory image.  Note,
; that the assembler requires the SYMBOL-TABLE as an argument.  Our
; Y86-ASM assembler does indeed assemble a program in one pass after
; being given a symbol table (the first pass).  Thus, our assembler is
; a two-pass assembler.

(! init-mem
   (hons-shrink-alist
    (y86-asm (@ sum)      ; The same, sum-1-to-n program
             (@ location)      ; Same beginning program location
             (@ symbol-table)  ; The contents of our symbol table
             'sum-1-to-n)      ; Name of the assembler output
    'shrunk-sum-1-to-n))       ; Name of reversed, compressed assembler output

; Now, what happens if we were to change the initial location from
; what its value was for the first pass?  Interesting problem.  Could
; this be done to relocate a program?  Or, do we just create a mess?
; You may wish to see a part of this file (below) that starts with
; "Debugging Aids:"


; Up to this point, we have only been concerned with creating an
; appropriate memory image.  But, our Y86 processor has internal
; registers.  We need to initialize the entire Y86 state, or at least
; the part we are going to use.  Since, we want to execute our
; program, we definitely need to initialize the program counter.  In
; fact, we generally choose to initialize all of the registers.  Note,
; if we want to initialize a specific register, we will need to name
; it and provide an initial value.

(! init-pc 0)
(! y86-status nil)   ; Initial value for the Y86 status register

; If we supply a NIL as the initial value for the registers or the
; flags, then our y86-state-builder function (INIT-Y86-STATE), will
; initialize such values to zero.

(init-y86-state
 (@ y86-status)  ; Y86 status
 (@ init-pc)     ; Initial program counter
 nil             ; Initial registers, if NIL, then registers set to zero
 nil             ; Initial flags, if NIL, then flags set zero
 (@ init-mem)    ; Initialize memory with the assembler output
 x86-32          ; Name for the entire Y86 processor state
 )

; Once we have initialized the Y86 state, we are ready to execute.

(y86 x86-32 100)                 ; Step ISA 100 steps or to HALT
(m32-get-regs-and-flags x86-32)  ; Show the registers
