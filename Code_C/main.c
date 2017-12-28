
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include "lcd.h"
#include "getip.h"

// 47,1C


char* get_temp() 
{
	FILE* file; 
	size_t nread;	
	char* temp = malloc(8 * sizeof(char)); 

	file = fopen ("/sys/class/thermal/thermal_zone0/temp", "r");
		
	if(file)
	{
		while ((nread = fread(temp, 1 , sizeof temp, file)) > 0); 
		fwrite(temp, 1, nread, stdout);
	
    	if (ferror(file)) 
		{
      	printf("main.c : error while reading the temperature file"); 
			return "error"; 
		}
		else
		{
			printf("\nTempérature : %s \n", temp);
			return temp; 
		}
	}
	else 
	{		
   	printf("main.c : error while opening the temperature file"); 
	}	
}


int main()
{
	//char* ip_eth = get_ip_eth(); 
	char* ip_wlan = get_ip_wlan(); 
	 	
	i2c_lcd_init(LCD_ADDRS); 
	
	lcd_display_string(1, 0, "       R-A-M      "); 
	lcd_display_string(2, 0, "IPE:"); 
	lcd_display_string(3, 0, "IPW:"); 
//	lcd_display_string(2, 5, ip_eth); 
	lcd_display_string(3, 5, ip_wlan); 
	
char kerem[5] ="kerem";  
 
	lcd_display_string(4,0,get_temp()); 

	
  return 0; 
}
