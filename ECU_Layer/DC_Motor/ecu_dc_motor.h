/* 
 * File:   ecu_dc_motor
 * Author: Mohamed Fadel
 * https://www.linkedin.com/in/mohamed-fadel-713898212/
 * Created on 12 ??????, 2023, 11:24 ?
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/*Includes Section*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_dc_motor_cfg.h"

/*Data types declaration Section*/


typedef struct{

    pin_config_t dc_motor[2];

}dc_motor_t;

/*Macro declaration Section*/
#define DC_MOTOR_STATUS_ON   0x01u
#define DC_MOTOR_STATUS_OFF  0x00u
#define DC_MOTOR_PIN1        0x00 
#define DC_MOTOR_PIN2        0x01 
/*Functions declaration Section*/
Std_ReturnType dc_motor_init(const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_move_left(const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_turn_off(const dc_motor_t *dc_motor);

#endif	/* ECU_DC_MOTOR_H */

