

CC=gcc 
CFLAGS= -Wall -pedantic 
LDFLAGS= 
EXEC= runlcd


all : $(EXEC)

$(EXEC): i2c.o lcd.o get_ip.o 
	$(CC) -o $(EXEC) i2c.o lcd.o get_ip.o $(LDFLAGS)


i2c.o: i2c.c
	$(CC) -o i2c.o -c i2c.c $(CFLAGS)

lcd.o: i2c.c
	$(CC) -o lcd.o -c lcd.c $(CFLAGS)

get_ip.o: get_ip.c
	$(CC) -o get_ip.o -c get_ip.c $(CFLAGS)

clean: 
	rm -rf *.o

cleanall: 
	rm -rf *.o $(EXEC)
