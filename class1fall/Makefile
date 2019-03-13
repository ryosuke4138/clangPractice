newton:main.o funcs_newton.o
	gcc -lm -o newton main.o funcs_newton.o
.c.o: 
	gcc -c $< -l.

clean:
	rm -f newton*.o*~
