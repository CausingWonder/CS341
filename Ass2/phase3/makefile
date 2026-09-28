DECK.exe: driver.o standardDeck.o card.o
	g++ card.o standardDeck.o driver.o -o DECK.exe

card.o: card.cpp
	g++ -c card.cpp -o card.o

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

standardDeck.o: standardDeck.cpp
	g++ -c standardDeck.cpp -o standardDeck.o

test:
	valgrind --log-file=valgrind.txt ./DECK.exe

run:
	./DECK.exe

clean:
	rm -f *.o *.exe