bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,printf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import scanf msvcrt.dll
import printf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; a,b-byte; c-word; e-doubleword; x-qword
    
    ;;s1 db '+', '4', '2', 'a', '8', '4', 'X', '5'
    ;;l1 equ ($-s1)
    ;;s2 db 'a', '4', '5'
    ;;l2 equ ($-s2)
    ;;d times (l1+l2+1) db 0
    
    s1 dd 12345678h, 1256ABCDh, 12AB4344h
    len equ ($-s1-4)
; our code starts here
segment code use32 class=code
; prob 2 de le lab 7
    start:
        ; 
        
        mov eax,0
        mov ebx,0
        mov ecx,0
        mov edx,0
        cmp ecx,len
        je final
        loop1:
                mov ebx,[s1+ecx]    ;numarul complet care trebuie aranjat
                mov edi,ebx             ;edi=max
                mov esi,ecx
                mov edx,4           ; contor pentru j
                add edx,ecx
                cmp edx,len
                je here
                loop2:      ; in ebx- primul v[i] in eax - al doilea v[j], ecx=i edx=j esi=poz
                        mov eax,[s1+edx]
                        cmp eax,edi
                        jg here1
                        jmp end1
                        here1:
                        mov edi,eax
                        mov esi,edx
                        
                        
                        
                        end1:
                        add edx,4
                        cmp edx,len
                        je here
                
                
                here:
                cmp edx,ecx
                jne here2
                jmp end2
                here2:
                push di
                push eax
                mov eax,[s1+esi]
                mov edx,0
                mov di,ax
                mov ax,bx
                mov bx,di
                mov [s1+esi],eax
                mov [s1+edx],ebx
                pop eax
                pop edi
                end2:
                add ecx,4
                cmp ecx,len
                je final
        
        
        
        
        
        
        final:
        push dword s1
        call [printf]
        add esp,4
        ;;mov eax,0
        ;;mov ebx,0
        ;;mov ecx,0
        ;;mov edx,0
        ;;mov eax,l1
        ;;cmp eax,0
        ;;je do
        ;;mov ebx,0
        ;;loop1:
        ;;    mov eax,0
        ;;    mov al,[s1+ebx]
        ;;    add ebx,1
        ;;    cmp ebx,l1
        ;;    jge do
        ;;    mov [d+ecx],al
        ;;    add ecx,1
        ;;    add ebx,2
        ;;    cmp ebx,l1
        ;;    jge do
        ;;    jmp loop1
        ;;
        ;;do:
        ;;mov eax,l2
        ;;cmp eax,0
        ;;je final
        ;;mov ebx,l2
        ;;loop2:
        ;;    mov eax,0
        ;;    sub ebx,1
        ;;    cmp ebx,-1
        ;;    je final
        ;;    mov al,[s2+ebx]
        ;;    je final
        ;;    mov [d+ecx],al
        ;;    add ecx,1
        ;;    jmp loop2
        ;;
        ;;final:
        ;;push dword d
        ;;call [printf]
        ;;add esp,4
        
        
        ;mov ebx,0
        ;mov eax,0
        ;mov ax,0101100110010000b
        ;mov bx,0101010010011100b
        ;mov cl,11
        ;shr ax,cl
        ;and ax,0000000000001111b
        ;
        ;mov cl,1
        ;shr bx,cl
        ;and ax,0000000000111111b
        ;mov edx,11111111111111110000000000111000b
        ;mov cl,6
        ;ror edx,cl
        ;or edx,ebx
        ;mov cl,4
        ;ror edx,cl
        ;or edx,eax
        ;mov cl,10
        ;rol edx,cl
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
