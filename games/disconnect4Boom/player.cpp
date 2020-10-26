#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include "player.h"
#include "environment.h"

using namespace std;

const double masinf=9999999999.0, menosinf=-9999999999.0;


// Constructor
Player::Player(int jug){
    jugador_=jug;
}

// Actualiza el estado del juego para el jugador
void Player::Perceive(const Environment & env){
    actual_=env;
}

double Puntuacion(int jugador, const Environment &estado){
    double suma=0;

    for (int i=0; i<7; i++)
      for (int j=0; j<7; j++){
         if (estado.See_Casilla(i,j)==jugador){
            if (j<3)
               suma += j;
            else
               suma += (6-j);
         }
      }

    return suma;
}


// Funcion de valoracion para testear Poda Alfabeta
double ValoracionTest(const Environment &estado, int jugador){
    int ganador = estado.RevisarTablero();

    if (ganador==jugador)
       return 99999999.0; // Gana el jugador que pide la valoracion
    else if (ganador!=0)
            return -99999999.0; // Pierde el jugador que pide la valoracion
    else if (estado.Get_Casillas_Libres()==0)
            return 0;  // Hay un empate global y se ha rellenado completamente el tablero
    else
          return Puntuacion(jugador,estado);
}

// ------------------- Los tres metodos anteriores no se pueden modificar


double Diagonal(const Environment &estado, int jugador, int col)
{
   int valor = 0, repetidas = 0;
   int contador=0;

   for(int fil = 0 ; fil < 7; fil++)
   {
      if(fil<4 && col<4) //diagonal parte derecha
         if(estado.See_Casilla(fil+contador,col+contador) == jugador)
            repetidas++;
         else
            {
               if(repetidas == 2)
                  valor +=100;
               else if(repetidas == 3)
                     valor+=1000;
               else if(repetidas == 1)
                     valor+=10;
               repetidas=0;
            }

      if(fil>2 && col<4) //diagonal parte izquierda
         if(estado.See_Casilla(fil-contador,col+contador) == jugador)
            repetidas++;
         else
            {
               if(repetidas == 2)
                  valor +=100;
               else if(repetidas == 3)
                     valor+=1000;
               else if(repetidas == 1)
                     valor+=10;
               repetidas=0;
            }

      contador++;
   }

   if(repetidas == 2)
         valor +=100;
   else if(repetidas == 3)
         valor+=1000;
   else if(repetidas == 1)
         valor+=10;

   return valor;
}

double Filas(const Environment &estado, int jugador,int fil)
{
   int valor = 0, repetidas = 0;

   for(int col = 0 ; col < 7; col++)
   {
      if(estado.See_Casilla(fil,col) == jugador)
            repetidas++;
      else
      {
         if(repetidas == 2)
            valor +=100;
         else if(repetidas == 3)
               valor+=1000;
         else if(repetidas == 1)
               valor+=10;
         repetidas=0;
      }
      
   }

   if(repetidas == 2)
   {
         valor +=100;
   }
   else if(repetidas == 3)
   {
         valor+=1000;
   }
   else if(repetidas == 1)
   {
         valor+=10;
   }
         
   return valor;
}

double Columna(const Environment &estado, int jugador,int col)
{
   int valor = 0, repetidas = 0;

   for(int fil = 0 ; fil < 7; fil++)
   {
      if(estado.See_Casilla(fil,col) == jugador)
            repetidas++;
      else
      {
         if(repetidas == 2)
            valor +=100;
         else if(repetidas == 3)
               valor+=1000;
         else if(repetidas == 1)
               valor+=10;
         repetidas=0;
      }
   }

   if(repetidas == 2)
         valor +=100;
   else if(repetidas == 3)
         valor+=1000;
   else if(repetidas == 1)
         valor+=10;

   return valor;
}

double Heuristica(const Environment &estado, int jugador)
{
   int v_columnas=0,v_diagonal=0,v_filas=0,valor;

   for(int i=0; i<7; i++)
   {
      v_columnas += Columna(estado,jugador,i);
      v_filas +=Filas(estado,jugador,i);
      v_diagonal+=Diagonal(estado,jugador,i);
   }


   valor = v_columnas + v_diagonal + v_filas;
   return -valor;
}


// Funcion heuristica
double Valoracion(const Environment &estado, int jugador)
{
   int gana = estado.RevisarTablero();

   if(gana == jugador)
   {
      return masinf;
   }
   else if(gana !=0)
      return menosinf;
   else 
   {
      if(jugador == 1)
      {
         return Heuristica(estado,jugador) - Heuristica(estado,2);
      }
      else
      {
         return Heuristica(estado,jugador) - Heuristica(estado,1);
      }
   }
}

double Poda_AlfaBeta(const Environment &E, int jugador, int profundidad, Environment::ActionType &action, double alpha,double beta, bool max_min, double &numeroNodos)
{
   if(profundidad == 0 || E.JuegoTerminado())
   {
      numeroNodos++;
      return Valoracion(E, jugador);
   }

   int act = -1, hijos;
   double nodo;
   Environment::ActionType accion;
   Environment hijo = E.GenerateNextMove(act);
   bool VecAct[8];
   hijos = E.possible_actions(VecAct);

   
   if(!max_min)
   {
      for(int i=0; i<hijos;i++)
      {
         nodo=Poda_AlfaBeta(hijo,jugador,profundidad-1,accion,alpha,beta,true,numeroNodos);
         if(nodo>alpha)
         {
            alpha=nodo;
            action=static_cast<Environment::ActionType>(act);
         }
         if(beta<=alpha)
            break;

         hijo = E.GenerateNextMove(act);
      }
      return alpha;
   }
   else if(max_min)
   {
      for(int i=0; i<hijos;i++)
      {
         nodo=Poda_AlfaBeta(hijo,jugador,profundidad-1,accion,alpha,beta,false,numeroNodos);
         if(nodo<beta)
         {
            beta=nodo;
            action=static_cast<Environment::ActionType>(act);
         }
         if(beta<=alpha)
            break;

         hijo = E.GenerateNextMove(act);
      }
      return beta;
   }
}


// Esta funcion no se puede usar en la version entregable
// Aparece aqui solo para ILUSTRAR el comportamiento del juego
// ESTO NO IMPLEMENTA NI MINIMAX, NI PODA ALFABETA
void JuegoAleatorio(bool aplicables[], int opciones[], int &j){
    j=0;
    for (int i=0; i<8; i++){
        if (aplicables[i]){
           opciones[j]=i;
           j++;
        }
    }
}

vector<int> buscarBomba(const Environment &estado, int jugador)
{
   int bomba;
   vector<int> solucion(2,0);
   bool encontrado=false;

   if(jugador == 1)
      bomba = 4;
   else
      bomba = 5;
      
   for(int i=0; i<7 && !encontrado; i++)
   {
      for(int j=0; j<7 && !encontrado; j++)
      {
         if(estado.See_Casilla(i,j) == bomba)
         {
            solucion[0]=i;
            solucion[1]=j;
            encontrado=true;
         }
      }
   }

   if(!encontrado)
   {
      solucion[0] = -1;
      solucion[1] = -1;
   }
      return solucion;
}


// Invoca el siguiente movimiento del jugador
Environment::ActionType Player::Think(){
    const int PROFUNDIDAD_MINIMAX = 6;  // Umbral maximo de profundidad para el metodo MiniMax
    const int PROFUNDIDAD_ALFABETA = 8; // Umbral maximo de profundidad para la poda Alfa_Beta

    Environment::ActionType accion; // acci�n que se va a devolver
    bool aplicables[8]; // Vector bool usado para obtener las acciones que son aplicables en el estado actual. La interpretacion es
                        // aplicables[0]==true si PUT1 es aplicable
                        // aplicables[1]==true si PUT2 es aplicable
                        // aplicables[2]==true si PUT3 es aplicable
                        // aplicables[3]==true si PUT4 es aplicable
                        // aplicables[4]==true si PUT5 es aplicable
                        // aplicables[5]==true si PUT6 es aplicable
                        // aplicables[6]==true si PUT7 es aplicable
                        // aplicables[7]==true si BOOM es aplicable



    double valor; // Almacena el valor con el que se etiqueta el estado tras el proceso de busqueda.
    double alpha, beta; // Cotas de la poda AlfaBeta

    int n_act; //Acciones posibles en el estado actual
    double numeroNodos=0;




    n_act = actual_.possible_actions(aplicables); // Obtengo las acciones aplicables al estado actual en "aplicables"
    int opciones[10];

    // Muestra por la consola las acciones aplicable para el jugador activo
    //actual_.PintaTablero();
    cout << " Acciones aplicables ";
    (jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
    for (int t=0; t<8; t++)
      if (aplicables[t])
         cout << " " << actual_.ActionStr( static_cast< Environment::ActionType > (t)  );
    cout << endl;

    //--------------------- AQUI EMPIEZA LA PARTE A REALIZAR POR EL ALUMNO ------------------------------------------------
    
   vector<int> bomba(2,0);
   
   bool revisar=true;


   if(actual_.Have_BOOM(jugador_))
   {
      Environment::ActionType explosion;
      Environment estadoExplosion = actual_;
      explosion=static_cast<Environment::ActionType>(7);
      bomba=buscarBomba(actual_,jugador_);

      if(bomba[0] != -1)
      {
         estadoExplosion.AplicarExplosion(bomba[0],bomba[1]);
      }

      if(estadoExplosion.RevisarTablero() == jugador_)
      {
         revisar=false;
         accion=explosion;
      }
   }
   if(revisar)
   {
      valor = Poda_AlfaBeta(actual_, jugador_, PROFUNDIDAD_ALFABETA, accion, menosinf, masinf,false, numeroNodos);
      cout << "Valor AlfaBeta: " << valor << "  Accion: " << actual_.ActionStr(accion) << endl;
   }

   return accion;
}

