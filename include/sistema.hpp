#ifndef TP_SISTEMA_H
#define TP_SISTEMA_H

#include <iostream>
#include <list>
#include <string>

/**
*@file sistema.hpp
*@author Letícia Alexandre
*@brief Classe central do programa, chamada de Sistema e Classe do tratamento de exceções
*@version 1.0
*@date 26/11/2022
*@details Classe Sistema responsável por realizar o procedimento de cadastro e login da loja de açaí, juntamente com a exibição de produtos disponíveis e Classe DadosInvalidos que faz o tratamento de exceções
*@copyright GNU General Public License v2.0
*/

class DadosInvalidos : public std::exception {

	/**
	 * @brief Classe para tratamento de exceções, presente na função de verificar logins
	 * @details Classe que faz o throw para quando o login inserido pelo usuário não for encontrado no banco de dados.
	 */
	
	private:
	std::string mensagem_de_erro;
	
	public:

	/**
	 * @brief Construtor da Classe DadosInvalidos
	 * @details Constrói um novo objeto da Classe DadosInvalidos definindo uma mensagem de erro para o objeto 
	 */

	DadosInvalidos(){
		mensagem_de_erro ="Usuario ou senha invalidos. Tente novamente";
	}

	/**
	 * @brief Função que retorna a mensagem de erro 
	 * @details Função que sobrescreve a função what() da Classe mãe std::exception e retorna a mensagem de erro definida no construtor
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
	 * @details Função que cria o cadastro de um novo usuário, utilizando dados inseridos de cpf e senha e retorna um inteiro para indicar se o cadastro foi bem sucedido ou não
	 * @param cpf_novo - cpf inserido pelo usuário para cadastro
	 * @param senha_nova - senha inserida pelo usuário para cadastro
	 * @return int - 0 para um cadastro bem sucedido e 1 para erro no cadastro
	 */
	int cria_cadastro(long int cpf_novo, std::string senha_nova);

	/**
	 * @brief Função que verifica o login 
	 * @details Função que compara o cpf e senha inseridos com os usuários cadastrados no banco de dados para identificar o usuário e emite uma mensagem de erro caso o login não seja localizado
	 * @param c - cpf inserido pelo usuário para fazer login
	 * @param s - senha inserida pelo usuário para fazer login
	 * @return Usuario - usuário identificado pelo login
	 */
	Usuario verifica_login(long int c, std::string s);

	/**
	 * @brief Função que exibe informações dos produtos
	 * @details Função que mostra ao usuário todos os produtos disponíveis
	 * @return std::string - mensagem em formato de string que descreve os produtos disponíveis
	 */
	std::string informacoes_produtos();
};


#endif