BISON_FILE = sintatico_novo.y

LEX_FILE = lexico.l

HELPER_SOURCES = arvore.c symbol_table.c erros.c

EXECUTABLE = compilador

CC = gcc

#flags do bison
BISON_FLAGS = -d -v

#flags do flex
FLEX_FLAGS =

CFLAGS = -g -Wall -I.

# bibliotecas ( -lfl para Flex )
LIBS = -lfl

BISON_C_OUT = $(BISON_FILE:.y=.tab.c)
BISON_H_OUT = $(BISON_FILE:.y=.tab.h)
LEX_C_OUT = lex.yy.c

.PHONY: all clean

all: $(EXECUTABLE)


$(EXECUTABLE): $(BISON_C_OUT) $(LEX_C_OUT) $(HELPER_SOURCES)
	@echo "--- [GCC] Compilando tudo junto: $^"
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BISON_C_OUT) $(BISON_H_OUT): $(BISON_FILE)
	@echo "--- [BISON] Gerando parser..."
	bison $(BISON_FLAGS) $(BISON_FILE)

$(LEX_C_OUT): $(LEX_FILE) $(BISON_H_OUT)
	@echo "--- [FLEX] Gerando lexer..."
	flex $(FLEX_FLAGS) -o $(LEX_C_OUT) $(LEX_FILE)

clean:
	@echo "--- [CLEAN] Limpando bagunça..."
	rm -f $(EXECUTABLE) $(BISON_C_OUT) $(BISON_H_OUT) $(LEX_C_OUT) *.o *.output