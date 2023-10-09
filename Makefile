CC = gcc
CFLAGS = -Wall
LIBS = -lraylib
TARGET = rk4-demo

all: rk4-demo

release:
	$(CC) -O3 -o $(TARGET) $(CFLAGS) $(LIBS) $(TARGET).c
	
rk4-demo:
	$(CC) -o $(TARGET) $(CFLAGS) $(LIBS) $(TARGET).c

clear:
	rm $(TARGET)
