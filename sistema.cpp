#include <iostream>
#include <list>
#include <string>
#include <map>

#include "sistema.hpp"

Usuario Sistema::inicializacao_usuario(){

    std::cout << "Seja bem vindx a nossa loja de acai e vitaminas!"<<std::endl;
    std::cout << "Voce ja possui cadastro? Digite S para sim e N para nao."<<std::endl;

    if(std::cin>>S)
        std::cout<<"Que otimo!" <<std::endl;
        return this->verifica_login();
    else if (std::cin>>N)
        return this->cria_cadastro();
}

Usuario Sistema::cria_cadastro(){
    std::cout<<"Para criar o seu cadastro, precisamos que voce digite o seu cpf e, em seguida, crie e digite uma senha, nessa ordem." <<std::endl;
    int cpf;
    std::string senha
    cin>>cpf>>senha;
    Usuario *u = new Usuario(cpf, senha, 0);

    banco_de_usuarios.push_back(*u);

    std::cout<<"Prontinho! Cadastro efetuado com sucesso. Digite L para ser redirecionado a pagina de login."<<std::endl;
    if(std::cin>>L)
        return this->verifica_login();
}

Usuario Sistema::verifica_login(){

    std::cout<<"Digite o seu CPF e a sua senha, separados por um espaco para entrar em sua conta "
    std::string cpf_digitado;
    std::cin>>string senha_digitada
    std::cin>>cpf_digitado>>senha_digitada;
    
    int aux = 0;

    for(std::list<Usuario*>::iterator it = banco_de_usuarios.begin(); it!= banco_de_usuarios.end(); it++){

        std::string cpf;
        std::string senha;

        (*it)->getCPF() = cpf;
        (*it)->getSenha() = senha;

        if(cpf_digitado == cpf && senha_digitada == senha){
            return *it;
            aux++;
        }
    }

    if(aux == 0){

        //fazer um throw da classe do erro aqui:
        //lembrar de fazer o try catch do erro!

        throw DadosInvalidos();
        return 0;
    }
    else 
        std::cout<<"Obaaaa, conseguimos acessar sua conta :) " << std::endl;
        this->informacoes_produtos();
}

void Sistema::informacoes_produtos() {
    std::cout<<"Para saber quais sao nossas opcoes de produtos, digite O" << std::endl;
    std::cout<<"Para fazer o pedido, digite P" << std::endl;

    if(std::cin>>O)
       //funcao descricao dos produtos
    else if(std::cin>>P) 
        this->fazendo_pedidos()
}

void Sistema::fazendo_pedidos(){
    Produto *p = new();
    std::cout<<"Digite A para pedir um acai e V para pedir uma vitamina" << std::endl;
    if(std::cin>>A)
        //aqui entra funcao monta_acai
    else if(std::cin>>V)
        //aqui entra funcao monta_vitamina
}

//depois entra a parte do carrinho:adiciona produto + remove produto + calcula total + finaliza pedido.


