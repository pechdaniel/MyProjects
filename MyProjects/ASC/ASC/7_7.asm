bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,printf,fopen,fclose,fread               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
file db 'mine.txt',0
acces db 'r',0
leg dd 0
len equ 1
chr resb len
s1 times 26 db 0
s2 times 26 db 0
l1 db 0
format db '%c',0
format3 db '%c, ',0
format1 db '%c with %d',0
format2 db '%d ',0
format4 db '%s',0
s3 db 'what is love, I love God!!!!!!!!!!!!!!!!',0
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    
; our code starts here
segment code use32 class=code
    start:
        ;fread(chr,1,len,leg)
        mov eax,0
        mov ecx,0
        mov ebx,0                       ; lenght
        mov edx,0
        mov edi,0
        mov esi,0
        ;mov edx,s3
        ;push dword edx
        ;push dword format4
        ;call [printf]
        push dword acces
        push dword file
        call [fopen]
        add esp,4*2
        mov ebx,0
        mov [leg],eax
        cmp eax,0
        je final
        mov ebx,4
        
        push dword [leg]
                push dword len
                push dword 1
                push dword chr
                call [fread]
                add esp,4*4
                cmp eax,0
                je final
                mov ecx,0
                
                mov ecx,[chr]
                
                cmp ecx,'a'
                jl loop1
                cmp ecx,'z'
                jg loop1
                add ebx,1
                push ecx
                push dword format3
                call[printf]
                mov [s1],byte ecx
                mov ecx,1
                mov [s2],byte ecx
        
        loop1:
                push dword [leg]
                push dword len
                push dword 1
                push dword chr
                call [fread]
                add esp,4*4
                cmp eax,0
                je final
                mov ecx,0
                
                mov ecx,[chr]
                
                cmp ecx,'a'
                jl here1
                cmp ecx,'z'
                jg here2
                push ecx
                push dword format3
                call[printf]
                mov esi,0           ; contor pentru sir
                loop2:
                
                        cmp esi,ebx
                        jle mine
                        jg here1
                        
                        mine:
                        
                        mov ecx,[s1+esi]
                        
                        cmp ecx,[chr]
                        je case1
                        cmp esi,ebx
                        je  case2
                        jmp stop
                        case2:
                        
                        mov [s1+ebx],ecx
                        mov ecx,[s1+ebx]
                        
                        mov ecx,1
                        mov [s2+ebx],ecx
                        add ebx,1
                        jmp here1
                        
                        case1:
                        push esi
                        mov esi,[s2+ebx]
                        add esi,1
                        mov [s2+ebx],esi
                        pop esi
                        jmp here1
                        
                        stop:
                        add esi,1
                        jmp loop2
                        
                        
                
                here1:
                here2:
                jmp loop1
        final:
        push dword s1
        push dword format3
        call[printf]
        push dword [leg]
        call [fclose]
        add esp,4
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
