#include "buttons.h"
#include "buzzer.h"
#include "heater.h"
#include "sensor.h"

#include "SSD1306_minimal/SSD1306_minimal.h"
#include "stdio.h"
//  ============================================================================
unsigned int sensor_temp;
unsigned int heater_power;
SSD1306_Mini oled;

//  ============================================================================
char buffer[32];

//  ============================================================================
int main()
{
  init_buttons();
  init_buzzer();
  init_heater();
  init_sensor();

  oled.init();
  oled.startScreen();
  oled.clear();

  set_heater_power(127);

  while (1)
  {
    sensor_temp = read_temp();
    sprintf(buffer, "%uHz  ", sensor_temp);

    oled.cursorTo (0, 0);
    oled.printString (buffer);

    switch (read_buttons())
    {
    case BTN_NONE:
      sprintf(buffer, "none    ");
      break;
    case BTN_UP:
      sprintf(buffer, "up      ");
      break;
    case BTN_DOWN:
      sprintf(buffer, "down    ");
      break;
    case BTN_BOTH:
      sprintf(buffer, "both    ");
      break;
    default:
      sprintf(buffer, "error   ");
      break;
    }

    oled.cursorTo (1, 0);
    oled.printString (buffer);
  }
}
//  ============================================================================
