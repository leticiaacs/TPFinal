#include <iostream>
#include "produto.hpp"

float Produto::getPreco() const{

    return this->_preco;
}

int Produto::getTamanho() const{

    return this->_tamanho;
}