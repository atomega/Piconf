// ///////////////////////////////////////////////////////
// Created by 	: Kerem Yollu												
//	Project 		: Multiprise conectée
//	Date 			: 27.12.2017
//			
//_________________________Info_________________________
//
// Header pour I2C.c ecrit pour l'utilisation du protocol 
// I2C avec une raspberry PI 3 
//
// ///////////////////////////////////////////////////////

#include "i2c.h"




int fd = 0; 																		// File description (pour suivre létat du port i2c) 
char buf[24]; 	
char current_dev_id = 0;


void i2c_open_device( int address )
{
	char *fileName = PORT_I2C;													// Nom du port I2C a etre tuilisé 
	
	if ((fd = open(fileName, O_RDWR)) < 0)		 							// Ouverture du port pour le lecture et l'écriture 
	{							
		printf("Failed to open i2c port\n");
		exit(1); 
	}

	if (ioctl(fd, I2C_SLAVE, address) < 0) {								// mise en place de l'otion du port (SLAVE) et l'addresse de l'esclave avec qui nou aimerion parler								
		printf("Unable to get bus access to talk to slave\n");
		exit(1); 
	}
	else 
	{
		buf[0] = 0;																		// This is the register we want to read from
		current_dev_id = address; 
	}
	
} 


int i2c_write_8(char data)
{
	buf[0] = data; 
	if ((write(fd, buf, 1)) != 1) 
	{	
//		printf("\nError writing : 8 bits \n");
//		printf("Data  \t : 0x%x \n", buf[0] & 0xff); 
//		printf("To Slave : 0x%x \n \n", current_dev_id & 0xff);  
		return 1; 
	}
	else 
	{
		
//		printf("\nWiriting Succesfull : 8 bits \n");
//		printf("Data  \t : 0x%x \n", buf[0] & 0xff); 
//		printf("To Slave : 0x%x \n \n", current_dev_id & 0xff);  
		return 0; 
	}
	
	return 1; 
}


int i2c_write_16(char reg, char data)
{
	buf[0] = reg; 
	buf[1] = data; 
	if ((write(fd, buf, 2)) != 2) 
	{														
//		printf("\nError writing : 16 bits \n");
//		printf("Data 1 \t : 0x%x \n", buf[0] & 0xff); 
//		printf("data 2 \t : 0x%x \n", buf[1] & 0xff);
//		printf("To Slave : 0x%x \n \n", current_dev_id & 0xff);  
		return 1; 
	}	
	else 
	{
		
//		printf("\nWiriting Succesfull : 16 bits \n");
//		printf("Data 1 \t : 0x%x \n", buf[0] & 0xff); 
//		printf("data 2 \t : 0x%x \n", buf[1] & 0xff);
//		printf("To Slave : 0x%x \n \n", current_dev_id & 0xff);  
		return 0; 
	}
	
	return 1; 
}

