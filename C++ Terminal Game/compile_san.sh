#!/bin/bash
path=`pwd`
touch ncurses_has_been_set_up.txt
mkdir local_astrid
mkdir repos_astrid
cd repos_astrid
git clone https://github.com/mirror/ncurses.git
cd ncurses
./configure --prefix $path/local_astrid --enable-widec --with-pthread
make -j
make -j install
cd ..
