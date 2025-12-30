#include<iostream>
#include<cstdlib>//para uso del rand (Numero aleatorio)
#include<ctime>//complemento para el rand
using namespace std;

void inicializarTabler(char tablero[][6], int filas){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < 6; j++){
			tablero[i][j] = '~';  // CORRECCIÓN: faltaba = '~'
		}
	}
}

void colocarBarco(char tablero[][6], int filas){
	srand(time(0));//los numeros siempre sean diferentes cada vez
	//fila aleatoria (0-5)
	int fila = rand() % filas;
	//columna aleatoria(0-3)
	int colInicio = rand() % 4; // el rand genera aleatorios grandes
	//uso el % para limitar el rango
	//colocar el barco
	for(int j = colInicio; j < colInicio + 3; j++){
		tablero[fila][j] = 'B';
	}
}

void mostrarTabler(char tablero[][6], int filas, bool mostrarBarco){
	cout << "--Tablero--\n";
	cout << "  0 1 2 3 4 5\n";
	
	for(int i = 0; i < filas; i++){
		cout << i << " ";
		for(int j = 0; j < 6; j++){
			if(mostrarBarco){
				cout << tablero[i][j] << " ";
			} else {
				if(tablero[i][j] == 'B'){
					cout << "~ ";
				} else {
					cout << tablero[i][j] << " ";
				}
			}
		}
		cout << endl;
	}
}

bool coordenada(int fila, int columna){
	return (fila >= 0 && fila < 6 && columna >= 0 && columna < 6);
}

bool disparo(char tablero[][6], int fila, int columna){
	if(tablero[fila][columna] == 'B'){
		tablero[fila][columna] = 'X'; //Marcar disparo acertó
		return true;
	} else {
		tablero[fila][columna] = 'O'; //Marcar disparo falló
		return false;
	}
}

int contarDisparo(char tablero[][6], int filas){  // CORRECCIÓN: era "tabero"
	int impacto = 0;
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < 6; j++){
			if(tablero[i][j] == 'X'){
				impacto++;
			}
		}
	}
	return impacto;
}

int main(){
	char tablero[6][6];
	int fila, columna;
	
	//inicializar
	inicializarTabler(tablero, 6);
	
	//colocar BARCO ALEATORIO
	colocarBarco(tablero, 6);
	
	//Mostrar el tablero 
	cout << "---TABLERO---\n";
	mostrarTabler(tablero, 6, false);
	
	bool jugando = true;
	
	while(jugando){
		mostrarTabler(tablero, 6, false);
		
		do{
			cout << "Ingrese la fila de disparo (0-5): ";
			cin >> fila;
			cout << "Ingrese la columna de disparo (0-5): ";
			cin >> columna;
			
			if(!coordenada(fila, columna)){
				cout << "Coordenadas fuera de rango\n";
			}
		} while(!coordenada(fila, columna));  // CORRECCIÓN: llave bien colocada
		
		// CORRECCIÓN: Este código debe estar FUERA del do-while
		if(tablero[fila][columna] == 'X' || tablero[fila][columna] == 'O'){
			cout << "Ya disparaste en esta posicion\n";
			continue;
		}
		
		bool impacto = disparo(tablero, fila, columna);
		
		if(impacto){
			cout << "¡Le diste al barco!\n";
		} else {
			cout << "No le diste al barco\n";
		}
		
		int impactos = contarDisparo(tablero, 6);
		
		if(impactos == 3){
			cout << "¡Hundiste al barco!\n";
			mostrarTabler(tablero, 6, true);
			jugando = false;
		}
		
		if(jugando){
			char continuar;
			cout << "¿Otro disparo? (s/n): ";
			cin >> continuar;
			if(continuar == 'n' || continuar == 'N'){
				cout << "Tablero final:\n";
				mostrarTabler(tablero, 6, true);
				jugando = false;
			}
		}
	}
	
	return 0;
}
