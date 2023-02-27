main: knight.o
	g++ -o main knight.o

knight.o: knight.cpp
	g++ -c knight.cpp
