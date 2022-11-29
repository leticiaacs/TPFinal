#include "complemento.hpp"

Complemento(float preco, std::string nome){

    _nome = nome;
}
std::string Complemento::getNome()
{
    return _nome;
}

int Complemento::getPreco()
{
    return _preco;
}