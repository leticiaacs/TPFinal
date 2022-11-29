#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
#include <exception>

/**
 *@file produto.hpp 
 *@author Luiz Kevenin
 *@brief Classe produto, classe mãe das classes vitaminas e açai
 *@version 1.0
 *@date 26/11/2022
 *@details Classe produto, classe mãe da classe vitamina e da classe açai, tendo funções onde as classes filhas irão herdar
 *@copyright GNU General Public License v2.0
 */



/**
 * @brief Classe de tratamento de excessão caso o tamanho do produto seja invalido
 * 
 */
class tamanhoInvalido : public std::exception {
    
    protected:
        /**
         * @brief Mensagem de erro
         */
        std::string _erro;
    
    public:
        /**
         * @brief Construtora da classe, criando a mensagem de erro
         * 
         */
        tamanhoInvalido(){
            _erro = "O tamanho inserido é invalido, deseja tentar novamente? (s/n)?"
        }

        /**
         * @brief Função que retorna a mensagem de erro
         * 
         * @return retorna a string que contém a mensagem de erro
         */
        virtual const char* what() const noexcept {
            return _erro.c_str();
        }
}




/**
 * @brief Classe de tratamento de excessão caso a escolha seja invalida
 * 
 */
class escolhaInvalida : public std::exception {
    
    protected:
        /**
         * @brief Mensagem de erro
         */
        std::string _erro;
    
    public:
        /**
         * @brief Construtora da classe, criando a mensagem de erro
         * 
         */
        tamanhoInvalido(){
            _erro = "A escolha inserida é invalida, deseja tentar novamente? (s/n)?"
        }

        /**
         * @brief Função que retorna a mensagem de erro
         * 
         * @return retorna a string que contém a mensagem de erro
         */
        virtual const char* what() const noexcept {
            return _erro.c_str();
        }
}


class Produto {

    protected:
        /**
         * @brief Nome do produto
         */
        std::string _nome;

        /**
         * @brief Preco do produto
         */
        float _preco;

        /**
         * @brief Tamanho do produto
         */
        int _tamanho;
    
    public:
        /**
         * @brief calcula o preço unitario do produto
         * 
         * @return float Preco do Produto
         */
        virtual float calculaPreco() = 0;
        
        /**
         * @brief Retorna a descricao detalhada do produto
         * 
         * @return std::string Descricao do produto
         */
        virtual std::string descricao() = 0;

        /**
         * 
         *@brief Chama todas as funções para montar um acai ou uma vitamina
         * 
         */
        virtual void montar() = 0;

        /**
         * 
         *@brief Exibe todos os produtos disponiveis na loja
         * 
         */
        void exibeProdutos();

        /**
         * @brief Retorna o preco unitario do produto
         * 
         * @return float preco unitario do produto
         */
        float getPreco() const;

        /**
         * @brief retorna o tamanho do produto
         * 
         * @return int tamanho do produto
         */
        int getTamanho() const;
};
#endif