CPP  = g++ -g
CC   = gcc
OBJ  = main.o player.o environment.o GUI.o  conexion.o include/glui.o include/glui_bitmap_img_data.o include/glui_bitmaps.o include/glui_button.o include/glui_column.o include/glui_control.o include/glui_edittext.o include/glui_node.o include/glui_panel.o include/glui_radio.o include/glui_rollout.o include/glui_spinner.o include/glui_statictext.o include/glui_string.o include/glui_window.o include/glui_filebrowser.o include/glui_list.o include/glui_scrollbar.o include/glui_tree.o
LIBS =  -lGL -lGLU -lglut
BIN  = Disconnect4Boom
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(OBJ) -o $(BIN) $(LIBS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)

player.o: player.cpp
	$(CPP) -c player.cpp -o player.o $(CXXFLAGS)

environment.o: environment.cpp
	$(CPP) -c environment.cpp -o environment.o $(CXXFLAGS)


GUI.o: GUI.cpp
	$(CPP) -c GUI.cpp -o GUI.o $(CXXFLAGS)

conexion.o: conexion.cpp
	$(CPP) -c conexion.cpp -o conexion.o $(CXXFLAGS)



include/glui.o: include/glui.cpp
	$(CPP) -c include/glui.cpp -o include/glui.o -Linclude/GL $(CXXFLAGS)

include/glui_bitmap_img_data.o: include/glui_bitmap_img_data.cpp
	$(CPP) -c include/glui_bitmap_img_data.cpp -o include/glui_bitmap_img_data.o $(CXXFLAGS)

include/glui_bitmaps.o: include/glui_bitmaps.cpp
	$(CPP) -c include/glui_bitmaps.cpp -o include/glui_bitmaps.o $(CXXFLAGS)

include/glui_button.o: include/glui_button.cpp
	$(CPP) -c include/glui_button.cpp -o include/glui_button.o $(CXXFLAGS)

include/glui_column.o: include/glui_column.cpp
	$(CPP) -c include/glui_column.cpp -o include/glui_column.o $(CXXFLAGS)

include/glui_control.o: include/glui_control.cpp
	$(CPP) -c include/glui_control.cpp -o include/glui_control.o $(CXXFLAGS)

include/glui_edittext.o: include/glui_edittext.cpp
	$(CPP) -c include/glui_edittext.cpp -o include/glui_edittext.o $(CXXFLAGS)

include/glui_node.o: include/glui_node.cpp
	$(CPP) -c include/glui_node.cpp -o include/glui_node.o $(CXXFLAGS)

include/glui_panel.o: include/glui_panel.cpp
	$(CPP) -c include/glui_panel.cpp -o include/glui_panel.o $(CXXFLAGS)

include/glui_radio.o: include/glui_radio.cpp
	$(CPP) -c include/glui_radio.cpp -o include/glui_radio.o $(CXXFLAGS)

include/glui_rollout.o: include/glui_rollout.cpp
	$(CPP) -c include/glui_rollout.cpp -o include/glui_rollout.o $(CXXFLAGS)

include/glui_spinner.o: include/glui_spinner.cpp
	$(CPP) -c include/glui_spinner.cpp -o include/glui_spinner.o $(CXXFLAGS)

include/glui_statictext.o: include/glui_statictext.cpp
	$(CPP) -c include/glui_statictext.cpp -o include/glui_statictext.o $(CXXFLAGS)

include/glui_string.o: include/glui_string.cpp
	$(CPP) -c include/glui_string.cpp -o include/glui_string.o $(CXXFLAGS)

include/glui_window.o: include/glui_window.cpp
	$(CPP) -c include/glui_window.cpp -o include/glui_window.o $(CXXFLAGS)

include/glui_filebrowser.o: include/glui_filebrowser.cpp
	$(CPP) -c include/glui_filebrowser.cpp -o include/glui_filebrowser.o $(CXXFLAGS)

include/glui_list.o: include/glui_list.cpp
	$(CPP) -c include/glui_list.cpp -o include/glui_list.o $(CXXFLAGS)

include/glui_scrollbar.o: include/glui_scrollbar.cpp
	$(CPP) -c include/glui_scrollbar.cpp -o include/glui_scrollbar.o $(CXXFLAGS)

include/glui_tree.o: include/glui_tree.cpp
	$(CPP) -c include/glui_tree.cpp -o include/glui_tree.o $(CXXFLAGS)