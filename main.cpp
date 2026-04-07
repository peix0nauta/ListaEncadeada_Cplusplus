#include "headers.h"
#include "pessoa.h"
#include "lista.h"


void Menuprincipal(lista &minhaLista);
void SeparaNomeRG(lista &listaDePessoas, int tamanho);
void ImprimePessoas(lista &listaDePessoas);
int main()
{
    unsigned int qntspessoas;
    cout << "Digite a quantidade de pessoas: ";
    cin >> qntspessoas;

    lista listaDePessoas;

    SeparaNomeRG(listaDePessoas, qntspessoas);
    Menuprincipal(listaDePessoas);
    


    return 0;
}

void SeparaNomeRG(lista &listaDePessoas, int tamanho) {

    listaDePessoas.zerarMetricas();
    
    string nomeArquivo, linha, nomeaux, rgaux;
    int começaRG = 0;

    cout << "Digite o nome do arquivo: ";
    cin >> nomeArquivo;
    ifstream arquivo(nomeArquivo);

    for(int i = 0; i < tamanho; i++){
        listaDePessoas.Cn++; listaDePessoas.Mn++;
        Pessoa* nova = new Pessoa();
        
        listaDePessoas.Cn++;
        if (!getline(arquivo, linha)) {
            cout << "Erro ao ler a linha do arquivo." << endl;
            break;
        }
        
        começaRG = 0;
        listaDePessoas.Mn++;

        for(int j = 0; j < linha.size(); j++){
            listaDePessoas.Cn += 2;
            if(linha[j] == ','){
                começaRG++;
                listaDePessoas.Mn++;
            }
            else {
                listaDePessoas.Cn++;
                if(!começaRG){
                    nomeaux += linha[j];
                    listaDePessoas.Mn++;
                }
                else {
                    rgaux += linha[j];
                    listaDePessoas.Mn++;
                }
            }
        }
        listaDePessoas.Cn++;

        nova->Setnome((char*)nomeaux.c_str());
        nova->SetRG((char*)rgaux.c_str());
        listaDePessoas.Mn += 2;

        listaDePessoas.inserirnofinal(nova);
        
        nomeaux = "";
        rgaux = "";
        listaDePessoas.Mn += 2;
    }
    listaDePessoas.Cn++;

    cout << "Lendo e criando a lista" << endl
         << "M(n):" << listaDePessoas.Mn << endl
         <<"C(n):" << listaDePessoas.Cn << endl;
}

void ImprimePessoas(lista &listaDePessoas){
    listaDePessoas.zerarMetricas();
    Pessoa* atual =  listaDePessoas.getprim();
    int i=1;
    listaDePessoas.Mn++;

    while(atual!=nullptr){
        listaDePessoas.Cn++;
        cout << i<<". Nome: " << atual->Getnome() << endl 
             << " | RG: " << atual->GetRG() << endl<<endl;

        atual = atual->getprox();
        i++;
        listaDePessoas.Mn += 2;
    }
    listaDePessoas.Cn++;

    cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-"
         << "Imprimindo a lista" << endl
         << "M(n): " << listaDePessoas.Mn << endl
         << "C(n): " << listaDePessoas.Cn << endl;
}