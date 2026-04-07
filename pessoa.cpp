#include "pessoa.h"
#include "headers.h"


Pessoa::Pessoa(){
    rg[0] = '\0';
    nome[0] = '\0';
    prox = nullptr;
}
Pessoa::~Pessoa(){}

void Pessoa::Setnome(char* nome){
    strcpy(this->nome, nome);
}
void Pessoa::SetRG(char* RG){
    strcpy(this->rg, RG);
}
char* Pessoa::Getnome(){
    return nome;
}   
char* Pessoa::GetRG(){
    return rg;
}
void Pessoa::Setprox(Pessoa* new_prox){
    this->prox = new_prox;
}
void Pessoa::Setant(Pessoa* new_ant){
    this->ant = new_ant;
}