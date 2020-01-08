#ifndef _SOLDERING_STATION_BUTTONS_
#define _SOLDERING_STATION_BUTTONS_

//  ============================================================================
enum BTN_STATE
{
    BTN_UP,
    BTN_DOWN,
    BTN_BOTH,
    BTN_NONE
};

//  ============================================================================
void init_buttons();

BTN_STATE read_buttons();

//  ============================================================================
#endif //!_SOLDERING_STATION_BUTTONS_