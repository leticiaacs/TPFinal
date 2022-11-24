#ifndef TP_SISTEMA_H
#define TP_SISTEMA_H

#include <iostream>
#include <list>
#include <string>
#include <map>

//ESCREVER CLASSE DO ERRO AQUI!!!!!

class DadosInvalidos : public std::invalid_argument{
	
	private:
	std::string mensagem_de_erro;
	
	public:
	DadosInvalidos(){
		mensagem_de_erro = "Usuario ou senha invalidos, tentar novamente? Digite S para sim ou qualquer outro caracter para retornar a pagina inicial"
	}
	
	const char* what() const noexcept override {
		
		return mensagem_de_erro.c_str();
	}
}

class Sistema {
	
	private:
	std::list<Usuario*> banco_de_usuarios;
	
	public:
	Usuario inicializacao_usuario();
	Usuario cria_cadastro();
	Usuario verifica_login();
	void informacoes_produtos()
	void fazendo_pedidos();
};


#endif