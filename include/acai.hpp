#ifndef ACAI_H
#define ACAI_H

#include "complemento.hpp"
#include "produto.hpp"
#include <exception>
#include <iostream>
#include <vector>
#include <string>

/**
*@file acai.hpp
*@author Yaggo Cardoso (yaggovteixeira@gmail.com)
*@brief Classe Açaí e Classe do tratamento de exceções
*@version 1.0
*@date 27/11/2022
*@details Classe Acai que usará o vector de Complemento para fazer a montagem do açaí e Classe complementoInvalido que fará o tratamento de exceções
*@copyright GNU General Public License v2.0
*/

class Acai : public Produto
{

    /**
    * @brief Classe de montagem do açaí.
    * @details Classe Acai que recebe dois objetos e uma estutura de dados que que será usada para a montagem do açaí.
    */

    private:

        /**
        * @brief Tamanho do açaí.
        */

        int _tamanho;

        /**
        * @brief Quantidade de açaí's.
        */

        int _quantidade;

        /**
        * @brief Vector de tipo Complemento que será usado
        * para adicionar ou remover complementos do açaí.
        */

        std::vector<Complemento> _acrescimos;

    public:

        /**
	* @brief Construtor da Classe Acai.
	* @details Constrói dois novos objetos da Classe Acai.
        * @param tamanho - tamanho do açaí
        * @param quantidade - quantidade de açaí's
        */

        Acai(int tamanho, 
            int quantidade);
        
        /**
	* @brief Função que retorna o tamanho do açaí.
	* @return int - tamanho do açaí.
	*/

        int getTamanho();

        /**
	* @brief Função que retorna a quantidade de açaí's.
	* @return int - quantidade de açaí's.
	*/
	
        int getQuantidade();

        /**
	* @brief Função que calcula o preço total do açaí.
        * @details Função que faz a soma total de quantidade, tamanho e complementos do açaí, retornando o valor final.
	* @return float - preço do açaí.
	*/

        float calculaPreco();

        /**
	* @brief Função que faz a descrição do açaí.
	* @details Função que faz a leitura de todos os atributos e retorna uma descrição detalhada dos componentes do açaí.
	* @return std::string - descrição do açaí.
	*/

        std::string descricao();

        /**
	* @brief Função que remove complementos do açaí.
	* @details Função que acessa o vector de Complemento e remove o último complemento adicionado.
        * @param nome - nome do complemento a ser removido.
	*/

        void removeComplemento(std::string nome);

        /**
	* @brief Função que remove complemento incorreto do açaí.
	* @details Função que acessa o vector de Complemento e remove o último complemento adicionado.
	*/

        void removeComplementoIncorreto();

        /**
	* @brief Função que adiciona complementos ao açaí.
	* @details Função que acessa o vector de Complemento e adicona um novo complemento ao açaí.
        * @param nome - nome do complemento a ser adicionado.
	*/

        void adicionaComplemento(std::string nome);
};

class complementoInvalido : public std::exception
{

    /**
    * @brief Classe para tratamento de exceções, presente na função removeComplemento e adicionaComplemento.
    * @details Classe que faz o throw para quando o nome do complemento inserido não coincidir com as opções.
    */

    private:
    
    	/**
        * @brief Mensagem de erro para complemento.
        */
	
        std::string _msg_erro_complemento;

    public:

        /**
	* @brief Construtor da Classe complementoInvalido.
	* @details Constroi um novo objeto para a Classe complementoInvalido e define uma mensagem de erro.
	*/

        complementoInvalido()
        {
            _msg_erro_complemento = "Complemento inválido. Pressione S se deseja remover o último complemento adicionado ou N se deseja ignorar e seguir em frente.";     
        }

        /**
	* @brief Função que retorna uma mensagem de erro.
	* @details Função que sobrescreve a função what() da Classe mãe std::exception e retorna a mensagem de erro definida no construtor.
	* @return const char* mensagem de erro.
	*/

        const char* what() const noexcept override
        {
            return _msg_erro_complemento.c_str();
        }
};
#endif
