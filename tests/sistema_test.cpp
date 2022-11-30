#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sistema.hpp"
#include "usuario.hpp"

TEST_CASE("Testando cria_cadastro"){
   
    SUBCASE("Caso geral: cadastro realizado corretamente"){
        Sistema s = Sistema();

        CHECK_EQ(s.cria_cadastro("12345678911","AZUL"), 0);
    }

    SUBCASE("Caso negativo: cadastro ja existe"){
        Sistema s = Sistema();
        std::string cpf = "12345678911";
        REQUIRE(s.cria_cadastro(cpf,"senha"));

        CHECK_EQ(s.cria_cadastro(cpf,"AZUL"), 1);
    }

    SUBCASE("Caso inválido: valores inválidos de cadastro"){
        Sistema s = Sistema();
        
        CHECK_EQ(s.cria_cadastro("-12345678911","AZUL"), 1);
        CHECK_EQ(s.cria_cadastro("00000000000","azul"), 1);
        CHECK_EQ(s.cria_cadastro("12","azul"), 1);
    }
}

TEST_CASE("Testando verifica_login"){
   
    SUBCASE("Caso geral: login realizado corretamente"){
        Sistema s = Sistema();
        Usuario u = Usuario("12345678911","senha",0);
        REQUIRE(s.cria_cadastro("12345678911","senha"));

        CHECK_EQ(s.verifica_login("12345678911","senha"), u);
    }

    SUBCASE("Caso negativo: login incorreto"){
        Sistema s = Sistema();
        REQUIRE(s.cria_cadastro("12345678911","senha"));

        CHECK_THROWS_AS(s.verifica_login("12345678911","s"), DadosInvalidos);
        CHECK_THROWS_AS(s.verifica_login("12345678910","senha"), DadosInvalidos);
    }

}

TEST_CASE("Testando informacoes_produtos"){
   
    SUBCASE("Caso geral: mensagem exibida corretamente"){
        Sistema s = Sistema();
        //FALTA INSERIR A INFORMACAO FINAL QUE VAI SER EXIBIDA
        CHECK_EQ(s.informacoes_produtos(),"INSERIR AQUI DESCRICAO FINAL" );
    }

}