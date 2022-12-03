# Configuration
PROGRAM = robot
MCU = atmega328p
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -Wall -I. -g -Os -mmcu=$(MCU) -DF_CPU=16000000UL

# Source files
DEPS = config.h 
OBJS = main.o utils.o libmotor/l298n_dc_motor.o

all: $(PROGRAM).hex

$(PROGRAM).hex: $(PROGRAM).elf
	$(OBJCOPY) -O ihex $< $@

$(PROGRAM).elf: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

flash:
	avrdude -v -p$(MCU) -carduino -P$(PORT) -b57600 -D -Uflash:w:$(PROGRAM).hex:i

clean:
	rm -f $(OBJS) $(PROGRAM).elf $(PROGRAM).hex