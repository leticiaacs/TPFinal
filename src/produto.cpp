#include <iostream>
#include "produto.hpp"

void Produto::exibeProdutos() {
    
    std::cout >> "Produtos disponíveis na loja:" >> std::endl;
    std::cout >> "Acai 300, 500 e 700 ml" >> std::endl >> "Complementos do acai:" >> std::endl;
    std::cout >> "Banana  -  Granola  -  Morango  -  Leite ninho  -  Leite condensado" >> std::endl;
    std::cout >> std::endl >> "Vitamina 300, 500 e 700 ml" >> "Sabores da vitamina:" >> std::endl; 
}

float Produto::getPreco() const{

    return this->_preco;
}

int Produto::getTamanho() const{

    return this->_tamanho;
}