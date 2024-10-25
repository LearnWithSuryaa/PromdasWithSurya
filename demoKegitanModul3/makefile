# Nama program
TARGET = surya

# Compiler
CC = gcc

# Flags untuk compiler
CFLAGS = -Wall -g

# Daftar file sumber
SRCS = main.c bioskop.c

# Daftar file objek
OBJS = $(SRCS:.c=.o)

# Rule untuk membuat target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule untuk membuat file objek
%.o: %.c bioskop.h
	$(CC) $(CFLAGS) -c $<

# Rule untuk membersihkan file objek dan executable
sapu:
	rm -f $(OBJS) $(TARGET)