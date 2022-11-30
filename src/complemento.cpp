#include <string>

#include "complemento.hpp"


Complemento::Complemento(std::string nome, float preco) {

    _nome = nome;
	_preco = preco;
}

std::string Complemento::getNome() {
    return _nome;
}

int Complemento::getPreco() {
    return _preco;
}