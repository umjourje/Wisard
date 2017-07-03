# Universidade Federal do Rio de Janeiro
# Programa de Engenharia em Sistemas de Computacao
# Author: Juliana Fernandes Dal Piaz
# Date: 03/07/2017


CC = gcc
LD = gcc

CFLAGS = -Wall
LFLAGS = -Wall -O3
MFLAGS = -lm


# Dependencias
RAMOBJS = ram.o
DISCRIMINATOROBJS = discriminator.o
WISARDOBJS = wisard.o
MAINOBJS = ram.o discriminator.o wisard.o main.o



# Executaveis
EXECS = teste
        

# Regras implicitas para execucao
.c.o:
	$(CC) $(CFLAGS) $(MFLAGS) -c $<

all: $(EXECS)


teste: $(MAINOBJS)
	$(LD) -o $@ $(MAINOBJS) $(LFLAGS) $(MFLAGS) 



clean:
	rm -f *.o $(EXECS)

