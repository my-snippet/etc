;; 1.3.1 Deactivate interrupt, Move system module 0x00000
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


;;1.3.3 Activate A20 gate & 32 bit address
; It extends the address upto 4GB
; CPU has 1MB space from 0x00000 to 0xFFFFF in real mode.
; At this time, only 20 pin(CPU address pin) is needed for addressing.
; However, If A20 gate is activated, CPU will use 32 bit address.
call    empty_8042
mov     a1,0xD1         ! write
out     #0x64,a1
call    empty_8042
mov     a1,0xDF         ! A20 activation
out     #0x60,a1
call    empty_8042
