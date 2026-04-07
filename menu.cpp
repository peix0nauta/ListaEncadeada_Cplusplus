#include "headers.h"
#include "pessoa.h"
#include "lista.h"


void ImprimePessoas(lista &listaDePessoas);
void subMenuInserir(lista &minhaLista);
void subMenuRemover(lista &minhaLista);
void salvararquivo();


void Menuprincipal(lista &minhaLista){
    int opcao;
    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1.Inserir"<<endl<<
                 "2.Remover"<<endl<< 
                 "3.Imprimir"<<endl<< 
                 "4.Salva"<<endl<<
                 "5.procurar pelo CPF"<<endl <<
                "6.sair"<<endl ;
        cin >> opcao;

        switch(opcao) {
            case 1: subMenuInserir(minhaLista); break;
            case 2: subMenuRemover(minhaLista); break;
            case 3: ImprimePessoas(minhaLista); break;
            case 4: minhaLista.salvararquivo(); break;
            case 5: minhaLista.ProcuraRG(); break;
        }
    } while(opcao != 6);
}
void subMenuInserir(lista &minhaLista) {

    int escolha;
        cout << "1.Inicio"<<endl<<
                "2.fim"<<endl<< 
                "3.meio"<<endl<< 
                "4.voltar"<<endl ;

    cin >> escolha;
    
    if(escolha == 1) minhaLista.inserirnocomeço();
    else if(escolha == 2) minhaLista.inserirnofinal();
    else if(escolha == 3) minhaLista.inserirnomeio();
}

void subMenuRemover(lista &minhaLista) {
    int escolha;
    cout << "1.Inicio"<<endl<<
            "2.fim"<<endl<< 
            "3.meio"<<endl<< 
            "4.voltar"<<endl ;
    cin >> escolha;
    
    if(escolha == 1) minhaLista.removerdoinicio();
    else if(escolha == 2) minhaLista.removedofim();
    else if(escolha == 3) minhaLista.removedomeio();
}