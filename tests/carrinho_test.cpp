/** 
 * @file carrinho_test.cpp
 * @author Leon Marcos Felix Gonçalves & Naiara Silveira (naiarabarceloss@gmail.com)
 * @brief Classe principal com os testes da classe carrinho
 * @version 1.0
 * @date 2022-11-30
 * @details Responsável por testar as funções da classe carrinho
 * @copyright GNU General Public License v2.0
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>

#include "doctest.h"
#include "carrinho.hpp"
#include "produto.hpp"

TEST_CASE("Testando adicionaProduto"){

    Carrinho *carrinho = new Carrinho();
    Produto *p;

    SUBCASE("Caso geral: produto adicionado corretamente"){ 

        carrinho->adicionaProduto(p);

        std::vector<Produto*> vetorTeste;
        vetorTeste = carrinho->getPedidosProduto();
        CHECK(vetorTeste[0] == p);
    }

    SUBCASE("Usuario desistiu de adicionar produto"){
        carrinho->adicionaProduto(p);
        CHECK(carrinho->getPedidosProduto[0] != p);

    }

    SUBCASE("Usuario entra com uma escolha invalida"){
        CHECK_THROWS_AS(carrinho->adicionaProduto(Produto a));
    }

}

TEST_CASE("Testando removeProduto"){

    Carrinho *carrinho = new Carrinho();
    Produto *p;

    SUBCASE("Caso geral: produto removido corretamente"){
        carrinho->adicionaProduto(p);
        carrinho->removeProduto(p);
        CHECK(carrinho->_pedidosProduto[0] != produto);
    }

    SUBCASE("Usuario desistiu de remover produto"){
        carrinho->adicionaProduto(p);
        carrinho->removeProduto(p);
        CHECK (ca->_pedidosProduto[0] == p);
    }

    SUBCASE("Usuario entra com uma escolha invalida"){
        CHECK_THROWS(carrinho.removeProduto(Produto a));
    }

}

TEST_CASE("Testando calculaTotal"){
    Usuario *u = new Usuario();
    Carrinho *carrinho = new Carrinho();
    Produto *p;

    SUBCASE("Caso geral: Retorna a soma dos produtos pedidos sem desconto"){

    }

    SUBCASE("Retorna a soma dos produtos pedidos com desconto"){

    }

}

TEST_CASE("Testando descricaoFinal"){

    SUBCASE("Caso geral: imprime corretamente as descrições"){
        
    }

}