#include "headers.h"
#include "pessoa.h"
#include "lista.h"

void Menuprincipal(Lista &minhaLista);
void SeparaNomeRG(Lista* &listaDePessoas);



int main() {

    

    Lista* minhaLista = nullptr; 
    SeparaNomeRG(minhaLista);

    if (minhaLista != nullptr) {
        Menuprincipal(*minhaLista); 
        delete minhaLista; 
    }

    

    return 0;
}

void SeparaNomeRG(Lista* &listaDePessoas) {



    string nomeArquivo,linha,nomeaux,rgaux;;
    int começaRG = 0;
    unsigned int tamanho;

    cout << "Digite o numero de pessoas: ";
    cin >> tamanho;

    listaDePessoas = new Lista(tamanho);

    cout << "Digite o nome do arquivo: ";
    cin >> nomeArquivo;
    ifstream arquivo(nomeArquivo);

    for(int i= 0; i<tamanho; i++){
        if (!getline(arquivo, linha)) {
            cout << "Erro ao ler a linha do arquivo." << endl;
            break;

        }
        começaRG = 0;

        for(int j = 0; j < linha.size(); j++){
            if(linha[j] == ','){
                começaRG++;
                
            }
            else if(!começaRG)
                nomeaux += linha[j];
            
            else
                rgaux += linha[j];
            }

        listaDePessoas->InserirRapido(nomeaux, rgaux);

        nomeaux = "";
        rgaux = "";
        }

        listaDePessoas->ExibirMetricas();

}

