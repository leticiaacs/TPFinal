#ifndef ACAI_H
#define ACAI_H

#include <exception>
#include <iostream>
#include <vector>
#include <string>

#include "produto.hpp"
#include "acai.hpp"
#include "complemento.hpp"

/**
*@file acai.hpp
*@author Yaggo Cardoso (yaggovteixeira@gmail.com)
*@brief Classe Açaí e Classe do tratamento de exceções
*@version 1.0
*@date 27/11/2022
*@details Classe Acai que usará o vector de Complemento para fazer a 
*montagem do açaí e Classe complementoInvalido que fará o tratamento 
*de exceções
*@copyright GNU General Public License v2.0
*/

class Acai : public Produto {
    /**
    * @brief Classe de montagem do açaí.
    * @details Classe Acai que recebe dois objetos e uma estutura 
    * de dados que que será usada para a montagem do açaí.
    */

    private:

        /**
        * @brief Vector de tipo Complemento que será usado
        * para adicionar ou remover complementos do açaí.
        */

        std::vector<Complemento*> _acrescimos;

    public:

        /**
		* @brief Construtor da Classe Acai.
		* @details Constrói um novo objeto da Classe Acai.
        */

        Acai() = default;

        /**
		* @brief Função que calcula o preço total do açaí.
        * @details Função que faz a soma total de quantidade, 
        * tamanho e complementos do açaí, retornando o valor final.
		* @return float - preço do açaí.
		*/

        float calculaPreco() override;

        /**
		* @brief Função que faz a descrição do açaí.
		* @details Função que faz a leitura de todos os atributos e 
        * retorna uma descrição detalhada dos componentes do açaí.
		* @return std::string - descrição do açaí.
		*/

        std::string descricao() override;

        /**
		* @brief Função que faz a montagem do açaí.
		* @details Função que fará contato iterativo com o cliente para
        * a montagem do açaí. Receberá o tamanho do açaí desejado, uma 
        * quantia de 1 a 5 complementos a serem inseridos, remoção de 
        * complementos a serem removidos do açaí e finalizando quando o
        * cliente estiver satisfeito com seu pedido.
		*/

        void montar() override;
};
#endif