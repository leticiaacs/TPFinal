#include <iostream>
#include <string>
#include <list>

#include "sistema.hpp"
#include "carrinho.hpp"
#include "produto.hpp"
#include "acai.hpp"
#include "vitamina.hpp"
#include "complemento.hpp"

int main(){
	char prog = '1';

	Sistema sistema = Sistema();
	Carrinho *ca = new Carrinho();
	Usuario *u = new Usuario();
	Produto *p;

	do {
		std::cout << "Seja bem vindx a nossa loja de acai e vitaminas! Na nossa loja, depois que voce chega no decimo pedido, o decimo primeiro vem com um desconto de 50%!!!!"<<std::endl;
		std::cout << std::endl;
		std::cout<< "Voce ja possui cadastro? Digite 1 para nao ou qualquer outra tecla para sim"<<std::endl;

		std::string ajuda;
		std::cin>>ajuda;
	
		if(ajuda == std::to_string(1)) {
		
			do{	
				std::cout << std::endl;
				std::cout<<"Para criar o seu cadastro, precisamos que voce digite o seu cpf e, em seguida, crie e digite uma senha, nessa ordem." <<std::endl;
				std::cout << std::endl;

				std::string cpf;
				std::string senha;
				int a = 0;
		
				std::cin>>cpf>>senha;
				std::cout << std::endl;
				a = sistema.cria_cadastro(cpf, senha);
				if(a==1){
					std::cout << std::endl;
					std::cout<<"Esse cpf ja esta cadastrado ou eh um numero invalido. Digite 1 para voltar para a pagina de cadastros"<<std::endl;
					ajuda = std::to_string(1);
				}
				else 
					ajuda = std::to_string(2);
			}while(ajuda == std::to_string(1));
		
			std::cout << std::endl;
			std::cout<<"Prontinho! Cadastro efetuado com sucesso"<<std::endl;
		} 

		int auxiliar = 0;
	
	
		do{
			auxiliar = 0;
			std::cout<<"Para entrar em sua conta, digite o seu CPF e a sua senha. "<<std::endl;
			std::string cpf_digitado;
			std::string senha_digitada;
			std::cin>>cpf_digitado>>senha_digitada;

			try{
				u = sistema.verifica_login(cpf_digitado, senha_digitada);
			}

			catch (DadosInvalidos &e){

				std::cout<<e.what()<<std::endl;
				auxiliar = 1;
			
			}
		} while(auxiliar == 1);

		std::cout << std::endl;
		std::cout<<"Obaaaa, conseguimos acessar sua conta :) " << std::endl;
		std::cout << "Voce jah realizou " << u->getQtdCompras() << " compras!" << std::endl;
		std::cout << std::endl;
		std::cout<<"Para saber quais sao nossas opcoes de produtos, digite 1" << std::endl;
		std::cout<<"Para fazer o pedido, digite qualquer outra tecla" << std::endl;

		std::string b;
		std::cin>>b;

		if(b == "1") {
			sistema.informacoes_produtos();
			std::cout<<"Pronto! Agora que voce ja sabe quais os nossos produtos, pode fazer seu pedido." << std::endl;
		}

		int aux = 0;

		do {
			std::cout<<"Digite A para pedir um acai e V para pedir uma vitamina" << std::endl;
			
			char c;
			std::cin>>c;
			if(c == 'A' || c == 'a')
				p = new Acai();
			
			else if(c == 'V' || c == 'v')
				p = new Vitamina();

        	try{
				p->montar();
            	ca->adicionaProduto(p);
				std::cout<< "Prontinho! Seu pedido escolhido foi: " << p->descricao()<<std::endl;
				std::cout<< "Ja adicionamos o produto no carrinho! Deseja pedir mais alguma coisa? Digite 1 para nao ou qualquer outra tecla para sim"<<std::endl;
			
				std::string d;
				std::cin>>d;
				if (d == std::to_string(1))
					aux = 1;
				else
					aux = 0;
			}

        	catch(Incorreto &e) {
            	std::cout<<e.what()<<std::endl;
            	aux = 0;
        	}
			catch (tamanhoInvalido &e) {
				std::cout<<e.what()<<std::endl;
            	aux = 0;
			
			}
    	} while (aux == 0);

		int novo_aux = 0;

		do{
		
			std::cout<< "Os itens no seu carrinho sao: " <<std::endl;
			ca->descricaoFinal();
			std::cout<< "O valor final do pedido eh: " <<ca->calculaTotal(u)<< " reais." << std::endl;
			std::cout<< "Para remover algum produto, digite 1." <<std::endl;
			std::cout<< "Para finalizar o pedido, digite qualquer outra tecla." <<std::endl;
		
			std::string e;
			std::cin>>e;
		
			if(e == "1")
				ca->removeProduto();
			else {
				std::cout << "Nova compra computada no seu usuario!" << std::endl;
				sistema.modifica_usuario(u);
				novo_aux = 1;
			}
		} while(novo_aux == 0);

		std::cout << std::endl;
		std::cout<<"Seu pedido foi computado! Agradecemos pela compra e volte sempre :)"<<std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Deseja continuar o programa? Tecle 1 pra continuar e qualquer outra tecla para sair." << std::endl;
		std::cin >> prog;
	}while(prog == '1');
}