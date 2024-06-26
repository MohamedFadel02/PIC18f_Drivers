#include "ecu_7segment.h"

/**
 * 
 * @param seg
 * @return 
 */
Std_ReturnType segment_init(const segment_t * seg){
Std_ReturnType ret = E_OK;
    if(NULL == seg){
        ret = E_NOT_OK;
    }
    else{
       ret= gpio_pin_init(&(seg->segment_pins[SEGMENT_PIN1]));
       ret= gpio_pin_init(&(seg->segment_pins[SEGMENT_PIN2]));
       ret= gpio_pin_init(&(seg->segment_pins[SEGMENT_PIN3]));
       ret= gpio_pin_init(&(seg->segment_pins[SEGMENT_PIN4]));
       
    }
    return ret;


}
/**
 * 
 * @param seg
 * @param number
 * @return 
 */
Std_ReturnType segment_write_number(const segment_t * seg,uint8 number){
Std_ReturnType ret = E_OK;
    if(NULL == seg || number > 9 ){
        ret = E_NOT_OK;
    }
    else{
         ret= gpio_pin_write_logic(&(seg->segment_pins[SEGMENT_PIN1]),number & 0x01);
         ret= gpio_pin_write_logic(&(seg->segment_pins[SEGMENT_PIN2]),(number<<1) & 0x01);
         ret= gpio_pin_write_logic(&(seg->segment_pins[SEGMENT_PIN3]),(number<<2) & 0x01);
         ret= gpio_pin_write_logic(&(seg->segment_pins[SEGMENT_PIN4]),(number<<3) & 0x01);
    }
    return ret;






}
