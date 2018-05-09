all : cuerda
	./cuerda
cuerda : cuerda.o
	g++ cuerda.o -o cuerda -lsfml-graphics -lsfml-window -lsfml-system
cuerda.o : cuerda.cpp window.hpp
	g++ -c cuerda.cpp
clean :
	rm -f *.o *.out *.dat *.mp4
