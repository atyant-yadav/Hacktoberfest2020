
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include <string>
using std::string;
#include "stdlib.h"

#include "environment.h"
#include"include/GL/glui.h"


Environment::Environment(){
    MAZE_SIZE = 7;
	maze_ = new char*[MAZE_SIZE];
	maze_[0] = new char[MAZE_SIZE*MAZE_SIZE];
	for (int i=1; i<MAZE_SIZE; i++)
	  maze_[i] = &(maze_[i-1][0])+7;

    tope_= new char[MAZE_SIZE];


	for (int col=0; col<MAZE_SIZE; col+=1)
	{
		for (int row=0; row<MAZE_SIZE; row+=1)
		{
		    maze_[row][col]=0;
		}// for - col
		tope_[col]=0;
	}// for - row


    jugador_activo_=1;
    casillas_libres_=49;
    last_action1_=-1;
    last_action2_=-1;
    explosion[0]=explosion[1]=explosion[2]=false;
    n_jugada=1;
    n_veces=5;
}

// -----------------------------------------------------------
Environment::~Environment(){
    delete [] maze_[0];
    delete [] maze_;

    delete [] tope_;
}
// -----------------------------------------------------------
Environment::Environment(const Environment &env){
    MAZE_SIZE=env.MAZE_SIZE;

	maze_ = new char*[MAZE_SIZE];
	maze_[0] = new char[MAZE_SIZE*MAZE_SIZE];
	for (int i=1; i<MAZE_SIZE; i++)
	  maze_[i] = &(maze_[i-1][0])+7;

    tope_ = new char[MAZE_SIZE];

    for (int i=0; i<MAZE_SIZE; i++)
      for (int j=0; j<MAZE_SIZE; j++)
        maze_[i][j]=env.maze_[i][j];

    for (int i=0; i<MAZE_SIZE; i++)
        tope_[i]=env.tope_[i];

    jugador_activo_=env.jugador_activo_;
    casillas_libres_=env.casillas_libres_;
    last_action1_=env.last_action1_;
    last_action2_=env.last_action2_;
    for (int i=0; i<3; i++)
        explosion[i]=env.explosion[i];
    n_jugada = env.n_jugada;
    n_veces = env.n_veces;

}
// -----------------------------------------------------------
Environment& Environment::operator=(const Environment& env)
{
    if (this == &env) return *this; // handle self assignment

    if (MAZE_SIZE>0){
      delete [] maze_[0];
      delete [] maze_;

      delete [] tope_;
    }

    MAZE_SIZE=env.MAZE_SIZE;

	maze_ = new char*[MAZE_SIZE];
	maze_[0] = new char[MAZE_SIZE*MAZE_SIZE];
	for (int i=1; i<MAZE_SIZE; i++)
	  maze_[i] = &(maze_[i-1][0])+7;

    tope_ = new char[MAZE_SIZE];

    for (int i=0; i<MAZE_SIZE; i++)
      for (int j=0; j<MAZE_SIZE; j++)
        maze_[i][j]=env.maze_[i][j];

    for (int i=0; i<MAZE_SIZE; i++)
        tope_[i]=env.tope_[i];

    jugador_activo_=env.jugador_activo_;
    casillas_libres_=env.casillas_libres_;
    last_action1_=env.last_action1_;
    last_action2_=env.last_action2_;
    for (int i=0; i<3; i++)
        explosion[i]=env.explosion[i];
    n_jugada = env.n_jugada;
    n_veces = env.n_veces;
}
// -----------------------------------------------------------
void Environment::ModificarTablero(const char *origen){
   for (int i=0; i<49; i++)
     maze_[0][i]=origen[i];
}


void Environment::CopiarTablero(char *destino) const{
   for (int i=0; i<49; i++)
     destino[i]=maze_[0][i];
}


// -----------------------------------------------------------
void Environment::Show(int w,int h)
{
    char m[7][7];
    for (int row=0; row<7; row++)
      for (int col=0; col<7; col++)
         m[6-row][col]=maze_[row][col];

    //cout << "Repintando el tablero\n";

	const static float dirty_level=10.0;
	float length=(float)(w>h?h:w)/(float)(MAZE_SIZE+4);
	float size=0.8*length;
	for (int row=0; row<MAZE_SIZE; row++)
	{
	    //cout << endl;
		for (int col=0; col<MAZE_SIZE; col+=1)
		{
            //cout <<  (char) (maze_[row][col]+'0');
			float x=(col-MAZE_SIZE/2)*length*2+length,y=(MAZE_SIZE/2-row)*length*2-length;
			if (m[row][col] == 1){
				//cout << "XXXXXX";

				glBegin(GL_POLYGON);
					glColor3f(0,1,0);
					glVertex2f(x-(0.9*length),y-(0.9*length));	glVertex2f(x+(0.9*length),y-(0.9*length));
					glVertex2f(x+(0.9*length),y+(0.9*length));	glVertex2f(x-(0.9*length),y+(0.9*length));
				glEnd();
				glBegin(GL_POLYGON);
					glColor3f(1,1,1);
					glVertex2f(x-length,y-length);	glVertex2f(x+length,y-length);
					glVertex2f(x+length,y+length);	glVertex2f(x-length,y+length);
				glEnd();
			}
			else if (m[row][col] == 2){
				//cout << "XXXXXX";

				glBegin(GL_POLYGON);
					glColor3f(0,0,1);
					glVertex2f(x-(0.9*length),y-(0.9*length));	glVertex2f(x+(0.9*length),y-(0.9*length));
					glVertex2f(x+(0.9*length),y+(0.9*length));	glVertex2f(x-(0.9*length),y+(0.9*length));
				glEnd();
				glBegin(GL_POLYGON);
					glColor3f(1,1,1);
					//glColor3f(((float)(dirty_level-maze_[row][col]))/dirty_level,((float)(dirty_level-maze_[row][col]))/dirty_level,((float)(dirty_level-maze_[row][col]))/dirty_level);
					glVertex2f(x-length,y-length);	glVertex2f(x+length,y-length);
					glVertex2f(x+length,y+length);	glVertex2f(x-length,y+length);
				glEnd();
			}
			else if (m[row][col] == 4){
				//cout << "XXXXXX";

                glBegin(GL_POLYGON);
                    glColor3f(0.0,0.0,0.0);
                    for(int j=0;j<100;j++)
                    {
                        float angle = ((2*3.1415926535897*j)/100);

                       glVertex2f(x+size*cos(angle),y+size*sin(angle));
                    }
                glEnd();
				glBegin(GL_POLYGON);
					glColor3f(0,1,0);
					glVertex2f(x-(0.9*length),y-(0.9*length));	glVertex2f(x+(0.9*length),y-(0.9*length));
					glVertex2f(x+(0.9*length),y+(0.9*length));	glVertex2f(x-(0.9*length),y+(0.9*length));
				glEnd();
				glBegin(GL_POLYGON);
					glColor3f(1,1,1);
					glVertex2f(x-length,y-length);	glVertex2f(x+length,y-length);
					glVertex2f(x+length,y+length);	glVertex2f(x-length,y+length);
				glEnd();
			}
			else if (m[row][col] == 5){
				//cout << "XXXXXX";

                glBegin(GL_POLYGON);
                    glColor3f(0.0,0.0,0.0);
                    for(int j=0;j<100;j++)
                    {
                        float angle = ((2*3.1415926535897*j)/100);

                       glVertex2f(x+size*cos(angle),y+size*sin(angle));
                    }
                glEnd();
				glBegin(GL_POLYGON);
					glColor3f(0,0,1);
					glVertex2f(x-(0.9*length),y-(0.9*length));	glVertex2f(x+(0.9*length),y-(0.9*length));
					glVertex2f(x+(0.9*length),y+(0.9*length));	glVertex2f(x-(0.9*length),y+(0.9*length));
				glEnd();
				glBegin(GL_POLYGON);
					glColor3f(1,1,1);
					//glColor3f(((float)(dirty_level-maze_[row][col]))/dirty_level,((float)(dirty_level-maze_[row][col]))/dirty_level,((float)(dirty_level-maze_[row][col]))/dirty_level);
					glVertex2f(x-length,y-length);	glVertex2f(x+length,y-length);
					glVertex2f(x+length,y+length);	glVertex2f(x-length,y+length);
				glEnd();
			}
			else if (m[row][col] == 7){
				//cout << "XXXXXX";

				glBegin(GL_POLYGON);
					glColor3f(0,0,0);
					glVertex2f(x-(0.3*length),y-(0.3*length));	glVertex2f(x+(0.3*length),y-(0.3*length));
					glVertex2f(x+(0.3*length),y+(0.3*length));	glVertex2f(x-(0.3*length),y+(0.3*length));
				glEnd();
				glBegin(GL_POLYGON);
					glColor3f(0,1,0);
					glVertex2f(x-(0.9*length),y-(0.9*length));	glVertex2f(x+(0.9*length),y-(0.9*length));
					glVertex2f(x+(0.9*length),y+(0.9*length));	glVertex2f(x-(0.9*length),y+(0.9*length));
				glEnd();
				glBegin(GL_POLYGON);
					glColor3f(1,1,1);
					glVertex2f(x-length,y-length);	glVertex2f(x+length,y-length);
					glVertex2f(x+length,y+length);	glVertex2f(x-length,y+length);
				glEnd();
			}
			else if (m[row][col] == 8){
				//cout << "XXXXXX";

				glBegin(GL_POLYGON);
					glColor3f(0,0,0);
					glVertex2f(x-(0.3*length),y-(0.3*length));	glVertex2f(x+(0.3*length),y-(0.3*length));
					glVertex2f(x+(0.3*length),y+(0.3*length));	glVertex2f(x-(0.3*length),y+(0.3*length));
				glEnd();
				glBegin(GL_POLYGON);
					glColor3f(0,0,1);
					glVertex2f(x-(0.9*length),y-(0.9*length));	glVertex2f(x+(0.9*length),y-(0.9*length));
					glVertex2f(x+(0.9*length),y+(0.9*length));	glVertex2f(x-(0.9*length),y+(0.9*length));
				glEnd();
				glBegin(GL_POLYGON);
					glColor3f(1,1,1);
					//glColor3f(((float)(dirty_level-maze_[row][col]))/dirty_level,((float)(dirty_level-maze_[row][col]))/dirty_level,((float)(dirty_level-maze_[row][col]))/dirty_level);
					glVertex2f(x-length,y-length);	glVertex2f(x+length,y-length);
					glVertex2f(x+length,y+length);	glVertex2f(x-length,y+length);
				glEnd();
			}
			else
			{
				glBegin(GL_POLYGON);
					glColor3f(0.9,0.9,0.9);
					glVertex2f(x-(0.9*length),y-(0.9*length));	glVertex2f(x+(0.9*length),y-(0.9*length));
					glVertex2f(x+(0.9*length),y+(0.9*length));	glVertex2f(x-(0.9*length),y+(0.9*length));
				glEnd();
				glBegin(GL_POLYGON);
					glColor3f(1,1,1);
					//glColor3f(((float)(dirty_level-maze_[row][col]))/dirty_level,((float)(dirty_level-maze_[row][col]))/dirty_level,((float)(dirty_level-maze_[row][col]))/dirty_level);
					glVertex2f(x-length,y-length);	glVertex2f(x+length,y-length);
					glVertex2f(x+length,y+length);	glVertex2f(x-length,y+length);
				glEnd();
				//cout << symbol;
				//cout << setw(4) << maze_[row][col];
				//cout << symbol;


			}
		}// for - col
		//cout << endl;
	}// for - row
    /*for (int row=0; row<7; row++)
      for (int col=0; col<7; col++)
          if (maze_[row][col]>2)
             maze_[row][col]-=2;*/


}
// -----------------------------------------------------------
void Environment::Change()
{
}
// -----------------------------------------------------------
void Environment::AcceptAction(Environment::ActionType action)
{
    //cout << "AcceptAction: " << ActionStr(action) << endl;
    int i;
    switch (action){
		case Environment::PUT1:
                                if (n_jugada%n_veces==0 and !explosion[jugador_activo_]){
                                    explosion[jugador_activo_]=true;
                                    maze_[tope_[0]][0]=jugador_activo_+3;
                                }
                                else
                                    maze_[tope_[0]][0]=jugador_activo_;

                                casillas_libres_--;
                                tope_[0]++;
                                break;
		case Environment::PUT2:
                                if (n_jugada%n_veces==0 and !explosion[jugador_activo_]){
                                    explosion[jugador_activo_]=true;
                                    maze_[tope_[1]][1]=jugador_activo_+3;
                                }
                                else
                                    maze_[tope_[1]][1]=jugador_activo_;

                                casillas_libres_--;
                                tope_[1]++;
                                break;
		case Environment::PUT3:
                                if (n_jugada%n_veces==0 and !explosion[jugador_activo_]){
                                    explosion[jugador_activo_]=true;
                                    maze_[tope_[2]][2]=jugador_activo_+3;
                                }
                                else
                                    maze_[tope_[2]][2]=jugador_activo_;

                                casillas_libres_--;
                                tope_[2]++;
                                break;
		case Environment::PUT4:
                                if (n_jugada%n_veces==0 and !explosion[jugador_activo_]){
                                    explosion[jugador_activo_]=true;
                                    maze_[tope_[3]][3]=jugador_activo_+3;
                                }
                                else
                                    maze_[tope_[3]][3]=jugador_activo_;

                                casillas_libres_--;
                                tope_[3]++;
                                break;
		case Environment::PUT5:
                                if (n_jugada%n_veces==0 and !explosion[jugador_activo_]){
                                    explosion[jugador_activo_]=true;
                                    maze_[tope_[4]][4]=jugador_activo_+3;
                                }
                                else
                                    maze_[tope_[4]][4]=jugador_activo_;

                                casillas_libres_--;
                                tope_[4]++;
                                break;
		case Environment::PUT6:
                                if (n_jugada%n_veces==0 and !explosion[jugador_activo_]){
                                    explosion[jugador_activo_]=true;
                                    maze_[tope_[5]][5]=jugador_activo_+3;
                                }
                                else
                                    maze_[tope_[5]][5]=jugador_activo_;

                                casillas_libres_--;
                                tope_[5]++;
                                break;
		case Environment::PUT7:
                                if (n_jugada%n_veces==0 and !explosion[jugador_activo_]){
                                    explosion[jugador_activo_]=true;
                                    maze_[tope_[6]][6]=jugador_activo_+3;
                                }
                                else
                                    maze_[tope_[6]][6]=jugador_activo_;

                                casillas_libres_--;
                                tope_[6]++;
                                break;
		case Environment::BOOM:
                                // Desactivar la opcion de explosion al jugador actual
                                //cout << "\t Antes del boom\n";
                                if (!explosion[jugador_activo_]){
                                    cout << "\t\tNo tiene ficha bomba\n";
                                }

                                explosion[jugador_activo_]=false;


                                // Buscar la casilla con la bomba
                                int i=0,j;
                                bool encontrado=false;
                                while (!encontrado and i<7 ){
                                    j=0;
                                    while (j<7 and !encontrado)
                                        if (maze_[i][j]!=jugador_activo_+3)
                                            j++;
                                        else
                                            encontrado=true;
                                    if (!encontrado)
                                        i++;
                                }


                                // Esta en la coordenada (i,j)
                                //cout << "i: " << i << " j: "<< j << endl;
                                if (encontrado){
                                    AplicarExplosion(i,j);
                                    //cout << "\t Despues del boom\n";
                                    //PintaTablero();
                                }
                                else
                                    cout << "No encontrada la ficha bomba\n";


                                break;
    }

    //PintaTablero();

    if (jugador_activo_==1)
        last_action1_ = (int) (action);
    else
        last_action2_ = (int) (action);


}
// -----------------------------------------------------------
int Environment::possible_actions(bool *act) const{

   for (int i=0; i<7; i++)
     if (tope_[i]<7)
        act[i]=true;
     else
        act[i]=false;


    act[7]=explosion[jugador_activo_];

    int n_act=0;
    for (int i=0; i<8; i++)
      if (act[i])
        n_act++;

    return n_act;
}

//------------------------------------------------------------------------

int Environment::GenerateAllMoves(Environment *V) const{
  bool act[8];
  int n_act=0;
  possible_actions(act);
  for (int i=0; i<8; i++){
    if (act[i]){
       V[n_act] = *this;
       V[n_act].AcceptAction(static_cast<ActionType> (i));
       V[n_act].ChangePlayer();
       n_act++;
    }
  }
  return n_act;
}

Environment Environment::GenerateNextMove(int &act) const{
    bool posibles[8];
    possible_actions(posibles);
    act++;
    while (act<8 and !posibles[act])
      act++;
    if (act>=8){
        return *this;
    }
    else{
        Environment nuevo = *this;
        nuevo.AcceptAction(static_cast<ActionType> (act));
        nuevo.ChangePlayer();
        return nuevo;
    }
}

// -----------------------------------------------------------
int Environment::Last_Action(int jug) const{
    if (jug==1)
      return last_action1_;
    else
      return last_action2_;
}
// -----------------------------------------------------------
bool Environment::EnLinea(int fila, int columna, int &ganador) const{
    if (maze_[fila][columna]==0)
        return false;
    ganador=0;
    //En la misma Fila
    if (columna<4){
      if ((maze_[fila][columna]%3)   == (maze_[fila][columna+1]%3) and
          (maze_[fila][columna+1]%3) == (maze_[fila][columna+2]%3) and
          (maze_[fila][columna+2]%3) == (maze_[fila][columna+3]%3)){
          //cout << "En la misma fila\n";
          ganador= (maze_[fila][columna]%3);
          return true;
      }
    }
    //En la misma columna
    if (fila<4){
      if ((maze_[fila][columna]%3)   == (maze_[fila+1][columna]%3) and
          (maze_[fila+1][columna]%3) == (maze_[fila+2][columna]%3) and
          (maze_[fila+2][columna]%3) == (maze_[fila+3][columna]%3)){
          //cout << "En la misma columna\n";

          ganador= (maze_[fila][columna]%3);
          return true;
      }
    }
    //En la diagonal hacia arriba
    if (fila<4 and columna<4){
      if ((maze_[fila][columna]%3)     == (maze_[fila+1][columna+1]%3) and
          (maze_[fila+1][columna+1]%3) == (maze_[fila+2][columna+2]%3) and
          (maze_[fila+2][columna+2]%3) == (maze_[fila+3][columna+3]%3)){
          //cout << "En la diagonal principal\n";

          ganador= (maze_[fila][columna]%3);
          return true;
      }
    }

    //En la diagonal hacia abajo
    if (fila>2 and columna<4){
      if ((maze_[fila][columna]%3)   == (maze_[fila-1][columna+1]%3) and
          (maze_[fila-1][columna+1]%3) == (maze_[fila-2][columna+2]%3) and
          (maze_[fila-2][columna+2]%3) == (maze_[fila-3][columna+3]%3)){
          //cout << "En la diagonal secundaria\n";

          ganador= (maze_[fila][columna]%3);
          return true;
      }
    }

    return false;

}


// -----------------------------------------------------------
bool Environment::EnLinea2(int fila, int columna, int &ganador) const{
    if (maze_[fila][columna]==0)
        return false;
    ganador=0;
    //En la misma Fila
    if (columna<4){
      if ((maze_[fila][columna]%3)   == (maze_[fila][columna+1]%3) and
          (maze_[fila][columna+1]%3) == (maze_[fila][columna+2]%3) and
          (maze_[fila][columna+2]%3) == (maze_[fila][columna+3]%3)){
          //cout << "En la misma fila\n";
          ganador= (maze_[fila][columna]%3);
          if (ganador==1){
              maze_[fila][columna]=7;
              maze_[fila][columna+1]=7;
              maze_[fila][columna+2]=7;
              maze_[fila][columna+3]=7;
          }
          else{
              maze_[fila][columna]=8;
              maze_[fila][columna+1]=8;
              maze_[fila][columna+2]=8;
              maze_[fila][columna+3]=8;
          }
          return true;
      }
    }
    //En la misma columna
    if (fila<4){
      if ((maze_[fila][columna]%3)   == (maze_[fila+1][columna]%3) and
          (maze_[fila+1][columna]%3) == (maze_[fila+2][columna]%3) and
          (maze_[fila+2][columna]%3) == (maze_[fila+3][columna]%3)){
          //cout << "En la misma columna\n";

          ganador=(maze_[fila][columna]%3);
          if (ganador==1){
              maze_[fila][columna]=7;
              maze_[fila+1][columna]=7;
              maze_[fila+2][columna]=7;
              maze_[fila+3][columna]=7;
          }
          else{
              maze_[fila][columna]=8;
              maze_[fila+1][columna]=8;
              maze_[fila+2][columna]=8;
              maze_[fila+3][columna]=8;

          }
          return true;
      }
    }
    //En la diagonal hacia arriba
    if (fila<4 and columna<4){
      if ((maze_[fila][columna]%3)     == (maze_[fila+1][columna+1]%3) and
          (maze_[fila+1][columna+1]%3) == (maze_[fila+2][columna+2]%3) and
          (maze_[fila+2][columna+2]%3) == (maze_[fila+3][columna+3]%3)){
          //cout << "En la diagonal principal\n";

          ganador=(maze_[fila][columna]%3);
          if (ganador==1){
              maze_[fila][columna]=7;
              maze_[fila+1][columna+1]=7;
              maze_[fila+2][columna+2]=7;
              maze_[fila+3][columna+3]=7;
          }
          else{
              maze_[fila][columna]=8;
              maze_[fila+1][columna+1]=8;
              maze_[fila+2][columna+2]=8;
              maze_[fila+3][columna+3]=8;
          }
          return true;
      }
    }

    //En la diagonal hacia abajo
    if (fila>2 and columna<4){
      if ((maze_[fila][columna]%3)     == (maze_[fila-1][columna+1]%3) and
          (maze_[fila-1][columna+1]%3) == (maze_[fila-2][columna+2]%3) and
          (maze_[fila-2][columna+2]%3) == (maze_[fila-3][columna+3]%3)){
          //cout << "En la diagonal secundaria\n";

          ganador=(maze_[fila][columna]%3);
          if (ganador==1){
              maze_[fila][columna]=7;
              maze_[fila-1][columna+1]=7;
              maze_[fila-2][columna+2]=7;
              maze_[fila-3][columna+3]=7;
          }
          else{
              maze_[fila][columna]=8;
              maze_[fila-1][columna+1]=8;
              maze_[fila-2][columna+2]=8;
              maze_[fila-3][columna+3]=8;
          }
          return true;
      }
    }

    return false;

}


// -----------------------------------------------------------
bool Environment::JuegoTerminado() const{
    if (casillas_libres_==0){
      //cout << "Juego Terminado\n";
      return true;
    }

    bool cuatro_en_raya=false;
    int ganador;

    for (int i=0; !cuatro_en_raya and i<7; i++)
      for (int j=0; !cuatro_en_raya and j<7; j++){
          if (maze_[i][j]!=0)
            cuatro_en_raya=EnLinea(i,j,ganador);
      }

    /*if (cuatro_en_raya)
            cout << "Juego Terminado\n";*/
    if (ganador==1)
        ganador=2;
    else if (ganador==2)
        ganador=1;


    return cuatro_en_raya;
}

// -----------------------------------------------------------
int Environment::RevisarTablero() const{
    bool cuatro_en_raya=false;
    int ganador;

    for (int i=0; !cuatro_en_raya and i<7; i++)
      for (int j=0; !cuatro_en_raya and j<7; j++){
          if (maze_[i][j]!=0)
            cuatro_en_raya=EnLinea(i,j,ganador);
      }

    if (ganador==1)
        ganador=2;
    else if (ganador==2)
        ganador=1;


    if (cuatro_en_raya)
       return ganador;
    else
       return 0;
}


// -----------------------------------------------------------
int Environment::RevisarTablero2() const{
    bool cuatro_en_raya=false;
    int ganador;

    for (int i=0; !cuatro_en_raya and i<7; i++)
      for (int j=0; !cuatro_en_raya and j<7; j++){
          if (maze_[i][j]!=0)
            cuatro_en_raya=EnLinea2(i,j,ganador);
      }

    if (ganador==1)
        ganador=2;
    else if (ganador==2)
        ganador=1;

    if (cuatro_en_raya){
       return ganador;
    }
    else
       return 0;
}

// -----------------------------------------------------------
bool Environment::operator==(const Environment & env) const{
    bool iguales=true;
    for (int i=0; i<MAZE_SIZE and iguales; i++)
      for (int j=0; j<MAZE_SIZE and iguales; j++)
        if (maze_[i][j]!=env.maze_[i][j])
          iguales=false;
    return iguales;
}



void Environment::PintaTablero()const{
  for (int row=6; row>=0; row--){
     for (int col=0; col<7; col++){
        cout << (char) (maze_[row][col]+48);
     }
    cout << endl;
  }
}


// Elimina todas las fichas de la fila
void Environment::AplicarExplosion(int fila, int columna){
    // Mirar si en la explosion desaparece la bomba del adversario
    int adversario=2;
    if (jugador_activo_==2)
        adversario=1;


    // for (int x=0; x<7; x++)
    //         if (maze_[fila][x]==adversario+3)
    //             explosion[adversario]=false;

    // Elimino toda la fila
    bool ficha_eliminada;
    for (int x=0; x<7; x++){
        int t = fila;
        ficha_eliminada = false;
        if (maze_[t][x]==jugador_activo_ or maze_[t][x]==jugador_activo_+3){
            ficha_eliminada=true;
            while (t<6 and maze_[t+1][x]!=0){
                maze_[t][x]=maze_[t+1][x];
                t++;
            }
            maze_[t][x]=0;
            casillas_libres_++;
            tope_[x]--;
        }
    }
    explosion[jugador_activo_]=false;


    // for (int k=0; k<7; k++)
    //     if (tope_[k]<0 or tope_[k]>7)
    //         cout << "Desbordado el tope de la columna " << k+1 << endl;

}

string Environment::ActionStr(ActionType action)
{
	switch (action)
	{
	case Environment::PUT1: return "PUT 1";
	case Environment::PUT2: return "PUT 2";
	case Environment::PUT3: return "PUT 3";
	case Environment::PUT4: return "PUT 4";
	case Environment::PUT5: return "PUT 5";
	case Environment::PUT6: return "PUT 6";
	case Environment::PUT7: return "PUT 7";
	case Environment::BOOM: return "BOOM ";
	default: return "???";
	}
}
