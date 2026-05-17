#include "pessoa.h"
#include "headers.h"

Pessoa::Pessoa(){
    rg[0] = '\0';
    nome[0] = '\0';
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
