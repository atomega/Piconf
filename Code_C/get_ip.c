#include <stdio.h>
#include <unistd.h>
#include <string.h> /* for strncpy */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include "lcd.h"


int
main()
{
 int fd;
 struct ifreq ifr;

 fd = socket(AF_INET, SOCK_DGRAM, 0);

 /* I want to get an IPv4 IP address */
 ifr.ifr_addr.sa_family = AF_INET;

 /* I want IP address attached to "eth0" */
 strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);

 ioctl(fd, SIOCGIFADDR, &ifr);

 close(fd);

 /* display result */
char* ip_address = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr); 
 
printf("%s\n", ip_address);

int size = strlen(ip_address); 



printf("SIZE : %d \n", size ); 
	

 i2c_lcd_init(LCD_ADDRS); 
 lcd_display_string(1, 0, "       R-A-M        "); 
 lcd_display_string(2, 0, ip_address); 



 return 0;
}
