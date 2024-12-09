# Nama program yang akan dihasilkan
TARGET = surya

# Compiler dan opsi kompilasi
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Direktori sumber dan objek
SRC_DIR = .
OBJ_DIR = obj

# File sumber
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/fungsi.c $(SRC_DIR)/utils.c

# File objek
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# File header
HEADERS = $(SRC_DIR)/fungsi.h $(SRC_DIR)/utils.h

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
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET)
