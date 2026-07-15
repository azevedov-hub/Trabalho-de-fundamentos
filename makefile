CC = gcc
FLAGS = -Wall

all: main

main: main.o condutor.o arquivo.o relatorio.o veiculo.o cotacaox.o menu.o
	$(CC) $(FLAGS) -o main main.o condutor.o arquivo.o relatorio.o veiculo.o cotacaox.o menu.o

main.o: main.c condutor.h arquivo.h relatorio.h veiculo.h cotacaox.h menu.h 
	$(CC) $(FLAGS) -c main.c

condutor.o: condutor.c condutor.h 
	$(CC) $(FLAGS) -c condutor.c

arquivo.o: arquivo.c arquivo.h
	$(CC) $(FLAGS) -c arquivo.c

relatorio.o: relatorio.c relatorio.h improviso.h
	$(CC) $(FLAGS) -c relatorio.c

veiculo.o: veiculo.c veiculo.h
	$(CC) $(FLAGS) -c veiculo.c

cotacaox.o: cotacaox.c cotacaox.h
	$(CC) $(FLAGS) -c cotacaox.c

menu.o: menu.c menu.h
	$(CC) $(FLAGS) -c menu.c

clean:
	rm -f *.o main