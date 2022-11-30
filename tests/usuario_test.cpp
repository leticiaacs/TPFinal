/** 
 * @file usuario_test.cpp
 * @author Naiara Silveira (naiarabarceloss@gmail.com)
 * @brief Classe principal com os testes da classe usuario
 * @version 1.0
 * @date 2022-11-30
 * @details Responsável por testar as funções da classe usuario
 * @copyright GNU General Public License v2.0
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "usuario.hpp"

TEST_CASE("Testando construtor"){
    Usuario u = Usuario("11122233344", "senhaSenha", 0);
    CHECK_EQ("11122233344", u.getCPF());
    CHECK_EQ("senhaSenha", u.getSenha());
    CHECK_EQ(0, u.getQtdCompras());
}

TEST_CASE("Testando verificaDesconto"){
    Usuario u = Usuario("11122233344", "senhaSenha", 10);
    CHECK_EQ(true, u.verificaDesconto());
}