#include <iostream>
#include <list>
#include <string>
#include "usuario.hpp"
#include "sistema.hpp"
#include "produto.hpp"



int Sistema::cria_cadastro(std::string cpf_novo, std::string senha_nova){
    
    std::string c;
    for(std::list<Usuario*>::iterator it = banco_de_usuarios.begin(); it!= banco_de_usuarios.end(); it++){

        (*it)->getCPF() = c;

        if(c == cpf_novo|| cpf_novo == "00000000000"|| cpf_novo.size() < 11){
            return 1;
        }
    }

    Usuario *u = new Usuario(cpf_novo, senha_nova, 0);
    banco_de_usuarios.push_back(u);

    return 0;
}


Usuario Sistema::verifica_login(std::string c, std::string s){

    int aux = 0;
    std::string cpf;
    std::string senha;
    for(std::list<Usuario*>::iterator it = banco_de_usuarios.begin(); it!= banco_de_usuarios.end(); it++){

        (*it)->getCPF() = cpf;
        (*it)->getSenha() = senha;

        if(c == cpf && s == senha){
            aux++;
            return it;
        }
    }

    if(aux == 0){

        throw DadosInvalidos();
        exit(1);
    }

}

std::string Sistema::informacoes_produtos() {

    Produto p = Produto();    
    p.exibeProdutos();
       
}

