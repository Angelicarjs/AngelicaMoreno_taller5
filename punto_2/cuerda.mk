cuerda.gif : cuerda.txt
	python animacion.py
cuerda.txt: cuerda
	./cuerda > cuerda.txt

cuerda: cuerda.cpp
	c++ cuerda.cpp -o ./cuerda 
