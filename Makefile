F=cinensegabriel_exer9

default: combi

perm:
	gcc -o permutation permutation.c
	./permutation

seq:
	gcc -o sequence sequence.c
	./sequence

combi:
	gcc -o combination combination.c
	./combination

final: 
	gcc -o $(F) $(F).c
	./$(F)

