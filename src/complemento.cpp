#include "complemento.hpp"

Complemento::Complemento(std::string nome) {

    _nome = nome;
}

std::string Complemento::getNome() {
    return _nome;
}

int Complemento::getPreco() {
    return _preco;
}