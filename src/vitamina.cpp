#include <iostream>
#include <vector>
#include <string>
#include "vitamina.hpp"
#include "usuario.hpp"
#include "sistema.hpp"
#include "produto.hpp"
#include "carrinho.hpp"
#include "acai.hpp"

const float sabor_Acai = 1.50;
const float sabor_Banana = 0.50;
const float sabor_Morango = 1.00;
const float sabor_Abacaxi = 0.50;


std::string Vitamina::getSabor() 
{
    return _sabor;
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

void Vitamina::montar() 
{
    std::string str; 
    char c;
    int n, m = 0;

    std::cout << "Digite o número de acordo tamanho que você deseja:" << std::endl << "1. 300 ml" << std::endl << "2. 500 ml" << std::endl << "3. 700 ml" << std::endl;
    std::cin >> n;
    if(n == 1){
        _tamanho = 300;
    } else if(n == 2){
        _tamanho = 500;
    } else if(n == 3){
        _tamanho = 700;
    }

    std::cout << "Você tem direito até escolher 2 sabores" << std::endl;
    do
    {
        std::cout << "Digite o número de acordo com o sabor que você deseja:" << std::endl;
        std::cout << "1. Açaí" << std::endl << "2. Banana" << std::endl << "3. Morango" << std::endl << "4. Abacaxi" << std::endl;
        std::cin >> n;

        if(n == 1){
            _saboresVitamina.push_back("Açaí");
        } else if(n == 2){
            _saboresVitamina.push_back("Banana");
        } else if(n == 3){
            _saboresVitamina.push_back("Morango");
        } else if(n == 4){
            _saboresVitamina.push_back("Abacaxi");
        } 

        std::cout << "Deseja adicionar mais sabores à sua vitamina? (s/n)?" << std::endl;
        std::cin >> c;
        if(c == 's')
        {
            m++;
        } 
        if(m > 1)
        {
            std::cout << "O limite de sabores foi alcançado" << std::endl;
            c = 'n';
        }
    }while(c == 's');

    std::cout << "Deseja remover algum Sabor? (s/n)?" << std::endl;
    std::cin >> c;
    if(c == 's')
    {
        std::cout << "Digite o nome do sabor que deseja remover." << std::endl;
        std::cin >> str;

        std::vector<std::string>::iterator it;
        for(it = _saboresVitamina.begin(); it != _saboresVitamina.end(); it++) 
        {
            if(*it == str)
            {
                _saboresVitamina.erase(it);
                break;
            }
        }
    } 
}


std::string Vitamina::descricao() 
{
    std::string descricao;
    descricao = std::to_string(_quantidade) + " vitaminas de " + std::to_string(_tamanho) + " de sabor ";

    std::vector<std::string>::iterator it;
    for(it = _saboresVitamina.begin(); it != _saboresVitamina.end(); it++)
    {
        descricao = descricao + *it + " ";
    }
    return descricao;
}