/* 
 * File:   mcal_interrut_manager.h
 * Author: Aya Ali
 *
 * Created on November 25, 2023, 3:04 PM
 */

#include "mcal_interrupt_manager.h"


#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
void  __interrupt() Interrupt_Manager_High(void){
  if((INTCONbits.INT0IE ==INTERRUPT_ENABLE) && (INTCONbits.INT0IF==INTERRUPT_OCCUR)){
    INT0_ISR();
    }
    else{}
   if((INTCON3bits.INT2E ==INTERRUPT_ENABLE) && (INTCON3bits.INT2F ==INTERRUPT_OCCUR)){
    INT2_ISR();
    }
    else{}
  
}
void __interrupt(low_priority) Interrupt_Manager_Low(void){
 if((INTCON3bits.INT1E ==INTERRUPT_ENABLE) && (INTCON3bits.INT1F ==INTERRUPT_OCCUR)){
    INT1_ISR();
    }
    else{}
}
#else
void __interrupt() Interrupt_Manager_High(void){
    if((INTCONbits.INT0IE ==INTERRUPT_ENABLE) && (INTCONbits.INT0IF==INTERRUPT_OCCUR)){
    INT0_ISR();
    }
    else{}
    if((INTCON3bits.INT1E ==INTERRUPT_ENABLE) && (INTCON3bits.INT1F ==INTERRUPT_OCCUR)){
    INT1_ISR();
    }
    else{}
    if((INTCON3bits.INT2E ==INTERRUPT_ENABLE) && (INTCON3bits.INT2F ==INTERRUPT_OCCUR)){
    INT2_ISR();
    }
    else{}
}
#endif