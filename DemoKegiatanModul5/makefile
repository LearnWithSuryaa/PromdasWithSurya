# Nama program yang akan dihasilkan
TARGET = surya

# Compiler dan opsi kompilasi
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Direktori sumber dan objek
SRC_DIR = .
OBJ_DIR = obj

# File sumber
SRCS = main.c calculation.c input.c output.c utility.c

# File objek
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# File header
HEADERS = calculation.h input.h output.h utility.h

# Rule untuk membuat direktori objek jika belum ada
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rules untuk kompilasi objek
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule untuk membuat program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule untuk membersihkan objek dan executable
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Rule untuk menjalankan program
run: $(TARGET)
	./$(TARGET)

# Rule default
.PHONY: all clean run
all: $(TARGET)
