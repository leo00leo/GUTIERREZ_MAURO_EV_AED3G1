#ifndef DS1302_H
#define DS1302_H
#include "stm32f103xb.h"

void ds1302_init();// inicializacion
void ds1302_write(uint8_t address, uint8_t data);// enviar
uint8_t ds1302_read(uint8_t address);// leer 
void ds1302_set_time(uint8_t hora, uint8_t min, uint8_t seg); //tiempo configuracion
uint8_t ds1302_get_hours(); //horas
uint8_t ds1302_get_minutes(); //minutos
uint8_t ds1302_get_seconds(); // segundos

#endif