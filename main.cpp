#include <iostream>
#include <string>
#include <sstream>
/*
 * Как только температура снаружи падает ниже 0 °С, надо включить систему обогрева водопровода.
 * Если температура снаружи поднялась выше 5 °С, то систему обогрева водопровода нужно отключить.
   Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение, то необходимо включить садовое освещение.
   Если движения нет или время не вечернее, то света снаружи быть не должно.
   Если температура в помещении упала ниже 22 °С, должно включиться отопление.
   Как только температура равна или поднимается выше 25 °С, отопление автоматически отключается.
   Если температура в помещении поднялась до 30 °С, включается кондиционер. Как только температура становится 25 °С, кондиционер отключается.
   Всё освещение в доме также умное и поддерживает настройку цветовой температуры для комфортного нахождения.
   Каждый день начиная с 16:00 и до 20:00 температура цвета должна плавно изменяться с 5000K до 2700К.
   Разумеется, это изменение должно происходить, если свет сейчас включён. В 00:00 температура сбрасывается до 5000К.
 */
//Включение датчика switches_state |= HEATERS, отключение датчика switches_state &= ~HEATERS.

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16,
    OUTLETS = 32
};

int main() {
   bool power_supply, moving;
   std::stringstream readings;
   int water_heating = 0;
   std::string  instruction, time, temp_out, temp_inside, lights_inside, lights_outside, heaters, outlets,  conditioner;
   std::cout << "Enter the readings of all sensors:\n";
   std::getline(std::cin, instruction) >> instruction;
   readings << instruction;
   readings >> time >> temp_out >> temp_inside >> power_supply >> moving;
   std::cout << temp_out;
   if (std::stoi(temp_out) < 0) {
      water_heating |= WATER_PIPE_HEATING;
   }
   else if (std::stoi(temp_out) > 5) {
       water_heating &= ~WATER_PIPE_HEATING;
   }
   if (water_heating & WATER_PIPE_HEATING) {
       std::cout << "Heating of the water pipe is included\n";
   }
   else if (!(water_heating & WATER_PIPE_HEATING)) {
       std::cout << "Heating of the water pipe is included\n";
   }


    return 0;
}
