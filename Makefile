CC := g++
FLAGS := -I include/ -Wall -I third_party/ -Wall
BUILD := build/
SRC := src/
TEST := tests/
TARGET := main.out

all: main

sistema: usuario produto
	@mkdir build/sistema/
	$(CC) $(FLAGS) -c src/sistema.cpp -o build/sistema.o

usuario:
	@mkdir build/usuario/
	$(CC) $(FLAGS) -c src/usuario.cpp -o build/usuario.o

complemento:
	@mkdir build/complemento/
	$(CC) $(FLAGS) -c src/complemento.cpp -o build/complemento.o

produto:
	@mkdir build/produto/
	$(CC) $(FLAGS) -c src/produto.cpp -o build/produto.o

vitamina: produto
	@mkdir build/vitamina/
	$(CC) $(FLAGS) -c src/vitamina.cpp -o build/vitamina.o

acai: produto complemento
	@mkdir build/acai/
	$(CC) $(FLAGS) -c src/acai.cpp -o build/acai.o

carrinho: usuario produto
	@mkdir build/carrinho/
	$(CC) $(FLAGS) -c src/carrinho.cpp -o build/carrinho.o

main: sistema
	$(CC) $(FLAGS) build/sistema.o src/main.cpp -o $(TARGET)

clean: 
	$(RM) -r $(BUILDDIR)/* $(TARGET)
	