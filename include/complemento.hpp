#ifndef COMPLEMENTO_H
#define COMPLEMENTO_H

#include <iostream>
#include <string>


/**
*@file complemento.hpp
*@author Luiz Kevenin
*@brief Classe utilizada para adicionar complementos ao açaí
*@version 1.0
*@date 27/11/2022
*@details Classe utilizada para a criação de complementos para o acai
*@copyright GNU General Public License v2.0
*/

/**
 * @brief Classe de tratamento de excessões
 * 
 */
class complementoInvalido : public std::exception {
    
    private:
        /**
         * @brief String que contém a mensagem de erro
         */
        std::string _msg;

    public:
        /**
         * @brief Construtora da classe, controi a mensagem de erro
         */
        complementoInvalido() {
            _msg = "Complemento invalido, deseja tentar novamente? (s/n)?";     
        }

        /**
         * @brief Função onde retorna a mensagem de erro
         * 
         * @return uma string que contém a mensagem de erro
         */
        const char* what() const noexcept override {
            return _msg.c_str();
        }
};


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


};
#endif