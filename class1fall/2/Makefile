newton: main.o funcs_newton.o
	gcc main.o funcs_newton.o -o newton

main.o: main.c
	gcc -I. -c main.c -o main.o
funcs_newton.o: funcs_newton.c
	gcc -I. -c funcs_newton.c -o funcs_newton.o
clean: 
	rm -f *.o
