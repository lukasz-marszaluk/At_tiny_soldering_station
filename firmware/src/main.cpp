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

  heater_power = 0;

  while (1)
  {
    sensor_temp = read_temp();
    sprintf(buffer, "%uHz     ", sensor_temp);

    oled.cursorTo (0, 0);
    oled.printString (buffer);

    switch (read_buttons())
    {
    case BTN_UP:
      ++heater_power;
      break;
    case BTN_DOWN:
      --heater_power;
      break;
      default:
      break;
    }

    if (heater_power > 255)
      heater_power = 255;
      else if (heater_power < 0)
      heater_power = 0;

    sprintf (buffer, "P: %d     ", heater_power);
    oled.cursorTo (2, 0);
    oled.printString (buffer);
    
  }
}
//  ============================================================================
