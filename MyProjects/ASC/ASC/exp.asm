bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start   ,yes     

; declare external functions needed by our program
extern exit              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern eticheta
; our data is declared here (the variables needed by our program)
segment data use32 class=data public
    ; ...
    ;
    a db 0Ah,0,1,2,3,4,5,6,7,8,9,7,0xB
    b db "jambon"
; our code starts here
segment code use32 class=code public
    start:
        ; ...
        ;cmovc
        ;setc ceva
        ;mov eax,1
        ;mov ebx,a
        ;mov al,9
        ;ds xlat
        ;xchg eax,[a]
        ;pusha
        call eticheta
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
