#include "ds1302.h"
#include "stm32f103xb.h"


int  CE=5;
int IO=6;
int SCLK=7;

void ds1302_init(){       
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    GPIOA->CRL&=~(0XF<<CE*4);
    GPIOA->CRL|=(0X4<<CE*4);
    GPIOA->CRL&=~(0XF<<IO*4);
    GPIOA->CRL|=(0X4<<IO*4);
    GPIOA->CRL&=~(0XF<<SCLK*4);
    GPIOA->CRL|=(0X4<<SCLK*4);
};

void ds1302_write(uint8_t address, uint8_t data){
    GPIOA->BSRR|=(1<<CE);
    for(int i=0;i<=7;i++){
        if((address>>i)&0x01)GPIOA->BSRR|=(1<<IO);
        else GPIOA->BRR|=(0<<IO);
        GPIOA->BSRR|=(1<<SCLK);
        GPIOA->BSRR|=(0<<SCLK);
    };
    for(int i=0;i<=7;i++){
        if((data>>i)&0x01)GPIOA->BSRR|=(1<<IO);
        else GPIOA->BRR|=(0<<IO);
        GPIOA->BSRR|=(1<<SCLK);
        GPIOA->BSRR|=(0<<SCLK);
    };
    GPIOA->BSRR|=(0<<CE);
};

uint8_t ds1302_read(uint8_t address){
    GPIOA->BSRR|=(1<<CE);
    for(int i=0;i<=7;i++){
        if((address>>1)&0x01){
            GPIOA->CRL|=(0X1<<IO);
            GPIOA->BSRR|=(1<<IO);
        }
        else{
            GPIOA->BSRR|=(0<<IO);
            GPIOA->BSRR|=(1<<SCLK);
            GPIOA->BSRR|=(0<<SCLK);
        }
        for(int i=0;i<=7;i++){
            GPIOA->CRL|=(0X4<<IO);
            GPIOA->IDR=(IO);
            GPIOA->BSRR|=(0<<SCLK);
            GPIOA->BSRR|=(1<<SCLK);
        }
        GPIOA->BSRR|=(0<<CE);
    }
}

void ds1302_set_time(uint8_t hora, uint8_t min, uint8_t seg){

}