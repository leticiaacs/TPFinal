#ifndef VITAMINA_H
#define VITAMINA_H

#include "produto.hpp"
#include <iostream>
#include <vector>
#include <string>

/**
*@file vitamina.hpp
*@author Yaggo Cardoso (yaggovteixeira@gmail.com)
*@brief Classe Vitamina e Classe do tratamento de exceções
*@version 1.0
*@date 27/11/2022
*@details Classe Vitamina que usará o vector de 
*sabores para fazer a montagem da vitamina e Classe 
*saborInvalido que fará o tratamento de exceções
*@copyright GNU General Public License v2.0
*/

class Vitamina : public Produto
{

   /**
   * @brief Classe de montagem da vitamina.
   * @details Classe que recebe três objetos e faz a montagem 
   * da vitamina usando a estrutura de dados de sabores.
   */

    private:

        /**
        * @brief Tamanho da vitamina.
        */

        int _tamanho;

        /**
        * @brief Quantidade de vitaminas.
        */

        int _quantidade;

        /**
        * @brief Sabor da vitamina.
        */

        std::string _sabor;

        /**
        * @brief Vector usado para armazenar todos os sabores que
        * serão usados para montar a vitamina.
        */

        std::vector<std::string> _saboresVitamina;
    
    public:

        /**
	* @brief Construtor da Classe Vitamina.
	* @details Constrói dois novos objetos da Classe Vitamina.
        * @param tamanho - tamanho da vitamina.
        * @param sabor - sabor da vitamina.
        */

        Vitamina(int tamanho, std::string sabor);

        /**
	* @brief Função que retorna sabor da vitamina.
	* @return std::string - sabor da vitamina.
	*/

        std::string getSabor();

        /**
	* @brief Função que calcula o preço total da vitamina.
        * @details Função que faz a soma total de quantidade, 
        * tamanho e sabores da vitamina, retornando o valor final.
	* @return float - preço da vitamina.
	*/

        float calculaPreco() override;

        /**
	* @brief Função que faz a descrição da vitamina.
	* @details Função que faz a leitura de todos os atributos e
        * retorna uma descrição detalhada dos componentes da vitamina.
	* @return std::string - descrição do açaí.
	*/

        std::string descricao() override;

        /**
	* @brief Função que faz a montagem da vitamina.
	* @details Função que fará contato iterativo com o cliente para
        * a montagem da vitamina. Receberá o tamanho da vitamina desejado, uma 
        * quantia de 1 a 2 sabores a serem inseridos, remoção de 
        * sabores a serem removidos da vitamina e finalizando quando o
        * cliente estiver satisfeito com seu pedido.
	*/

        void montar() override;
};

class saborInvalido : public std::exception
{

    /**
    * @brief Classe para tratamento de exceções, 
    * presente na função montar() no momento de inserir sabores.
    * @details Classe que faz o throw para quando o 
    * nome do sabor inserido não coincidir com as opções.
    */

    private:

        /**
        * @brief Mensagem de erro para sabor.
        */

        std::string _msg_erro_sabor;

    public:

        /**
	* @brief Construtor da Classe saborInvalido.
	* @details Constroi um novo objeto para a Classe 
        * saborInvalido e define uma mensagem de erro.
	*/

        saborInvalido()
        {
            _msg_erro_sabor = "Sabor inválido. Por favor, digite novamente o número correspondente ao sabor desejado.";
        }

        /**
	* @brief Função que retorna uma mensagem de erro.
	* @details Função que sobrescreve a função what() 
        * da Classe mãe std::exception e retorna a mensagem 
        * de erro definida no construtor.
	* @return const char* mensagem de erro.
	*/

        const char* what() const noexcept override
        {
            return _msg_erro_sabor.c_str();
        }
};

class limiteDeSabores : public std::exception
{

    /**
    * @brief Classe para tratamento de exceções.
    * @details Classe que faz o throw para quando o usuário 
    * inserir mais sabores que o permitido.
    */

    private:

        /**
        * @brief Mensagem de erro para limite de sabores.
        */

        std::string _msg_limite_sabores;

    public:

        /**
	* @brief Construtor da Classe limiteDeSabores.
	* @details Constroi um novo objeto para a Classe 
        * limiteDeSabores e define uma mensagem de erro.
	*/

        limiteDeSabores()
        {
            _msg_limite_sabores = "Limite de sabores atingido!";
        }

        /**
	* @brief Função que retorna uma mensagem de erro.
	* @details Função que sobrescreve a função what() da 
        * Classe mãe std::exception e retorna a mensagem de erro 
        * definida no construtor.
	* @return const char* mensagem de erro.
	*/

        const char* what() const noexcept override
        {
            return _msg_limite_sabores.c_str();
        }
};
#endif