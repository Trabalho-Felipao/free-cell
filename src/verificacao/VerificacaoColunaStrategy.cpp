/**
 * @file VerificacaoColunaStrategy.cpp
 * 
 * @author Carlos Sérgio Fernandes Júnior - 2157633 <carlos_fernandes.1@hotmail.com>
 * @author Matheus Paulino Ribeiro - 2143432 <mathpaulinor@gmail.com>
 * @author Nicolas Fagundes Scarpa - 2093087 <bkscarpa@gmail.com>
 * 
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../include/verificacao/VerificacaoColunaStrategy.h"

bool VerificacaoColunaStrategy::podeMovimentar(unsigned short int colunaInicial,
        unsigned short int colunaFinal, const Mesa& mesa) {    
    Carta* cartas = mesa.getCartas();
    if (mesa.encontraUltimaCartaDaColuna(colunaFinal) == COLUNA_VAZIA)
        return true;
    Carta cartaMovimentacao = cartas[mesa.encontraUltimaCartaDaColuna(colunaInicial)];
    Carta cartaComparacao = cartas[mesa.encontraUltimaCartaDaColuna(colunaFinal)];
    return this->corDiferente(cartaMovimentacao, cartaComparacao) &&
        this->valorImediatamenteMenor(cartaMovimentacao, cartaComparacao);
}

bool VerificacaoColunaStrategy::corDiferente(const Carta cartaMovimentacao, const Carta cartaComparacao){
    bool corDiferente;
    switch(cartaMovimentacao.getNaipe()){
        case Simbolo::Naipe::ESPADAS:
        case Simbolo::Naipe::PAUS:
            corDiferente = cartaComparacao.getNaipe() == Simbolo::Naipe::COPAS || 
                cartaComparacao.getNaipe() == Simbolo::Naipe::OUROS;
            break;
        case Simbolo::Naipe::COPAS:
        case Simbolo::Naipe::OUROS:
            corDiferente = cartaComparacao.getNaipe() == Simbolo::Naipe::ESPADAS ||
                cartaComparacao.getNaipe() == Simbolo::Naipe::PAUS;
            break;
    }
    return corDiferente;
}

bool VerificacaoColunaStrategy::valorImediatamenteMenor(const Carta cartaMovimentacao, const Carta cartaComparacao){

    return static_cast<int>(cartaMovimentacao.getValor()) + 1 == static_cast<int>(cartaComparacao.getValor());  
}

std::string VerificacaoColunaStrategy::getMensagemErro() const {
    return this->mensagemErro;
}