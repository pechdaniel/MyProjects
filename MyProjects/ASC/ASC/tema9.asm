bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fopen,fclose,fread,printf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file db 'lol.txt',0
    acces db 'r',0
    nobine dd 0
    consoane db 'bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ',0    ;42
    format db '%d',0
    len equ 1
    chr resb len
        db 0
; our code starts here
segment code use32 class=code
    start:
        ; Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de consoane si sa se afiseze ;aceasta valoare. 
        ;Numele fisierului text este definit in segmentul de date. Problema este ca nu imi modifica bine valoarea din ecx!
        mov ecx,0   ;contor pentru cate caractere consoane sunt
        mov edx,0   ;contor pentru elementele din chr
        push dword acces
        push dword file
        call [fopen]
        add esp,4*2
        cmp eax,0
        je final1
        mov [nobine],eax
        execute:
        ;fread(chr,1,len,nobine)
        push ecx
        push dword [nobine]
        push dword len
        push dword 1
        push dword chr
        call [fread]
        add esp,4*4
        pop ecx
        ;eax=nr de caractere citite
        ;fclose(nobine)
        cmp eax,0
        je final
       
        ;mov eax,0
        mov dl,[chr]
        
        mov edi,0
        mov ebx,0
        mov edi,consoane
        mov esi,0
        verifica:
                ;cat timp poate citi din sir verifica daca este egal cu caract
                cmp esi,42
                je execute
                mov bl,[consoane +esi]
                cmp bl,dl
                je do
                inc esi
                jmp verifica
        ;consoane:   ;verific daca caracterul apare printre sirul de vocale si alte caractere
        ;cmp edi,11
        ;je do
        ;mov esi,[ebx+edi]
        ;cmp esi,edx
        ;je execute
        ;inc edi
        ;jmp consoane
        
        do:
           inc ecx  ; daca apare trec la urmatorul caracter din fisier
        jmp execute
        final:
        push ecx
        push dword [nobine]
        call [fclose]
        add esp,4
        pop ecx
        final1:
        push dword ecx  ; afisez numarul de consoane
        push dword format
        call[printf]
        add esp,4*2
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
