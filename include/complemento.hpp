#ifndef COMPLEMENTO_H
#define COMPLEMENTO_H

#include <iostream>
#include <string>
#include "usuario.hpp"
#include "sistema.hpp"
#include "produto.hpp"
#include "carrinho.hpp"
#include "acai.hpp"
#include "vitamina.hpp"


/**
*@file complemento.hpp
*@author Luiz Kevenin
*@brief Classe utilizada para adicionar complementos ao açaí
*@version 1.0
*@date 27/11/2022
*@details Classe utilizada para a criação de complementos para o acai
*@copyright GNU General Public License v2.0
*/


class Complemento{

    private:
        std::string _nome;
    
    public:
        /**
         * @brief Construtora do objeto complemento
         * 
         * @param nome string que recebe o nome do complemento
         */
        Complemento(std::string nome);

        /**
         * @brief Retorna o nome do complemento
         * 
         * @return Retorna uma string que contém o nome do complemento
         */
        std::string getNome();
		
		 /**
         * @brief Retorna o preço do complemento
         * 
         * @return Retorna um int que contém o nome do complemento
         */
		int getPreco();


};
#endif