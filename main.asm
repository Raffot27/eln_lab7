;**************************************************************
;* This stationery serves as the framework for a *
;* user application. For a more comprehensive program that *
;* demonstrates the more advanced functionality of this *
;* processor, please see the demonstration applications *
;* located in the examples subdirectory of the *
;* Freescale CodeWarrior for the HC12 Program directory *
;**************************************************************

; Include derivative-specific definitions
INCLUDE 'derivative.inc'

; export symbols
XDEF Entry, _Startup, main
; we use export 'Entry' as symbol. This allows us to
; reference 'Entry' either in the linker .prm file
; or from C/C++ later on
; code section
MyCode: SECTION
main:
_Startup:
Entry:
; Insert here your code

  LDAA #$F0 ; load the DDRT register initialization value (bits 7 to 4 at ‘1’) in A
  STAA DDRT ; write the content of A to the DDRT register
  STAA PTT ; turn off the 4 LEDsDDRT (writing ‘1’)
  LDX  #1000 ; X=1000
  
loop1:  CMPA #0
        BGE  YESX
        BRA  NOX

YESX: LDAA 
      EORA    
