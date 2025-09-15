CC=g++ -c -I.
LD=g++ -o

all: testRatio

testRatio: %: %.o Ratio.o
	$(LD) $@ $^

testRatio.o: %.o: %.cpp Ratio.h
	$(CC) $<

Ratio.o: %.o: %.cpp %.h
	$(CC) $<

clean:
	del *.o testRatio.exe

