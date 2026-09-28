ARRAY.exe: driver.o  bitarray.o
	g++ bitarray.o  driver.o -o ARRAY.exe

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