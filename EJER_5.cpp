#include<iostream>
#include<string>
using namespace std;

int contarPalabras(string cadena){
	int contador=0;
	bool enPalabra=false;
	for(int i=0;i<cadena.length();i++){
		if(cadena[i]!=' '){
			if(!enPalabra){
				contador++;
				enPalabra=true;
			}
		}else{
			enPalabra=false;
		}
	}
	return contador;
}

int main(){
	
	string frase;
	cout<<"Ingrese una frase:";
	getline(cin, frase);
		
	int totalPalabra=contarPalabras(frase);
	cout<<"\n La frase tiene: "<<totalPalabra<<" palabras.\n";
	
	
return 0;
}
