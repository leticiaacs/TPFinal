#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "vitamina.hpp"
#include "produto.hpp"

TEST_CASE("Testando o calculaPreco()")
{

    SUBCASE("Caso positivo: preço da vitamina calculada corretamente")
    {
        Vitamina c = Vitamina();

        std::vector<std::string> _testeSabores;
        std::string a = "Morango";
        std::string b = "Abacaxi";
        _testeSabores.push_back(a);
        _testeSabores.push_back(b);

        CHECK_EQ(c.Vitamina::calculaPreco(), 9);
    }
    
    SUBCASE("Caso negativo: preço da vitamina calculada incorretamente")
    {
        Vitamina c = Vitamina();

        std::vector<std::string> _testeSabores;
        std::string a = "Manga";
        std::string b = "Abacaxi";
        _testeSabores.push_back(a);
        _testeSabores.push_back(b);

        CHECK_EQ(c.Vitamina::calculaPreco(), 8);
    }
}

TEST_CASE("Testando o descricao()")
{

    SUBCASE("Caso positivo: descrição da vitamina impressa corretamente")
    {
        Vitamina c = Vitamina();

        std::vector<std::string> _testeSabores;
        std::string a = "Morango";
        std::string b = "Abacaxi";
        _testeSabores.push_back(a);
        _testeSabores.push_back(b);

        CHECK_EQ(c.Vitamina::descricao(), "Vitamina de 500 de sabor: Morango Abacaxi");
    }

    SUBCASE("Caso negativo: descrição da vitamina impressa incorretamente")
    {
        Vitamina c = Vitamina();

        std::vector<std::string> _testeSabores;
        std::string a = "Acerola";
        std::string b = "Melão";
        _testeSabores.push_back(a);
        _testeSabores.push_back(b);

        CHECK_EQ(c.Vitamina::descricao(), "Vitamina de 500 de sabor: Acerola Melão");
    }
}

TEST_CASE("Testando o montar()")
{

    SUBCASE("Caso positivo: vitamina montada corretamente")
    {
        Vitamina c = Vitamina();

        std::string str;
        std::istringstream in("3");
        in >> str;

        //CHECK_EQ(c.Vitamina::montar());

    }

    
    SUBCASE("Caso negativo: vitamina montada incorretamente")
    {
        Vitamina c = Vitamina();

        std::string n;
        std::istringstream in("8");
        in >> n;

        CHECK_THROWS_AS(c.Vitamina::montar(), tamanhoInvalido());
    }
}