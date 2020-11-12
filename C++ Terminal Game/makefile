flags = -pedantic-errors -std=c++11 -Wall
begnc = -I local_astrid/include -I local_astrid/include/ncursestw -L local_astrid/lib
endnc = -lncursestw -ldl -pthread
nc = ncurses_has_been_set_up.txt

ncurses_has_been_set_up.txt:
	./compile_san.sh

windowDetails.o: windowDetails.cpp windowDetails.h $(nc)
	g++ $(flags) $(begnc) -o $@ -c $< 

mainMenu.o: mainMenu.cpp mainMenu.h windowDetails.h $(nc)
	g++ $(flags) $(begnc) -o $@ -c $<

roll.o: roll.cpp roll.h $(nc)
	g++ $(flags) $(begnc) -o $@ -c $<

newGame.o: newGame.cpp newGame.h $(nc)
	g++ $(flags) $(begnc) -o $@ -c $<

test.o: test.cpp test.h roll.h newGame.h mainMenu.h windowDetails.h $(nc)
	g++ $(flags) $(begnc) -o $@ -c $<

Game: windowDetails.o mainMenu.o roll.o newGame.o test.o $(nc)
	g++ $(flags) $(begnc) -o $@ windowDetails.o mainMenu.o roll.o newGame.o test.o $(endnc) 
	touch Leaderboard.txt

run:
	./Game 2> log.txt

delnc:
	rm ncurses_has_been_set_up.txt
	rm -rf local_astrid repos_astrid
	echo "The ncurses files have been deleted"

clean:
	rm *.o
	rm Game
	rm Leaderboard.txt
	rm log.txt

full_clean:
	rm ncurses_has_been_set_up.txt
	rm -rf local_astrid repos_astrid
	rm *.o
	rm Game
	rm Leaderboard.txt
	rm log.txt

.PHONY: run delnc clean full_clean

