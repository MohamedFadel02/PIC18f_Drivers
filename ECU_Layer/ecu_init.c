#include "ecu_init.h"


Std_ReturnType ret= E_NOT_OK;

chr_lcd_4bit_t lcd_1 ={    
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin =  GPIO_PIN0,
    .lcd_rs.direction = GPIO_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.pin =  GPIO_PIN1,
    .lcd_en.direction = GPIO_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    .lcd_data[0].port =  PORTC_INDEX,
    .lcd_data[0].pin = GPIO_PIN2,
    .lcd_data[0].direction = GPIO_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[1].port =  PORTC_INDEX,
    .lcd_data[1].pin = GPIO_PIN3,
    .lcd_data[1].direction = GPIO_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[2].port =  PORTC_INDEX,
    .lcd_data[2].pin = GPIO_PIN4,
    .lcd_data[2].direction = GPIO_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[3].port =  PORTC_INDEX,
    .lcd_data[3].pin = GPIO_PIN5,
    .lcd_data[3].direction = GPIO_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,
    
};
chr_lcd_8bit_t lcd_2 ={
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin =  GPIO_PIN6,
    .lcd_rs.direction = GPIO_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.pin =  GPIO_PIN7,
    .lcd_en.direction = GPIO_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    .lcd_data[0].port= PORTD_INDEX,
    .lcd_data[0].pin= GPIO_PIN0,
    .lcd_data[0].direction = GPIO_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[1].port= PORTD_INDEX,
    .lcd_data[1].pin= GPIO_PIN1,
    .lcd_data[1].direction = GPIO_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[2].port= PORTD_INDEX,
    .lcd_data[2].pin= GPIO_PIN2,
    .lcd_data[2].direction = GPIO_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[3].port= PORTD_INDEX,
    .lcd_data[3].pin= GPIO_PIN3,
    .lcd_data[3].direction = GPIO_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,
    .lcd_data[4].port= PORTD_INDEX,
    .lcd_data[4].pin= GPIO_PIN4,
    .lcd_data[4].direction = GPIO_OUTPUT,
    .lcd_data[4].logic = GPIO_LOW,
    .lcd_data[5].port= PORTD_INDEX,
    .lcd_data[5].pin= GPIO_PIN5,
    .lcd_data[5].direction = GPIO_OUTPUT,
    .lcd_data[5].logic = GPIO_LOW,
    .lcd_data[6].port= PORTD_INDEX,
    .lcd_data[6].pin= GPIO_PIN6,
    .lcd_data[6].direction = GPIO_OUTPUT,
    .lcd_data[6].logic = GPIO_LOW,
    .lcd_data[7].port= PORTD_INDEX,
    .lcd_data[7].pin= GPIO_PIN7,
    .lcd_data[7].direction = GPIO_OUTPUT,
    .lcd_data[7].logic = GPIO_LOW,
    

};




/*
keypad_t keypad_1 ={

.keypad_row_pins[0].port=PORTB_INDEX,
.keypad_row_pins[0].pin=GPIO_PIN0,
.keypad_row_pins[0].direction=GPIO_OUTPUT,
.keypad_row_pins[0].logic=GPIO_LOW,
.keypad_row_pins[1].port=PORTB_INDEX,
.keypad_row_pins[1].pin=GPIO_PIN1,
.keypad_row_pins[1].direction=GPIO_OUTPUT,
.keypad_row_pins[1].logic=GPIO_LOW,
.keypad_row_pins[2].port=PORTB_INDEX,
.keypad_row_pins[2].pin=GPIO_PIN2,
.keypad_row_pins[2].direction=GPIO_OUTPUT,
.keypad_row_pins[2].logic=GPIO_LOW,
.keypad_row_pins[3].port=PORTB_INDEX,
.keypad_row_pins[3].pin=GPIO_PIN3,
.keypad_row_pins[3].direction=GPIO_OUTPUT,
.keypad_row_pins[3].logic=GPIO_LOW,
.keypad_columns_pins[0].port=PORTB_INDEX,
.keypad_columns_pins[0].pin=GPIO_PIN4,
.keypad_columns_pins[0].direction=GPIO_INPUT,
.keypad_columns_pins[0].logic=GPIO_LOW,
.keypad_columns_pins[1].port=PORTB_INDEX,
.keypad_columns_pins[1].pin=GPIO_PIN5,
.keypad_columns_pins[1].direction=GPIO_INPUT,
.keypad_columns_pins[1].logic=GPIO_LOW,
.keypad_columns_pins[2].port=PORTB_INDEX,
.keypad_columns_pins[2].pin=GPIO_PIN6,
.keypad_columns_pins[2].direction=GPIO_INPUT,
.keypad_columns_pins[2].logic=GPIO_LOW,
.keypad_columns_pins[3].port=PORTB_INDEX,
.keypad_columns_pins[3].pin=GPIO_PIN7,
.keypad_columns_pins[3].direction=GPIO_INPUT,
.keypad_columns_pins[3].logic=GPIO_LOW,

};





dc_motor_t motor_1={
    .dc_motor[0].pin=GPIO_PIN0,
    .dc_motor[0].port=PORTD_INDEX,
    .dc_motor[0].direction=DC_MOTOR_STATUS_OFF,
    .dc_motor[1].pin=GPIO_PIN1,
    .dc_motor[1].port=PORTD_INDEX,
    .dc_motor[1].direction=DC_MOTOR_STATUS_OFF,
};
dc_motor_t motor_2={
    .dc_motor[0].pin=GPIO_PIN2,
    .dc_motor[0].port=PORTD_INDEX,
    .dc_motor[0].direction=DC_MOTOR_STATUS_OFF,
    .dc_motor[1].pin=GPIO_PIN3,
    .dc_motor[1].port=PORTD_INDEX,
    .dc_motor[1].direction=DC_MOTOR_STATUS_OFF,
};




pin_config_t LED_1 = {

   .port =PORTC_INDEX,
   .pin = GPIO_PIN0,
   .direction=GPIO_OUTPUT,
   .logic=GPIO_LOW
   
};
pin_config_t LED_2 = {

   .port =PORTC_INDEX,
   .pin = GPIO_PIN1,
   .direction=GPIO_OUTPUT,
   .logic=GPIO_LOW
};
pin_config_t LED_3 = {

   .port =PORTC_INDEX,
   .pin = GPIO_PIN2,
   .direction=GPIO_OUTPUT,
   .logic=GPIO_LOW
};
pin_config_t LED_4 = {

   .port =PORTC_INDEX,
   .pin = GPIO_PIN3,
   .direction=GPIO_OUTPUT,
   .logic=GPIO_LOW
};
*/
void ecu_init(void){

/*ret = dc_motor_init(&motor_1);
ret = dc_motor_init(&motor_2);
ret = keypad_initialize(&keypad_1); */
    ret= lcd_4bit_intialize(&lcd_1);
    ret= lcd_8bit_intialize(&lcd_2);


}