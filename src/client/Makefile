CC = gcc
TARGET = chat-client
OBJS = ../chat.o client.o main.o

all : $(TARGET)

main.o: ../chat.h ../chat.c client.h client.c main.c
client.o: ../chat.h ../chat.c client.h

$(TARGET) : $(OBJS)
	$(CC) -o ../$(@) $(OBJS)

clean:
	@rm -f *.o
	@rm -f ../$(TARGET)