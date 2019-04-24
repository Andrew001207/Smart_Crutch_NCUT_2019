#include <mbed.h>
#include <Vl53L1_PWM.h>

  Vl53L1_PWM sensor(PA_9);
  DigitalOut led (PC_13, 1);
  Serial pc(PA_2, PA_3,115200);
  const int safe_distance = 300;

int main() {
  // put your setup code here, to run once:

  while(1) {
    //sensor.getRange();
    int x = sensor.getRange();
    if (x <= 300)
      {
        led = 0;
      }
    else
      {
        led = 1;
      }
    pc.printf("%i\r\n", x);
    
    // put your main code here, to run repeatedly:
  }
}