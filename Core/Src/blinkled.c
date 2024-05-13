#include "blinkled.h"
//0x4001 1000 GPIOC BASE ADDRESS 
#define RCC_APB2ENR *((uint32_t *)0x40021018)
#define RCC_APB2ENR_IOPCEN 1<<4

void gpio_init(void){
    RCC_APB2ENR |= RCC_APB2ENR_IOPCEN;

    *((uint32_t *)0x40011004)&= ~(1<<20);
    *((uint32_t *)0x40011004)|=  (1<<21);
}
void gpio_writepin(void){
    *((uint32_t * )0x4001100C) |= (1<<13);
}    
void gpio_togglepin(void){
    *((uint32_t * )0x4001100C) ^= (1<<13);
}
void gpio_resetpin(void){
    *((uint32_t * )0x4001100C) &= ~(1<<13);
}

