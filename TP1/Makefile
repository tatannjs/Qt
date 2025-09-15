CC=g++ -c -I.
LD=g++ -o

all: testOperation testDate

testOperation: %: %.o Operation.o Date.o
	$(LD) $@ $^

testDate: %: %.o Date.o
	$(LD) $@ $^

testOperation.o: %.o: %.cpp Operation.h Date.h
	$(CC) $<

testDate.o: %.o: %.cpp Date.h
	$(CC) $<

Operation.o Date.o: %.o: %.cpp %.h
	$(CC) $<

clean:
	del *.o *.exe

