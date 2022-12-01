/** 
 * @file carrinho.hpp
 * @author Leon Marcos Felix Goncalves & Naiara Silveira (naiarabarceloss@gmail.com)
 * @brief Classe principal com a lógica do carrinho, classe para tratamento de excessoes
 * @version 1.0
 * @date 2022-11-30
 * @details Carrinho é a classe Responsável por setar e retornar os parametros. Incorreto é a classe que trata excessões
 * da compra
 * @copyright GNU General Public License v2.0
*/

#ifndef CARRINHO_H
#define CARRINHO_H

#include <iostream>
#include <string>
#include <vector>
#include "carrinho.hpp"
#include "usuario.hpp"
#include "produto.hpp"

class Incorreto : public std::exception{

/**
	 * @brief Classe para tratamento de exceções, presente nas funções adicionaProduto e removeProduto
	 * @details Classe que faz o throw para quando os valores inseridos pelo usuário não sao corretos para o a adicao ou exclusao de produtos
	 */

    
    private:
    std::string erro;

    public:

    /**
	 * @brief Construtor da Classe Incorreto
	 * @details Constrói um novo objeto da Classe Incorreto definindo uma mensagem de erro para o objeto para 
	 * quando a função for chamada.
	 */
     Incorreto() : erro("Valores nao suportados. Tente novamente com valores inteiros.") {}


    /**
	 * @brief Função que retorna a mensagem de erro 
	 * @details Função que sobrescreve a função what() da Classe mãe std::exception e retorna a mensagem de erro definida no construtor 
	 * (Valores nao suportados. Tente novamente com valores inteiros.)
	 * @return const char* erro
	 */
    const char* what() const noexcept override {
		
		return erro.c_str();
	}
};



class Carrinho {
    /**
     * @brief classe que armazena as compras do usuário
     * @details parametros e métodos
     */
    
    private:
    std::vector<Produto*> _pedidosProduto;
    float _valorFinal;

    public:

   /**
    * @brief adiciona novo produto ao pedido
    * @details coloca novo pedido na vector de _pedidosProduto
    * @param Produto a
    */
    void adicionaProduto(Produto* a);

   /**
    * @brief retira produto do pedido
    * @details retira pedido da vector de _pedidosProduto
    */
    void removeProduto();

   /**
    * @brief calcula valor
    * @details soma valor de todos os pedidos juntos e trata descontos
    */
    float calculaTotal(Usuario* u);

   /**
    * @brief texto do pedido
    * @details imprime descricao de todos os pedidos juntos
    */
    void descricaoFinal();

    /**
    * @brief get vetor de produtos para teste
    * @details retorna o vetor de produtos do objeto carrinho
    */
    std::vector<Produto*> getPedidosProduto();    

};

#endif