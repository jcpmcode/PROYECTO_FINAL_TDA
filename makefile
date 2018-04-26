default:principal.o topologia.o ruteo.o direccionamiento.o
	gcc principal.o topologia.o ruteo.o direccionamiento.o -o ruta.out
principal.o:principal.c
	gcc -c principal.c
topologia.o:topologia.c
	gcc -c topologia.c
ruteo.o:ruteo.c
	gcc -c ruteo.c
direccionamiento.o:direccionamiento.c
	gcc -c direccionamiento.c
clean:
	rm *.o
	clear
