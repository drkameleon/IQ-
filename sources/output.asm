%include "lib/asm_io.inc"

;==========================
;   Initialised Data
;==========================
segment .data

;==========================
;   Uninitialised Data
;==========================
segment .bss

		k resd 1		;	 Declare k as DOUBLE-WORD
		a resd 1		;	 Declare a as DOUBLE-WORD
		c resd 1		;	 Declare c as DOUBLE-WORD
;==========================
;   Main Program
;==========================
segment .text
	global asm_main

	asm_main:
		enter 0,0		;	setup routine
		pusha
		call proc_main
		popa
		mov eax, 0
		leave
		ret

	jmp after_end_int_getNum
	;===================================
	; FUNCTION getNum
	;
	; args : none
	;-----------------------------------
	_int_getNum:
		push ebp			;	Push ebp to stack
		mov ebp, esp		;	ebp = esp
		mov eax, 3		;	eax = 3
		push eax			;	Push eax to stack
		pop eax			;	Pop eax from stack
		mov dword[k], eax		;	dword[k] = eax
		push dword[k]			;	Push dword[k] to stack
		push 2			;	Push 2 to stack
		pop ebx			;	Pop ebx from stack
		pop eax			;	Pop eax from stack
		mul ebx			;	eax *= ebx
		push eax			;	Push eax to stack
		pop eax			;	Pop eax from stack
	end_int_getNum:
		pop ebp			;	Pop ebp from stack
		ret
	;-----------------------------------
	; END OF FUNCTION getNum
	;===================================
	after_end_int_getNum:
	jmp after_end_proc_printSum
	;===================================
	; PROCEDURE printSum
	;
	; args : none
	;-----------------------------------
	proc_printSum:
		push ebp			;	Push ebp to stack
		mov ebp, esp		;	ebp = esp
		mov eax, 2		;	eax = 2
		push eax			;	Push eax to stack
		pop eax			;	Pop eax from stack
		mov dword[a], eax		;	dword[a] = eax
		push 2			;	Push 2 to stack
		call _int_getNum		;	_int_getNum
		push eax			;	Push eax to stack
		pop ebx			;	Pop ebx from stack
		pop eax			;	Pop eax from stack
		add eax, ebx		;	eax += ebx
		push eax			;	Push eax to stack
		push dword[a]			;	Push dword[a] to stack
		pop ebx			;	Pop ebx from stack
		pop eax			;	Pop eax from stack
		mul ebx			;	eax *= ebx
		push eax			;	Push eax to stack
		pop eax			;	Pop eax from stack
		mov dword[c], eax		;	dword[c] = eax
		mov eax, dword[c]		;	eax = dword[c]
		push eax			;	Push eax to stack
		mov eax, 2		;	eax = 2
		push eax			;	Push eax to stack
		pop ebx			;	Pop ebx from stack
		pop eax			;	Pop eax from stack
		cmp eax, ebx		;	Compare eax, ebx
		jle 	if_block_end_1			;	If less equal, jump to 	if_block_end_1
	if_block_1:
		mov eax, [c]		;	eax = [c]
		call print_int		;	print_int
		call print_nl		;	print_nl
	if_block_end_1:
	end_proc_printSum:
		pop ebp			;	Pop ebp from stack
		ret
	;-----------------------------------
	; END OF PROCEDURE printSum
	;===================================
	after_end_proc_printSum:
	jmp after_end_proc_main
	;===================================
	; PROCEDURE main
	;
	; args : none
	;-----------------------------------
	proc_main:
		push ebp			;	Push ebp to stack
		mov ebp, esp		;	ebp = esp
		call proc_printSum		;	proc_printSum
	end_proc_main:
		pop ebp			;	Pop ebp from stack
		ret
	;-----------------------------------
	; END OF PROCEDURE main
	;===================================
	after_end_proc_main:

