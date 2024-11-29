CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = main.o utility.o input.o output.o calculation.o
TARGET = surya

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

main.o: main.c utility.h input.h output.h calculation.h
	$(CC) $(CFLAGS) -c main.c

utility.o: utility.c utility.h
	$(CC) $(CFLAGS) -c utility.c

input.o: input.c input.h utility.h
	$(CC) $(CFLAGS) -c input.c

output.o: output.c output.h utility.h
	$(CC) $(CFLAGS) -c output.c

calculation.o: calculation.c calculation.h utility.h
	$(CC) $(CFLAGS) -c calculation.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)
