#include <iostream>
#include <vector>
#include <string>
#include "produto.hpp"
#include "vitamina.hpp"


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
        if(*it == "acai")
            soma = soma + sabor_Acai;
        else if(*it == "banana")
            soma = soma + sabor_Banana;
        else if(*it == "morango")
            soma = soma + sabor_Morango;
        else if(*it == "abacaxi")
            soma = soma + sabor_Abacaxi;
    }
    return soma + _tamanho*0.015;
}

std::string Vitamina::descricao() 
{
    std::string descricao;
    descricao ="Vitamina de " + std::to_string(_tamanho) + " de sabor " ;
	
   /* std::vector<std::string>::iterator it;
    for(it = _saboresVitamina.begin(); it != _saboresVitamina.end(); it++)
    {
        descricao = descricao + getSabor() + " ";
    }*/
	
	for (int i = 0; i<2;i++){
		descricao = descricao + _saboresVitamina[i] + " ";	
	}
		descricao = descricao + '\n';

    return descricao;
}

void Vitamina::montar() 
{
    std::string str; 
    char c;
    std::string n;
	int m = 0;

    std::cout << "Digite o numero de acordo tamanho que voce deseja:" << std::endl << "1. 300 ml" << std::endl << "2. 500 ml" << std::endl << "3. 700 ml" << std::endl;
    std::cin >> n;
    if(n == std::to_string(1)){
        _tamanho = 300;
    } else if(n == std::to_string(2)){
        _tamanho = 500;
    } else if(n == std::to_string(3)){
        _tamanho = 700;
    } else {
		throw tamanhoInvalido();
	}

    std::cout << "Voce tem direito de escolher ate 2 sabores" << std::endl;
    do
    {
        std::cout << "Digite o numero de acordo com o sabor que voce deseja:" << std::endl;
        std::cout << "1. Acai" << std::endl << "2. Banana" << std::endl << "3. Morango" << std::endl << "4. Abacaxi" << std::endl;
        std::cin >> n;

        if(n == std::to_string(1)){
            _saboresVitamina.push_back("Acai");
        } else if(n == std::to_string(2)){
            _saboresVitamina.push_back("Banana");
        } else if(n == std::to_string(3)){
            _saboresVitamina.push_back("Morango");
        } else if(n == std::to_string(4)){
            _saboresVitamina.push_back("Abacaxi");
        } 

        std::cout << "Deseja adicionar mais sabores a sua vitamina? (s/n)?" << std::endl;
        std::cin >> c;
        if(c == 's')
        {
            m++;
        } 
        if(m > 1)
        {
            std::cout << "O limite de sabores foi alcancado" << std::endl;
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


