#include<iostream>
#include<string>
using namespace std;

void extraerDatos(string chat[], int size, string horas[], string usuarios[],string mensajes[]){
	for(int i=0;i<size;i++){
		string linea=chat[i];
		
		//separa hora-usuario
		int pos1= linea.find("//");
		horas[i]=linea.substr(0,pos1);
		
		//separa usuario-mensaje
		int pos2=linea.find("//",pos1+2);
		usuarios[i]=linea.substr(pos1+2,pos2-pos1-2);
		
		//mensaje
		mensajes[i]=linea.substr(pos2+2);
	}
}

void mostrarMensajes(string usuarios[],string horas[], string mensajes[], int size){
	cout<<"\n---Mensajes Extraidos---\n";
	for(int i=0;i<size;i++){
		cout<<"Mensaje "<<i+1<<": \n";
		cout<<" Hora: "<<horas[i]<<endl;
		cout<<" Usuario: "<<usuarios[i]<<endl;
		cout<<" Mensajes: "<<mensajes[i]<<endl;	
		cout<<endl;
	}
}

int contarMensajes(string usuarios[], int size,string nombreUser){
	int contador=0;
	
	for(int i=0;i<size;i++){
		if(usuarios[i]==nombreUser){
			contador++;
		}
	}
	return contador;
}

void mostrar(string usuarios[],int size){
	int mensajeRoberto=contarMensajes(usuarios,size,"Roberto");
	int mensajeBelen=contarMensajes(usuarios,size,"Belen");
	
	cout<<"\n---REPORTE DE MENSAJES---\n";
	cout<<"Roberto envio: "<<mensajeRoberto<<" mensajes\n";
	cout<<"Belen envio: "<<mensajeBelen<<" mensajes\n";
	cout<<"Total de mensajes: "<<size<<endl;
}

int main(){

string chat[] = {
        "08:15//Roberto//Hola perdida, ¿como estas?",
        "08:17//Belen//Bien, gracias. ¿Y tu?",
        "08:20//Roberto//Aqui pensandote. ¿Quieres salir al cine hoy?",
        "08:21//Belen//Tu novia, ¿si te da permiso?",
        "08:22//Roberto//Cual novia?. Es una amiga nomas",
        "08:23//Roberto//mejor tu pide permiso a tu novio?"
    };
		
	int size=6;
	string horas[6];
	string usuarios[6];
	string mensajes[6];
	
	extraerDatos(chat,size,horas,usuarios,mensajes);
	
	mostrarMensajes(horas,usuarios,mensajes,size);
	
	mostrar(usuarios,size);

return 0;
}
