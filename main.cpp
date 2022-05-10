#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
/*
 * Как только температура снаружи падает ниже 0 °С, надо включить систему обогрева водопровода.
 * Если температура снаружи поднялась выше 5 °С, то систему обогрева водопровода нужно отключить.
 *Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение, то необходимо включить садовое освещение.
   Если движения нет или время не вечернее, то света снаружи быть не должно.
Если температура в помещении упала ниже 22 °С, должно включиться отопление.
   Как только температура равна или поднимается выше 25 °С, отопление автоматически отключается.
   Если температура в помещении поднялась до 30 °С, включается кондиционер. Как только температура становится 25 °С, кондиционер отключается.

   Всё освещение в доме также умное и поддерживает настройку цветовой температуры для комфортного нахождения.
   Каждый день начиная с 16:00 и до 20:00 температура цвета должна плавно изменяться с 5000K до 2700К.
   Разумеется, это изменение должно происходить, если свет сейчас включён. В 00:00 температура сбрасывается до 5000К.
 */
//Включение датчика switches_state |= HEATERS, отключение датчика switches_state &= ~HEATERS.
float parsing_kelvin(std::string a) {
    std::string tempo = " ";
    for (int i = 0; i < 2; i++) {
        tempo += a[i];
    }

}
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
   std::stringstream readings;
   float kelvin = 5000;
   int water_heating = 0, lights_outside = 0, heaters = 0, conditioner = 0;
   std::string  instruction, moving, time, power_supply, temp_out, temp_inside, lights_inside, outlets;
   std::cout << "Enter the readings of all sensors:\n";
   std::getline(std::cin, instruction);
   readings << instruction;
   readings >> time >> temp_out >> temp_inside >> power_supply >> moving;
   std::cout << time << " " << temp_out << " " << temp_inside << " " << power_supply << " " << moving << "\n";
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
       std::cout << "The heating of the water supply is turned off\n";
   }
   if ((time > "16:00" || time < "05:00") && moving == "yes") {
       lights_outside |= LIGHTS_OUTSIDE;
   }
   else if ((time < "16:00" || time > "05:00") && moving == "no") {
       lights_outside &= ~LIGHTS_OUTSIDE;
   }
   if (lights_outside & LIGHTS_OUTSIDE) {
       std::cout << "Yard lighting is on\n";
   }
   else if (!(lights_outside & LIGHTS_OUTSIDE)) {
        std::cout << "Yard lighting is off\n";
   }
   if (std::stoi(temp_inside) < 22) {
       heaters |= HEATERS;
   }
   else if (std::stoi(temp_inside) >= 25) {
       heaters &= ~HEATERS;
   }
   else if (std::stoi(temp_inside) == 30) {
       conditioner |= CONDITIONER;
   }
   else if (std::stoi(temp_inside) == 25) {
       conditioner &= ~CONDITIONER;
   }
   if (heaters & HEATERS) {
       std::cout << "Heating is on! \n";
   }
   else if (!((heaters & HEATERS))) {
       std::cout << "The heating is off! \n";
   }
   if (conditioner & CONDITIONER) {
       std::cout << "The air conditioner is on! \n";
   }
   else if (!((conditioner & CONDITIONER))) {
       std::cout << "The air conditioner is off! \n";
   }
   if (power_supply == "on") {

   }


    return 0;
}
