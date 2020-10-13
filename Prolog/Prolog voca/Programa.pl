% Autor:
% Fecha: 20/08/2017

:-pce_image_directory('./imagenes').
resource(preg,image,image('preg.jpg')).
esrespuesta('no').
esrespuesta('si').
% AREA I: ARTE Y CREATIVIDAD.
espregunta('Ilustrar, dibujar y animar digitalmente',X):-esrespuesta(X).
espregunta('Fotografiar Paisajes',X):-esrespuesta(X).
espregunta('Dise�ar logotipos y portadas de una revista',X):-esrespuesta(X).
espregunta('Pintar, hacer esculturas, ilustrar libros de arte, etc�tera',X):-esrespuesta(X).
espregunta('Prepararse para ser modelo profesional',X):-esrespuesta(X).
espregunta('Dise�ar juegos interactivos electr�nicos para computadora',X):-esrespuesta(X).
espregunta('Redactar guiones y libretos para un programa de televisi�n',X):-esrespuesta(X).
espregunta('Crear campa�as publicitarias',X):-esrespuesta(X).
%% AREA II: CIENCIAS SOCIALES.
espregunta('Realizar excavaciones para descubrir restos del pasado',X):-esrespuesta(X).
espregunta('Organizar eventos y atender a sus asistentes',X):-esrespuesta(X).
espregunta('Investigar el pasado y saber acerca de Historia',X):-esrespuesta(X).
espregunta('Ayudar a la sociedad con los problemas que tienen',X):-esrespuesta(X).
espregunta('Escribir art�culos period�sticos, cuentos, novelas y otros',X):-esrespuesta(X).
espregunta('Estudiar la diversidad cultural en el �mbito rural y urbano',X):-esrespuesta(X).
espregunta('Gestionar y evaluar convenios internacionales de cooperaci�n para el desarrollo social',X):-esrespuesta(X).

%% AREA III: ECONOMICA, ADMINISTRATIVA Y FINANCIERA.
espregunta('Seleccionar, capacitar y motivar al personal de una organizaci�n/empresa',X):- esrespuesta(X).
espregunta('Planificar cu�les son las metas de una organizaci�n p�blica o privada a mediano y largo plazo',X):- esrespuesta(X).
espregunta('Controlar ingresos y egresos de fondos y presentar el balance final de una instituci�n',X):- esrespuesta(X).
espregunta('Hacer propuestas y formular estrategias para aprovechar las relaciones econ�micas entre dos pa�ses',X):- esrespuesta(X).
espregunta('Elaborar campa�as para introducir un nuevo producto al mercado',X):- esrespuesta(X).
espregunta('Supervisar las ventas de un centro comercial',X):- esrespuesta(X).
espregunta('Aconsejar a las personas sobre planes de ahorro e inversiones',X):- esrespuesta(X).
espregunta('Tener un negocio propio de tipo comercial',X):- esrespuesta(X).
espregunta('Organizar un plan de distribuci�n y venta de un gran almac�n',X):- esrespuesta(X).

%% AREA IV: CIENCIA Y TECONOLOGIA.
espregunta('Dise�ar programas de computaci�n y explorar nuevas aplicaciones tecnol�gicas para uso del internet',X):-esrespuesta(X).
espregunta('Resolver Problemas de Calculo Matematico',X):-esrespuesta(X).
espregunta('Te gusta la programaci�n o cosas que tenga que ver con computadoras',X):-esrespuesta(X).
espregunta('Te gusta la Fisica, Matematica, y todo lo que tenga que ver con numeros',X):-esrespuesta(X).
espregunta('Investigar y probar nuevos productos farmac�uticos',X):-esrespuesta(X).
espregunta('Dise�ar m�quinas que puedan simular actividades humanas',X):-esrespuesta(X).
espregunta('Elaborar mapas, planos e im�genes para el estudio y an�lisis de datos geogr�ficos',X):-esrespuesta(X).

%% AREA V: CIENCIAS ECOLOGICAS, BIOLOGICAS Y DE SALUD.
espregunta('Criar, cuidar y tratar animales dom�sticos y de campo',X):-esrespuesta(X).
espregunta('Investigar sobre �reas verdes, medio ambiente y cambios clim�ticos',X):-esrespuesta(X).
espregunta('Dise�ar cursos para ense�ar a la gente sobre temas de salud e higiene',X):-esrespuesta(X).
espregunta('Atender la salud de personas enfermas',X):-esrespuesta(X).
espregunta('Hacer experimentos con plantas (frutas, �rboles, flores)',X):-esrespuesta(X).
espregunta('Examinar y tratar los problemas visuales',X):-esrespuesta(X).
espregunta('Atender y realizar ejercicios a personas que tienen limitaciones f�sicas, problemas de lenguaje, etc�tera',X):-esrespuesta(X).
espregunta('Realizar el control de calidad de los alimentos',X):-esrespuesta(X).

%PRINCIPAL
espregunta('es hombre ?',X):-esrespuesta(X).
espregunta('es mujer ?',X):-esrespuesta(X).

main:-
        new(D,dialog('ORIENTACION VOCACIONAL')),

        send(D,colour,colour(red)),
        send(D, append, new(Menu, menu_bar)),
        send(Menu, append, new(Iniciar, popup(iniciar))),
        send(Menu, append, new(Acerca, popup(acerca_de))),
        send(Menu, append, new(Ayuda, popup(ayuda))),
        new(Boton2,button('SALIR',and(message(D, destroy)))),


        send_list(Iniciar, append,
                         [ menu_item(iniciar, message(@prolog,pp))
                         ]),
        send_list(Acerca, append,
                        [menu_item(informaci�n, message(@display, inform, 'Encontraras una serie de situaciones con dos alternativas de respuesta [Si] [NO]
Elije la alternativa que coincida contigo.'))
                          ]),
        send_list(Ayuda, append,
                         [ menu_item(autor, message(@display, inform, 'Maicol Palomino - ProgramadorMP - 2017'))
                         ]),
        mostrar('C:/Programa/img_principal.jpg',D,Menu),
        send(D,append,Boton2),
        send(D,open_centered).


%% FUNCION PARA MOSTRAR LA IMAGEN
%V:Direccion de imagen
%D: Pantalla
%M: mostrar imagen
mostrar(V,D,M):- new(I, image(V)),
        new(B, bitmap(I)),
        new(F2, figure),
        send(F2, display, B),
        new(D1, device),
        send(D1, display, F2),
        send(D, display, D1),
        send(D1,below(M)).

%% VENTANA DE INICIO, PREGUNTA SI ES HOMBRE O MUJER.
pp:-new(D,dialog('PREGUNTAS')),
       new(Pre1,menu('es hombre ?')),
       send_list(Pre1,append,[si , no]),
       new(Pre2,menu('es mujer ?')),
       send_list(Pre2,append,[si,no]),

       %Imprimimos las preguntas de Hombre o Mujer?
       send(D,append(Pre1)),
       send(D,append,Pre2),

       %vamos a la siguiente ventana para contestar el test con el boton siguiente, Dirigimos al prinicipal:-.
       new(A,button(atras,and(message(D,destroy)))),
       new(B,button(siguiente,and(message(@prolog,principal,Pre1?selection,Pre2?selection),message(D,destroy)))),
       send(D,append,A),
       send(D,append,B),
       send(D,default_button,siguiente),
       send(D,open_centered).

%% Eleccion de sexo.
principal(P1,P2):-
                  espregunta('es hombre ?',P1),P1='si',
                  espregunta('es mujer ?',P2),P2='no',
                  %Nos dirigimos a pho:-
                  pho.

principal(P1,P2):-
                   espregunta('es hombre ?',P1),P1='no',
                   espregunta('es mujer ?',P2),P2='si',
                   %Nos dirigimos a pho:-
                   pho.

%%En caso de elegir mal el sexo
principal(_,_):-new(D,dialog('ERROR')),
                new(L,label(l,'DEBES ELEGIR SOLO UNA OPCION',font('times','roman',16))),
                new(Atras,button(atras,and(message(@prolog,pp),message(D,destroy)))),
                send(D,append,L),
                send(D,append,Atras),
                send(D,open_centered).



pho:-   %Preguntas del test:
        new(D, dialog('PREGUNTAS')),

        new(Pre1,menu('1. Dise�ar programas de computaci�n y explorar nuevas aplicaciones \ntecnol�gicas para uso del internet')),
        send_list(Pre1,append,[si , no]),
        new(Pre2,menu('2. Criar, cuidar y tratar animales dom�sticos y de campo')),
        send_list(Pre2,append,[si , no]),
        new(Pre3,menu('3. Investigar sobre �reas verdes, medio ambiente y cambios clim�ticos')),
        send_list(Pre3,append,[si , no]),
        new(Pre4,menu('4. Ilustrar, dibujar y animar digitalmente')),
        send_list(Pre4,append,[si , no]),
        new(Pre5,menu('5. Seleccionar, capacitar y motivar al personal de una organizaci�n/empresa')),
        send_list(Pre5,append,[si , no]),
        new(Pre6,menu('6. Realizar excavaciones para descubrir restos del pasado')),
        send_list(Pre6,append,[si , no]),
        new(Pre7,menu('7. Resolver Problemas de Calculo Matematico')),
        send_list(Pre7,append,[si , no]),
        new(Pre8,menu('8. Investigar el pasado y saber acerca de Historia')),
        send_list(Pre8,append,[si , no]),
        new(Pre9,menu('9. Fotografiar paisajes')),
        send_list(Pre9,append,[si , no]),
        new(Pre10,menu('10. Planificar cu�les son las metas de una organizaci�n p�blica o privada a \nmediano y largo plazo')),
        send_list(Pre10,append,[si , no]),
        new(Pre11,menu('11. Dise�ar y planificar la producci�n masiva de art�culos')),
        send_list(Pre11,append,[si , no]),
        new(Pre12,menu('12. Te gusta la programaci�n o cosas que tenga que ver con computadoras')),
        send_list(Pre12,append,[si , no]),
        new(Pre13,menu('13. Organizar eventos y atender a sus asistentes')),
        send_list(Pre13,append,[si , no]),
        new(Pre14,menu('14. Atender la salud de personas enfermas')),
        send_list(Pre14,append,[si , no]),
        new(Pre15,menu('15. Controlar ingresos y egresos de fondos y presentar el balance final de \nuna instituci�n')),
        send_list(Pre15,append,[si , no]),
        new(Pre16,menu('16. Ayudar a la sociedad con los problemas que tienen')),
        send_list(Pre16,append,[si , no]),
        new(Pre17,menu('17. Te gusta la Fisica, Matematica, y todo lo que tenga que ver con numeros')),
        send_list(Pre17,append,[si , no]),
        new(Pre18,menu('18. Investigar y probar nuevos productos farmac�uticos')),
        send_list(Pre18,append,[si , no]),
        new(Pre19,menu('19. Hacer propuestas y formular estrategias para aprovechar las relaciones \necon�micas entre dos pa�ses')),
        send_list(Pre19,append,[si , no]),
        new(Pre20,menu('20. Pintar, hacer esculturas, ilustrar libros de arte, etc�tera')),
        send_list(Pre20,append,[si , no]),

        %Imprimiendo test
        send_list(D,append,[Pre1,Pre2,Pre3,Pre4,Pre5,Pre6,Pre7,Pre8,Pre9,Pre10,Pre11,Pre12,Pre13,Pre14,Pre15,Pre16,Pre17,Pre18,Pre19,Pre20]),

        send(D, scrollbars, vertical),


        %Boton de retroceso
        new(B1,button(atras,and(message(@prolog,pp),message(D,destroy)))),

        %Al momento de seleccionar siguiente pasamos al areaI:- para comprobar las respuestas que dimos.
        new(B,button(siguiente,message(@prolog,areaI,Pre1?selection,Pre2?selection,Pre3?selection,
        Pre4?selection,Pre5?selection,Pre6?selection,Pre7?selection,Pre8?selection,Pre9?selection,Pre10?selection,
        Pre11?selection,Pre12?selection,Pre13?selection,Pre14?selection,Pre15?selection,Pre16?selection,Pre17?selection,
        Pre18?selection,Pre19?selection,Pre20?selection))),

        %Colocamos los botones.
        send(D,append,B1),
        send(D,append,B),

        send(D,open_centered).

%% AREA I: ARTE Y CREATIVIDAD.
areaI(_,_,_,P4,_,_,_,_,P9,_,_,P12,_,_,_,_,_,_,_,P20):-
                                                      espregunta('Ilustrar, dibujar y animar digitalmente',P4),P4='si',
                                                      espregunta('Fotografiar paisajes',P9),P9='si',
                                                      espregunta('Dise�ar logotipos y portadas de una revista',P12),P12='si',
                                                      espregunta('Pintar, hacer esculturas, ilustrar libros de arte, etc�tera',P20),P20='si',
                                                      pf3('C:/Programa/imagen1.jpg','ARTE Y CREATIVIDAD:
                                                      Dise�o Gr�fico, Artes Pl�sticas (Pintura, Escultura, Danza, Teatro, Artesan�a, Cer�mica), Fotograf�a, Fotograf�a Digital, Gesti�n Gr�fica y
                                                      Publicitaria, Locuci�n y Publicidad, Actuaci�n, Camarograf�a').
%% AREA II: CIENCIAS SOCIALES
areaI(_,_,_,_,_,P6,_,P8,_,_,_,_,P13,_,_,P16,_,_,_,_):-
                                                  espregunta('Realizar excavaciones para descubrir restos del pasado',P6),P6='si',
                                                  espregunta('Investigar el pasado y saber acerca de Historia',P8),P8='si',
                                                  espregunta('Organizar eventos y atender a sus asistentes',P13),P13='si',
                                                  espregunta('Ayudar a la sociedad con los problemas que tienen',P16),P16='si',
                                                  pf3('C:/Programa/Imagen2.jpg','CIENCIAS SOCIALES:
                                                  Trabajo Social, Idiomas, Educaci�n, Historia y Geograf�a, Periodismo, Antropolog�a, Arqueolog�a, Gesti�n Social y Desarrollo, Consejer�a Familiar,
                                                  Educaci�n Especial, Hoteler�a y Turismo; Teolog�a.').

%% AREA III: Econ�mica, Administrativa y Financiera
areaI(_,_,_,_,P5,_,_,_,_,P10,_,_,_,_,P15,_,_,_,P19,_):-
                                                      espregunta('Seleccionar, capacitar y motivar al personal de una organizaci�n/empresa',P5),P5='si',
                                                      espregunta('Planificar cu�les son las metas de una organizaci�n p�blica o privada a mediano y largo plazo',P10),P10='si',
                                                      espregunta('Controlar ingresos y egresos de fondos y presentar el balance final de una instituci�n',P15),P15='si',
                                                      espregunta('Hacer propuestas y formular estrategias para aprovechar las relaciones econ�micas entre dos pa�ses',P19),P19='si',
                                                      pf3('C:/Programa/imagen3.jpg','ECONOMIA, ADMINISTRATIVA y FINANCIERA:
                                                      Administraci�n de Empresas, Contabilidad, Marketing Estrat�gico, Gesti�n y Negocios Internacionales, Gesti�n Empresarial,
                                                      Gesti�n Financiera, Ingenier�a Comercial, Comercio Exterior, Banca y Finanzas, Gesti�n de Recursos Humanos, Comunicaciones Integradas en
                                                      Marketing, Administraci�n de Empresas Ecotur�sticas y de Hospitalidad, Ciencias Econ�micas y Financieras, Administraci�n y Ciencias Pol�ticas,
                                                      Ciencias Empresariales, Comercio Electr�nico, Emprendedores, Gesti�n de Organismos P�blicos (Municipios, Ministerios, etc�tera.), Gesti�n de
                                                      Centros Educativos.').

%% AREA IV: Ciencia y Tecnolog�a
areaI(P1,_,_,_,_,_,P7,_,_,_,P11,_,_,_,_,_,P17,_,_,_):-
                                                    espregunta('Dise�ar programas de computaci�n y explorar nuevas aplicaciones tecnol�gicas para uso del internet',P1),P1='si',
                                                    espregunta('Resolver Problemas de Calculo Matematico',P7),P7='si',
                                                    espregunta('Te gusta la programaci�n o cosas que tenga que ver con computadoras',P11),P11='si',
                                                    espregunta('Te gusta la Fisica, Matematica, y todo lo que tenga que ver con numeros',P17),P17='si',
                                                    pf3('C:/Programa/imagen4.jpg','CIENCIA Y TECNOLOGIA:
                                                    Ingenieria Informatica,Ingenier�a en Sistemas, Ingenier�a Civil, Arquitectura, Electr�nica, Telecomunicaciones, Ingenier�a
                                                    Mecatr�nica (Rob�tica), Ingenier�a Mec�nica, Ingenier�a Industrial, F�sica, Matem�ticas Aplicadas, Ingenier�a en Estad�stica,
                                                    Ingenier�a Automotriz, Biotecnolog�a Ambiental ').

%% AREA V: Ciencias Ecol�gicas, Biol�gicas y de Salud
areaI(_,P2,P3,_,_,_,_,_,_,_,_,_,_,P14,_,_,_,P18,_,_):-
                                                      espregunta('Criar, cuidar y tratar animales dom�sticos y de campo',P2),P2='si',
                                                      espregunta('Investigar sobre �reas verdes, medio ambiente y cambios clim�ticos',P3),P3='si',
                                                      espregunta('Atender la salud de personas enfermas',P14),P14='si',
                                                      espregunta('Investigar y probar nuevos productos farmac�uticos',P18),P18='si',
                                                      pf3('C:/Programa/imagen5.jpg','CIENCIAS ECOL�GICAS, BIOL�GICAS Y DE LASALUD:
                                                      Biolog�a, Farmacia, Zootecnia, Veterinaria, Medicina, Enfermer�a.').
areaI(_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_):-new(D,dialog('ERROR')),
                                                new(L,label(l,'NO SE PUEDE DEFINIR EL RESULTADO DEL TEST DE ORIENTACION VOCACIONAL',font('times','roman',16))),
                                                send(D,append,L),
                                                send(D,open,point(350,350)).


mostrar1(V,D):- new(I, image(V)),
        new(B, bitmap(I)),
        new(F2, figure),
        send(F2, display, B),
        new(D1, device),
        send(D1, display, F2),
        send(D, display, D1).


pf3(X,Y):-new(D,dialog('RESULTADOS TEST ORIENTACION VOCACIONAL')),
          mostrar2(X,D,20,30),
          new(L,label(n,'')),
          send(D, append(label(n,''))),
          send(D, append(label(n,'RECOMENDACION DE AREA DE VOCACION: '))),
          send(D, append(label(n,Y))),
          send(D,append,L),
         send(D,open_centered).

f3(X,Y):-new(F,frame('IMAGEN DE LA PROFESION')),
         send(F,append(new(F1,browser))),
         mostrar(X,F1),
         send(new(D,dialog),below(F1)),
         send(D, append(label(n,''))),
         send(D, append(label(n,''))),
         send(D, append(label(n,Y))),

   send(F,open,point(300,300)).

mostrar(V,D):- new(I, image(V)),
        new(B, bitmap(I)),
        new(F2, figure),
        send(F2, display, B),
        new(D1, device),
        send(D1, display, F2),
        send(D, display, D1).

mostrar2(V,D,X,Y):- new(I, image(V)),
        new(B, bitmap(I)),
        new(F2, figure),
        send(F2, display, B),
        new(D1, device),
        send(D1, display, F2),
        send(D, display, D1),
        send(D,display,D1,point(X,Y)).

