#include <mbed.h>
#include <Vl53L1_PWM.h>

  Vl53L1_PWM sensor(PA_9);

int main() {
  // put your setup code here, to run once:

  while(1) {
    sensor.getRange();
    // put your main code here, to run repeatedly:
  }
}