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
*@details Classe Vitamina que usará o vector de sabores para fazer a montagem da vitamina e Classe saborInvalido que fará o tratamento de exceções
*@copyright GNU General Public License v2.0
*/

class Vitamina : public Produto
{

   /**
   * @brief Classe de montagem da vitamina.
   * @details Classe que recebe três objetos e faz a montagem da vitamina usando a estrutura de dados de sabores.
   */

    private:

        /**
        * @brief Tamanho da vitamina.
        */

        int _tamanho;

        /**
        * @brief Quantidade de vitaminas.
        */

        //int _quantidade;

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
	* @brief Função que retorna o tamanho da vitamina.
	* @return int - tamanho da vitamina.
	*/

        int getTamanho();

        /**
	* @brief Função que retorna a quantidade de vitaminas.
	* @return int - quantidade de vitaminas.
	*/

        int getQuantidade();

        /**
	* @brief Função que retorna sabor da vitamina.
	* @return std::string - sabor da vitamina.
	*/

        std::string getSabor();

        /**
	* @brief Função que calcula o preço total da vitamina.
        * @details Função que faz a soma total de quantidade, tamanho e sabores da vitamina, retornando o valor final.
	* @return float - preço da vitamina.
	*/

        float calculaPreco() override;

        /**
	* @brief Função que faz a descrição da vitamina.
	* @details Função que faz a leitura de todos os atributos e retorna uma descrição detalhada dos componentes da vitamina.
	* @return std::string - descrição do açaí.
	*/

        std::string descricao() override;

        /**
	* @brief Função que remove sabores da vitamina.
	* @details Função que acessa o vector de sabores e remove o último sabor adicionado.
        * @param nome - nome do sabor a ser removido.
	*/

        void removeSabor(std::string sabor);

        /**
	* @brief Função que adiciona sabores na vitamina.
	* @details Função que acessa o vector de sabores e adicona um novo sabor ao a vitamina.
        * @param nome - nome do sabor a ser adicionado.
	*/

        void adicionaSabor(std::string sabor);

        void montar() override;
};

class saborInvalido : public std::exception
{

    /**
    * @brief Classe para tratamento de exceções, presente na função removeSabor e adicionaSabor.
    * @details Classe que faz o throw para quando o nome do sabor inserido não coincidir com as opções.
    */

    private:

        /**
        * @brief Mensagem de erro para sabor.
        */

        std::string _msg_erro_sabor;

    public:

        /**
	* @brief Construtor da Classe saborInvalido.
	* @details Constroi um novo objeto para a Classe saborInvalido e define uma mensagem de erro.
	*/

        saborInvalido()
        {
            _msg_erro_sabor = "Sabor inválido. Pressione S se deseja remover o último sabor adicionado ou N se deseja ignorar e seguir em frente.";
        }

        /**
	* @brief Função que retorna uma mensagem de erro.
	* @details Função que sobrescreve a função what() da Classe mãe std::exception e retorna a mensagem de erro definida no construtor.
	* @return const char* mensagem de erro.
	*/

        const char* what() const noexcept override
        {
            return _msg_erro_sabor.c_str();
        }
};
#endif
