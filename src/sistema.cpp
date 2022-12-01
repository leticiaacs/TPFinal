#include <iostream>
#include <list>
#include <string>
#include "usuario.hpp"
#include "sistema.hpp"
#include "produto.hpp"



int Sistema::cria_cadastro(std::string cpf_novo, std::string senha_nova){

    std::string c;

    //testa se tem letra
    for(int i=0; i<11; i++){

            if(cpf_novo[i] != '1' && cpf_novo[i] != '2' && cpf_novo[i] != '3' && cpf_novo[i] != '4' && cpf_novo[i] != '5' && cpf_novo[i] != '6' && cpf_novo[i] != '7' && cpf_novo[i] != '8' && cpf_novo[i] != '9' && cpf_novo[i] != '0'){
                return 1;

        }
    }
	
	if(cpf_novo == "00000000000" || cpf_novo.size() != 11){
        return 1;
    }

    for(std::list<Usuario*>::iterator it = banco_de_usuarios.begin(); it!= banco_de_usuarios.end(); it++){
        c = (*it)->getCPF();
        if(c == cpf_novo){
            return 1;
        }
    }

    Usuario *u = new Usuario(cpf_novo, senha_nova, 0);
    banco_de_usuarios.push_back(u);
	
    return 0;
}


Usuario* Sistema::verifica_login(std::string c, std::string s){

    int aux = 0;
    std::string cpf;
    std::string senha;
	Usuario *u;
    for(std::list<Usuario*>::iterator it = banco_de_usuarios.begin(); it!= banco_de_usuarios.end(); it++){

        cpf =(*it)->getCPF();
        senha = (*it)->getSenha();
	
		
        if((c == cpf) && (s == senha)){
            aux++;
            u = new Usuario(c, s, 0);
			break;
        }
    }

    if(aux == 0){

        throw DadosInvalidos();
    }
	
	else 
		return u;

}

void Sistema::informacoes_produtos() {

    std::cout << "Produtos disponiveis na loja:" << std::endl;
    std::cout << "Acai 300, 500 e 700 ml" << std::endl << "Complementos do acai:" << std::endl;
    std::cout << "Banana  -  Granola  -  Morango  -  Leite ninho  -  Leite condensado" << std::endl;
    std::cout << std::endl << "Vitamina 300, 500 e 700 ml" << "\nSabores da vitamina:" << std::endl;
	std::cout << std::endl << "Acai, Banana, Morango e Abacaxi" << std::endl;
}

