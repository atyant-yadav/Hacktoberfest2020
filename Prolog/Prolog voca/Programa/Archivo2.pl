% Autor:
% Fecha: 12/12/2019

:-pce_image_directory('./imagenes').
resource(preg,image,image('preg.jpg')).
esrespuesta('no').
esrespuesta('si').
% AREA I: ARTE Y CREATIVIDAD.
espregunta('Ilustrar, dibujar y animar digitalmente',X):-esrespuesta(X).
espregunta('Fotografiar Paisajes',X):-esrespuesta(X).
espregunta('Diseñar logotipos y portadas de una revista',X):-esrespuesta(X).
espregunta('Pintar, hacer esculturas, ilustrar libros de arte, etcétera',X):-esrespuesta(X).
espregunta('Prepararse para ser modelo profesional',X):-esrespuesta(X).
espregunta('Diseñar juegos interactivos electrónicos para computadora',X):-esrespuesta(X).
espregunta('Redactar guiones y libretos para un programa de televisión',X):-esrespuesta(X).
espregunta('Crear campañas publicitarias',X):-esrespuesta(X).
%% AREA II: CIENCIAS SOCIALES.
espregunta('Realizar excavaciones para descubrir restos del pasado',X):-esrespuesta(X).
espregunta('Organizar eventos y atender a sus asistentes',X):-esrespuesta(X).
espregunta('Investigar el pasado y saber acerca de Historia',X):-esrespuesta(X).
espregunta('Ayudar a la sociedad con los problemas que tienen',X):-esrespuesta(X).
espregunta('Escribir artículos periodísticos, cuentos, novelas y otros',X):-esrespuesta(X).
espregunta('Estudiar la diversidad cultural en el ámbito rural y urbano',X):-esrespuesta(X).
espregunta('Gestionar y evaluar convenios internacionales de cooperación para el desarrollo social',X):-esrespuesta(X).

%% AREA III: ECONOMICA, ADMINISTRATIVA Y FINANCIERA.
espregunta('Seleccionar, capacitar y motivar al personal de una organización/empresa',X):- esrespuesta(X).
espregunta('Planificar cuáles son las metas de una organización pública o privada a mediano y largo plazo',X):- esrespuesta(X).
espregunta('Controlar ingresos y egresos de fondos y presentar el balance final de una institución',X):- esrespuesta(X).
espregunta('Hacer propuestas y formular estrategias para aprovechar las relaciones económicas entre dos países',X):- esrespuesta(X).
espregunta('Elaborar campañas para introducir un nuevo producto al mercado',X):- esrespuesta(X).
espregunta('Supervisar las ventas de un centro comercial',X):- esrespuesta(X).
espregunta('Aconsejar a las personas sobre planes de ahorro e inversiones',X):- esrespuesta(X).
espregunta('Tener un negocio propio de tipo comercial',X):- esrespuesta(X).
espregunta('Organizar un plan de distribución y venta de un gran almacén',X):- esrespuesta(X).

%% AREA IV: CIENCIA Y TECONOLOGIA.
espregunta('Diseñar programas de computación y explorar nuevas aplicaciones tecnológicas para uso del internet',X):-esrespuesta(X).
espregunta('Resolver Problemas de Calculo Matematico',X):-esrespuesta(X).
espregunta('Te gusta la programación o cosas que tenga que ver con computadoras',X):-esrespuesta(X).
espregunta('Te gusta la Fisica, Matematica, y todo lo que tenga que ver con numeros',X):-esrespuesta(X).
espregunta('Investigar y probar nuevos productos farmacéuticos',X):-esrespuesta(X).
espregunta('Diseñar máquinas que puedan simular actividades humanas',X):-esrespuesta(X).
espregunta('Elaborar mapas, planos e imágenes para el estudio y análisis de datos geográficos',X):-esrespuesta(X).

%% AREA V: CIENCIAS ECOLOGICAS, BIOLOGICAS Y DE SALUD.
espregunta('Criar, cuidar y tratar animales domésticos y de campo',X):-esrespuesta(X).
espregunta('Investigar sobre áreas verdes, medio ambiente y cambios climáticos',X):-esrespuesta(X).
espregunta('Diseñar cursos para enseñar a la gente sobre temas de salud e higiene',X):-esrespuesta(X).
espregunta('Atender la salud de personas enfermas',X):-esrespuesta(X).
espregunta('Hacer experimentos con plantas (frutas, árboles, flores)',X):-esrespuesta(X).
espregunta('Examinar y tratar los problemas visuales',X):-esrespuesta(X).
espregunta('Atender y realizar ejercicios a personas que tienen limitaciones físicas, problemas de lenguaje, etcétera',X):-esrespuesta(X).
espregunta('Realizar el control de calidad de los alimentos',X):-esrespuesta(X).

%PRINCIPAL
espregunta('es hombre ?',X):-esrespuesta(X).
espregunta('es mujer ?',X):-esrespuesta(X).

main:-
        new(D,dialog('ORIENTACION VOCACIONAL')),

        send(D, append, new(Menu, menu_bar)),
        send(Menu, append, new(Iniciar, popup(iniciar))),
        send(Menu, append, new(Acerca, popup(acerca_de))),
        send(Menu, append, new(Ayuda, popup(ayuda))),
        new(Boton2,button('SALIR',and(message(D, destroy)))),


        send_list(Iniciar, append,
                         [ menu_item(iniciar, message(@prolog,pe))
                         ]),
        send_list(Acerca, append,
                        [menu_item(autor, message(@display, inform, 'Maicol Palomino - ProgramadorMP - 2017 - (Actualizacion) Gerson Gomez 2019'))
                          ]),
        send_list(Ayuda, append,
                         [ menu_item(información, message(@display, inform, 'Encontraras una serie de situaciones con dos alternativas de respuesta [Si] [NO]'))
                         ]),
        mostrar('C:/Users/Masamorro/Desktop/Prolog voca/Programa/img_principal.jpg',D,Menu),
        send(D,append,Boton2),
        send(D,open_centered).


%% FUNCION PARA MOSTRAR LA IMAGEN
%below = debajo
mostrar(V,D,M):- new(I, image(V)),
        new(B, bitmap(I)),
        new(F2, figure),
        send(F2, display, B),
        new(D1, device),
        send(D1, display, F2),
        send(D, display, D1),
        send(D1,below(M)).

%%Ventana para poner Datos de Persona.
pe:-new(D,dialog('Datos Personales')),
    new(T1,text_item('Nombres')),
    new(T2,text_item('Apellidos')),
    new(T3,text_item('Colegio')),
    new(A1,button(atras,message(D,destroy))),
    new(S1,button(siguiente,and(message(@prolog,pp),message(D,destroy)))),
    
    send_list(D,append,[T1,T2,T3,A1,S1]),
    send(D,open_centered).


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
       new(A,button(atras,and(message(@prolog,pe),message(D,destroy)))),
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

        new(Pre1,menu('1. Diseñar programas de computación y explorar nuevas aplicaciones \ntecnológicas para uso del internet')),
        send_list(Pre1,append,[si , no]),
        new(Pre2,menu('2. Criar, cuidar y tratar animales domésticos y de campo')),
        send_list(Pre2,append,[si , no]),
        new(Pre3,menu('3. Investigar sobre áreas verdes, medio ambiente y cambios climáticos')),
        send_list(Pre3,append,[si , no]),
        new(Pre4,menu('4. Ilustrar, dibujar y animar digitalmente')),
        send_list(Pre4,append,[si , no]),
        new(Pre5,menu('5. Seleccionar, capacitar y motivar al personal de una organización/empresa')),
        send_list(Pre5,append,[si , no]),
        new(Pre6,menu('6. Realizar excavaciones para descubrir restos del pasado')),
        send_list(Pre6,append,[si , no]),
        new(Pre7,menu('7. Resolver Problemas de Calculo Matematico')),
        send_list(Pre7,append,[si , no]),
        new(Pre8,menu('8. Investigar el pasado y saber acerca de Historia')),
        send_list(Pre8,append,[si , no]),
        new(Pre9,menu('9. Fotografiar paisajes')),
        send_list(Pre9,append,[si , no]),
        new(Pre10,menu('10. Planificar cuáles son las metas de una organización pública o privada a \nmediano y largo plazo')),
        send_list(Pre10,append,[si , no]),
        new(Pre11,menu('11. Te gusta la programación o cosas que tenga que ver con computadoras')),
        send_list(Pre11,append,[si , no]),
        new(Pre12,menu('12. Diseñar logotipos y portadas de una revista')),
        send_list(Pre12,append,[si , no]),
        new(Pre13,menu('13. Organizar eventos y atender a sus asistentes')),
        send_list(Pre13,append,[si , no]),
        new(Pre14,menu('14. Atender la salud de personas enfermas')),
        send_list(Pre14,append,[si , no]),
        new(Pre15,menu('15. Controlar ingresos y egresos de fondos y presentar el balance final de \nuna institución')),
        send_list(Pre15,append,[si , no]),
        new(Pre16,menu('16. Ayudar a la sociedad con los problemas que tienen')),
        send_list(Pre16,append,[si , no]),
        new(Pre17,menu('17. Te gusta la Fisica, Matematica, y todo lo que tenga que ver con numeros')),
        send_list(Pre17,append,[si , no]),
        new(Pre18,menu('18. Investigar y probar nuevos productos farmacéuticos')),
        send_list(Pre18,append,[si , no]),
        new(Pre19,menu('19. Hacer propuestas y formular estrategias para aprovechar las relaciones \neconómicas entre dos países')),
        send_list(Pre19,append,[si , no]),
        new(Pre20,menu('20. Pintar, hacer esculturas, ilustrar libros de arte, etcétera')),
        send_list(Pre20,append,[si , no]),

        %Imprimiendo test
        send_list(D,append,[Pre1,Pre2,Pre3,Pre4,Pre5,Pre6,Pre7,Pre8,Pre9,Pre10,Pre11,Pre12,Pre13,Pre14,Pre15,Pre16,Pre17,Pre18,Pre19,Pre20]),

        send(D, scrollbars, vertical),


        %Boton de retroceso
        new(B1,button(atras,and(message(@prolog,pp),message(D,destroy)))),

        %Al momento de seleccionar siguiente pasamos al areaI:- para comprobar las respuestas que dimos.
        new(B,button(siguiente,and(message(@prolog,areaI,Pre1?selection,Pre2?selection,Pre3?selection,
        Pre4?selection,Pre5?selection,Pre6?selection,Pre7?selection,Pre8?selection,Pre9?selection,Pre10?selection,
        Pre11?selection,Pre12?selection,Pre13?selection,Pre14?selection,Pre15?selection,Pre16?selection,Pre17?selection,
        Pre18?selection,Pre19?selection,Pre20?selection),message(D,destroy)))),

        %Colocamos los botones.
        send(D,append,B1),
        send(D,append,B),

        send(D,open_centered).


%% AREA II: CIENCIAS SOCIALES
areaI(_,_,_,_,_,P6,_,P8,_,_,_,_,P13,_,_,P16,_,_,_,_):-
                                                  espregunta('Realizar excavaciones para descubrir restos del pasado',P6),P6='si',
                                                  espregunta('Investigar el pasado y saber acerca de Historia',P8),P8='si',
                                                  espregunta('Organizar eventos y atender a sus asistentes',P13),P13='si',
                                                  espregunta('Ayudar a la sociedad con los problemas que tienen',P16),P16='si',
                                                  pf3('C:/Users/Masamorro/Desktop/Prolog voca/Programa/Imagen2.jpg','CIENCIAS SOCIALES:
                                                  Trabajo Social, Idiomas, Educación, Historia y Geografía, Periodismo, Antropología, Arqueología, Gestión Social y Desarrollo, Consejería Familiar,
                                                  Educación Especial, Hotelería y Turismo; Teología.').
                                                  
%% AREA I: ARTE Y CREATIVIDAD.
areaI(_,_,_,P4,_,_,_,_,P9,_,_,P12,_,_,_,_,_,_,_,P20):-
                                                      espregunta('Ilustrar, dibujar y animar digitalmente',P4),P4='si',
                                                      espregunta('Fotografiar paisajes',P9),P9='si',
                                                      espregunta('Diseñar logotipos y portadas de una revista',P12),P12='si',
                                                      espregunta('Pintar, hacer esculturas, ilustrar libros de arte, etcétera',P20),P20='si',
                                                      pf3('C:/Users/Masamorro/Desktop/Prolog voca/Programa/imagen1.jpg','ARTE Y CREATIVIDAD:
                                                      Diseño Gráfico, Artes Plásticas (Pintura, Escultura, Danza, Teatro, Artesanía, Cerámica), Fotografía, Fotografía Digital, Gestión Gráfica y
                                                      Publicitaria, Locución y Publicidad, Actuación, Camarografía').

%% AREA III: Económica, Administrativa y Financiera
areaI(_,_,_,_,P5,_,_,_,_,P10,_,_,_,_,P15,_,_,_,P19,_):-
                                                      espregunta('Seleccionar, capacitar y motivar al personal de una organización/empresa',P5),P5='si',
                                                      espregunta('Planificar cuáles son las metas de una organización pública o privada a mediano y largo plazo',P10),P10='si',
                                                      espregunta('Controlar ingresos y egresos de fondos y presentar el balance final de una institución',P15),P15='si',
                                                      espregunta('Hacer propuestas y formular estrategias para aprovechar las relaciones económicas entre dos países',P19),P19='si',
                                                      pf3('C:/Users/Masamorro/Desktop/Prolog voca/Programa/imagen3.jpg','ECONOMIA, ADMINISTRATIVA y FINANCIERA:
                                                      Administración de Empresas, Contabilidad, Marketing Estratégico, Gestión y Negocios Internacionales, Gestión Empresarial,
                                                      Gestión Financiera, Ingeniería Comercial, Comercio Exterior, Banca y Finanzas, Gestión de Recursos Humanos, Comunicaciones Integradas en
                                                      Marketing, Administración de Empresas Ecoturísticas y de Hospitalidad, Ciencias Económicas y Financieras, Administración y Ciencias Políticas,
                                                      Ciencias Empresariales, Comercio Electrónico, Emprendedores, Gestión de Organismos Públicos (Municipios, Ministerios, etcétera.), Gestión de
                                                      Centros Educativos.').

%% AREA IV: Ciencia y Tecnología
areaI(P1,_,_,_,_,_,P7,_,_,_,P11,_,_,_,_,_,P17,_,_,_):-
                                                    espregunta('Diseñar programas de computación y explorar nuevas aplicaciones tecnológicas para uso del internet',P1),P1='si',
                                                    espregunta('Resolver Problemas de Calculo Matematico',P7),P7='si',
                                                    espregunta('Te gusta la programación o cosas que tenga que ver con computadoras',P11),P11='si',
                                                    espregunta('Te gusta la Fisica, Matematica, y todo lo que tenga que ver con numeros',P17),P17='si',
                                                    pf3('C:/Users/Masamorro/Desktop/Prolog voca/Programa/imagen4.jpg','CIENCIA Y TECNOLOGIA:
                                                    Ingenieria Informatica,Ingeniería en Sistemas, Ingeniería Civil, Arquitectura, Electrónica, Telecomunicaciones, Ingeniería
                                                    Mecatrónica (Robótica), Ingeniería Mecánica, Ingeniería Industrial, Física, Matemáticas Aplicadas, Ingeniería en Estadística,
                                                    Ingeniería Automotriz, Biotecnología Ambiental ').
                                                    
%% AREA 6:Tecnología
areaI(P1,_,_,P4,_,_,_,_,_,_,P11,_,_,_,_,_,P17,_,_,_):-
                                                    espregunta('Diseñar programas de computación y explorar nuevas aplicaciones tecnológicas para uso del internet',P1),P1='si',
                                                    espregunta('Ilustrar, dibujar y animar digitalmente',P4),P4='si',
                                                    espregunta('Te gusta la programación o cosas que tenga que ver con computadoras',P11),P11='si',
                                                    espregunta('Te gusta la Fisica, Matematica, y todo lo que tenga que ver con numeros',P17),P17='si',
                                                    pf3('C:/Users/Masamorro/Desktop/Prolog voca/Programa/imagen4.jpg','TECNOLOGIA:
                                                    Ingenieria Informatica,Ingeniería en Sistemas, Ingeniería de software,Electrónica,Telecomunicaciones, Ingeniería
                                                    Mecatrónica (Robótica), Matemáticas Aplicadas, Limpiar Teclados  ').

%% AREA V: Ciencias Ecológicas, Biológicas y de Salud
areaI(_,P2,P3,_,_,_,_,_,_,_,_,_,_,P14,_,_,_,P18,_,_):-
                                                      espregunta('Criar, cuidar y tratar animales domésticos y de campo',P2),P2='si',
                                                      espregunta('Investigar sobre áreas verdes, medio ambiente y cambios climáticos',P3),P3='si',
                                                      espregunta('Atender la salud de personas enfermas',P14),P14='si',
                                                      espregunta('Investigar y probar nuevos productos farmacéuticos',P18),P18='si',
                                                      pf3('C:/Users/Masamorro/Desktop/Prolog voca/Programa/imagen5.jpg','CIENCIAS ECOLÓGICAS, BIOLÓGICAS Y DE LASALUD:
                                                      Biología, Farmacia, Zootecnia, Veterinaria, Medicina, Enfermería.').
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
          new(A22,button(salir,and(message(D,destroy)))),
          send(D, append(label(n,''))),
    send(D, append(label(n,'RECOMENDACION DE AREA DE VOCACION: '))),
         send(D, append(label(n,Y))),
          send(D,append,L),
          send(D,append,A22),
         send(D,open_centered).


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

