bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a db "fagbd214fagbd324kfsjbf"
    lenA equ ($-a)
    b db "fagbd"
    lenB equ ($-b) 
    c times lenA db 0
    lenC db 0
; our code starts here
segment code use32 class=code
    start:
        ;Dandu-se un sir de octeti si un subsir al sau, sa se elimine din primul sir toate aparitiile subsirului.
        mov ecx,b       ;contor pentru sirul b
        mov edx,0
        mov ebx,[b]     ;ebx=prima valoare din sirul b
        mov esi,c       ;esi=contor pentru sirul c
        mov eax,lenA
        cmp eax,0
        je final
        mov eax,a       ;eax e contor pentru sirul a
        loopu:
        cmp ebx,[eax]
        jne puneinc
        mov ecx,0
        inc eax
        push eax        ;retin pe stiva eax
        repeta:
                push edx
                mov edx,0
                mov edx,[eax]
                cmp edx,[ecx]
                pop edx
                jne termina
                inc eax
                inc ecx
                cmp byte [ecx],lenB
                je loopu
                push edx
                mov edx,0
                mov edx,eax
                sub edx,a
                cmp byte [edx],lenA  
                pop edx
                je final
        
                
        termina:
                mov ecx,0
                pop eax
                repetare:
                        push edx
                        mov edx,0
                        mov edx,[eax]   ;fac o smecherie
                        mov [esi],edx
                        pop edx
                        inc eax         ;cresc contorii
                        inc esi
                        cmp byte [ecx],lenB
                        jne repetare
                        
                push edx
                mov edx,0
                mov edx,eax
                sub edx,a
                cmp byte [edx],lenA  
                pop edx
                jne loopu
                jmp final
        
        puneinc:    ;pun in c valoarea de la adresa din eax
                push edx
                mov edx,0
                mov edx,[eax]   ;fac o smecherie
                mov [esi],edx
                pop edx
                inc eax         ;cresc contorii
                inc esi
        
        mov edx,0
        mov edx,eax
        sub edx,a
        cmp byte [edx],lenA
        jne loopu
        
        
        
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
