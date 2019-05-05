#include <mbed.h>
#include <Vl53L1_PWM.h>

    Vl53L1_PWM sensor_A(PA_9);
    Vl53L1_PWM sensor_B(PA_8);
    Vl53L1_PWM sensor_C(PB_12);
    Vl53L1_PWM sensor_D(PB_14);
    Vl53L1_PWM sensor_E(PB_13);
    uint16_t values[5];
  DigitalOut led (PC_13, 1);
  Serial pc(PA_2, PA_3,115200);
  const int safe_distance = 300;

void UpdateSensors();

int main() {
    pc.printf("--RUN--\n\r");
  // put your setup code here, to run once

  while(1) {

    
    for (int i = 0; i < 5; i++)
        pc.printf("%i\t", values[i]);
    pc.printf("\r\n");
    wait(0.1);
    UpdateSensors();
    
    //sensor.getRange();
//    int x = sensor.getRange();
    // if (x <= 300)
    //   {
    //     led = 0;
    //   }
    // else
    //   {
    //     led = 1;
    //   }
    // pc.printf("%i\r\n", x);
    
    // put your main code here, to run repeatedly:
  }
}

void UpdateSensors()
{
    values[0] = sensor_A.getRange();
    values[1] = sensor_B.getRange();
    values[2] = sensor_C.getRange();
    values[3] = sensor_D.getRange();
    values[4] = sensor_E.getRange();
}