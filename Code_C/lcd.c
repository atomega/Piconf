#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/time.h>
#include "lcd.h"
#include "i2c.h"



int i2c_lcd_init(int addrs)
{
	i2c_open_device(addrs);
	lcd_write(0x03,CMD_MODE); 
 	lcd_write(0x03,CMD_MODE); 
  	lcd_write(0x03,CMD_MODE); 
	lcd_write(0x02,CMD_MODE);  
	lcd_write(LCD_FUNCTIONSET | LCD_2LINE | LCD_5x8DOTS | LCD_4BITMODE ,CMD_MODE); 
	lcd_write(LCD_DISPLAYCONTROL | LCD_DISPLAYON ,CMD_MODE); 
	lcd_write(LCD_CLEARDISPLAY ,CMD_MODE); 
	lcd_write(LCD_ENTRYMODESET | LCD_ENTRYLEFT ,CMD_MODE); 
	return 1; 				
}


void lcd_write_char( char charvalue)
{	
	lcd_write_4bits(CHAR_MODE | (charvalue & 0xF0)); 
  	lcd_write_4bits(CHAR_MODE | ((charvalue << 4) & 0xF0)); 	
}

 
void lcd_display_string(char line, char pos, char* charvalue)
{
	char setPosition = 0;	
	int i, S_length = 0; 
	char buf[60];  
	strcpy(buf, charvalue);								// Copty string into buffer with space at start for command byte	

	S_length	= strlen(buf); 	

	if(line == 1)
	{
		setPosition = pos; 		
	}
	else if(line ==2)
	{
		setPosition = 0x40 + pos; 
	}
	else if(line ==3)
	{
		setPosition = 0x14 + pos;
	}
	else if(line ==4)
	{
		setPosition = 0x54 + pos; 
	}
	else 
	{
		printf("\nLCD : the number of line specified are incorrect\n"); 
		exit(1); 
	}
	
	lcd_write(LCD_SETDDRAMADDR + setPosition, CMD_MODE);

	for(i = 0; i < S_length; i++ )
	{
		lcd_write(buf[i],RS); 
	}
}


void ldc_pulse_En(char data)
{
	i2c_write_8(data | EN | LCD_BACKLIGHT);
	usleep(100);  
	i2c_write_8(((data & ~EN) | LCD_BACKLIGHT));
	usleep(500);  
}


void lcd_write(char cmd, char mode)
{
	lcd_write_4bits(mode | (cmd & 0xF0)); 
  	lcd_write_4bits(mode | ((cmd << 4) & 0xF0)); 	
}

void lcd_write_4bits(char data)
{	
	i2c_write_8(data | LCD_BACKLIGHT);
	ldc_pulse_En(data); 
}
