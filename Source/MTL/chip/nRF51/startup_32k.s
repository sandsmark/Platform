@------------------------------------------------------------------------------
@ Copyright (c) 2016 John D. Haughton
@
@ Permission is hereby granted, free of charge, to any person obtaining a copy
@ of this software and associated documentation files (the "Software"), to deal
@ in the Software without restriction, including without limitation the rights
@ to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
@ copies of the Software, and to permit persons to whom the Software is
@ furnished to do so, subject to the following conditions:
@
@ The above copyright notice and this permission notice shall be included in
@ all copies or substantial portions of the Software.
@
@ THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
@ IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
@ FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
@ AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
@ LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
@ OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
@ SOFTWARE.
@------------------------------------------------------------------------------

.cpu cortex-m0
.fpu softvfp

.section .vectors
.align	2

.global vector_table

vector_table:
   .word  0x20008000        @ stack pointer (32k RAM)
   .word  reset+1
   .word  nmi+1
   .word  fault+1
   .word  0
   .word  0
   .word  0
   .word  0
   .word  0
   .word  0
   .word  0
   .word  svc+1
   .word  0
   .word  0
   .word  pendSv+1
   .word  sysTick+1

   .word  PowerClock_IRQ+1  @ IRQ  0
   .word  Radio_IRQ+1       @ IRQ  1
   .word  Uart_IRQ+1        @ IRQ  2
   .word  SpiTwi_0_IRQ+1    @ IRQ  3
   .word  SpiTwi_1_IRQ+1    @ IRQ  4
   .word  irq5+1            @ IRQ  5
   .word  GpioTE_IRQ+1      @ IRQ  6
   .word  Adc_IRQ+1         @ IRQ  7
   .word  Timer_0_IRQ+1     @ IRQ  8
   .word  Timer_1_IRQ+1     @ IRQ  9
   .word  Timer_2_IRQ+1     @ IRQ 10
   .word  Rtc_0_IRQ+1       @ IRQ 11
   .word  Temp_IRQ+1        @ IRQ 12
   .word  Rng_IRQ+1         @ IRQ 13
   .word  Ecb_IRQ+1         @ IRQ 14
   .word  CcmAar_IRQ+1      @ IRQ 15
   .word  Wdt_IRQ+1         @ IRQ 16
   .word  Rtc_1_IRQ+1       @ IRQ 17
   .word  Qdec_IRQ+1        @ IRQ 18
   .word  LpComp_IRQ+1      @ IRQ 19
   .word  Swi_0_IRQ+1       @ IRQ 20
   .word  Swi_1_IRQ+1       @ IRQ 21
   .word  Swi_2_IRQ+1       @ IRQ 22
   .word  Swi_3_IRQ+1       @ IRQ 23
   .word  Swi_4_IRQ+1       @ IRQ 24
   .word  Swi_5_IRQ+1       @ IRQ 25

   .weak  reset
   .weak  nmi
   .weak  fault
   .weak  svc
   .weak  pendSv
   .weak  sysTick

   .weak  PowerClock_IRQ
   .weak  Radio_IRQ
   .weak  Uart_IRQ
   .weak  SpiTwi_0_IRQ
   .weak  SpiTwi_1_IRQ
   .weak  irq5
   .weak  GpioTE_IRQ
   .weak  Adc_IRQ
   .weak  Timer_0_IRQ
   .weak  Timer_1_IRQ
   .weak  Timer_2_IRQ
   .weak  Rtc_0_IRQ
   .weak  Temp_IRQ
   .weak  Rng_IRQ
   .weak  Ecb_IRQ
   .weak  CcmAar_IRQ
   .weak  Wdt_IRQ
   .weak  Rtc_1_IRQ
   .weak  Qdec_IRQ
   .weak  LpComp_IRQ
   .weak  Swi_0_IRQ 
   .weak  Swi_1_IRQ 
   .weak  Swi_2_IRQ 
   .weak  Swi_3_IRQ 
   .weak  Swi_4_IRQ 
   .weak  Swi_5_IRQ 

.text
.align	2

reset:
#
# Make sure all RAM banks are powered on
#
    movs    r1,#3
#
    ldr     r0,ramon
    str     r1,[r0]
#
    ldr     r0,ramonb
    str     r1,[r0]
#
# Initialise C/C++ runtime
#
    bl      tinyc_init
#
# Call application entry point
#
    mov     r0, #0   @ ensure argc is zero
    bl      main
#
# Fall through to unhandled exception
#

unhandled_exception:
nmi:
fault:
svc:
pendSv:
sysTick:

PowerClock_IRQ:
Radio_IRQ:
Uart_IRQ:
SpiTwi_0_IRQ:
SpiTwi_1_IRQ:
irq5:
GpioTE_IRQ:
Adc_IRQ:
Timer_0_IRQ:
Timer_1_IRQ:
Timer_2_IRQ:
Rtc_0_IRQ:
Temp_IRQ:
Rng_IRQ:
Ecb_IRQ:
CcmAar_IRQ:
Wdt_IRQ:
Rtc_1_IRQ:
Qdec_IRQ:
LpComp_IRQ:
Swi_0_IRQ:
Swi_1_IRQ:
Swi_2_IRQ:
Swi_3_IRQ:
Swi_4_IRQ:
Swi_5_IRQ:
loop:
    b       loop

.align 2
ramon:
   .word 0x40000524
ramonb:
   .word 0x40000554

