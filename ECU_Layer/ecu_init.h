/* 
 * File:   ecu_init.h
 * Author: Mohamed Fadel
 * https://www.linkedin.com/in/mohamed-fadel-713898212/
 * Created on 13 ??????, 2023, 12:24 ?
 */

#ifndef ECU_INIT_H
#define	ECU_INIT_H

#include "Char_LCD/ecu_lcd.h"
#include  "LED/ecu_led.h"
#include "Button/ecu_button.h"
#include "Relay/ecu_relay.h"
#include "DC_Motor/ecu_dc_motor.h"
#include "Keypad/ecu_keypad.h"

void ecu_init(void);


#endif	/* ECU_INIT_H */

