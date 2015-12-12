; The core program(program except for bootsect, setup) is moved to 0x00000 from 0x10000 by the setup.
; The location(0x00000) was originally for ISR, BIOS data. so this process remove the data.
; after that, OS cannot work with a interrupt, so interrupt was deactivated beforhand.
do_move:
mov     es,ax
add     ax,#0x1000
cmp     ax,#0x9000
jz      end_move
mov     ds,ax
sub     di,di
sub     si,si
mov     cx,#0x8000
rep
movsw
jmp     do_move
