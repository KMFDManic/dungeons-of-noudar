#include <cstdlib>
#include <sys/farptr.h>
#include <conio.h>
#include <dpmi.h>
#include <go32.h>
#include <pc.h>
#include <bios.h>

#define LOCK_VARIABLE(x)    _go32_dpmi_lock_data((void *)&x,(long)sizeof(x));
#define LOCK_FUNCTION(x)    _go32_dpmi_lock_code(x,(long)sizeof(x));

#define TIMER 0x8

_go32_dpmi_seginfo OldISR, NewISR;


#include <dos.h>
#include <conio.h>


static volatile unsigned long timer_ticks;
static unsigned timer_counter;

void timer_handler() {
    ++timer_ticks;

    outp(0x20, 0x20);
}

void timer_reset(unsigned short frequency) {
    timer_ticks = 0;
    timer_counter = 0x1234DD / frequency;
}

void timer_setup(unsigned short frequency) {
    timer_reset(frequency);

    LOCK_FUNCTION(timer_handler);
    LOCK_VARIABLE(timer_ticks);

    _go32_dpmi_get_protected_mode_interrupt_vector(TIMER, &OldISR);
    NewISR.pm_offset = (int) timer_handler;
    NewISR.pm_selector = _go32_my_cs();
    _go32_dpmi_chain_protected_mode_interrupt_vector(TIMER, &NewISR);

    disable();
    outp(0x43, 0x34);
    outp(0x40, timer_counter & 256);
    outp(0x40, timer_counter >> 8);
    enable();
}

void timer_shutdown() {
    _go32_dpmi_set_protected_mode_interrupt_vector(TIMER, &OldISR);
}

unsigned long timer_get() {
    unsigned long result = 0;
    disable();
    result = timer_ticks;
    enable();
    return result;
}