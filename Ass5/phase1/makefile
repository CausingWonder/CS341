.DEFAULT_GOAL := p1

P1.exe: Ingest.o driver_p1.o
	g++ Ingest.o driver_p1.o -o P1.exe

Ingest.o: Ingest.cpp
	g++ -c Ingest.cpp -o Ingest.o
driver_p1.o: driver_p1.cpp
	g++ -c driver_p1.cpp -o driver_p1.o
driver_full.o: driver_full.cpp
	g++ -c driver_full.cpp -o driver_full.o

p1:
	make P1.exe
	./P1.exe

clean:
	rm -f *.o *.exe