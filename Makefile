all: bstcount 

bstcount: bstcount.cpp
	g++ -o bstcount.out bstcount.cpp

