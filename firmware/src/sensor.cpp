#include "sensor.h"

#include <avr/interrupt.h>
#include <avr/io.h>

//  ============================================================================
volatile unsigned int frequency_count;
volatile unsigned int frequency;
volatile unsigned int timer_ovf_count;
//  ============================================================================
void init_sensor()
{
    frequency_count = 0;    // set variables
    frequency = 0;
    timer_ovf_count = 0;


    DDRB &= ~(1 << PB3); // set PB3 as input

    TCCR0B |= (1 << CS00); // set prescaller to clk/1024
    TCCR0B |= (1 << CS02); // --||--
    
    TCNT0 = 0;             // reset timer 0

    GIMSK |= (1 << PCIE);   // enable pin change interrupts
    PCMSK |= (1 << PCINT3); // set PB3 as pin change interrupt
    TIMSK |= (1 << TOIE0);  // enable timer 0 overflow interrupt
    sei();
}
//  ============================================================================
unsigned int read_temp()
{
    return frequency;
}
//  ============================================================================
ISR(PCINT0_vect)
{
    ++frequency_count;
}
//  ============================================================================
ISR(TIM0_OVF_vect)
{
    TIFR = 0;
    ++timer_ovf_count;
    
    // save counted frequency during c.a. one second
    if (timer_ovf_count == 30)
    {
        frequency = frequency_count;
        frequency_count = 0;
        timer_ovf_count = 0;
    }
}
//  ============================================================================
