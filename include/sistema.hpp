#ifndef TP_SISTEMA_H
#define TP_SISTEMA_H

#include <iostream>
#include <list>
#include <string>
#include "usuario.hpp"
#include "sistema.hpp"
#include "produto.hpp"
#include "carrinho.hpp"

/**
*@file sistema.hpp
*@author Letícia Alexandre
*@brief Classe central do programa, chamada de Sistema e Classe na qual está o tratamento de exceção, chamada de DadosInvalidos
*@version 1.0
*@date 26/11/2022
*@details Classe Sistema responsável por realizar os procedimentos iniciais da loja, como a criação de cadastro, o login do cliente
* e a exibição de informações sobre os produtos (descrição de produtos disponíveis)
*@copyright GNU General Public License v2.0
*/

class DadosInvalidos : public std::exception {

	/**
	 * @brief Classe para tratamento de exceções, presente na função de verificar logins
	 * @details Classe que faz o throw para quando o login inserido pelo usuário não for encontrado no banco de dados
	 */
	
	private:
	std::string mensagem_de_erro;
	
	public:

	/**
	 * @brief Construtor da Classe DadosInvalidos
	 * @details Constrói um novo objeto da Classe DadosInvalidos definindo uma mensagem de erro para o objeto para 
	 * quando a função for chamada.
	 */

	DadosInvalidos(){
		mensagem_de_erro ="Usuario ou senha invalidos. Tente novamente";
	}

	/**
	 * @brief Função que retorna a mensagem de erro 
	 * @details Função que sobrescreve a função what() da Classe mãe std::exception e retorna a mensagem de erro definida no construtor 
	 * (Usuario ou senha invalidos. Tente novamente)
	 * @return const char* mensagem de erro
	 */
	
	const char* what() const noexcept override {
		
		return mensagem_de_erro.c_str();
	}
};

class Sistema {

	/**
	 * @brief Classe central do programa
	 * @details Classe que cria o banco de usuários, realiza os cadastros, faz a verificação de login e exibe os produtos disponíveis na loja.
	 */
	
	private:
	std::list<Usuario*> banco_de_usuarios;
	
	public:
	/**
	 * @brief Construtor da Classe Sistema
	 * @details Constrói um novo objeto da Classe Sistema, usando um construtor vazio 
	 */
	Sistema() = default;

	/**
	 * @brief Função que cria o cadastro
	 * @details Função que cria o cadastro de um novo usuário, utilizando dados inseridos de cpf e senha e retorna um inteiro para 
	 * indicar se o cadastro foi bem sucedido ou não
	 * @param cpf_novo - string cpf com 11 caracteres inseridos pelo usuário para cadastro
	 * @param senha_nova - string senha inserida pelo usuário para cadastro
	 * @return inteiro - retorna 0 para um cadastro bem sucedido e 1 para erro no cadastro. Esses dados serão usados na main para instruir o usuario 
	 * sobre os proximos passos, que dependerão do retorno desta função.
	 */
	int cria_cadastro(std::string cpf_novo, std::string senha_nova);

	/**
	 * @brief Função que verifica o login 
	 * @details Função que compara o cpf e senha inseridos com o cpf e senha de usuarios cadastrados no banco de dados para identificar 
	 * o usuário e emite uma mensagem de erro caso o cadastro não seja localizado. O throw da classe DadosInvalidos se encontra nesta função.
	 * @param c - string cpf de 11 numeros inseridos pelo usuário para fazer login
	 * @param s - string senha inserida pelo usuário para fazer login
	 * @return Usuario - retorna o usuário identificado pelo login, para ser usado em outras funções da main posteriormente
	 */
	Usuario* verifica_login(std::string c, std::string s);

	/**
	 * @brief Função que exibe informações dos produtos
	 * @details Função que mostra ao usuário todos os produtos disponíveis na loja
	 */


	void informacoes_produtos();
	
	/**
	 * @brief Função que modifica o parametro quantidade de pedidos do usuario
	 * @details Função que verifica qual usuario acabou de fazer o pedido e chama a função da classe usuário que aumenta 1 pedido
	 */
	
	void modifica_usuario(Usuario *u);
};


#endif