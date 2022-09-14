/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

BusOut seg_dis(D2,D3,D4,D5,D6,D7,D8);
DigitalOut display(D9);

static int unidades=0;
const char visualiza[16] = {0b0000001, //0
                            0b1001111, //1
                            0b0010010, //2
                            0b0000110, //3
                            0b1001100, //4
                            0b0100100, //5
                            0b0100000, //6
                            0b0001110, //7
                            0b0000000, //8
                            0b0000100, //9
                            0b0001000, //10
                            0b1100000, //11
                            0b0110001, //12
                            0b1000010, //13
                            0b0110000, //14
                            0b0111000}; //15

//hilos
Thread hilo_contar;

//prototipos
void contar(void);

int main()
{
    hilo_contar.start(contar);
    while (true) {
    }
}

void contar(void){
    while(true){
        for (unidades = 0; unidades < 16; unidades++){
            display = true;
            seg_dis = visualiza[unidades];
            ThisThread::sleep_for(600ms);
        }
        for(unidades = 15; unidades > 0; unidades--){
            display = true;
            seg_dis = visualiza[unidades];
            ThisThread::sleep_for(600ms);
        }
    }
}

