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
        ; Dandu-se un sir de octeti si un subsir al sau, sa se elimine din primul sir toate aparitiile subsirului.
        mov edi,b
        mov edx,0   ;contor pentru sirul b
        mov eax,0
        mov ecx,lenA
        mov esi, a
        mov ebx, c ;contor ptr sirul c
        jecxz final
        pool:
        mov edx,[b] ;prima valoare din b
        pool1:
            lodsb ; in al valoarea curenta din a
            cmp eax, edx    ;
            jne skip    ;sare peste loop daca caracterul din a nu este egal cu primul caracter din b
            push esi    ;pune esi pe stiva
            push ecx    ;pune ecx pe stiva
            add esi,1   ;trece la caracterul urmator din a
            ;mov edi,0   ;contor pentru elementele din b
            inc edi
            cmp edi,[lenB]
                    pool2:  ;verivica daca toate caracterele din b apar in a
                        dec ecx
                        cmp ecx,0
                        je skip
                        cmp esi,edx
                        jne here    ;daca nu sunt egale caracterele sare la here, altfel repeta pana se termina sirul b 
                        inc edi
                        cmp edi,[lenB]
                        je pool2    ;repeta de lenB ori
            pop esi
            pop ecx
            add esi,[lenB]
            loop pool
            here:   ;se intoarce cu edi ori inapoi pentru a pune caracterele in c
            pop esi
            pop ecx
            push eax
            mov eax,0
            mov eax,[lenB]
            sub eax,edi
            mov edi,eax
            pop eax
                pool3:
                    mov [ebx],esi
                    inc ebx
                    inc esi
                    dec edi
                    cmp edi,0
                    jne pool3
            dec ecx
            jmp pool
            skip:
            mov [ebx], eax
            inc ebx
        loop pool1
        cmp ecx,0
        loop pool
        
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
