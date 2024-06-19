/* 
 * File:   ecu_relay.h
 * Author: Mohamed Fadel
 * https://www.linkedin.com/in/mohamed-fadel-713898212/
 * Created on 11 ??????, 2023, 11:04 ?
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H


/*Includes Section*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_relay_cfg.h"
/*Data types declaration Section*/
typedef struct{

    uint8 relay_port :4;
    uint8 relay_pin : 3;
    uint8 relay_status :1;
}relay_t;

/*Macro declaration Section*/
#define RELAY_STATUS_ON   0x01u
#define RELAY_STATUS_OFF   0x00u

/*Functions declaration Section*/

Std_ReturnType relay_init(const relay_t *relay);
Std_ReturnType relay_turn_on(const relay_t *relay);
Std_ReturnType relay_turn_off(const relay_t *relay);



#endif	/* ECU_RELAY_H */

