/** 
 * @file usuario.hpp
 * @author Naiara Silveira (naiarabarceloss@gmail.com)
 * @brief Classe principal com a lógica do usuário
 * @version 1.0
 * @date 2022-11-27
 * @details Responsável por setar e retornar os parametros 
 * dos usuarios
 * @copyright GNU General Public License v2.0
*/

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include "usuario.hpp"


class Usuario {

    /** 
     * @brief classe que comporta os dados do usuario e cria novos
     * @details parametros e métodos
    */

   private:
   std::string _cpf;
   std::string _senha;
   //total de compras do usuario
   int _qtdCompras;
   
   public:
   
	 /**
    * @brief construtor vazio
    * @details constrói um novo usuário sem nenhum parâmetro
    */
	
	Usuario() = default;

   /**
    * @brief criação de um novo cadastro
    * @details constrói um novo usuário a partir do construtor
    * @param _cpf
    * @param _senha
    * @param _qtdCompras
    */

   Usuario(std::string cpf, std::string senha, int qtdCompras);

   /**
    * @brief retorna senha
    * @details usada na verificacao do login
    */
   std::string getSenha();

    /**
    * @brief retorna cpf
    * @details usada na verificacao do login
    */
   std::string getCPF();

    /**
    * @brief retorna quantas compras o usuario fez
    * @details usada para descontos de fidelidade
    */
   int getQtdCompras();

    /**
    * @brief retorna se a fidelidade é suficiente para receber desconto
    * @details usada para descontos de fidelidade
    */
   bool verificaDesconto();

   /**
    * @brief adiciona uma nova compra ao total
    * @details soma uma nova compra ao finalizar a compra
    */
   void aumentaQtdCompras();

};

#endif