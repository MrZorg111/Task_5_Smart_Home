#include <iostream>
#include <sstream>
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
   std::string lights_inside, lights_outside, heaters, outlets, water_heating, conditioner;
   std::cout << "Enter the readings of all sensors:";
   std::cin >> readings;
    return 0;
}
