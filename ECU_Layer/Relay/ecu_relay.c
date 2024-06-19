#include "ecu_relay.h"
/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_init(const relay_t *relay){
Std_ReturnType ret = E_OK;
    if(NULL == relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = { .port = relay->relay_port, .pin = relay->relay_pin, 
                                 .direction = GPIO_OUTPUT,.logic = relay->relay_status };
        gpio_pin_init(&pin_obj);
    }
    return ret;


}
/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_turn_on(const relay_t *relay){
Std_ReturnType ret = E_OK;
    if(NULL == relay){
       ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = { .port = relay->relay_port, .pin = relay->relay_pin, 
                                 .direction = GPIO_OUTPUT,.logic = relay->relay_status };
        gpio_pin_write_logic(&pin_obj, GPIO_HIGH);
    }
    return ret;


}
/**
 * 
 * @param relay
 * @return 
 */
Std_ReturnType relay_turn_off(const relay_t *relay){
Std_ReturnType ret = E_OK;
if(NULL == relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_obj = { .port = relay->relay_port, .pin = relay->relay_pin, 
                                 .direction = GPIO_OUTPUT,.logic = relay->relay_status };
        gpio_pin_write_logic(&pin_obj, GPIO_LOW);
    }
    return ret;

}
