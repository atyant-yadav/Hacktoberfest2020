////////////////////////////////////////////////////////////////////////////////
//Este programa es para diseñar el tablero de una partida de buscaminas.
//Guión prácticas-sesión 12-Ejercicio 29-Relación de problemas III.
//Francisco Matilla Serrano Grupo 2.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <random> // -> generación de números pseudoaleatorios 
#include <chrono> // -> para la semilla

using namespace std;

class TableroBuscaMinas {
private:
	static const int MAXFILAS = 50;
	static const int MAXCOLUMNAS = 30;
	
	bool tablero [MAXFILAS][MAXCOLUMNAS];
	int util_filas;
	int util_columnas;
	
public:
	
	TableroBuscaMinas (int filas, int columnas){
		
		int util_filas = filas;
		int util_columnas = columnas;
		
		for (int i = 0; i < filas; i++)
			for (int j = 0; j < columnas; j++)
				tablero [i][j] = false;
	}
	
	void ColocarMina (int i, int j){
		tablero [i][j] = true;
	}
	
	void QuitarMina (int i, int j){
		tablero [i][j] = false;
	}
	
	int ContarMinas (int i, int j){
		int contador = 0;
		
		if (tablero [i][j] == true){
			return -1;     //Hay mina en esa casilla.
		}else{
				
				if (i > 0 && j > 0 && i < util_filas-1 && j < util_columnas-1){//Casillas centrales.
					//Se comprueban las casillas de alrededor (8).
					if (tablero [i-1][j-1] == true){
						contador++;
					}
					if (tablero [i][j-1] == true){
						contador++;
					}
					if (tablero [i+1][j-1] == true){
						contador++;
					}
					if (tablero [i-1][j] == true){
						contador++;
					}
					if (tablero [i+1][j] == true){
						contador++;
					}
					if (tablero [i-1][j+1] == true){
						contador++;
					}
					if (tablero [i][j+1] == true){
						contador++;
					}
					if (tablero [i+1][j+1] == true){
						contador++;
					}
				}
				
				//Casillas no centrales, es decir, laterales.
				if ((i == 0 || j == 0 || i == util_filas-1 || j == util_columnas-1)){
					/*Filtro general que tienen que cumplir todas las casillas laterales
					para no admitir valores basura o leer de memoria no reservada:
					i-1 >= 0
					j-1 >= 0
					i+1 < util_filas
					j+1 < util_columnas
					*/
					
					/*Se siguen comprobando las mismas 8 casillas de antes pero con el 
					filtro puesto*/
					if (i-1 >= 0 && j-1 >= 0){
						if (tablero [i-1][j-1] == true){
						contador++;
						}
					}
					if (j-1 >= 0 ){
						if (tablero [i][j-1] == true){
						contador++;
						}
					}
					if (j-1 >= 0 && i+1 < util_filas){
						if (tablero [i+1][j-1] == true){
						contador++;
						}
					}
					if (i-1 >= 0){
						if (tablero [i-1][j] == true){
						contador++;
						}
					}
					if (i+1 < util_filas){
						if (tablero [i+1][j] == true){
						contador++;
						}
					}
					if (i-1 >= 0 && i+1 < util_filas){
						if (tablero [i-1][j+1] == true){
						contador++;
						}
					}
					if (j+1 < util_columnas){
						if (tablero [i][j+1] == true){
						contador++;
						}
					}
					if (i+1 < util_filas && j+1 < util_columnas){
						if (tablero [i+1][j+1] == true){
						contador++;
						}
					}
					
				}
			}
	return contador;		
	}
	
};

class GeneradorAleatorioEnteros{
private:
	mt19937 generador_mersenne; // Mersenne twister
	uniform_int_distribution<int> distribucion_uniforme;

	long long Nanosec(){
	return chrono::high_resolution_clock::now().
	time_since_epoch().count();
	}
public:
	GeneradorAleatorioEnteros()
	:GeneradorAleatorioEnteros(0, 1){
	}
	GeneradorAleatorioEnteros(int min, int max){
	const int A_DESCARTAR = 70000;
	// ACM TOMS Volume 32 Issue 1, March 2006
	auto semilla = Nanosec();
	generador_mersenne.seed(semilla);
	generador_mersenne.discard(A_DESCARTAR);
	distribucion_uniforme =
	uniform_int_distribution<int> (min, max);
	}
	int Siguiente(){
	return distribucion_uniforme(generador_mersenne);
	}
};


int main(){
	int minas;
	int filas;
	int columnas;
	
	
	do{
		cout << "Introduzca el n\243mero de filas y de columnas: ";
		cin >> filas >> columnas;	
	}while (!(filas > 0 && columnas > 0));
	
	TableroBuscaMinas mapa (filas, columnas);
	GeneradorAleatorioEnteros minasf (0, filas-1);
	GeneradorAleatorioEnteros minasc (0, columnas-1);
	
	do{
		cout << "Introduzca el n\243mero de minas: ";
		cin >> minas;	
	}while (!(minas > 0 && minas < (filas*columnas)));
	
	/*Este bucle genera las minas, pero tiene un problema, puede darse el caso 
	en el que dos minas coincidan en la misma casilla, sobretodo cuando hay 
	pocas casillas. 
	Esto ocasionaría que hubiera menos minas de las especificadas.*/
	for (int i = 0; i < minas; i++){
		mapa.ColocarMina(minasf.Siguiente(), minasc.Siguiente());
	}
	
	for (int i = 0; i < filas; i++){
		for ( int j = 0; j < columnas; j++){
				cout << mapa.ContarMinas(i,j) << "   ";
		}
		cout << endl;
	}
}
