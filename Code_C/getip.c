#include <stdio.h>
#include <unistd.h>
#include <string.h> /* for strncpy */
#include <netdb.h>
#include <ifaddrs.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include "getip.h"
#include "lcd.h"



void get_ip_eth() 
{
    struct ifaddrs *ifaddr, *ifa;
    int s;
    char host[NI_MAXHOST];
	  
    if (getifaddrs(&ifaddr) == -1) 
    {
        printf("getip.c : getifaddrs error");
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) 
    {
        if (ifa->ifa_addr == NULL)
            continue;  

        s=getnameinfo(ifa->ifa_addr,sizeof(struct sockaddr_in),host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

        if((strcmp(ifa->ifa_name,"eth0")==0)&&(ifa->ifa_addr->sa_family==AF_INET))
        {
            if (s != 0)
            {
                printf("getip.c : getnameinfo() failed: %s\n", gai_strerror(s));
            }
				 
				lcd_display_string(2, 0, "IPE:"); 
				lcd_display_string(2, 5, host); 
            printf("\tInterface : <%s>\n",ifa->ifa_name );
            printf("\t  Address : <%s>\n", host); 
        }
    }
}


void get_ip_wlan() 
{
    struct ifaddrs *ifaddr, *ifa;
    int s;
    char host[NI_MAXHOST];

    if (getifaddrs(&ifaddr) == -1) 
    {
        printf("getip.c : getifaddrs error");
    }


    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) 
    {
        if (ifa->ifa_addr == NULL)
            continue;  

        s=getnameinfo(ifa->ifa_addr,sizeof(struct sockaddr_in),host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

        if((strcmp(ifa->ifa_name,"wlan0")==0)&&(ifa->ifa_addr->sa_family==AF_INET))
        {
            if (s != 0)
            {
                printf("getip.c : getnameinfo() failed: %s\n", gai_strerror(s));
            }
				lcd_display_string(3, 0, "IPW:"); 
				lcd_display_string(3, 5, host); 
            printf("\tInterface : <%s>\n",ifa->ifa_name );
            printf("\t  Address : <%s>\n", host); 
        }
    }

}
