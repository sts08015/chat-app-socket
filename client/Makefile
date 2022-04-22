CC = gcc
TARGET = chat-client
OBJS = client.o main.o

all : $(TARGET)

main.o: client.h client.c main.c
client.o: client.h

$(TARGET) : $(OBJS)
	$(CC) -o ../$(@) $(OBJS)

clean:
	@rm -f *.o
	@rm -f ../$(TARGET)

remake: clean all