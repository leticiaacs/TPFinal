#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>

/**
 *@file produto.hpp 
 *@author Luiz Kevenin
 *@brief Classe produto, classe mãe das classes vitaminas e açai
 *@version 1.0
 *@date 26/11/2022
 *@details Classe produto, classe mãe da classe vitamina e da classe açai, tendo funções onde as classes filhas irão herdar
 *@copyright GNU General Public License v2.0
 */
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