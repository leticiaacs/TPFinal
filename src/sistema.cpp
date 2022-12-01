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
    int qtd = 0;
    std::string cpf;
    std::string senha;
	Usuario *u;
    for(std::list<Usuario*>::iterator it = banco_de_usuarios.begin(); it!= banco_de_usuarios.end(); it++){

        cpf =(*it)->getCPF();
        senha = (*it)->getSenha();
	    qtd = (*it)->getQtdCompras();
		
        if((c == cpf) && (s == senha)){
            aux++;
            u = new Usuario(c, s, qtd);
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

    std::cout << std::endl;
    std::cout << "Produtos disponiveis na loja:" << std::endl << std::endl;
    std::cout << "Acai 300 (7.50 reais), 500 (12.50 reais) e 700 ml (17.50 reais)" << std::endl << "Complementos do acai:" << std::endl;
    std::cout << "Banana (1.50 reais) - Granola (1.50 reais) - Morango (2 reais) - Leite ninho (2.50 reais) - Leite condensado (2.50 reais)" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl << "Vitamina 300 (4.50 reais), 500 (7.50 reais) e 700 ml (10.50 reais)" << "\nSabores da vitamina:" << std::endl;
	std::cout <<  "Acai (1.50 reais), Banana (50 centavos), Morango (1 real) e Abacaxi (50 centavos)" << std::endl;
    std::cout << std::endl;
}

void Sistema::modifica_usuario(Usuario *u) {
	std::string senha;
	std::string cpf;
	std::string s;
	std::string c;
	
	s = u->getSenha();
	c = u->getCPF();
	
	for(std::list<Usuario*>::iterator it = banco_de_usuarios.begin(); it!= banco_de_usuarios.end(); it++){
        
		cpf = (*it)->getCPF();
		senha = (*it)->getSenha();
        
		if((c == cpf) && (s == senha)){
            (*it)->aumentaQtdCompras();
        }
    }

}