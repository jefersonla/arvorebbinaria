# 2º Trabalho de Estrutura de Dados
# Makefile para compilação da atividade
#
# Obs.: Este makefile é apenas para linkagem da biblioteca
#		arvore, evitando assim erros de compilação

# Compilador a ser usado
CC = mingw32-gcc

all: trabalho

trabalho: main.o arvore.o
	$(CC) main.o arvore.o -o trabalho

main.o: main.c
	$(CC) -c main.c

arvore.o: arvore.c
	$(CC) -c arvore.c 

clean:
	rm -rf *o hello 