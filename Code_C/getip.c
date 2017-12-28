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
#include "getip.h"

char* get_ip_eth() 
{
 	int fd;
 	struct ifreq ifr;
	char* ip_address; 
 	
	fd = socket(AF_INET, SOCK_DGRAM, 0);
 	ifr.ifr_addr.sa_family = AF_INET;  // I want to get an IPv4 IP address 
 	strncpy(ifr.ifr_name, ETH_INTERFACE, IFNAMSIZ-1); // I want IP address attached to "eth0"
 	ioctl(fd, SIOCGIFADDR, &ifr);
 	close(fd);
	
	ip_address = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr); 
	printf("%s\n", ip_address);
 	
	return ip_address;
}


char* get_ip_wlan() 
{
 	int fd;
 	struct ifreq ifr;
	char* ip_address; 
 	
	fd = socket(AF_INET, SOCK_DGRAM, 0);
 	ifr.ifr_addr.sa_family = AF_INET;  // I want to get an IPv4 IP address 
 	strncpy(ifr.ifr_name, WLAN_INTERFACE, IFNAMSIZ-1); // I want IP address attached to "eth0"
 	ioctl(fd, SIOCGIFADDR, &ifr);
 	close(fd);
	
	ip_address = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr); 
	printf("%s\n", ip_address);
 	
	return ip_address;
}
