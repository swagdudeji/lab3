all: class_Menu.o class_Tour.o main.o project

class_Menu.o: class_Menu.cpp
	g++ -c -o class_Menu.o class_Menu.cpp

class_Tour.o: class_Tour.cpp
	g++ -c -o class_Tour.o class_Tour.cpp

main.o: main.cpp
	g++ -c -o main.o main.cpp

project: class_Menu.o class_Tour.o main.o
	g++ class_Menu.o class_Tour.o main.o -o project