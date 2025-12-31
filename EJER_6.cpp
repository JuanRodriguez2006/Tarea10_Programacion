#include<iostream>
#include<string>
using namespace std;

//Verificar que sea digito
bool esDigito(char c){
	return (c >= '0' && c <= '9');
}

//Verificar si es operador
bool esOperador(char c){
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=');
}

//separa componentes de la operacion
void separar(string expresion){
	string numeros = "";
	string operadores = "";
	string otros = "";
	
	for(int i = 0; i < expresion.length(); i++){
		char c = expresion[i];
		
		
		if(esDigito(c)){
			//Numeros
			if(numeros != ""){
				numeros += ", ";
			}
			numeros += c;
		}
		else if(esOperador(c)){
			//Operador
			if(operadores != ""){
				operadores += ", ";
			}
			operadores += c;
		}
		else if(c != ' '){  
			//Otros
			if(otros != ""){
				otros += ", ";
			}
			otros += c;
		}
	} 
	
	cout << "\n---RESULTADOS---\n";
	cout << "Numeros: " << numeros << endl;
	cout << "Operadores: " << operadores << endl;
	cout << "Otros: " << otros << endl;
}  

int main(){
	
	string expresion;
	
	cout << "Ingrese una expresion matematica: ";
	getline(cin, expresion);
	
	separar(expresion);
	
	return 0;
}
