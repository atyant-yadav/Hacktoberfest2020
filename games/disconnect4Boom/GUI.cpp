#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<string>
//#include<windows.h>
//#include<netdb.h>
using namespace std;
#include"GUI.h"
using namespace GUI;
#include<stdlib.h>
#include"environment.h"
#include "player.h"
#include "conexion.h"

const int NEWGAME_BTN_ID=102,SELECTMAP_BTN_ID=103,DISPLAY_BTN_ID=104,NEWMAP_BTN_ID=105;
const int NEWMAP_OK_BTN_ID=202,NEWMAP_CANCEL_BTN_ID=203;
const int SELECTMAP_SELECT_ID=302,SELECTMAP_CANCEL_BTN_ID=303;
const int DO_ONE_STEP_BTN_ID=402,DO_ONE_RUN_BTN_ID=403,NEXT_RUN_BTN_ID=404,DO_ALL_RUN_BTN_ID=405;
const int REINICIAR_BTN_ID=500, CURSOR_PUT1_BTN_ID=501, CURSOR_PUT2_BTN_ID=502, CURSOR_PUT3_BTN_ID=503,
CURSOR_PUT4_BTN_ID=504, CURSOR_PUT5_BTN_ID=505, CURSOR_PUT6_BTN_ID=506, CURSOR_PUT7_BTN_ID=507,CURSOR_BOOM_BTN_ID=508;
const int ERROR_OK_BTN_ID=602;

int main_window;
char field_ip_server[1024]="150.214.190.149",field_nickname[1024]="Tu_NIF",field_ip_ninja[1024]="150.214.190.149";
char display_step[20]="10",display_time[20]="10";
char ip_server[1024],mi_nick[1024],file_name_temp[1024], nick_adversario[1024]="Adversario";
int tx,ty,tw,th;
float magnification_x,magnification_y;
long long life_time=1000,current_time,total_runs=10,current_run,dirty_degree,consumed_energy;
long long total_dirty_degree,total_consumed_energy;
char time_step_msg[100],action_msg[100],dirty_degree_msg[100],consumed_energy_msg[100];


void GUI::cerrar(){

  cout << "Cerrando ventana\n";
}



//int JugadorActivo = 1;
int modo=0, jugador=0;

Environment *env=0;
Player *player1=0, *player2=0;
//RandomNumberGenerator *rng=NULL;
//Evaluator *evaluator=NULL;
Environment::ActionType action;
ifstream fin;
conexion_client Cliente;
conexion_server Servidor;
bool partida_remota=false, esperando_server=false, esperando_client=false;
int conectado;

GLUI *main_glui,*score_glui,*new_map_glui,*select_map_glui,*error_glui, *cursor_glui;
GLUI_Button *new_map_btn,*select_map_btn,*new_map_ok_btn,*new_map_cancel_btn;
GLUI_Button *do_one_step_btn,*display_btn,*do_one_run_btn,*next_run_btn,*do_all_run_btn;
GLUI_Button *cursor_put1, *cursor_put2, *cursor_put3, *cursor_put4, *cursor_put5, *cursor_put6, *cursor_put7, *cursor_boom;
GLUI_Button *reiniciar_btn;
GLUI_Button *quit_btn;
GLUI_StaticText *time_step_text,*action_text,*dirty_degree_text,*consumed_energy_text;
GLUI_StaticText *complete_runs_text,*total_score_text,*average_score_text, *juega_txt;
GLUI_FileBrowser *map_list;
GLUI_RadioGroup *radio1, *radio2;
GLUI_Panel *obj_panel1, *obj_panel2;
GLUI_EditText *obj_ip, *obj_mi_nick;


int GUI::startDraw(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowPosition(50,50);
	glutInitWindowSize(668,693);


    //glutCloseFunc(cerrar);
    //glutWMCloseFunc(cerrar);
    //glutSetOption ( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION );

	main_window=glutCreateWindow("PRACTICA 3: DESCONECTA 4 BOOM");
	GLUI_Master.set_glutReshapeFunc(myGlutReshape);
	glutDisplayFunc(myGlutDisplay);
	//glutIdleFunc(myGlutIdle);
	//glutTimerFunc(100,myGlutTimer2,10);
    glEnable(GL_DEPTH_TEST);


	score_glui=GLUI_Master.create_glui_subwindow(main_window,GLUI_SUBWINDOW_BOTTOM);
		new GLUI_StaticText(score_glui,"");//�H�ťզ氵���j
		time_step_text = new GLUI_StaticText(score_glui,"");
		new GLUI_StaticText(score_glui,"");//�H�ťզ氵���j
		action_text = new GLUI_StaticText(score_glui,"");
		new GLUI_StaticText(score_glui,"");//�H�ťզ氵���j
		dirty_degree_text = new GLUI_StaticText(score_glui,"");
		new GLUI_StaticText(score_glui,"");//�H�ťզ氵���j
		consumed_energy_text = new GLUI_StaticText(score_glui,"");
		new GLUI_StaticText(score_glui,"");//�H�ťզ氵���j
		new GLUI_Column(score_glui,false);
		new GLUI_Column(score_glui,false);
		new GLUI_Column(score_glui,false);
		new GLUI_Column(score_glui,false);
		new GLUI_Column(score_glui,false);
		new GLUI_Column(score_glui,false);
		new GLUI_Column(score_glui,false);
		new GLUI_Column(score_glui,false);
		new GLUI_Column(score_glui,false);
		new GLUI_Column(score_glui,false);
		new GLUI_StaticText(score_glui,"");//�H�ťզ氵���j
//		new GLUI_Column(score_glui,false);
//		new GLUI_Column(score_glui,false);
//		new GLUI_Column(score_glui,false);
		complete_runs_text = new GLUI_StaticText(score_glui,"");
		new GLUI_StaticText(score_glui,"");//�H�ťզ氵���j
		total_score_text = new GLUI_StaticText(score_glui,"");
		new GLUI_StaticText(score_glui,"");//�H�ťզ氵���j
		average_score_text = new GLUI_StaticText(score_glui,"");
		new GLUI_StaticText(score_glui,"");//�H�ťզ氵���j
	   score_glui->set_main_gfx_window( main_window );

      main_glui=GLUI_Master.create_glui_subwindow(main_window,GLUI_SUBWINDOW_RIGHT);
		new GLUI_StaticText(main_glui,"");//�H�ťզ氵���j
		//new_map_btn=new GLUI_Button(main_glui,"NewMap",NEWMAP_BTN_ID,control_cb);
		select_map_btn=new GLUI_Button(main_glui,"Opciones",SELECTMAP_BTN_ID,control_cb);
		new GLUI_StaticText(main_glui,"");//�H�ťզ氵���j
		do_one_step_btn=new GLUI_Button(main_glui,"Jug. Heuristica",DO_ONE_STEP_BTN_ID,control_cb);
		do_one_step_btn->disable();
		do_one_run_btn=new GLUI_Button(main_glui,"Partida Completa",DO_ONE_RUN_BTN_ID,control_cb);
		do_one_run_btn->disable();
		//next_run_btn=new GLUI_Button(main_glui,"NextRun",NEXT_RUN_BTN_ID,control_cb);
		//next_run_btn->disable();
		//do_all_run_btn=new GLUI_Button(main_glui,"DoAllRun",DO_ALL_RUN_BTN_ID,control_cb);
		//do_all_run_btn->disable();
		new GLUI_StaticText(main_glui,"");//�H�ťզ氵���j
		reiniciar_btn=new GLUI_Button(main_glui,"Reiniciar",REINICIAR_BTN_ID,control_cb);
		new GLUI_StaticText(main_glui,"");//�H�ťզ氵���j
		new GLUI_StaticText(main_glui,"");//�H�ťզ氵���j
		new GLUI_StaticText(main_glui,"Opciones de Display");//�H�ťզ氵���j
		new GLUI_EditText(main_glui,"Pasos:",display_step);
		//new GLUI_EditText(main_glui,"Time:",display_time);
		new GLUI_StaticText(main_glui,"");//�H�ťզ氵���j
		display_btn=new GLUI_Button(main_glui,"Display",DISPLAY_BTN_ID,control_cb);
		display_btn->disable();
		new GLUI_StaticText(main_glui,"");//�H�ťզ氵���j
		new GLUI_StaticText(main_glui,"");//�H�ťզ氵���j
		juega_txt =new GLUI_StaticText(main_glui,"");
		cursor_put1=new GLUI_Button(main_glui,"Col 1",CURSOR_PUT1_BTN_ID,control_cb);
		cursor_put1->disable();

		cursor_put2=new GLUI_Button(main_glui,"Col 2",CURSOR_PUT2_BTN_ID,control_cb);
		cursor_put2->disable();

		cursor_put3=new GLUI_Button(main_glui,"Col 3",CURSOR_PUT3_BTN_ID,control_cb);
		cursor_put3->disable();

		cursor_put4=new GLUI_Button(main_glui,"Col 4",CURSOR_PUT4_BTN_ID,control_cb);
		cursor_put4->disable();

		cursor_put5=new GLUI_Button(main_glui,"Col 5",CURSOR_PUT5_BTN_ID,control_cb);
		cursor_put5->disable();

		cursor_put6=new GLUI_Button(main_glui,"Col 6",CURSOR_PUT6_BTN_ID,control_cb);
		cursor_put6->disable();

		cursor_put7=new GLUI_Button(main_glui,"Col 7",CURSOR_PUT7_BTN_ID,control_cb);
		cursor_put7->disable();

		cursor_boom=new GLUI_Button(main_glui,"BOOM",CURSOR_BOOM_BTN_ID,control_cb);
		cursor_boom->disable();

		new GLUI_StaticText(main_glui,"");//�H�ťզ氵���j
		new GLUI_StaticText(main_glui,"");//�H�ťզ氵���j

		quit_btn = new GLUI_Button(main_glui,"Salir",0,(GLUI_Update_CB)exit );//QUIT
	main_glui->set_main_gfx_window( main_window );
	newGame();
	glutMainLoop();
	return 0;
}




void GUI::showScore(){
	ostringstream sout;

	sout.str("");
	if (env->JugadorActivo()==1)
	  sout<<"Juega VERDE";
    else
      sout << "Juega AZUL";
	juega_txt->set_text(sout.str().c_str());


	sout.str("");
	sout<<"JUGADOR VERDE: " << env->ActionStr( (Environment::ActionType) env->Last_Action(1)) << endl;
	time_step_text->set_text(sout.str().c_str());

	sout.str("");
	sout<<"JUGADOR AZUL: " << env->ActionStr( (Environment::ActionType) env->Last_Action(2)) << endl;
	action_text->set_text(sout.str().c_str());

	sout.str("");
	switch(modo){
	    case 2: // soy cliente
	            if (partida_remota and esperando_server)
 	              sout<<"Esperando la jugada de " << nick_adversario << endl;
 	            else
 	              sout<<"Te toca jugar...";
                break;
	    case 3: // soy servidor
	            if (partida_remota and esperando_client)
 	              sout<<"Esperando la jugada de " << nick_adversario << endl;
 	            else
 	              sout<<mi_nick << " te toca jugar...";
                break;
        default:
                sout << "";

	}
	dirty_degree_text->set_text(sout.str().c_str());


	/*sout.str("");
	sout<<"INSTANTE : " << env->Get_Instante() << endl;
	consumed_energy_text->set_text(sout.str().c_str());*/


    sout.str("");
    if (env->JuegoTerminado()){
        int ganador=env->RevisarTablero2();
        if (ganador==2)
          sout<<"GANA EL JUGADOR AZUL"<<endl;
        else if (ganador==1)
           sout<<"GANA EL JUGADOR VERDE" << endl;
             else
           sout<<"SE HA PRODUCIDO UN EMPATE" <<endl;
		cursor_boom->disable();
    }
    else {
        sout << "" <<endl;
    }

	consumed_energy_text->set_text(sout.str().c_str());

	//complete_runs_text->set_text(sout.str().c_str());

	//long long complete_runs=current_run-(current_time!=life_time);
	//The Round has been completed
	sout.str("");
	if (env->Put_FichaBOOM_now())
        sout<<"Jugada: " << env->N_Jugada() << " (Ficha bomba)";
    else
        sout<<"Jugada: " << env->N_Jugada();
	complete_runs_text->set_text(sout.str().c_str());

	/*sout.str("");
	if (Juego_Terminado()){
	    bool act[6];
	    env->possible_actions(act);
        int n_act=0;
        for (int i=0; i<5 and n_act==0; i++)
          if (act[i])
            n_act++;

        if (n_act==0){
            if (env->JugadorActivo()==1)
              sout<<"GANA EL JUGADOR AZUL";
            else
	           sout<<"GANA EL JUGADOR VERDE";
        }
	    else if (env->Marcador(1)>env->Marcador(2))
	           sout<<"GANA EL JUGADOR VERDE";
             else if (env->Marcador(2)>env->Marcador(1))
                    sout<<"GANA EL JUGADOR AZUL";
	              else
	                sout<<"SE HA PRODUCIDO UN EMPATE";
	}
	total_score_text->set_text(sout.str().c_str());

	sout.str("");
    sout<<"SUCIEDAD OBJETIVO: " << env->Suciedad_Objetivo() << endl;
	average_score_text->set_text(sout.str().c_str());
    */

}


void GUI::myGlutReshape(int w,int h){
	GLUI_Master.get_viewport_area(&tx,&ty,&tw,&th);
	glViewport(tx,ty,tw,th);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(tw<=th){
		magnification_x=1;
		magnification_y=(GLfloat)th/(GLfloat)tw;
	}
	else{
		magnification_x=(GLfloat)tw/(GLfloat)th;
		magnification_y=1;
	}
	glOrtho(-10.0*magnification_x,10.0*magnification_x,-10.0*magnification_y,10.0*magnification_y,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}



void GUI::myGlutDisplay(){
	glClearColor(200.0/255,200.0/255,200.0/255,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(-50.0,50.0,-50.0,50.0);
	if(env!=0){
		env->Show(tw,th);
		showScore();
	}
	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}


void GUI::myGlutTimer(int x){
    if (partida_remota){
        if (esperando_server){
          if (!env->JuegoTerminado()){
              //Recibir Accion del servidor
              char aux;
              cout << "Espero accion del servidor" << endl;
              aux = Cliente.Recibir_Accion_del_Servidor()-48;
              cout << "Accion Recibida: " << (int) (aux) << endl;

              action = static_cast<Environment::ActionType> (aux);
              env->AcceptAction(action);
              env->ChangePlayer();
              UpdateButton_Sin_Reiniciar();
              esperando_server=false;
              myGlutDisplay();
              //glutTimerFunc(1000, myGlutTimer2,0);
              if (env->JuegoTerminado()){
                  Cliente.Cerrar_Conexion();
                  esperando_server=false;
                  esperando_client=false;
                  select_map_btn->enable();
		  modo=0;
              }
          }
          else {
              Cliente.Cerrar_Conexion();
              esperando_server=false;
              esperando_client=false;
              select_map_btn->enable();
	      modo=0;
          }
        }
        else if (esperando_client){
          if (!env->JuegoTerminado()){
              //Recibir Accion
              cout << "Esperando la accion del otro jugador" << endl;
              char ac=Servidor.Recibir_Accion()-48;
              cout << "Accion Recibida: " << (int) (ac) << endl;

              //Actualizar el estado
              action = static_cast<Environment::ActionType> (ac);
              env->AcceptAction(action);
              env->ChangePlayer();
              UpdateButton_Sin_Reiniciar();
              esperando_client=false;
              myGlutDisplay();
              //glutTimerFunc(1000, myGlutTimer2,0);
              if (env->JuegoTerminado()){
                  Servidor.Cerrar_Conexion();
                  esperando_server=false;
                  esperando_client=false;
                  select_map_btn->enable();
		  modo=0;
              }
          }
          else {
              Servidor.Cerrar_Conexion();
              esperando_server=false;
              esperando_client=false;
              select_map_btn->enable();
	      modo=0;
          }

        }
    }
}

bool Juego_Terminado(){
    return env->JuegoTerminado();
}


bool Existe(const char *fichname){
    fstream f;
    f.open(fichname,fstream::in);
    if (f.is_open()){
        f.close();
        return true;
    }
    else {
        cout << "No existe el fichero " << fichname << endl;
        return false;
    }
}



void GUI::Load_Conf(){
    fstream f("game.conf",fstream::in);
    string aux;
    getline(f,aux);
    strcpy(ip_server,aux.c_str());
    getline(f,aux);
    strcpy(mi_nick,aux.c_str());
    f.close();
}

void GUI::Save_Conf(){
    strcpy(ip_server,field_ip_server);
    strcpy(mi_nick,field_nickname);
    fstream f("game.conf",fstream::out);
    f << ip_server << endl;
    f << mi_nick << endl;
    f.close();
}


void GUI::control_cb(int id){
	switch(id){
		case SELECTMAP_BTN_ID:
			//new_map_btn->disable();
			select_map_btn->disable();
			if (Existe("game.conf")){
                Load_Conf();
			}
			else {
                Save_Conf();
			}
            strcpy(file_name_temp,field_ip_ninja);
			select_map_glui=GLUI_Master.create_glui("New Game Setting",0,100,100);
                obj_panel1 = new GLUI_Panel( select_map_glui, "Modo de Juego" );
                  radio1 = new GLUI_RadioGroup( obj_panel1, &modo,5,control_cb );
                           new GLUI_RadioButton( radio1, "Normal" );
                           new GLUI_RadioButton( radio1, "Vs mi heuristica" );
                           new GLUI_RadioButton( radio1, "Vs un jugador remoto (yo Cliente)" );
                           new GLUI_RadioButton( radio1, "Vs un jugador remoto (yo Server)" );
                           new GLUI_RadioButton( radio1, "Vs Ninja 1" );
                           new GLUI_RadioButton( radio1, "Vs Ninja 2" );
                           new GLUI_RadioButton( radio1, "Vs Ninja 3" );

                obj_panel2 = new GLUI_Panel( select_map_glui, "Jugador" );
                  radio2 = new GLUI_RadioGroup( obj_panel2,&jugador,2,control_cb );
                          new GLUI_RadioButton( radio2, "Jugador 1 (Verde)" );
                          new GLUI_RadioButton( radio2, "Jugador 2 (Azul)" );
				    obj_mi_nick = new GLUI_EditText(select_map_glui,"Mi Apodo:",mi_nick);
				    //map_list=new GLUI_FileBrowser(select_map_glui,"",false,SELECTMAP_SELECT_ID,control_cb);
				    obj_ip = new GLUI_EditText(select_map_glui,"IP Servidor:",ip_server);
				    obj_ip->set_w(200);
				//conect_btn=new GLUI_Button(select_map_glui,"Conect",CONECT_BTN_ID,control_cb);
				new_map_cancel_btn=new GLUI_Button(select_map_glui,"Ok",SELECTMAP_CANCEL_BTN_ID,control_cb);
			break;
		case DISPLAY_BTN_ID:

				for(long long t=atol(display_step);t>0 && !Juego_Terminado();--t){
                  doOneStep();
                  myGlutDisplay();
				}
				if (Juego_Terminado()){
                  do_one_run_btn->disable();
                  do_one_step_btn->disable();
                  cursor_put1->disable();
                  cursor_put2->disable();
                  cursor_put3->disable();
                  cursor_put4->disable();
                  cursor_put5->disable();
                  cursor_put6->disable();
                  cursor_put7->disable();
                  cursor_boom->disable();
                  display_btn->disable();
				}

			break;
		case NEWMAP_OK_BTN_ID:
			strcpy(field_ip_server,ip_server);
			strcpy(field_nickname,mi_nick);
			newGame();
			//new_map_btn->enable();
			select_map_btn->enable();
			new_map_glui->close();
			break;
		case NEWMAP_CANCEL_BTN_ID:
			//new_map_btn->enable();
			select_map_btn->enable();
            new_map_glui->close();
			break;
		case SELECTMAP_SELECT_ID:
			strcpy(field_ip_server,ip_server);
			strcpy(field_nickname,mi_nick);
			newGame();
			//new_map_btn->enable();
			select_map_btn->enable();
			select_map_glui->close();
			break;
		case SELECTMAP_CANCEL_BTN_ID:
			//new_map_btn->enable();
			strcpy(field_ip_server,ip_server);
			strcpy(field_nickname,mi_nick);
			Save_Conf();
            myGlutDisplay();
            glutPostRedisplay();
            glutSetWindow(main_window);
            glutPostRedisplay();
 			select_map_btn->enable();
			select_map_glui->close();
			partida_remota=false;
			//cout << "Modo: " << modo << "   Jugador Elegido: " << jugador << endl;
			if (modo==2){ // En red yo en modo cliente
	            char mensaje[1024];

                Cliente.Establecer_Conexion(ip_server, "5127");
                cout << "Empezamos las partida..." << endl;
                cout << "Enviando mi nick al servidor..." << endl;
                Cliente.Enviar_Msg(mi_nick);
                cout << "Le mando que voy a jugar contra otra maquina..." << endl;
                Cliente.Enviar_Accion('0');
                cout << "Recibiendo el nick del servidor..." << endl;
                Cliente.Recibir_Msg(nick_adversario);
		cout << "Nick Adversario: " << nick_adversario <<endl;

		mensaje[0]=Cliente.Recibir_Accion_del_Servidor();
		//Cliente.Recibir_Msg(mensaje);
                jugador = mensaje[0]-48;
                cout << "Yo juego con el jugador " << jugador+1 << endl;
			    select_map_btn->enable();
			    select_map_glui->close();
                partida_remota=true;

			}
			else if (modo==3){ // En red yo en modo servidor
	            char mensaje[1024];


                Servidor.Crear_Servidor();

                conectado = Servidor.Aceptar_Cliente();
                cout << "Recibir el nick del adversario: " << endl;
                Servidor.Recibir_Mensaje(nick_adversario);
                cout << "El adversario es " << nick_adversario << endl;

		cout << "Esperando al cliente\n";
                Servidor.Recibir_Accion();

		cout << "Enviar mi nick del adversario: " << endl;
                Servidor.Enviar_Cliente_Msg(mi_nick);
                cout << "Empezamos las partida..." << endl;
                // Le indica al cliente que jugador es
                if (jugador==0)
                  Servidor.Enviar_Accion_al_Cliente('0');
                else
                  Servidor.Enviar_Accion_al_Cliente('1');


		cout << "Yo soy el jugador " << jugador+1 << endl;
			    select_map_btn->enable();
			    select_map_glui->close();
                partida_remota=true;

			}
			else if (modo==4){ // Vs Ninja 1
	            char mensaje[1024];

                Cliente.Establecer_Conexion(field_ip_ninja, "5127");
                cout << "Empezamos las partida..." << endl;
                cout << "Enviando mi nick al servidor..." << mi_nick << endl;
                Cliente.Enviar_Msg(mi_nick);
                cout << "Le mando que voy a jugar contra el ninja 1 ..." << endl;
                Cliente.Enviar_Accion('1');
                cout << "Recibiendo el nick del servidor..." << endl;
                Cliente.Recibir_Msg(nick_adversario);
		cout << "Nick Adversario: " << nick_adversario <<endl;
                cout << "Le mando que soy el jugador " << jugador+1 << endl;
                if (jugador==0)
                  Cliente.Enviar_Accion('0');
                else
                  Cliente.Enviar_Accion('1');

                cout << "Yo juego con el jugador " << jugador+1 << endl;
			    select_map_btn->enable();
			    select_map_glui->close();
                partida_remota=true;

			}
      else if (modo==5){ // Vs Ninja 2
	            char mensaje[1024];

                Cliente.Establecer_Conexion(field_ip_ninja, "5128");
                cout << "Empezamos las partida..." << endl;
                cout << "Enviando mi nick al servidor..." << mi_nick << endl;
                Cliente.Enviar_Msg(mi_nick);
                cout << "Le mando que voy a jugar contra el ninja 2 ..." << endl;
                Cliente.Enviar_Accion('1');
                cout << "Recibiendo el nick del servidor..." << endl;
                Cliente.Recibir_Msg(nick_adversario);
		cout << "Nick Adversario: " << nick_adversario <<endl;
                cout << "Le mando que soy el jugador " << jugador+1 << endl;
                if (jugador==0)
                  Cliente.Enviar_Accion('0');
                else
                  Cliente.Enviar_Accion('1');

                cout << "Yo juego con el jugador " << jugador+1 << endl;
			    select_map_btn->enable();
			    select_map_glui->close();
                partida_remota=true;

			}
      else if (modo==6){ // Vs Ninja 3
	            char mensaje[1024];

                Cliente.Establecer_Conexion(field_ip_ninja, "5129");
                cout << "Empezamos las partida..." << endl;
                cout << "Enviando mi nick al servidor..." << mi_nick << endl;
                Cliente.Enviar_Msg(mi_nick);
                cout << "Le mando que voy a jugar contra el ninja 3 ..." << endl;
                Cliente.Enviar_Accion('1');
                cout << "Recibiendo el nick del servidor..." << endl;
                Cliente.Recibir_Msg(nick_adversario);
		cout << "Nick Adversario: " << nick_adversario <<endl;
                cout << "Le mando que soy el jugador " << jugador+1 << endl;
                if (jugador==0)
                  Cliente.Enviar_Accion('0');
                else
                  Cliente.Enviar_Accion('1');

                cout << "Yo juego con el jugador " << jugador+1 << endl;
			    select_map_btn->enable();
			    select_map_glui->close();
                partida_remota=true;

			}
            newGame();
			break;
		case DO_ONE_STEP_BTN_ID:
			doNextMove();
			break;
		case DO_ONE_RUN_BTN_ID:
			doOneRun();
			break;
        case CURSOR_PUT1_BTN_ID:
        case CURSOR_PUT2_BTN_ID:
        case CURSOR_PUT3_BTN_ID:
        case CURSOR_PUT4_BTN_ID:
        case CURSOR_PUT5_BTN_ID:
        case CURSOR_PUT6_BTN_ID:
        case CURSOR_PUT7_BTN_ID:
        case CURSOR_BOOM_BTN_ID:
             //cout << "\tModo: "<< modo << endl;
             switch (modo){
                 case 0: // Modo Normal
                         do_move(id-501);
                         break;
                 case 1: // Vs mi heuristica
                         if ((env->JugadorActivo()==1 and jugador==0) or (env->JugadorActivo()==2 and jugador==1)){
                           do_move(id-501);
                           doOneStep();
                         }
                         break;
                 case 2: // Vs jugador remoto (yo cliente)
                         if ((env->JugadorActivo()==1 and jugador==0) or (env->JugadorActivo()==2 and jugador==1)){
                              cout << "Jugador Activo: " << env->JugadorActivo() << "  " << mi_nick << endl;
                              do_move(id-501);
                              char aux=(id-501)+48;
                              // Enviar Accion
                              cout << "Envio la accion al servidor" << endl;
                              Cliente.Enviar_Accion(aux);

                              UpdateButton2();
                              esperando_client=false;
                              esperando_server=true;

                              myGlutDisplay();
                              glutTimerFunc(1000,myGlutTimer,10);

                         }
                         else{
                              cout << "Jugador Activo: " << env->JugadorActivo() << "  " << nick_adversario << endl;
                         }
                         break;
                 case 3: // Vs jugador remoto (yo servidor)
                         if ((env->JugadorActivo()==1 and jugador==0) or (env->JugadorActivo()==2 and jugador==1)){
                              do_move(id-501);
                              cout << "Envio accion al cliente" << endl;
                              char aux = (id-501)+48;
                              Servidor.Enviar_Accion_al_Cliente(aux);
                              cout << "Accion Enviada: " << (int) (aux) << endl;

                              UpdateButton2();
                              esperando_client=true;
                              esperando_server=false;

                              myGlutDisplay();
                              glutTimerFunc(1000,myGlutTimer,10);

                         }
                         break;
                 case 4: // Vs ninja
                 case 5: // Vs ninja
                 case 6: // Vs ninja
                         if ((env->JugadorActivo()==1 and jugador==0) or (env->JugadorActivo()==2 and jugador==1)){
                              cout << "Jugador Activo: " << env->JugadorActivo() << "  " << mi_nick << endl;
                              do_move(id-501);
                              char aux=(id-501)+48;
                              // Enviar Accion
                              cout << "Envio la accion al servidor" << endl;
                              Cliente.Enviar_Accion(aux);

                              UpdateButton2();
                              esperando_client=false;
                              esperando_server=true;

                              myGlutDisplay();
                              glutTimerFunc(1000,myGlutTimer,10);

                         }
                         else{
                              cout << "Jugador Activo: " << env->JugadorActivo() << "  " << "NINJA" << endl;
                         }
                         break;
             }
             break;

		case ERROR_OK_BTN_ID:
			error_glui->close();
			break;
        case REINICIAR_BTN_ID:
            newGame();
            break;
		default:
			break;
	}
	glutPostRedisplay();
}

void GUI::doNextMove(){
    switch (modo){
        case 0: //Normal
        case 1: //Vs mi heuristica
                doOneStep();
                break;
        case 2: //Vs jugador remoto (yo cliente)
                if ((env->JugadorActivo()==1 and jugador==0) or (env->JugadorActivo()==2 and jugador==1)){
                    //Peticion automatica de jugada del jugador local
                      player1->Perceive(*env);

                      action = player1->Think();
                      env->AcceptAction(action);
                      env->ChangePlayer();



                      UpdateButton2();
                      myGlutDisplay();

                      char aux = static_cast<char>(action) + 48;
                      // Enviar Accion
                      cout << "Envio la accion al servidor" << endl;
                      Cliente.Enviar_Accion(aux);


                      esperando_client=false;
                      esperando_server=true;

                      glutTimerFunc(1000,myGlutTimer,10);

                }
                break;
        case 3: //Vs jugador remoto (yo servidor)
                if ((env->JugadorActivo()==1 and jugador==0) or (env->JugadorActivo()==2 and jugador==1)){
                    //Peticion automatica de jugada del jugador local
                      player1->Perceive(*env);

                      action = player1->Think();
                      env->AcceptAction(action);
                      env->ChangePlayer();

                      UpdateButton2();
                      myGlutDisplay();

                      cout << "Envio accion al cliente" << endl;
                      char aux = static_cast<char>(action) + 48;
                      Servidor.Enviar_Accion_al_Cliente(aux);
                      cout << "Accion Enviada: " << (int) (aux) << endl;

                      esperando_client=true;
                      esperando_server=false;

                      glutTimerFunc(1000,myGlutTimer,10);

                }
                break;
        case 4: //Vs ninja
        case 5: //Vs ninja
        case 6: //Vs ninja
                if ((env->JugadorActivo()==1 and jugador==0) or (env->JugadorActivo()==2 and jugador==1)){
                    //Peticion automatica de jugada del jugador local
                      player1->Perceive(*env);

                      action = player1->Think();
                      env->AcceptAction(action);
                      env->ChangePlayer();



                      UpdateButton2();
                      myGlutDisplay();

                      char aux = static_cast<char>(action) + 48;
                      // Enviar Accion
                      cout << "Envio la accion al servidor" << endl;
                      Cliente.Enviar_Accion(aux);


                      esperando_client=false;
                      esperando_server=true;

                      glutTimerFunc(1000,myGlutTimer,10);

                }
                break;

    }
}

void GUI::doOneStep(){
  if (!Juego_Terminado()){


   if (env->JugadorActivo()==1){
		  player1->Perceive(*env);

		  action = player1->Think();
		  env->AcceptAction(action);

		  env->ChangePlayer();
   }
   else {

		  player2->Perceive(*env);

		  action = player2->Think();
		  env->AcceptAction(action);

		  env->ChangePlayer();

   }
  }

   UpdateButton();

}

void GUI::do_move(int accion){
    env->AcceptAction(static_cast<Environment::ActionType> (accion));

	myGlutDisplay();
	//Sleep(100);

    env->ChangePlayer();

    UpdateButton();

}



void GUI::doOneRun(){
	do_one_run_btn->disable();

	while(!Juego_Terminado()){
		doOneStep();
	    myGlutDisplay();
	    //Sleep(100);
	    //glutMainLoop();

	}

    UpdateButton();
}


void GUI::UpdateButton(){

  if (env==0 or Juego_Terminado()){
	do_one_step_btn->disable();
    select_map_btn->enable();
      cursor_put1->disable();
      cursor_put2->disable();
      cursor_put3->disable();
      cursor_put4->disable();
      cursor_put5->disable();
      cursor_put6->disable();
      cursor_put7->disable();
      display_btn->disable();
      quit_btn->enable();

  }
  else {
    do_one_step_btn->enable();
    quit_btn->enable();
    select_map_btn->enable();
    reiniciar_btn->enable();
    bool act[8];
	env->possible_actions(act);

	if (act[0])
	  cursor_put1->enable();
    else
	  cursor_put1->disable();

	if (act[1])
	  cursor_put2->enable();
    else
	  cursor_put2->disable();

	if (act[2])
	  cursor_put3->enable();
    else
	  cursor_put3->disable();

	if (act[3])
	  cursor_put4->enable();
    else
	  cursor_put4->disable();

	if (act[4])
	  cursor_put5->enable();
    else
	  cursor_put5->disable();

	if (act[5])
	  cursor_put6->enable();
    else
	  cursor_put6->disable();

	if (act[6])
	  cursor_put7->enable();
    else
	  cursor_put7->disable();

	if (act[7])
	  cursor_boom->enable();
    else
	  cursor_boom->disable();
  }

}


void GUI::UpdateButton_Sin_Reiniciar(){

  if (env==0 or Juego_Terminado()){
	do_one_step_btn->disable();
    select_map_btn->enable();
      cursor_put1->disable();
      cursor_put2->disable();
      cursor_put3->disable();
      cursor_put4->disable();
      cursor_put5->disable();
      cursor_put6->disable();
      cursor_put7->disable();
      display_btn->disable();
      quit_btn->enable();
  }
  else {
    do_one_step_btn->enable();
    quit_btn->enable();
    select_map_btn->enable();
    reiniciar_btn->disable();
    bool act[8];
	env->possible_actions(act);

	if (act[0])
	  cursor_put1->enable();
    else
	  cursor_put1->disable();

	if (act[1])
	  cursor_put2->enable();
    else
	  cursor_put2->disable();

	if (act[2])
	  cursor_put3->enable();
    else
	  cursor_put3->disable();

	if (act[3])
	  cursor_put4->enable();
    else
	  cursor_put4->disable();

	if (act[4])
	  cursor_put5->enable();
    else
	  cursor_put5->disable();

	if (act[5])
	  cursor_put6->enable();
    else
	  cursor_put6->disable();

	if (act[6])
	  cursor_put7->enable();
    else
	  cursor_put7->disable();

	if (act[7])
	  cursor_boom->enable();
    else
	  cursor_boom->disable();
  }

}





void GUI::UpdateButton2(){

  do_one_step_btn->disable();
  display_btn->disable();
  do_one_run_btn->disable();
  reiniciar_btn->disable();
  cursor_put1->disable();
  cursor_put2->disable();
  cursor_put3->disable();
  cursor_put4->disable();
  cursor_put5->disable();
  cursor_put6->disable();
  cursor_put7->disable();
  cursor_boom->disable();
  quit_btn->disable();
  select_map_btn->disable();

}




void GUI::newGame(){
    if (env!=0)
	  delete env;


	if (player1!=0)
      delete player1;


	if (player2!=0)
	  delete player2;


	switch(modo){
	    case 0: // Modo normal
                env=new Environment();
                player1=new Player(1);
                player2=new Player(2);

                do_one_step_btn->enable();
                display_btn->enable();
                do_one_run_btn->enable();

                UpdateButton();

	            break;
        case 1: // Contra mi heuristica
                env=new Environment();
                player1=new Player(1);
                player2=new Player(2);

                do_one_step_btn->disable();
                display_btn->disable();
                do_one_run_btn->disable();

                if (jugador==0)
                  UpdateButton();
                else
                  doOneStep();

                break;

        case 2: // Contra otro usuario (yo cliente)
                partida_remota=true;

                env=new Environment();
                if (jugador==0){
                  player1=new Player(1);
                  player2=new Player(2);
                }
                else{
                  player1=new Player(2);
                  player2=new Player(1);
                }

                do_one_step_btn->enable();
                display_btn->disable();
                do_one_run_btn->disable();

                esperando_client=false;
                esperando_server=false;

                if (jugador==0){
                  cout << "Juego yo" << endl;
                  UpdateButton_Sin_Reiniciar();
                }
                else{
                  esperando_client=false;
                  esperando_server=true;

                  UpdateButton2();
                  myGlutDisplay();
                  glutPostRedisplay();
                  glutSetWindow(main_window);
                  glutPostRedisplay();
                  //Sleep(10);

                  glutTimerFunc(1000,myGlutTimer,10);
                }

                break;
        case 3: // Contra otro usuario (yo server)
                partida_remota=true;

                env=new Environment();
                if (jugador==0){
                  player1=new Player(1);
                  player2=new Player(2);
                }
                else{
                  player1=new Player(2);
                  player2=new Player(1);
                }

                do_one_step_btn->enable();
                display_btn->disable();
                do_one_run_btn->disable();

                esperando_client=false;
                esperando_server=false;

                if (jugador==0){
                  cout << "Juego yo" << endl;
                  UpdateButton_Sin_Reiniciar();
                }
                else{
                  UpdateButton2();

                  esperando_client=true;
                  esperando_server=false;

                  myGlutDisplay();
                  glutPostRedisplay();
                  glutSetWindow(main_window);
                  glutPostRedisplay();
                  //Sleep(10);

                  glutTimerFunc(1000,myGlutTimer,10);
                }

                break;
        case 4: // Vs Ninja
        case 5: // Vs Ninja
        case 6: // Vs Ninja
                cout << "He llegado aqui al modo ninja" << endl;
                partida_remota=true;

                env=new Environment();
                if (jugador==0){
                  player1=new Player(1);
                  player2=new Player(2);
                }
                else{
                  player1=new Player(2);
                  player2=new Player(1);
                }

                do_one_step_btn->enable();
                display_btn->disable();
                do_one_run_btn->disable();

                esperando_client=false;
                esperando_server=false;

                if (jugador==0){
                  cout << "Juego yo" << endl;
                  UpdateButton_Sin_Reiniciar();
                }
                else{
                  cout << "Juega el Ninja" << endl;
                  esperando_client=false;
                  esperando_server=true;

                  UpdateButton2();
                  myGlutDisplay();
                  glutPostRedisplay();
                  glutSetWindow(main_window);
                  glutPostRedisplay();
                  //Sleep(10);

                  glutTimerFunc(1000,myGlutTimer,10);
                }
	}


		//do_all_run_btn->enable();
}
