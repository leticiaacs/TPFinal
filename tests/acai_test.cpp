#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "acai.hpp"
#include "produto.hpp"

TEST_CASE("Testando o calculaPreco()")
{

    SUBCASE("Caso positivo: preço do açaí calculado corretamente")
    {
        Acai c = Acai();

        std::vector<Complemento*> _testeComplemento;
        Complemento *a = new Complemento("Banana", 1.50);
        Complemento *b = new Complemento("Leite Ninho", 2.50);
        _testeComplemento.push_back(a);
        _testeComplemento.push_back(b);

        CHECK_EQ(c.Acai::calculaPreco(), 16.5);
    }
    
    SUBCASE("Caso negativo: preço do açaí calculado incorretamente")
    {
        Acai c = Acai();

        std::vector<Complemento*> _testeComplemento;
        Complemento *a = new Complemento("Abacaxi", 1.50);
        Complemento *b = new Complemento("Manga", 2.50);
        _testeComplemento.push_back(a);
        _testeComplemento.push_back(b);

        CHECK_EQ(c.Acai::calculaPreco(), 12.5);
    }
}

TEST_CASE("Testando o descricao()")
{

    SUBCASE("Caso positivo: descrição do açaí impressa corretamente")
    {
        Acai c = Acai();

        std::vector<Complemento*> _testeComplemento;
        Complemento *a = new Complemento("Banana", 1.50);
        Complemento *b = new Complemento("Morango", 2.00);
        _testeComplemento.push_back(a);
        _testeComplemento.push_back(b);

        CHECK_EQ(c.Acai::descricao(), "Acai de 500 com complementos: Banana Morango");
    }

    SUBCASE("Caso negativo: descrição do açaí impressa incorretamente")
    {
        Acai c = Acai();

        std::vector<Complemento*> _testeComplemento;
        Complemento *a = new Complemento("Abacaxi", 1.50);
        Complemento *b = new Complemento("Manga", 2.00);
        _testeComplemento.push_back(a);
        _testeComplemento.push_back(b);

        CHECK_EQ(c.Acai::descricao(), "Acai de 500 com complementos: Abacaxi Manga");
    }
}

TEST_CASE("Testando o montar()")
{

    SUBCASE("Caso positivo: açaí montado corretamente")
    {
        Acai c = Acai();

        std::string n;
        std::istringstream in("3");
        in >> n;

        //CHECK(c.Acai::montar());

    }

    
    SUBCASE("Caso negativo: açaí montado incorretamente")
    {
        Acai c = Acai();

        std::string n;
        std::istringstream in("5");
        in >> n;

        CHECK_THROWS_AS(c.Acai::montar(), tamanhoInvalido());
    }
}