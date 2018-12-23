%ifndef modul11
%define modul11
modul:
        mov al,[a+edi-1]
        mov dl,[b+esi-1]
        cmp al,dl
        je continue
        jne dont
        continue:
                 dec edi
                 dec esi
                 cmp edi,0
                 ret 8
                 cmp esi,0
                 ret 8
                 mov [z+edi+2+m],al
                 inc ecx
                 jmp modul
%endif