ARRAY.exe: driver.o bitarray.o set.o dictionary.o
	g++ dictionary.o set.o bitarray.o  driver.o -o ARRAY.exe

dictionary.o: dictionary.cpp
	g++ -c dictionary.cpp -o dictionary.o

set.o: set.cpp
	g++ -c set.cpp -o set.o

bitarray.o: bitarray.cpp
	g++ -c bitarray.cpp -o bitarray.o

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

test:
	valgrind --log-file=valgrind.txt ./ARRAY.exe

run:
	./ARRAY.exe

clean:
	rm -f *.o *.exe