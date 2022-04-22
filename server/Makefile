CC = gcc
TARGET = chat-server
OBJS = server.o main.o

all : $(TARGET)

main.o: server.h server.c main.c
server.o: server.h

$(TARGET) : $(OBJS)
	$(CC) -o ../$(@) $(OBJS)

clean:
	@rm -f *.o
	@rm -f ../$(TARGET)

remake: clean all