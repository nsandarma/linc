# Nama output executable
TARGET = LIBLINEAR

# Compiler yang digunakan
CC = gcc

# Opsi kompilasi
CFLAGS = -Wall -Wextra -std=c11

# Direktori untuk source code
SRCDIR = src

# File source code
SRC = $(wildcard $(SRCDIR)/*c)

# Object files yang dihasilkan
OBJ = $(SRC:.c=.o)

# Target default, akan dijalankan jika tidak ada target spesifik yang diberikan
all: $(TARGET)

# Proses linking untuk membuat executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

# Kompilasi file .c menjadi .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Membersihkan file objek dan executable
clean:
	rm -f $(OBJ) $(TARGET)

# Phony target untuk memastikan clean dan all tidak bentrok dengan file bernama sama
.PHONY: clean all
