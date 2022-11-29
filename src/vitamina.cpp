#include "vitamina.hpp"

const float sabor_Acai = 1.50;
const float sabor_Banana = 0.50;
const float sabor_Morango = 1.00;
const float sabor_Abacaxi = 0.50;

Vitamina::Vitamina(int tamanho, std::string sabor)
{
    _tamanho = tamanho;
    _sabor = sabor;
}

int Vitamina::getQuantidade()
{
    return _quantidade;
}

std::string Vitamina::getSabor()
{
    return _sabor;
}

void Vitamina::adicionaSabor(std::string s)
{
    if(s != "açaí" && s != "banana" && s != "morango" && s != "abacaxi")
    {
        throw saborInvalido();
    }
    _saboresVitamina.push_back(s);
}

void Vitamina::removeSabor(std::string s)
{
    _saboresVitamina.pop_back();
}

float Vitamina::calculaPreco()
{
    float soma;

    std::vector<std::string>::iterator it;
    for(it = _saboresVitamina.begin(); it != _saboresVitamina.end(); it++)
    {
        if(*it == "açaí")
            soma = soma + sabor_Acai;
        else if(*it == "banana")
            soma = soma + sabor_Banana;
        else if(*it == "morango")
            soma = soma + sabor_Morango;
        else if(*it == "abacaxi")
            soma = soma + sabor_Abacaxi;
        else
            throw saborInvalido();
    }
    return (soma + (_tamanho*0,015)) * _quantidade;
}

std::string Vitamina::descricao()
{
    std::string descricao;
    descricao = std::to_string(_quantidade);
    descricao = descricao + "\n";
    descricao = descricao + std::to_string(_tamanho);
    descricao = descricao + "\n";

    std::vector<std::string>::iterator it;
    for(it = _saboresVitamina.begin(); it != _saboresVitamina.end(); it++)
    {
        descricao = descricao + *it;
        descricao = descricao + "\n";
    }
    return descricao;
}