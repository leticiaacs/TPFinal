/** 
 * @file carrinho.hpp
 * @author Leon & Naiara Silveira (naiarabarceloss@gmail.com)
 * @brief Classe principal com a lógica do carrinho
 * @version 1.0
 * @date 2022-11-28
 * @details Responsável por setar e retornar os parametros 
 * da compra
 * @copyright GNU General Public License v2.0
*/

#ifndef CARRINHO_H
#define CARRINHO_H

#include <iostream>
#include <string>
#include <list>

#include "usuario.hpp"
#include "acai.hpp"

class Carrinho {
    /**
     * @brief classe que armazena as compras do usuário
     * @details parametros e métodos
     */
    
    private:
    //std::list<Acai> _pedidosAcai;
    float _valorFinal;

    public:

   /**
    * @brief adiciona novo produto ao pedido
    * @details coloca novo pedido na list de _pedidosAcai
    * @param acai a
    */
    void adicionaProduto(Acai a);

   /**
    * @brief retira produto do pedido
    * @details retira pedido da list de _pedidosAcai
    * @param acai a
    */
    void removeProduto(Acai a);

   /**
    * @brief calcula valor
    * @details soma valor de todos os pedidos juntos e trata descontos
    */
    float calculaTotal();

   /**
    * @brief texto do pedido
    * @details imprime descricao de todos os pedidos juntos
    */
    std::string descricaoFinal();

   /**
    * @brief fim
    * @details chama adciona pedido do usuario e finaliza tratativas
    * @param usuario u
    */
    void finalizaPedido(Usuario *u);

};

#endif