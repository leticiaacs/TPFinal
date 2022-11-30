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
*@details Classe Acai que usará o vector de Complemento para fazer a 
*montagem do açaí e Classe complementoInvalido que fará o tratamento 
*de exceções
*@copyright GNU General Public License v2.0
*/

class Acai : public Produto 
{
    /**
    * @brief Classe de montagem do açaí.
    * @details Classe Acai que recebe dois objetos e uma estutura 
    * de dados que que será usada para a montagem do açaí.
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

        Acai(int tamanho, int quantidade);

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

class complementoInvalido : public std::exception
{
    /**
    * @brief Classe para tratamento de exceções, presente na função 
    * montar() no momento de inserir complementos ao açaí.
    * @details Classe que faz o throw para quando o código do complemento 
    * inserido não coincidir com as opções.
    */

    private:
    
    	/**
        * @brief Mensagem de erro para complemento.
        */
	
        std::string _msg_erro_complemento;

    public:

        /**
	* @brief Construtor da Classe complementoInvalido.
	* @details Constroi um novo objeto para a Classe 
        * complementoInvalido e define uma mensagem de erro.
	*/

        complementoInvalido()
        {
            _msg_erro_complemento = "Complemento inválido. Por favor, digite novamente o número correspondente ao complemento desejado.";     
        }

        /**
	* @brief Função que retorna uma mensagem de erro.
	* @details Função que sobrescreve a função what() da Classe mãe 
        * std::exception e retorna a mensagem de erro definida no construtor.
	* @return const char* mensagem de erro.
	*/

        const char* what() const noexcept override
        {
            return _msg_erro_complemento.c_str();
        }
};

class limiteDeComplementos : public std::exception
{
    /**
    * @brief Classe para tratamento de exceções.
    * @details Classe que faz o throw para quando o limite de 
    * complementos for atingido na função montar().
    */

    private:

        /**
        * @brief Mensagem de erro para limite de complementos.
        */

        std::string _msg_limite_complementos;

    public:

        /**
	* @brief Construtor da Classe limiteDeComplementos.
	* @details Constroi um novo objeto para a Classe 
        * limiteDeComplementos e define uma mensagem de erro.
	*/

        limiteDeComplementos()
        {
            _msg_limite_complementos = "Limite de complementos atingido!";
        }

        /**
	* @brief Função que retorna uma mensagem de erro.
	* @details Função que sobrescreve a função what() da Classe mãe
        * std::exception e retorna a mensagem de erro definida no construtor.
	* @return const char* mensagem de erro.
	*/

        const char* what() const noexcept override
        {
            return _msg_limite_complementos.c_str();
        }
};

class acaiSemComplementos : public std::exception
{
    /**
    * @brief Classe para tratamento de exceções.
    * @details Classe que faz o throw para quando o usuário tentar 
    * remover complementos com o açaí já vazio na função montar().
    */

    private:

        /**
        * @brief Mensagem de erro para retirada de complementos.
        */

        std::string _msg_acai_vazio;

    public:

        /**
	* @brief Construtor da Classe AcaiSemComplementos.
	* @details Constroi um novo objeto para a Classe AcaiSemComplementos 
        * e define uma mensagem de erro.
	*/

        acaiSemComplementos()
        {
            _msg_acai_vazio = "Remoção inválida, já não existem complementos no açaí.";
        }

        /**
	* @brief Função que retorna uma mensagem de erro.
	* @details Função que sobrescreve a função what() da Classe mãe 
        * std::exception e retorna a mensagem de erro definida no construtor.
	* @return const char* mensagem de erro.
	*/

        const char* what() const noexcept override
        {
            return _msg_acai_vazio.c_str();
        }
};
#endif
