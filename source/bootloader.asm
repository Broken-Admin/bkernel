bits 32 ;; 32 bit mode
section .text
        align 4
        dd 0x1BADB002            ;bootloader signifier
        dd 0x00                  ;flags
        dd - (0x1BADB002 + 0x00) ;checksum

global start
extern kmain

start:
  cli ; disable interrupts
  mov esp, stack_space ; set stack pointer
  call kmain ; call main kernel function
  hlt ; disable CPU after kernel exit

section .bss
resb 8192 ; reserve 8KB for stack space
stack_space: