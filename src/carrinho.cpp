/** 
 * @file carrinho.cpp
 * @author Leon Marcos Felix Goncalves & Naiara Silveira (naiarabarceloss@gmail.com)
 * @brief Classe principal com a lógica do carrinho
 * @version 1.0
 * @date 2022-11-28
 * @details Responsável por setar e retornar os parametros 
 * da compra
 * @copyright GNU General Public License v2.0
*/

#define DESCONTO 0.5

#include <iostream>
#include <vector>
#include <string>
#include "carrinho.hpp"
#include "usuario.hpp"
#include "produto.hpp"


void Carrinho::adicionaProduto(Produto* a){
    std::string c;

    std::cout<<"Voce tem certeza que deseja adicionar este produto ao carrinho? Digite 1 para sim e 2 para nao."<<std::endl;
    std::cin>>c;

    if(c == "1"){

        _pedidosProduto.push_back(a);//Adiciona produtos ao final da lista
        std::cout<<"Produto adicionado a lista com sucesso!"<<std::endl;
            
    }else if(c == "2"){

        std::cout<<"Produto nao adicionado a lista."<<std::endl;

    }else{

        throw Incorreto();
                     
    }
}

void Carrinho::removeProduto(){

    int c=0;

    std::cout<<"Qual produto deseja remover? Digite o NUMERO do produto de acordo com a ordem do pedido"<<std::endl;
    std::cin>>c;

    for(std::vector<Produto*>::iterator it = _pedidosProduto.begin(); it!= _pedidosProduto.end(); it++){

        if(it == (_pedidosProduto.begin() +c - 1))
    		_pedidosProduto.erase(it);
        }


    std::cout<<"Produto removido da lista com sucesso!"<<std::endl;
        
}

float Carrinho::calculaTotal(Usuario* u){

    for(std::vector<Produto*>::iterator it = _pedidosProduto.begin(); it!= _pedidosProduto.end(); it++){

        this->_valorFinal= this->_valorFinal+(*it)->calculaPreco();//Soma o valor de cada produto da lista

    }

    if(u->verificaDesconto()!=0){//retorna preco conforme desconto do usuario
           
        this->_valorFinal=this->_valorFinal*DESCONTO;
        return this->_valorFinal;

    }else{
            
        return this->_valorFinal;

    }

}

void Carrinho::descricaoFinal(){

    for(std::vector<Produto*>::iterator it = _pedidosProduto.begin(); it!= _pedidosProduto.end(); it++){

        std::cout<< (*it)->descricao()<<std::endl;//Exibe a descrição de cada produto da lista

    }

}

std::vector<Produto*> Carrinho::getPedidosProduto(){
    return _pedidosProduto;
}