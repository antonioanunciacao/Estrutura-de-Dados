#include <fstream>
#include <string> 
#include <iostream>

/* Essa definição apenas porque é o número de linhas
 * do arquivo 07.txt, como não pode usar o objecto vector,
 * daria mais trabalho construir um vetor dinâmico.
 */
#define NLINHAS 101;

using namespace std;

int main () {
	int num_planetas, num_caracteres;
    string arquivo;

    cout << "Digite o nome do arquivo: " << endl;
    cin >> arquivo;

    ifstream in(arquivo);

    while (in.fail()) {
        cout << "arquivo não existe! digite novamente: " << endl;
        cin >> arquivo;
    } 
	
    in >> Tempo_visitacao >> num_planetas >> num_caracteres;

    string str;
    string vecStr[NLINHAS];
    int vecInt[NLINHAS];
    int i=0;

    while (getline(in, str)) {
        vecInt[i] = stoi(str.substr(0, str.find(' ')));
        vecStr[i] = str.substr(str.find(' '));
        i++;
    }

    for (i = 0 ; i < NLINHAS ; i++ ) {
        cout << vecInt[i] << " : " << vecStr[i] << endl;
    }
}