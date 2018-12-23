bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    S db "+42a84XS"
    len equ($-S)
    cifra db "0123456789",0
    D db "",0
    lenD dd 0
; our code starts here
segment code use32 class=code
    start:
        ;Se da un sir de caractere S. Sa se construiasca sirul D care sa contina toate caracterele cifre din sirul S. 
        mov ebx,0           ;ebx=0 parcurgem s
        mov ecx,len         ;ecx=len
        cmp ecx,0
        je final            ;sare la final daca ecx=0
        pool:              ;cuz why not
        mov eax, 0
        mov al,[S+ebx] ; in al avem car curent din s
        push ecx        ; punem deasupra stivei pentru a conserva
        push ebx
        mov ecx, 10 ;
        mov ebx, 0
            pool2:     ;compara caracterul din primul sir cu fiecare dintre car din al doilea si verifica daca este cifra
            cmp al,[cifra+ebx]
            je cif
            inc ebx
            loop pool2
        jmp over
        cif:
        mov ebx, [lenD]
        mov [D+ebx],al
        
        over:
        pop ebx   ;scoatem de pe stiva pentru a reveni la valoarea initiala
        pop ecx
        add ebx,1
        loop pool ;repeta pana se termina sirul
        final:
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
