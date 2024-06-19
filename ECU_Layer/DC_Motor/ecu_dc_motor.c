#include "ecu_dc_motor.h"

/**
 * 
 * @param dc_motor
 * @return 
 */
Std_ReturnType dc_motor_init(const dc_motor_t *dc_motor){
Std_ReturnType ret = E_OK;
    if(NULL == dc_motor){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_init(&(dc_motor->dc_motor[DC_MOTOR_PIN1]));
        gpio_pin_init(&(dc_motor->dc_motor[DC_MOTOR_PIN2]));
       
    }
    return ret;
}
/**
 * 
 * @param dc_motor
 * @return 
 */
Std_ReturnType dc_motor_move_right(const dc_motor_t *dc_motor){
Std_ReturnType ret = E_OK;
    if(NULL == dc_motor){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_write_logic(&(dc_motor->dc_motor[DC_MOTOR_PIN1]), GPIO_HIGH);
        gpio_pin_write_logic(&(dc_motor->dc_motor[DC_MOTOR_PIN2]), GPIO_LOW);
    }
    return ret;
}
/**
 * 
 * @param dc_motor
 * @return 
 */
Std_ReturnType dc_motor_move_left(const dc_motor_t *dc_motor){
Std_ReturnType ret = E_OK;
    if(NULL == dc_motor){
        ret = E_NOT_OK;
    }
    else{
       
       gpio_pin_write_logic(&(dc_motor->dc_motor[DC_MOTOR_PIN1]), GPIO_LOW);
        gpio_pin_write_logic(&(dc_motor->dc_motor[DC_MOTOR_PIN2]), GPIO_HIGH);
    }
    return ret;
}

Std_ReturnType dc_motor_turn_off(const dc_motor_t *dc_motor){

gpio_pin_write_logic(&(dc_motor->dc_motor[DC_MOTOR_PIN1]), GPIO_LOW);
        gpio_pin_write_logic(&(dc_motor->dc_motor[DC_MOTOR_PIN2]), GPIO_LOW);


}
