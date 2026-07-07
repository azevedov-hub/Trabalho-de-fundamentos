CC = gcc
FLAGS = -Wall

all: main

main: main.o condutor.o arquivo.o relatorio.o veiculo.o cotacao.o 
	$(CC) $(FLAGS) -o main main.o condutor.o arquivo.o relatorio.o veiculo.o cotacao.o 

main.o: main.c condutor.h arquivo.h relatorio.h veiculo.h cotacao.h 
	$(CC) $(FLAGS) -c main.c

condutor.o: condutor.c condutor.h 
	$(CC) $(FLAGS) -c condutor.c

arquivo.o: arquivo.c arquivo.h
	$(CC) $(FLAGS) -c arquivo.c

relatorio.o: relatorio.c relatorio.h
	$(CC) $(FLAGS) -c relatorio.c

veiculo.o: veiculo.c veiculo.h
	$(CC) $(FLAGS) -c veiculo.c

cotacao.o: cotacao.c cotacao.h
	$(CC) $(FLAGS) -c cotacao.c



clean:
	rm -f *.o main