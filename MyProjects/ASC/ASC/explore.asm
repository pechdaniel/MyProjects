bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start ,eticheta       

; declare external functions needed by our program
extern exit   ,printf            ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a dw 0,1,2
    b dw $+a ; asa nu se poate
    c dw $+2; asa se poate, astea trebuie neaparat sa fie >= 16 octeti
    d dw $-a;asa se poate
    e dw $-2;asa se poate, astea trebuie neaparat sa fie >= 16 octeti
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        eticheta:
        ;mov eax,1
        ;mov ebx,3
        ;mov ecx,7
        ;ret
        ;std
        ;mov ecx,lol
        ;mov esi,string
        ;mov edi,yep
        ;add ecx,edi
        ;mov edi,ecx
        ;dec edi
        ;dec edi
        ;mov ecx,lol
        ;mov ebx,0
        ;jecxz final
        ;lop:
        ;lodsb
        ;std
        ;stosb
        ;cld
        ;loop lop
        ;; exit(0)
        ;final:
        ;push dword yep
        ;push dword format
        ;call[printf]
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
