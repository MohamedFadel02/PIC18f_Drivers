/* 
 * File:   hal_gpio.c
 * Author: Mohamed Fadel
 * https://www.linkedin.com/in/mohamed-fadel-713898212/
 * Created on 18 ?????, 2023, 12:04 ?
 */
/*includes section*/
#include "hal_gpio.h"


/*Data types section*/
volatile uint8 *tris_registers[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8 *lat_registers[]={&LATA,&LATB,&LATC,&LATD,&LATE};
volatile uint8 *port_registers[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};

/*Macro declaration section*/

#define GPIO_PORT_PIN_CFG    CONFIG_ENABLE
#define GPIO_PORT_CFG    CONFIG_ENABLE


/**
 * 
 * @param pin_config
 * @return 
 */
#if (GPIO_PORT_PIN_CFG==CONFIG_ENABLE)
Std_ReturnType gpio_pin_direction_init(const pin_config_t * pin_config){
    Std_ReturnType ret =E_OK;
    if(NULL==pin_config || pin_config->pin > MAX_PIN-1)
    {
        ret=E_NOT_OK;
    }
    
    else{
        switch(pin_config->direction){
        
            case GPIO_OUTPUT:
                
                CLEAR_BIT(*tris_registers[pin_config->port],pin_config->pin);
                break;
            case GPIO_INPUT:
                
                SET_BIT(*tris_registers[pin_config->port],pin_config->pin);
                break;
            default: ret=E_NOT_OK;
        
        
        }
    
    
    }
    
    
    return ret;
}
#endif
/**
 * 
 * @param pin_config
 * @param dic_status
 * @return 
 */
#if (GPIO_PORT_PIN_CFG==CONFIG_ENABLE)
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t * pin_config,direction_t *dic_status ){ 
    
    Std_ReturnType ret =E_OK;
    if(NULL==pin_config || NULL==dic_status || pin_config->pin > MAX_PIN-1)
    {
        ret=E_NOT_OK;
    }
    
    else{
    
             * dic_status = READ_BIT(*tris_registers[pin_config->port],pin_config->pin);
  
    
    }
    
    
    return ret;
}
#endif
/**
 * 
 * @param pin_config
 * @param logic
 * @return 
 */
#if (GPIO_PORT_PIN_CFG==CONFIG_ENABLE)
Std_ReturnType gpio_pin_write_logic(const pin_config_t * pin_config,logic_t logic ){
    
    Std_ReturnType ret =E_OK;
    if(NULL==pin_config|| pin_config->pin > MAX_PIN-1)
    {
        ret=E_NOT_OK;
    }
    
    else{
         
        if(logic==GPIO_HIGH){
         logic=SET_BIT(*lat_registers[pin_config->port],pin_config->pin);
        }
        else if(logic==GPIO_LOW){
         logic= CLEAR_BIT(*lat_registers[pin_config->port],pin_config->pin);
        }
        else{
                ret=E_NOT_OK;
        }
    
        
    
    }
    
    
    return ret;
}
#endif
/**
 * 
 * @param pin_config
 * @param logic
 * @return 
 */
#if (GPIO_PORT_PIN_CFG==CONFIG_ENABLE)
Std_ReturnType gpio_pin_read_logic(const pin_config_t * pin_config,logic_t *logic ){
    
    Std_ReturnType ret =E_OK;
    if(NULL==pin_config || NULL==logic|| pin_config->pin > MAX_PIN-1)
    {
        ret=E_NOT_OK;
    }
    
    else{
    
           * logic =READ_BIT(*port_registers[pin_config->port],pin_config->pin);

    
    }
    
    
    return ret;
}
#endif
/**
 * 
 * @param pin_config
 * @return 
 */
#if (GPIO_PORT_PIN_CFG==CONFIG_ENABLE)
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t * pin_config ){
    
    Std_ReturnType ret =E_OK;
    if(NULL==pin_config|| pin_config->pin > MAX_PIN-1)
    {
        ret=E_NOT_OK;
    }
    
    else{
    
   TOGGLE_BIT(*port_registers[pin_config->port],pin_config->pin);
    
    }
    
    
    return ret;
}
#endif
/**
 * 
 * @param pin_config
 * @return 
 */
#if (GPIO_PORT_PIN_CFG==CONFIG_ENABLE)
Std_ReturnType gpio_pin_init(const pin_config_t * pin_config){
    Std_ReturnType ret =E_OK;
 if(NULL==pin_config|| pin_config->pin > MAX_PIN-1)
    {
        ret=E_NOT_OK;
    }
    
    else{
    gpio_pin_direction_init(pin_config);
    gpio_pin_write_logic(pin_config,pin_config->logic);
    
    
    }
    
    
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param direction
 * @return 
 */
#if (GPIO_PORT_CFG==CONFIG_ENABLE)
Std_ReturnType gpio_port_direction_init(port_index_t port,direction_t direction){
   Std_ReturnType ret =E_OK;
   if(port>MAX_PORT-1)
   {
   ret=E_NOT_OK;
   
   }
   else
   {
    *tris_registers[port]=direction;
   
   }
   return ret;
}
#endif
/**
 * 
 * @param port
 * @param dic_status
 * @return 
 */
#if (GPIO_PORT_CFG==CONFIG_ENABLE)
Std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8 *dic_status){
    
    Std_ReturnType ret =E_OK;
    if(NULL==dic_status && port>MAX_PORT-1)
    {
        ret=E_NOT_OK;
    }
    
    else{
    
    *dic_status=*tris_registers[port];
    
    }
    
    
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return 
 */
#if (GPIO_PORT_CFG==CONFIG_ENABLE)
Std_ReturnType gpio_port_write_logic(port_index_t port,logic_t logic ){
    Std_ReturnType ret =E_OK;
    if(port>MAX_PORT-1)
    {
        ret=E_NOT_OK;    
    }
    
    else{
    
        *lat_registers[port]=logic;
    
    }
    
    
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return 
 */
#if (GPIO_PORT_CFG==CONFIG_ENABLE)
Std_ReturnType gpio_port_read_logic(port_index_t port,logic_t *logic ){
    
   Std_ReturnType ret =E_OK;
    if(NULL==logic && port>MAX_PORT-1)
    {
        ret=E_NOT_OK;
    }
    
    else{
    
    *logic=*lat_registers[port];
    
    }
    
    
    return ret;
}
#endif
/**
 * 
 * @param port
 * @return 
 */
#if (GPIO_PORT_CFG==CONFIG_ENABLE)
Std_ReturnType gpio_port_toggle_logic(port_index_t port ){
    
     *lat_registers[port]^= 0xff;
}
#endif