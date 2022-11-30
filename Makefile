CC := g++
FLAGS := -I include/ -Wall -I third_party/ -Wall
BUILD := build/
SRC := src/
TEST := tests/
TARGET := main.out

all: main

sistema: usuario produto
	$(CC) $(FLAGS) -c src/sistema.cpp -o build/sistema.o

usuario:
	$(CC) $(FLAGS) -c src/usuario.cpp -o build/usuario.o

complemento:
	$(CC) $(FLAGS) -c src/complemento.cpp -o build/complemento.o

produto:
	$(CC) $(FLAGS) -c src/produto.cpp -o build/produto.o

vitamina: produto
	$(CC) $(FLAGS) -c src/vitamina.cpp -o build/vitamina.o

acai: produto complemento
	$(CC) $(FLAGS) -c src/acai.cpp -o build/acai.o

carrinho: usuario produto
	$(CC) $(FLAGS) -c src/carrinho.cpp -o build/carrinho.o

main: sistema usuario carrinho produto acai vitamina complemento produto
	$(CC) $(FLAGS) build/sistema.o build/usuario.o build/carrinho.o build/produto.o build/acai.o build/vitamina.o build/complemento.o build/produto.o src/main.cpp -o $(TARGET)