#include "mbed.h"
#include "HEPTA_EPS.h"
#include "HEPTA_CDH.h"
#include "HEPTA_SENSOR.h"

RawSerial pc(USBTX,USBRX);
HEPTA_EPS eps(p16,p26);
HEPTA_CDH cdh(p5,p6,p7,p8,"sd");
HEPTA_SENSOR sensor(p17,
                  p28,p27,0x19,0x69,0x13,
                  p13, p14,p25,p24);

int main(){
    sensor.gps_setting();
    pc.printf("GPS Raw Data Mode\r\n");
    while(1) pc.putc(sensor.getc());
}

