Btree: Btree.o main.o 
	g++ -std=c++11 Btree.o main.o -o Run

Btree.o: Btree.cpp Btree.o 
	g++ -std=c++11 -c Btree.cpp

main.o: main.cpp Btree.h
	g++ -c main.cpp

clean:
	 rm -f*.o
	rm Run

run: buildTree
	/Run
