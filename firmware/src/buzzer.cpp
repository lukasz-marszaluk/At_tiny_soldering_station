#include "buzzer.h"
#include "avr/io.h"
#include "util/delay.h"

//  ============================================================================
void init_buzzer()
{
    DDRB |= (1 << PB1);    // set PB1 as output
    TCCR1 |= (1 << PWM1A); // enable PWM on OC1A

    TCCR1 |= (1 << CS12); // set Timer1 prescaller to PCK/32
    TCCR1 |= (1 << CS11); // to create proper buzzer sound

    // OC1A cleared on compare match. Set when TCNT1 = $00.
    // OC1A not connected.
    TCCR1 &= ~(1 << COM1A0);
    TCCR1 |= (1 << COM1A1);
}
//  ============================================================================
void buzzer_beep(unsigned int duration)
{
    OCR1A = 0x40;
    _delay_ms(duration);
    OCR1A = 0x00;
}
//  ============================================================================
