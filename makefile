hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Konum.o -c ./src/Konum.cpp
	g++ -I ./include/ -o ./lib/Labirent.o -c ./src/Labirent.cpp
	g++ -I ./include/ -o ./bin/Labirent ./lib/Konum.o ./lib/Labirent.o ./src/main.cpp
	
calistir:
	g++ -o bin/Labirent ./src/main.cpp ./lib/Konum.o ./lib/Labirent.o -I ./include/
	./bin/Labirent.exe
