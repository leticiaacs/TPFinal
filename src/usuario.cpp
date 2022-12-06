/** 
 * @file usuario.cpp
 * @author Naiara Silveira (naiarabarceloss@gmail.com)
 * @brief Classe principal com a lógica do usuário
 * @version 1.0
 * @date 2022-11-27
 * @details Responsável por setar e retornar os parametros
 * dos usuarios
 * @copyright GNU General Public License v2.0
*/

#include <iostream>
#include <string>
#include "usuario.hpp"

//construtor de um novo usuario
Usuario::Usuario(std::string cpf, std::string senha, int qtdCompras){
    _cpf = cpf;
    _senha = senha;
    _qtdCompras = qtdCompras;
}

//retorna senha para verificar login
std::string Usuario::getSenha(){
    return _senha;
}

//retorna cpf para verificar login
std::string Usuario::getCPF(){
    return _cpf;
}

//retorna quantidade de compras do usuario
int Usuario::getQtdCompras(){
    return _qtdCompras;
}

//retorna se merece desconto
bool Usuario::verificaDesconto(){

    if(_qtdCompras == 0){
        return false;
    }

    if(_qtdCompras%10 == 0){
        return true;
    }

    return false;

}

void Usuario::aumentaQtdCompras(){
    _qtdCompras++;
}