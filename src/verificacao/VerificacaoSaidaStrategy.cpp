#include "../../include/verificacao/VerificacaoSaidaStrategy.h"
#include <iostream> // ! Remover iostream

// TODO: Reimplementar regra
bool VerificacaoSaidaStrategy::podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Estrutura& estrutura) {
    std::cout << "Verificacao Saida Strategy" << std::endl;
    return true;
}

std::string VerificacaoSaidaStrategy::getMensagemErro() const {
    return this->mensagemErro;
}