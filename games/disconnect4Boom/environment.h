#ifndef ENVIRONMENT__
#define ENVIRONMENT__

#include <string>

#include <fstream>
using namespace std;

//#include "agent.h"
// -----------------------------------------------------------
//				class Environment
// -----------------------------------------------------------
// Esta clase representa el tablero del juego

class Environment
{
public:

	// Acciones posibles
	enum ActionType { PUT1, PUT2, PUT3, PUT4, PUT5, PUT6, PUT7, BOOM};

    // ------------------------ Constructores y destructor de la clase
    Environment();
	~Environment();
	Environment(const Environment &env);

	// ------------------------- Operador de Asignacion
    Environment& operator=(const Environment& env);

    // ------------------------- Operador de Igualdad
    bool operator==(const Environment & env) const;

    void ModificarTablero(const char *origen);
    void CopiarTablero(char *destino) const;

    // Metodos internos de gestion del propio entorno (no influyen para el desarrollo del metodo a realizar)
	void Show(int,int);
	void Change();
	void AcceptAction(ActionType accion);
	bool EnLinea(int fila, int columna, int &ganador) const;
	bool EnLinea2(int fila, int columna, int &ganador) const;
    void PintaTablero() const;
    void AplicarExplosion(int fila, int columna);
	int RevisarTablero2() const;





    // ------------ Aqui empiezan los metodos que pueden ser de utilidad para el desarrollo del metodo ----------------


	// Este metodo genera todas las situaciones resultantes de aplicar todas las acciones sobre el tablero actual para el
	// jugador que le toca jugar. Cada nuevo tablero se almacena en V, un vector de objetos de esta misma clase. El metodo
	// devuelve el tamano de ese vector, es decir, el numero de movimientos posibles.
	int GenerateAllMoves(Environment *V) const;

	// Este metodo genera el siguiente movimiento que se puede realizar el jugador al que le toca jugar sobre el tablero actual
	// devolviendolo como un objeto de esta misma clase. El parametro "act" indica cual fue el ultimo movimiento que se realizo
	// sobre el tablero. Este metodo asume el siguiente orden en la aplicacion de las acciones: 0 PUT 1, 1 PUT 2, ...,
	// 6 PUT7. Si no hay un siguiente movimiento, el metodo devuelve como tablero el actual.
	// La primera vez que se invoca en un nuevo estado se le pasa como argumento en act el valor -1.
	Environment GenerateNextMove(int &act) const;


	// Devuelve numero de acciones que puede realizar el jugador al que le toca jugar sobre el tablero. "VecAct" es un vector de
	// datos logicos que indican si una determinada accion es aplicable o no. Cada componente del vector esta asociada con una
	// accion. Asi, la [0] indica si PUT 1 es aplicable, [1] si lo es PUT2,y asi sucesivamente.
    int possible_actions(bool *VecAct) const;

    // Indica la ultima accion que se aplico para llegar a la situacion actual del tablero. El entero que se devuelve es el
    // ordinal de la acción.
    int Last_Action(int jug) const;


    // Expresa en una cadena de caracteres un dato del tipo enumerado "ActionType" que se pasa como argumento.
    string ActionStr(ActionType action);

    // Devuelve el jugador al que le toca jugar, siendo 1 el jugador Verde y 2 el jugador Azul.
    int JugadorActivo()const {return jugador_activo_;}

    // Cambia el jugador activo
    void ChangePlayer(){if (jugador_activo_==1) jugador_activo_=2; else {jugador_activo_=1;n_jugada++;}}

    // Devuelve el numero de jugada
    int N_Jugada() const{return n_jugada;}

    // Devuelve verdadera si en la siguiente jugada del jugador activo se colocara una ficha bomba
    bool Put_FichaBOOM_now() const {return (n_jugada%n_veces==0 and !explosion[jugador_activo_]);}

    // Indica el nivel de ocupacion de una determinada columna
    int Get_Ocupacion_Columna(int columna) const {return tope_[columna];}

    // Devuelve verdadero si tengo una casilla bomba en el tablero
    bool Have_BOOM(int jugador) const {return explosion[jugador];}

    // Devuelve el numero de casillas libres que quedan en el tablero
    int Get_Casillas_Libres() const {return casillas_libres_;}

    // Devuelve lo que hay en el tablero en la fila "row" columna "col": 0 vacia, 1 jugador1, 2 jugador2.
    char See_Casilla(int row, int col) const {return maze_[row][col];}

    // Devuelve verdadero cuando el juego ha terminado.
	bool JuegoTerminado()const;

	// Cuando el juego esta terminado devuelve quien ha ganado: 0 Empate, 1 Gana Jugador 1, 2 Gana Jugador2.
	int RevisarTablero() const;




private:

    // Tamano del mapa (Siempre el numero de filas (X) es igual al numero de columnas (Y)
	int MAZE_SIZE;


	// Matriz que codifica el tablero
	char **maze_;

    // Indica la ocupación de cada columna
	char *tope_;

	// Ultimas acciones realizadas por las dos aspiradoras.
	int last_action1_, last_action2_;

	// Jugador al que le toca realizar el siguiente movimiento
	int jugador_activo_;

	// Cantidad de suciedad que debe contener el marcador de un jugador para ganar la partida.
	int casillas_libres_;

	// Posibilidad de explotar una ficha
	bool explosion[3];

	// Numero de jugada
	int n_jugada;

	// Cada cuando aparece una bomba
	int n_veces;

};
// -----------------------------------------------------------

#endif
