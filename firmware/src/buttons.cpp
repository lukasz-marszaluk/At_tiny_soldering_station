#include "buttons.h"

#include "avr/io.h"

//  ============================================================================
void init_buttons ()
{
        ADCSRA |= (1 << ADEN);  // enable ADC

}
//  ============================================================================
BTN_STATE read_buttons()
{
    ADCSRA |= (1 << ADSC); // start conversion

    while (!(ADCSRA & (1 << ADIF)))
        ;

    if (ADC > 900)
        return BTN_NONE;
    else if (ADC > 800)
        return BTN_UP; // button 2
    else if (ADC > 650)
        return BTN_DOWN; //button 1
    else if (ADC > 512)
        return BTN_BOTH;

    return BTN_NONE;
}
//  ============================================================================
