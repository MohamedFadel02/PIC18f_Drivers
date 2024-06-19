/* 
 * File:   hal_gpio.h
 * Author: Mohamed Fadel
 * https://www.linkedin.com/in/mohamed-fadel-713898212/
 * Created on 18 ?????, 2023, 12:33 ?
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H
/*Includes Section*/
#include "pic18f4620.h" 
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "hal_gpio_cfg.h"
/*Data types declaration Section*/
typedef enum{
    GPIO_LOW=0,
    GPIO_HIGH        
}logic_t;

typedef enum {
    GPIO_OUTPUT=0,
    GPIO_INPUT        
}direction_t;
typedef enum {
    GPIO_PIN0=0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}pin_index_t;

typedef enum {
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct{

    uint8 port :3; /*@ref port_index_t */
    uint8 pin  :3; /*@ref pin_index_t */
    uint8 direction :1; /*@ref direction_t*/
    uint8 logic :1;     /*@ref logic_t*/

}pin_config_t;

/*Macro declaration Section*/



/*Macro functions declaration Section*/
#define HWREG(_x)      (*((volatile uint 8 *)(_x)))
#define _XTAL_FREQ 8000000
#define   SET_BIT(reg,bit)      (reg=reg|(1<<bit))
#define   CLEAR_BIT(reg,bit)    (reg=reg&(~(1<<bit)))
#define   READ_BIT(reg,bit)     ((reg>>bit)&1)
#define   TOGGLE_BIT(reg,bit)   (reg=reg^(1<<bit))
#define MAX_PIN    8
#define MAX_PORT   5
/*Functions declaration Section*/

Std_ReturnType gpio_pin_direction_init(const pin_config_t * pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t * pin_config,direction_t *dic_status );
Std_ReturnType gpio_pin_write_logic(const pin_config_t * pin_config,logic_t logic );
Std_ReturnType gpio_pin_read_logic(const pin_config_t * pin_config,logic_t *logic );
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t * pin_config );
Std_ReturnType gpio_pin_init(const pin_config_t * pin_config);

Std_ReturnType gpio_port_direction_init(port_index_t port,direction_t direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8 *dic_status);
Std_ReturnType gpio_port_write_logic(port_index_t port,logic_t logic );
Std_ReturnType gpio_port_read_logic(port_index_t port,logic_t *logic );
Std_ReturnType gpio_port_toggle_logic(port_index_t port );






#endif	/* HAL_GPIO_H */

