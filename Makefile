# ===================================================================
# Makefile para Compilador Flex/Bison
# ===================================================================

# --- Variáveis de Configuração ---
# Altere estes nomes para bater com os seus arquivos

# O nome do seu arquivo Bison (.y)
BISON_FILE = sintatico_novo.y

# O nome do seu arquivo Flex (.l)
LEX_FILE = lexico.l

# O nome que você quer para o seu programa final
EXECUTABLE = compilador

# --- Compilador e Flags ---
# Compilador C
CC = gcc

# Flags do Bison ( -d cria o arquivo .h de cabeçalho)
BISON_FLAGS = -d

# Flags do Flex
FLEX_FLAGS =

# Flags do Compilador ( -g para debug, -Wall para mostrar todos os avisos)
CFLAGS = -g -Wall

# Bibliotecas necessárias ( -lfl é a biblioteca do Flex)
LIBS = -lfl

# --- Nomes de Arquivos Gerados (Automático) ---
# Não precisa mexer aqui
BISON_C_OUT = $(BISON_FILE:.y=.tab.c)
BISON_H_OUT = $(BISON_FILE:.y=.tab.h)
LEX_C_OUT = lex.yy.c


# ===================================================================
# Regras do Makefile
# ===================================================================

# A regra 'all' é a padrão. 
# Quando você digitar 'make', ele tentará construir o EXECUTABLE.
.PHONY: all
all: $(EXECUTABLE)

# Regra para construir o executável final
# Depende dos arquivos .c gerados pelo Flex e Bison.
$(EXECUTABLE): $(BISON_C_OUT) $(LEX_C_OUT)
	@echo "--- [GCC] Compilando e linkando: $@"
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Regra para gerar o analisador sintático (Bison)
# Esta regra gera DOIS arquivos: .tab.c e .tab.h
# Depende do arquivo .y original
$(BISON_C_OUT) $(BISON_H_OUT): $(BISON_FILE)
	@echo "--- [BISON] Gerando analisador sintático: $(BISON_C_OUT) e $(BISON_H_OUT)"
	bison $(BISON_FLAGS) $(BISON_FILE)

# Regra para gerar o analisador léxico (Flex)
# Depende do arquivo .l E, crucialmente, do .h gerado pelo Bison.
$(LEX_C_OUT): $(LEX_FILE) $(BISON_H_OUT)
	@echo "--- [FLEX] Gerando analisador léxico: $(LEX_C_OUT)"
	flex $(FLEX_FLAGS) -o $(LEX_C_OUT) $(LEX_FILE)

# Regra 'clean' para limpar todos os arquivos gerados
# Permite que você "limpe" o diretório para recompilar do zero
.PHONY: clean
clean:
	@echo "--- [CLEAN] Limpando arquivos gerados..."
	rm -f $(EXECUTABLE) $(BISON_C_OUT) $(BISON_H_OUT) $(LEX_C_OUT) *.o