#include <iostream>
#include "sistema.hpp"
#include <string>

int main(){

Sistema sistema = Sistema();
Carrinho *ca = new Carrinho();

std::cout << "Seja bem vindx a nossa loja de acai e vitaminas! Na nossa loja, depois que voce chega no decimo pedido, o decimo primeiro vem com um desconto de 50%!!!!"<<std::endl;
std::cout<< "Voce ja possui cadastro? Digite 1 para nao ou qualquer outra tecla para sim"<<std::endl;

int a;
std::cin>>a;

if(a == 1) {
    std::cout<<"Para criar o seu cadastro, precisamos que voce digite o seu cpf e, em seguida, crie e digite uma senha, nessa ordem." <<std::endl;
    
    std::string cpf;
    std::string senha;
    int a = 0;

    do{
        std::cin>>cpf>>senha;
        a = sistema.cria_cadastro(cpf, senha);

        if(a==1){
            std::cout<<"Esse cpf ja esta cadastrado ou e um numero invalido. Digite 1 para voltar para a pagina de cadastros"<<std::endl;
        }
    }while(a == 1);
    std::cout<<"Prontinho! Cadastro efetuado com sucesso"<<std::endl;
} 

int auxiliar = 0;

do{
    std::cout<<"Para entrar em sua conta, digite o seu CPF e a sua senha. "<<std::endl;
    std::string cpf_digitado;
    std::string senha_digitada;
    std::cin>>cpf_digitado>>senha_digitada;

    try{
        Usuario *u = new Usuario();
        u = sistema.verifica_login(cpf_digitado, senha_digitada);
    }

    catch (DadosInvalidos &e){

        std::cout<<e.what()<<std::endl;
        auxiliar = 1;
        
    }
} while(auxiliar == 1);

std::cout<<"Obaaaa, conseguimos acessar sua conta :) " << std::endl;
std::cout<<"Para saber quais sao nossas opcoes de produtos, digite 1" << std::endl;
std::cout<<"Para fazer o pedido, digite qualquer outra tecla" << std::endl;

int b;
std::cin>>b;

if(b =='1') {
    std::string informacoes;
    informacoes = sistema.informacoes_produtos();
    std::cout<<"Pronto! Agora que você já sabe quais os nossos produtos, pode fazer seu pedido." << std::endl;
}

int aux;

do {
    Produto *p = new Produto();
    std::cout<<"Digite A para pedir um acai e V para pedir uma vitamina" << std::endl;
        
    char c;
    std::cin>>c;
    if(c =='A')
        p = new Acai();
        
    else if(c =='V')
        p = new Vitamina();
        
    p->montar();

    int aux = 0;

    do{
        try{
            ca->adicionaProduto(&p);
        }

        catch(Incorreto &e) {
            std::cout<<e.what()<<std::endl;
            aux = 1;
        }
    } while (aux == 1);

    std::cout<< "Prontinho! Seu pedido escolhido foi: " << p->descricao()<<std::endl;
    std::cout<< "Ja adicionamos o produto no carrinho! Deseja pedir mais alguma coisa? Digite 1 para nao ou qualquer outra tecla para sim"<<std::endl;

    int d;
    std::cin>>d;

    if (d == 1)
        aux = 1;
    else
        aux = 0;

} while (aux==0);

do{
    std::cout<< "Os itens no seu carrinho sao: " << ca->descricaoFinal()<<std::endl;
    std::cout<< "O valor final do pedido e: " <<ca->calculaTotal(u)<<std::endl;
    std::cout<< "Para remover algum produto, digite 1." <<std::endl;
    std::cout<< "Para finalizar o pedido, digite qualquer outra tecla." <<std::endl;
    
    int e;
    std::cin>>e;
    
    if(e ==1){
        int aux = 0;
        do{
            try{
                ca->removeProduto();
            }

            catch(Incorreto &e) {
                std::cout<<e.what()<<std::endl;
                aux = 1;
            }
        }while(aux == 1);
    else {
        u.aumentaQtdCompras(&p);
        aux = 1;
    }
} while(aux == 0);

std::cout<<"Seu pedido foi computado! Agradecemos pela compra e volte sempre :)"<<std::endl;

}