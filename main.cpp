#include <iostream>
#include <string>
#include <sstream>

float kelvin(std::string a) {
    std::string tempo_f;
    float tempo_h;
    for (int i = 0; i < 5; i++) {
        if (i != 2) {
            tempo_f += a[i];
        }
        if (i == 2) {
            tempo_h = (std::stof(tempo_f) - 16) * 60;
            tempo_f = "";
        }
    }
    return 5000 - ((tempo_h + std::stof(tempo_f)) * 9.58);
}
enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16,
};

int main() {
   std::stringstream readings;
   int water_heating = 0, lights_outside = 0, heaters = 0, conditioner = 0, lights_inside = 0;
   std::string  instruction, moving, time, power_supply, temp_out, temp_inside;
   std::cout << "Enter the data: "
                "Time, outdoor temperature, "
                "indoor temperature, the presence of light in the room (on/off), "
                "the presence of traffic in the yard (yes/no).\n";
   std::getline(std::cin, instruction);
   readings << instruction;
   readings >> time >> temp_out >> temp_inside >> power_supply >> moving;

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
   if (std::stoi(temp_inside) == 30) {
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
       lights_inside |= LIGHTS_INSIDE;
   }
   if (lights_inside & LIGHTS_INSIDE) {
        std::cout << "The lights are on!\n";
        if (time < "16:00" && time >= "00:00") {
            std::cout << "Color temperature 5000 Kelvin.";
        }
        else if (time > "16:00" && time < "20:00") {
            std::cout << "Color temperature: " << kelvin(time) << "Kelvin.";
        }
        else if (time >= "20:00" && time < "00:00") {
            std::cout << "Color temperature 2700 Kelvin.";
        }
   }
   else if (!(lights_inside & LIGHTS_INSIDE)) {
       std::cout << "The lights are off.";
   }
 return 0;
}
