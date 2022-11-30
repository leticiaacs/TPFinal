/** 
 * @file carrinho_test.cpp
 * @author Naiara Silveira (naiarabarceloss@gmail.com)
 * @brief Classe principal com os testes da classe carrinho
 * @version 1.0
 * @date 2022-11-30
 * @details Responsável por testar as funções da classe carrinho
 * @copyright GNU General Public License v2.0
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "carrinho.hpp"

TEST_CASE("Testando adicionaProduto"){

    SUBCASE("Caso geral: produto adicionado corretamente"){

    }

    SUBCASE("Usuario desistiu de adicionar produto"){

    }

    SUBCASE("Usuario entra com uma escolha invalida"){

    }

}

TEST_CASE("Testando removeProduto"){

    SUBCASE("Caso geral: produto removido corretamente"){

    }

    SUBCASE("Usuario desistiu de adicionar produto"){

    }

    SUBCASE("Usuario entra com uma escolha invalida"){

    }

}

TEST_CASE("Testando calculaTotal"){

    SUBCASE("Caso geral: Retorna a soma dos produtos pedidos sem desconto"){

    }

    SUBCASE("Retorna a soma dos produtos pedidos com desconto"){

    }

}

TEST_CASE("Testando descricaoFinal"){

    SUBCASE("Caso geral: imprime corretamente as descrições"){
        
    }

}