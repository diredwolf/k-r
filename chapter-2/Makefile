CC := clang
CFLAGS :=  -O0 -std=c89 -Wall -Wextra -Werror -Wformat=2 -Wunused-variable -Wno-implicit-int -Wno-return-type -pedantic
BIN := exe/

.PHONY: all clean

all:
	$(CC) $(CFLAGS) exercise-2-1.c -o $(BIN)exercise-2-1.exe
	$(CC) $(CFLAGS) exercise-2-2.c -o $(BIN)exercise-2-2.exe
	$(CC) $(CFLAGS) exercise-2-3.c -o $(BIN)exercise-2-3.exe
	$(CC) $(CFLAGS) exercise-2-4.c -o $(BIN)exercise-2-4.exe
	$(CC) $(CFLAGS) exercise-2-5.c -o $(BIN)exercise-2-5.exe
	$(CC) $(CFLAGS) exercise-2-6.c -o $(BIN)exercise-2-6.exe
	$(CC) $(CFLAGS) exercise-2-7.c -o $(BIN)exercise-2-7.exe
	$(CC) $(CFLAGS) exercise-2-8.c -o $(BIN)exercise-2-8.exe
	$(CC) $(CFLAGS) exercise-2-9.c -o $(BIN)exercise-2-9.exe
	$(CC) $(CFLAGS) exercise-2-10.c -o $(BIN)exercise-2-10.exe

clean:
	rm exe/*
