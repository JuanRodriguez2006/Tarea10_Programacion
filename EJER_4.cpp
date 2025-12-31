#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct PocionMagica{
    string nombre;
    vector<string> listaIngredientes;
    int minutosPreparacion;
    string efecto;
};

void registrarPocion(PocionMagica &p){
    string ingrediente;

    cout << "Ingrese el nombre de la pocion: ";
    getline(cin, p.nombre);

    cout << "Ingrese los 3 ingredientes:" << endl;
    for(int i = 0; i < 3; i++){
        getline(cin, ingrediente);
        p.listaIngredientes.push_back(ingrediente);
    }

    cout << "Ingrese el tiempo de preparacion (minutos): ";
    cin >> p.minutosPreparacion;
    cin.ignore();

    cout << "Ingrese el efecto magico: ";
    getline(cin, p.efecto);
}

void consultarIngrediente(string &ingBuscado, PocionMagica recetario[]){
    bool encontrado = false;

    for(int i = 0; i < 3; i++){
        for(const string &item : recetario[i].listaIngredientes){
            if(item == ingBuscado){
                encontrado = true;
                cout << "- " << recetario[i].nombre << endl;
            }
        }
    }

    if(!encontrado){
        cout << "No existen pociones con ese ingrediente." << endl;
    }
}

int main(){
    PocionMagica recetario[3];

    for(int i = 0; i < 3; i++){
        cout << "\n--- Pocion " << i + 1 << " ---" << endl;
        registrarPocion(recetario[i]);
    }

    string ingrediente;
    cout << "\nIngrese el ingrediente a buscar: ";
    getline(cin, ingrediente);

    consultarIngrediente(ingrediente, recetario);

return 0;
}
