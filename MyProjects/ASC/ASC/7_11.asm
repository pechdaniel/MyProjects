bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fclose,scanf,fprintf,printf             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fopen msvcrt.dll
import fclose msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import printf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_name db 'file1.txt',0
    mod_acces db 'w',0
    leg dd 0
    format db '%s',0
    format1 db '%c',0
    chr db 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        mov eax,0
        mov ebx,0
        mov ecx,0
        mov edx,0
        mov edx,'$'      ;dl=$
        mov es,[dx]
        push dword mod_acces
        push dword file_name
        call [fopen]
        add esp,4*2
        mov [leg],eax
        cmp eax,0
        je final
        loop1:
        
                
                push dword chr
                push dword format
                call [scanf]
                add esp,4*2
                mov ebx,0
                mov ebx,chr
                mov esi,'$'
                cmp ebx,esi
                je final
                
                
                
                
                push dword ebx
                push dword [leg]
                call [fprintf]
                add esp,4*2
                jmp loop1
                
        final:
        push dword [leg]
        call [fclose]
        add esp,4*2
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
