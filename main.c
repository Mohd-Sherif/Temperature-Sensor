/*
 * ADC_Project_negative_temperature.c
 *
 * Created: 04-Jul-22 8:36:27 PM
 * Author : Mohamed Sherif
 */ 

#include "HAL/LCD.h"
#include "MCAL/ADC.h"

int main(void)
{
	unsigned short temperature,volt_mV;
    LCD_vinit();
	ADC_vinit();
	LCD_vsend_string("Temp=");
    while (1) 
    {
		volt_mV=ADC_u16read()*2.5;
		LCD_vmove_cursor(1,6);
		if(volt_mV>=1000){
			temperature=(volt_mV-1000)/10;
			if(temperature<10){
				LCD_vsend_char(temperature+48);
				LCD_vsend_char(0xDF);
				LCD_vsend_char('C');
				LCD_vsend_char(0x20);
			}
			else if(temperature<100){
				LCD_vsend_char((temperature/10)+48);
				LCD_vsend_char((temperature%10)+48);
				LCD_vsend_char(0xDF);
				LCD_vsend_char('C');
				LCD_vsend_char(0x20);
			}
			else{
				LCD_vsend_char((temperature/100)+48);
				LCD_vsend_char(((temperature%100)/10)+48);
				LCD_vsend_char((temperature%10)+48);
				LCD_vsend_char(0xDF);
				LCD_vsend_char('C');
				LCD_vsend_char(0x20);
			}
		}
		else{
			LCD_vsend_char('-');
			temperature=(1000-volt_mV)/10;
			if(temperature<10){
				LCD_vsend_char(temperature+48);
				LCD_vsend_char(0xDF);
				LCD_vsend_char('C');
				LCD_vsend_char(0x20);
			}
			else if(temperature<100){
				LCD_vsend_char((temperature/10)+48);
				LCD_vsend_char((temperature%10)+48);
				LCD_vsend_char(0xDF);
				LCD_vsend_char('C');
				LCD_vsend_char(0x20);
			}
			else{
				LCD_vsend_char((temperature/100)+48);
				LCD_vsend_char(((temperature%100)/10)+48);
				LCD_vsend_char((temperature%10)+48);
				LCD_vsend_char(0xDF);
				LCD_vsend_char('C');
				LCD_vsend_char(0x20);
			}
		}
    }
}
