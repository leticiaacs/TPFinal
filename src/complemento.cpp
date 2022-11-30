#include "complemento.hpp"
#include "usuario.hpp"
#include "sistema.hpp"
#include "produto.hpp"
#include "carrinho.hpp"
#include "acai.hpp"
#include "vitamina.hpp"

Complemento::Complemento(std::string nome) {

    _nome = nome;
}

std::string Complemento::getNome() {
    return _nome;
}

int Complemento::getPreco() {
    return _preco;
}