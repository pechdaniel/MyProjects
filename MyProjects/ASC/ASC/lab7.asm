bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf               ; tell nasm that exit exists even if we won't be defining it
import printf msvcrt.dll
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    s db "Ana are mere"
    len equ ($-s)
    format db "%c ",0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov ecx,len
        cmp ecx,0
        je final
        mov eax,0
        mov esi,0
        bucla:
        mov al,[s+esi]
        push dword ecx
        push dword eax
        push dword format
        call [printf]
        add esp,4*2
        pop dword ecx
        inc esi
        loop bucla
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
