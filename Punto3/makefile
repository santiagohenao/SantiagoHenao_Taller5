all : result.png

result.png : result.dat
	python3 graph.py

result.dat : caos
	./caos

caos : caos.cpp
	g++ caos.cpp -o caos

clean :
	rm -f *.dat *.out result.png
