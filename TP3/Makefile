CFLAGS=-Wall
CC=g++ -g -c $(CFLAGS)
LD=g++ -g -o

all: testVecteur

testVecteur: testVecteur.o Vecteur.o
	$(LD) $@ $^

testVecteur.o: testVecteur.cpp Vecteur.h
	$(CC) $<

Vecteur.o: Vecteur.cpp Vecteur.h
	$(CC) $<

clean:
	rm testVecteur *.o

