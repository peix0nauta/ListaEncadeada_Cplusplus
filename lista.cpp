#include "lista.h"
#include "headers.h"

lista::lista(){
    prim = nullptr;
    ult = nullptr;
    Cn = 0;
    Mn = 0;
}

lista::~lista(){
    Pessoa* atual = prim;
    while (atual != nullptr) {
        Pessoa* prox = atual->getprox();
        delete atual;
        atual = prox;
    }
}



void lista::inserirnofinal(){
    zerarMetricas();
    char n[100], r[12];
    cout << "Nome: "; cin >> n;
    cout << "RG: "; cin >> r;

    Pessoa* nova = new Pessoa();
    nova->Setnome(n);
    nova->SetRG(r);
    Mn += 3;

    Cn++;
    if(prim == nullptr){
        prim = nova;
        ult = nova;
        nova->Setprox(nullptr);
        nova->Setant(nullptr);
        Mn += 4;
    }
    else{
        nova->Setant(ult);
        ult->Setprox(nova);
        ult = nova;
        nova->Setprox(nullptr);
        Mn += 4;
    }
    exibirMetricas();
}

void lista::inserirnocomeço(){
    zerarMetricas();
    char n[100], r[12];
    cout << "Nome: "; cin >> n;
    cout << "RG: "; cin >> r;

    Pessoa* nova = new Pessoa();
    nova->Setnome(n);
    nova->SetRG(r);
    Mn += 3;

    Cn++;
    if(prim == nullptr){
        prim = nova;
        ult = nova;
        nova->Setprox(nullptr);
        nova->Setant(nullptr);
        Mn += 4;
    }
    else{
        prim->Setant(nova);
        nova->Setprox(prim);
        prim = nova;
        Mn += 3;
    }
    exibirMetricas();
}

void lista::inserirnofinal(Pessoa* nova){
    Cn++;
    if(prim == nullptr){
        prim = nova;
        ult = nova;
        nova->Setprox(nullptr);
        nova->Setant(nullptr);
        Mn += 4;
    }
    else{
        nova->Setant(ult);
        ult->Setprox(nova);
        ult = nova;
        nova->Setprox(nullptr);
        Mn += 4;
    }
}

void lista::inserirnomeio(){
    zerarMetricas();
    char n[100], r[12];
    cout << "Nome: "; cin >> n;
    cout << "RG: "; cin >> r;

    Pessoa* nova = new Pessoa();
    nova->Setnome(n);
    nova->SetRG(r);
    Mn += 3;
    
    int posicao, i=1;
    Pessoa* atual = prim;
    Mn += 2;

    cout << "Em qual posição a pessoa vai ser inserida?";
    cin >> posicao;

    Cn += 2;
    if (prim == nullptr || posicao <= 1) {
        inserirnocomeço();
        return;     
    }

    while (atual != nullptr && i < posicao) {
        Cn += 2;
        atual = atual->getprox(); 
        i++;
        Mn += 2;
    }
    Cn++;

    Pessoa* anterior = atual->getant();
    nova->Setprox(atual);      
    nova->Setant(anterior);
    Mn += 3;

    Cn++;
    if (anterior != nullptr) {
        anterior->Setprox(nova);
        Mn++;
    }
    atual->Setant(nova);
    Mn++;
    exibirMetricas();
}

void lista::removerdoinicio() {
    zerarMetricas();
    Cn++;
    if (prim == nullptr) return; 

    Pessoa* aux = prim; 
    prim = prim->getprox(); 
    Mn += 2;

    Cn++;
    if (prim != nullptr) {
        prim->Setant(nullptr);
        Mn++;
    } 
    else {
        ult = nullptr;
        Mn++;
    }

    cout << aux->Getnome() << "removido(a) com sucesso!" << endl;
    delete aux;
    Mn++;
    exibirMetricas();
}

void lista::removedofim(){
    zerarMetricas();
    Cn++;
    if (ult == nullptr) return;

    Pessoa* aux = ult;
    ult = ult->getant();
    Mn += 2;

    Cn++;
    if(ult != nullptr){
        ult->Setprox(nullptr);
        Mn++;
    }
    else {
        prim = nullptr;
        Mn++;
    }

    cout << aux->Getnome() << "removido(a) com sucesso!" << endl;
    delete aux;
    Mn++;
    exibirMetricas();
}

void lista::removedomeio() {
    zerarMetricas();
    Cn++;
    if (prim == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }

    int posicao, i = 0;
    cout << "Em qual posicao a pessoa vai ser removida? ";
    cin >> posicao;

    Cn++;
    if (posicao <= 0) {
        removerdoinicio();
        return;
    }

    Pessoa* aux = prim;
    Mn++;
    while (aux != nullptr && i < posicao) {
        Cn += 2;
        aux = aux->getprox();
        i++;
        Mn += 2;
    }
    Cn++;

    Cn++;
    if (aux == nullptr) {
        cout << "Posicao inexistente!" << endl;
        return;
    }

    Cn++;
    if (aux == ult) {
        removedofim();
        return;
    }

    Pessoa* anterior = aux->getant();
    Pessoa* proxima = aux->getprox();
    Mn += 2;

    anterior->Setprox(proxima);
    proxima->Setant(anterior);
    Mn += 2;
    
    cout << aux->Getnome() << "removido(a) com sucesso!" << endl;
    delete aux;
    Mn++;
    exibirMetricas();
}

void lista::salvararquivo(){
    zerarMetricas();
    string nomearquivo;
    cout <<"Nome do novo arquivo:"<<endl;
    cin >> nomearquivo;

    ofstream arquivo(nomearquivo);

    Cn++;
    if (!arquivo.is_open()) {
        cout << "Erro ao criar o arquivo!" << endl;
        return;
    }

    Pessoa* atual = prim;
    Mn++;

    while(atual != nullptr){
        Cn++;
        arquivo << atual->Getnome() << "," << atual->GetRG() << endl;
        atual = atual->getprox();
        Mn++;
    }
    Cn++;
    arquivo.close();
    cout << "Dados salvos com sucesso em " << nomearquivo << "!" << endl;
    exibirMetricas();
}

void lista::ProcuraRG(){
    zerarMetricas();
    string cpf;
    Pessoa* aux = prim ;
    int encontrou = 0;
    Mn += 2;

    cout << "CPF:";
    cin >> cpf;

    while(aux != nullptr){
        Cn += 2;
        if(aux->GetRG()==cpf){
            cout << "O nome da pessoa é" << aux->Getnome();
            encontrou ++;
            Mn++;
            break;
        }
        aux = aux->getprox();
        Mn++;
    }
    Cn++;

    Cn++;
    if(!(encontrou)){
        cout << "CPF:"<< cpf << "nao esta no sistema.";
    }
    exibirMetricas();
}

void lista::exibirMetricas() {
    cout << "\n>>> [Analise de Desempenho]" << endl;
    cout << ">>> Comparacoes C(n): " << Cn << endl;
    cout << ">>> Movimentacoes M(n): " << Mn << endl;
    cout << "--------------------------" << endl;
}