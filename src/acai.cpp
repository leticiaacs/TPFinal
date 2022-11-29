#include "acai.hpp"

const float preco_Banana = 1.50;
const float preco_Granola = 1.50;
const float preco_Morango = 2.00;
const float preco_LeiteNinho = 2.50;
const float preco_LeiteCondensado = 2.50;

Acai::Acai(int tamanho, int quantidade)
{
    _tamanho = tamanho;
    _quantidade = quantidade; 
}

int Acai::getQuantidade()
{
    return _quantidade;
}

void Acai::adicionaComplemento(std::string nome)
{
    Complemento c = Complemento(nome);
    if(nome != "banana" && nome != "granola" && nome != "morango" && nome != "leite ninho" && nome != "leite condensado")
    {
        throw complementoInvalido();
    }
    _acrescimos.push_back(c);
}

void Acai::removeComplemento(std::string nome)
{   
    std::vector<Complemento>::iterator it;
    for(it = _acrescimos.begin(); it != _acrescimos.end(); it++)
    {
        if(it->Complemento::getNome() == nome)
        {
            _acrescimos.erase(it);
        }
        break;
    }
}

void Acai::removeComplementoIncorreto()
{
    _acrescimos.pop_back();
}

float Acai::calculaPreco() 
{
    float soma;

    std::vector<Complemento>::iterator it;
    for(it = _acrescimos.begin(); it != _acrescimos.end(); it++)
    {
        if(it->Complemento::getNome() == "banana")
            soma = soma + preco_Banana;
        else if(it->Complemento::getNome() == "granola")
            soma = soma + preco_Granola;
        else if(it->Complemento::getNome() == "morango")
            soma = soma + preco_Morango;
        else if(it->Complemento::getNome() == "leite ninho")
            soma = soma + preco_LeiteNinho;
        else if(it->Complemento::getNome() == "leite condensado")
            soma = soma + preco_LeiteCondensado;
    }
    return (soma + (_tamanho*0,025)) * _quantidade;
}

std::string Acai::descricao()
{
    std::string descricao;
    descricao = std::to_string(_quantidade);
    descricao = descricao + "\n";
    descricao = descricao + std::to_string(_tamanho);
    descricao = descricao + "\n";

    std::vector<Complemento>::iterator it;
    for(it = _acrescimos.begin(); it != _acrescimos.end(); it++)
    {
        descricao = descricao + it->Complemento::getNome();
        descricao = descricao + "\n";
    }
    return descricao;
}