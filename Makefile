# Makefile para Analisador Léxico 

LEX = flex
CC = gcc
CFLAGS = -Wall
TARGET = lex
SRC = lexico.l
OUT = lex.yy.c

all: $(TARGET)

$(TARGET): $(OUT)
	$(CC) $(CFLAGS) $(OUT) -o $(TARGET) -lfl

$(OUT): $(SRC)
	$(LEX) $(SRC)

run: $(TARGET)
	./$(TARGET) < teste.rascal

clean:
	rm -f $(OUT) $(TARGET)
