

CC=gcc 
CFLAGS= -Wall -pedantic 
LDFLAGS= 
EXEC= runlcd


all : $(EXEC)

$(EXEC): main.o i2c.o lcd.o getip.o 
	$(CC) -o $(EXEC) main.o i2c.o lcd.o getip.o $(LDFLAGS)

main.o: main.c
	$(CC) -o main.o -c main.c $(CFLAGS)

i2c.o: i2c.c
	$(CC) -o i2c.o -c i2c.c $(CFLAGS)

lcd.o: i2c.c
	$(CC) -o lcd.o -c lcd.c $(CFLAGS)

getip.o: getip.c
	$(CC) -o getip.o -c getip.c $(CFLAGS)

clean: 
	rm -rf *.o

cleanall: 
	rm -rf *.o $(EXEC)
