; Setup for loading with grub.
; Call the main kernel program

bits 32
section .text
        align 4
        dd 0x1BADB002              	; Grub boot magic number
        dd 0x00                    	; Boot flags
        dd - (0x1BADB002)	   	; Checksum

global main
extern kernel_main			; The main function that we will run

main:
	cli
	mov esp, stack_space		; Init stack pointer
	call kernel_main		; Call the kernel
	hlt 				; Shutdown computer

section .bss				; Create space for the stack
resb 8192				; Give 8KB to stack
stack_space:
