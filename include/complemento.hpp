#ifndef COMPLEMENTO_H
#define COMPLEMENTO_H

#include "produto.hpp"
#include <iostream>
#include <string>

/**
*@file complemento.hpp
*@author Yaggo Cardoso
*@brief Classe usada para adicionar complementos ao açaí
*@version 1.0
*@date 27/11/2022
*@details Classe Sistema responsável por realizar o procedimento de cadastro e login da loja de açaí, juntamente com a exibição de produtos disponíveis e Classe escolhaInvalida que faz o tratamento de exceções
*@copyright GNU General Public License v2.0
*/

class Complemento : public Produto
{
    private:
        std::string _nome;
    
    public:
        Complemento(std::string nome);
        std::string getNome();
};

class escolhaInvalida2 : public std::exception
{
    private:
        std::string _msg_erro;

    public:
        escolhaInvalida2()
        {
            _msg_erro = "Comando inválido, deseja tentar novamente? Pressione S para sim ou qualquer outro caractere para voltar ao menu inicial.";     
        }

        const char* what() const noexcept override
        {
            return _msg_erro.c_str();
        }
};
#endif