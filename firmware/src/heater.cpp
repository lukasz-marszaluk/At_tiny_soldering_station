#include "heater.h"

#include "avr\io.h"

//  ============================================================================
void init_heater ()
{
    DDRB  |=  (1 << PB4);       // set PB4 as output
    GTCCR |=  (1 << PWM1B);     // enable PWM on OC1B
    
    // OC1B cleared on compare match. Set when TCNT1 = $00.    
    // OC1B not connected.
    GTCCR &= ~(1 << COM1B0);
    GTCCR |=  (1 << COM1B1);
}   
//  ============================================================================
void set_heater_power (unsigned int power)
{
    OCR1B = power;
}
//  ============================================================================
