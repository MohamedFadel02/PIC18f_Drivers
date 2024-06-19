/* 
 * File:   ecu_7segment.h
 * Author: Mohamed Fadel
 * https://www.linkedin.com/in/mohamed-fadel-713898212/
 * Created on 12 ??????, 2023, 04:06 ?
 */

#ifndef ECU_7SEGMENT_H
#define	ECU_7SEGMENT_H


/*Includes Section*/
#include "ecu_7segment_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*Data types declaration Section*/

typedef enum{

    COMMON_ANODE,
    COMMON_CATHODE         
}segment_type_t;




typedef struct{
    pin_config_t segment_pins[4];
    segment_type_t segment_type;


}segment_t;

/*Macro declaration Section*/
#define SEGMENT_PIN1  0
#define SEGMENT_PIN2  1
#define SEGMENT_PIN3  2
#define SEGMENT_PIN4  3



/*Functions declaration Section*/
Std_ReturnType segment_init(const segment_t * seg);
Std_ReturnType segment_write_number(const segment_t * seg,uint8 number);


#endif	/* ECU_7SEGMENT_H */

