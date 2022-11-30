#ifndef VITAMINA_H
#define VITAMINA_H

#include <iostream>
#include <vector>
#include <string>

#include "produto.hpp"
#include "vitamina.hpp"


/**
*@file vitamina.hpp
*@author Yaggo Cardoso (yaggovteixeira@gmail.com)
*@brief Classe Vitamina
*@version 1.0
*@date 27/11/2022
*@details Classe Vitamina que usará o vector de 
*sabores para fazer a montagem da vitamina e Classe 
*saborInvalido que fará o tratamento de exceções
*@copyright GNU General Public License v2.0
*/

class Produto;

class Vitamina : public Produto  {
   /**
   * @brief Classe de montagem da vitamina.
   * @details Classe que recebe três objetos e faz a montagem 
   * da vitamina usando a estrutura de dados de sabores.
   */

    private:

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
		* @details Constrói um novo objeto da Classe Vitamina.
        */

        Vitamina() = default;

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


#endif