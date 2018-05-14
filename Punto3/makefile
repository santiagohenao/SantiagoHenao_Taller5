all : result.pdf

result.pdf : result.png
	pdflatex result.tex > NUL 2>&1
	rm -f result.aux result.log NUL

result.png : result.dat
	python3 graph.py

result.dat : caos
	./caos

caos : caos.cpp
	g++ caos.cpp -o caos

clean :
	rm -f caos result.png result.aux result.log result2.png result.pdf NUL
