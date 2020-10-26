#ifndef CONEXION__
#define CONEXION__
//#include <winsock2.h>     //Windows

#include <sys/socket.h> //Linux
#include <arpa/inet.h>  //Linux


using namespace std;

class conexion_server{

  public:
     // Para el Server
     int Crear_Servidor();
     int Aceptar_Cliente();
     void Enviar_Cliente_Msg(const char *msg);
     void Enviar_Tablero(char* tablero);
     void Recibir_Mensaje(char* msg);
     char Recibir_Accion();
     void Enviar_Accion_al_Cliente(const char accion);
     void Cerrar_Conexion();

  private:
    struct sockaddr_in server;    //servidor
    int conectado;
    int sock;
    int bytesenv, bytesrecv;
    char buffer[1024];

};



class conexion_client{

  public:
     // Para el cliente
     int Establecer_Conexion(const char *dir_ip, const char *puerto);
     void Enviar_Msg(const char *msg);
     void Recibir_Msg(char *msg);
     char *Recibir_Tablero();
     void Enviar_Accion(char accion);
     char Recibir_Accion_del_Servidor();
     void Cerrar_Conexion();




  private:
    struct sockaddr_in direccion; //datos del servidor al que conectaremos
    int sock;                     //descriptor del socket.
    int bytesenv, bytesrecv;
    char buffer[1024];

};



#endif
