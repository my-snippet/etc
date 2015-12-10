; 3. Load the Setup program to the memory

; INT 0x13h
; 1. INT 0x13h ISR loads the setup program.
; 2. Bootsect(a part of OS) executes INT 0x13h
; 3. INT 0x13h can loads a specific sector to the specific location(Anywhere).
; (That is, When this is called, 1) a necessary sector, 2) memory location should be passed with it

; INT 0x19h
; 1. Unlike INT 0x13h,
; 2. BIOS executes INT 0x19h service handler.
; 3. INT 0x19h ISR loads the first sector of the floppy disk to 0x7C00(fixed)
 
; * These mean INT 0x13h

load_setup:
        mov dx,#0x0000
        mov cx,#0x0002
        mov bx,#0x0200
        mov ax,#0x0200+SETUPLEN
        int 0x13
        jnc ok_load_setup
        mov dx,#0x0000
        mov ax,#0x0000
        int 0x13
        j   load_setup
        ok_load_setup:

; The following instruction change the execution address to 0x90200
; This address is that the setup address exists.
; That is, setup program will be executed after the bootsect process.
Jumpi 0, SETUPSEG
