#include <iostream>
#include <list>
#include <string>
#include <map>

#include "sistema.hpp"



int Sistema::cria_cadastro(long int cpf_novo, std::string senha_nova){
    
    long int c;
    std::string cpf_string = std::to_string(cpf_novo);
    for(std::list<Usuario*>::iterator it = banco_de_usuarios.begin(); it!= banco_de_usuarios.end(); it++){

        (*it)->getCPF() = c;

        if(c == cpf_novo|| cpf_novo <= 0 || cpf_string.size() < 11){
            return 1;
        }
    }

    Usuario *u = new Usuario(cpf, senha, 0);
    banco_de_usuarios.push_back(u);

    return 0;
}


Usuario Sistema::verifica_login(long int c, std::string s){

    int aux = 0;
    longint cpf;
    std::string senha;
    for(std::list<Usuario*>::iterator it = banco_de_usuarios.begin(); it!= banco_de_usuarios.end(); it++){

        (*it)->getCPF() = cpf;
        (*it)->getSenha() = senha;

        if(c == cpf && s == senha){
            aux++;
            return *it;
        }
    }

    if(aux == 0){

        throw DadosInvalidos();
        return 0;
    }

}

std::string Sistema::informacoes_produtos() {

    Produto p = Produto();    
    p.descricao_geral();
       
}

