GPA.exe: driver.o card.o
	g++ card.o driver.o -o DECK.exe

card.o: card.cpp
	g++ -c card.cpp -o card.o

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

run:
	./DECK.exe

clean:
	rm -f *.o *.exe