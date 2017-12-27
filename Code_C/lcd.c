#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

#include "lcd.h"
#include "i2c.h"

int i2c_lcd_init(int addrs)
{
	i2c_open_device(addrs);
	
	i2c_write_16(addrs,0 ,12); 

}
/*			
	if(addrs >= 0)
	{
		lcd_cmd_write (addrs, 0x03);		
		lcd_cmd_write (addrs, READ_WRITE); // find out whta it is		
		lcd_cmd_write (addrs, LCD_FUNCTIONSET 		| LCD_2LINE 		| LCD_5x8DOTS 	| LCD_4BITMODE	); 
		lcd_cmd_write (addrs, LCD_DISPLAYCONTROL 	| LCD_DISPLAYON											); 
		lcd_cmd_write (addrs, LCD_CLEARDISPLAY																		); 
		lcd_cmd_write (addrs, LCD_ENTRYMODESET 	| LCD_ENTRYLEFT											); 
		printf("\nINITIALIZATION WAS SUCCESFULL\n"); 			

		return 1; 
	}

	else 
	{
		printf("\nINITIALIZATION FAILED\n"); 			
			
		return 0; 
	}
}



void lcd_putc(unsigned char line, unsigned char collon, unsigned char)
{
		
}


void lcd_cmd_write(unsigned char value, unsigned char mode) {
	
	unsigned char highnib=value&0xf0;
	unsigned char lownib	=(value<<4)&0xf0;
   write4bits((highnib)|mode);
	write4bits((lownib)|mode); 
}

void write4bits(unsigned char value) {
	expanderWrite(value);
	pulseEnable(value);
}

void expanderWrite(unsigned char data){                                        
	
	i2c_writeii_8( | _backlightval);
	Wire.endTransmission();   
}
*/

int main (void)
{
 	printf("\n\nTESTIND THE LCD\n");
	i2c_lcd_init(0x27);  
	exit(1);  
}

