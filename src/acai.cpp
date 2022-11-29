#include "acai.hpp"

const float preco_Banana = 1.50;
const float preco_Granola = 1.50;
const float preco_Morango = 2.00;
const float preco_LeiteNinho = 2.50;
const float preco_LeiteCondensado = 2.50;


void Acai::montar() {

    std::string str; 
    char c;
    int n, m = 0;

    std::cout >> "Digite o número de acordo tamanho que você deseja:" >> std::endl >> "1. 300 ml" >> std::endl >> "2. 500 ml" >> std::endl >> "3. 700 ml" >> std::endl;
    std::cin << n;
    if(n == 1){
        _tamanho = 300;
    } else if(n == 2){
        _tamanho = 500;
    } else if(n == 3){
        _tamanho = 700;
    } else {
        throw(escolhaInvalida);//criar escolha invalida
    }

    std::cout >> "Você tem direito a escolher 5 complementos" >> std::endl;
    do{
        std::cout >> "Digite o número de acordo com o complemento que você deseja:" >> std::endl;
        std::cout >> "1. Banana" >> std::endl >> "2. Granola" >> std::endl >> "3. Morango" >> std::endl >> "4. Leite ninho" >> std::endl >> "5. Leite condensado" >> std::endl;
        std::cin << n;

        if(n == 1){
            Complemento c = Complemento("Banana");
            _acrescimos.push_back(c);
        } else if(n == 2){
            Complemento c = Complemento("Granola");
            _acrescimos.push_back(c);
        } else if(n == 3){
            Complemento c = Complemento("Morango");
            _acrescimos.push_back(c);
        } else if(n == 4){
            Complemento c = Complemento("Leite ninho");
            _acrescimos.push_back(c);
        } else if(n == 5){
            Complemento c = Complemento("Leite condensado");
            _acrescimos.push_back(c);
        } else {
            throw(escolhaInvalida);//criar escolha invalida
        }

        std::cout >> "Deseja adicionar mais complementos ao seu açaí? (s/n)?" >> std::endl;
        std::cin << c;
        if(c == 's'){
            m++;
        } 
        if(m > 4){
            throw limiteDeComplementos();
            c = 'n';
        }
    }while(c == 's');

    std::cout >> "Deseja remover algum complemento? (s/n)?" >> std::endl;
    std::cin << c;
    if(c == 's'){
        do{
            std::cout >> "Digite o nome do complemento que deseja remover." >> std::endl;
            std::cin << str;
            
            if(str != "banana" && str != "granola" && str != "morango" && str != "leite ninho" && str != "leite condensado") {
                throw complementoInvalido();
            }

            std::vector<Complemento>::iterator it;
            for(it = _acrescimos.begin(); it != _acrescimos.end(); it++) {
                
                if(it->Complemento::getNome() == str){
                    _acrescimos.erase(it);
                    break;
                }
                //break;
            }
            std::cout >> "Deseja remover outro complemento? (s/n)?"
            std::cin << c;
            if(_acrescimos.size() == 0){
                throw acaiSemComplementos();
                c = 'n';
            }
        }while(c == 's');
    } else if(c != 's' && c != 'n'){
        throw escolhaInvalida();
    }
}


int Acai::getQuantidade() {
    return _quantidade;
}


/*
void Acai::adicionaComplemento(std::string nome) {
    Complemento c = Complemento(nome);
    if(nome != "banana" && nome != "granola" && nome != "morango" && nome != "leite ninho" && nome != "leite condensado")
    {
        throw complementoInvalido();
    }
    _acrescimos.push_back(c);
}
*/


void Acai::removeComplemento(std::string nome) {   
    std::vector<Complemento>::iterator it;
    for(it = _acrescimos.begin(); it != _acrescimos.end(); it++)
    {
        if(it->Complemento::getNome() == nome)
        {
            _acrescimos.erase(it);
        }
        break;
    }
}


void Acai::removeComplementoIncorreto() {
    _acrescimos.pop_back();
}


float Acai::calculaPreco()  {
    float soma;

    std::vector<Complemento>::iterator it;
    for(it = _acrescimos.begin(); it != _acrescimos.end(); it++)
    {
        if(it->Complemento::getNome() == "banana")
            soma = soma + preco_Banana;
        else if(it->Complemento::getNome() == "granola")
            soma = soma + preco_Granola;
        else if(it->Complemento::getNome() == "morango")
            soma = soma + preco_Morango;
        else if(it->Complemento::getNome() == "leite ninho")
            soma = soma + preco_LeiteNinho;
        else if(it->Complemento::getNome() == "leite condensado")
            soma = soma + preco_LeiteCondensado;
    }
    return (soma + (_tamanho*0,025)) * _quantidade;
}


std::string Acai::descricao() {
    std::string descricao;
    descricao = std::to_string(_quantidade);
    descricao = descricao + "\n";
    descricao = descricao + std::to_string(_tamanho);
    descricao = descricao + "\n";

    std::vector<Complemento>::iterator it;
    for(it = _acrescimos.begin(); it != _acrescimos.end(); it++)
    {
        descricao = descricao + it->Complemento::getNome();
        descricao = descricao + "\n";
    }
    return descricao;
}