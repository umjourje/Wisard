Universidade Federal do Rio de Janeiro
Federal University of Rio de Janeiro

PESC/COPPE
Instituto Alberto Luiz Coimbra de Pós-Graduação e Pesquisa de Engenharia (COPPE)
Programa de Engenharia em Sistemas de Computação (PESC)


Author/ Autora: Juliana Fernandes Dal Piaz
Professor / Orientador: Felipe Maia Galvão França - PESC/COPPE

# Wisard

My BackUP for Wisard implementations. Still learning about it!


Compilando a WiSARD:

/Wisard_GitHub
gcc discriminator.c ram.c wisard.c main.c -o vteste -Wall -O1 -lm

Teste de 'Vazamentos':
valgrind --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./nomeDoTeste

Teste de Proximidade do ARduino:

