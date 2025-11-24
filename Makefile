# ===================================================================
# Makefile Atualizado para Compilador Modular (Flex/Bison + C)
# ===================================================================

# --- 1. Variáveis de Configuração ---

# O nome do seu arquivo Bison (.y)
BISON_FILE = sintatico_novo.y

# O nome do seu arquivo Flex (.l)
LEX_FILE = lexico.l

# --- !!! ATENÇÃO AQUI !!! ---
# Liste aqui os seus arquivos .c extras separados por espaço.
# Exemplo: HELPER_SOURCES = arvore.c tabela.c util.c
HELPER_SOURCES = arvore.c symbol_table.c 

# O nome que você quer para o seu programa final
EXECUTABLE = compilador

# --- 2. Compilador e Flags ---
CC = gcc

# Flags do Bison (-d cria o .h, -v cria o .output para debug de conflitos)
BISON_FLAGS = -d -v

# Flags do Flex
FLEX_FLAGS =

# Flags do GCC 
# -g: Debug (para usar gdb ou valgrind)
# -Wall: Mostra todos os avisos (importante!)
# -I.: Procura arquivos .h no diretório atual
CFLAGS = -g -Wall -I.

# Bibliotecas ( -lfl para Flex )
LIBS = -lfl

# --- 3. Nomes de Arquivos Gerados (Automático) ---
BISON_C_OUT = $(BISON_FILE:.y=.tab.c)
BISON_H_OUT = $(BISON_FILE:.y=.tab.h)
LEX_C_OUT = lex.yy.c

# ===================================================================
# 4. Regras do Makefile
# ===================================================================

.PHONY: all clean

all: $(EXECUTABLE)

# Regra Principal: Gera o executável
# Agora depende também dos $(HELPER_SOURCES)
$(EXECUTABLE): $(BISON_C_OUT) $(LEX_C_OUT) $(HELPER_SOURCES)
	@echo "--- [GCC] Compilando tudo junto: $^"
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Regra do Bison
$(BISON_C_OUT) $(BISON_H_OUT): $(BISON_FILE)
	@echo "--- [BISON] Gerando parser..."
	bison $(BISON_FLAGS) $(BISON_FILE)

# Regra do Flex
$(LEX_C_OUT): $(LEX_FILE) $(BISON_H_OUT)
	@echo "--- [FLEX] Gerando lexer..."
	flex $(FLEX_FLAGS) -o $(LEX_C_OUT) $(LEX_FILE)

# Regra de Limpeza
clean:
	@echo "--- [CLEAN] Limpando bagunça..."
	rm -f $(EXECUTABLE) $(BISON_C_OUT) $(BISON_H_OUT) $(LEX_C_OUT) *.o *.output