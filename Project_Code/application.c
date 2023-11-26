/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"
led_t led1 = {
.Port_Name = PORTC_INDEX,
.pin = PIN0,
.led_statues = LED_OFF
};

led_t led2 = {
.Port_Name = PORTC_INDEX,
.pin = PIN1,
.led_statues = LED_OFF
};

led_t led3 = {
.Port_Name = PORTC_INDEX,
.pin = PIN2,
.led_statues = LED_OFF
};


void Int0_ISR(void){
led_toggle(&led1);
__delay_ms(250);
}
void Int1_ISR(void){
led_toggle(&led2);
__delay_ms(250);
}
void Int2_ISR(void){
led_toggle(&led3);
__delay_ms(250);
}


 Ex_Interrupt_INTx_t INT0_obj= {
 .Ext_Intterrupt = Int0_ISR,
 .edge = EX_Interrupt_Rising_Edge,
 .priority = Interrupt_Periority_HIGH,
 .source = EX_Interrupt_INT0,
 .mcu_pin.port = PORTB_INDEX,
 .mcu_pin.pin = PIN0,
 .mcu_pin.direction = Input
 };

Ex_Interrupt_INTx_t INT1_obj= {
 .Ext_Intterrupt = Int1_ISR,
 .edge = EX_Interrupt_Rising_Edge,
 .priority = Interrupt_Periority_LOW,
 .source = EX_Interrupt_INT1,
 .mcu_pin.port = PORTB_INDEX,
 .mcu_pin.pin = PIN1,
 .mcu_pin.direction = Input
 }; 

 Ex_Interrupt_INTx_t INT2_obj= {
 .Ext_Intterrupt = Int2_ISR,
 .edge = EX_Interrupt_Rising_Edge,
 .priority = Interrupt_Periority_HIGH,
 .source = EX_Interrupt_INT2,
 .mcu_pin.port = PORTB_INDEX,
 .mcu_pin.pin = PIN2,
 .mcu_pin.direction = Input
 };
 
int main() {
   

Std_ReturnType ret = E_NOT_OK;
ret = Interrupt_INTx_Initialization(&INT0_obj);
ret = Interrupt_INTx_Initialization(&INT1_obj);
ret = Interrupt_INTx_Initialization(&INT2_obj);

ret = led_initialize(&led1);
ret = led_initialize(&led2);
ret = led_initialize(&led3);
application_initialize();

while(1){  

}
 return (EXIT_SUCCESS);
}
void application_initialize(void){
   ECU_Layer_initialize();
  
}
