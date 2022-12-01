#include <iostream>
#include <string>
#include <vector>

#include "acai.hpp"
#include "complemento.hpp"
#include "produto.hpp"


const float preco_Banana = 1.50;
const float preco_Granola = 1.50;
const float preco_Morango = 2.00;
const float preco_LeiteNinho = 2.50;
const float preco_LeiteCondensado = 2.50;

float Acai::calculaPreco()  
{
    float soma;
	
    std::vector<Complemento*>::iterator it;
    for(it = _acrescimos.begin(); it != _acrescimos.end(); it++)
    {
        if((*it)->getNome() == "Banana")
            soma = soma + preco_Banana;
        else if((*it)->getNome() == "Granola")
            soma = soma + preco_Granola;
        else if((*it)->getNome() == "Morango")
            soma = soma + preco_Morango;
        else if((*it)->getNome() == "Leite ninho")
            soma = soma + preco_LeiteNinho;
        else if((*it)->getNome() == "Leite condensado")
            soma = soma + preco_LeiteCondensado;
    }
    return soma + _tamanho*0.025;
}

std::string Acai::descricao() 
{
	
	std::string descricao;
    descricao ="Acai de " + std::to_string(_tamanho) + " com complementos: ";


    std::vector<Complemento*>::iterator it;
    for(it = _acrescimos.begin(); it != _acrescimos.end(); it++)
    {
        descricao = descricao + (*it)->getNome() + " ";
    }
	    descricao = descricao + '\n';
    return descricao;
}

void Acai::montar() 
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
	}else {
		throw tamanhoInvalido();
	}

    std::cout << "Voce tem direito a escolher 5 complementos" << std::endl;
    do
    {
        std::cout << "Digite o número de acordo com o complemento que você deseja:" << std::endl;
        std::cout << "1. Banana" << std::endl << "2. Granola" << std::endl << "3. Morango" << std::endl << "4. Leite ninho" << std::endl << "5. Leite condensado" << std::endl;
        std::cin >> n;

        if(n == std::to_string(1)){
            Complemento *a = new Complemento("Banana", preco_Banana);
            _acrescimos.push_back(a);
        } else if(n == std::to_string(2)){
            Complemento *a = new Complemento("Granola", preco_Granola);
            _acrescimos.push_back(a);
        } else if(n == std::to_string(3)){
            Complemento *a = new Complemento("Morango", preco_Morango);
            _acrescimos.push_back(a);
        } else if(n == std::to_string(4)){
            Complemento *a = new Complemento("Leite ninho", preco_LeiteNinho);
            _acrescimos.push_back(a);
        } else if(n == std::to_string(5)){
            Complemento *a = new Complemento("Leite condensado", preco_LeiteCondensado);
            _acrescimos.push_back(a);
        } 

        std::cout << "Deseja adicionar mais complementos ao seu acai? (s/n)?" << std::endl;
        std::cin >> c;
        if(c == 's')
        {
            m++;
        } 
        if(m > 4)
        {
            std:: cout << "Voce chegou ao limite de complementos."<<std::endl;
            c = 'n';
        }
    }while(c == 's');

    std::cout << "Deseja remover algum complemento? (s/n)?" << std::endl;
    std::cin >> c;
    if(c == 's')
    {
        do{
            std::cout << "Digite o nome do complemento que deseja remover." << std::endl;
            std::cin >> str;

            for(std::vector<Complemento*>::iterator it = _acrescimos.begin(); it != _acrescimos.end(); it++)
            {
                if((*it)->getNome() == str)
                {
                    _acrescimos.erase(it);
                    break;
                }
            }
            std::cout << "Deseja remover outro complemento? (s/n)?";
            std::cin >> c;
            if(_acrescimos.size() == 0)
            {
                c = 'n';
            }
        }while(c == 's');
    } 

}

