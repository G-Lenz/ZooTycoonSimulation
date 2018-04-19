zootycoon: animal.cpp tiger.cpp penguin.cpp turtle.cpp zoo.cpp  main.cpp validate.cpp
	g++ -std=c++11 animal.cpp tiger.cpp penguin.cpp turtle.cpp zoo.cpp validate.cpp main.cpp -o zootycoon

clean: 
	rm zootycoon
