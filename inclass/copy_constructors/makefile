# Lecture #9 - Copy Constructor
#
# By: Dr. Ryan Rybarczyk
Copy.exe: driver.o Deck.o
	g++ driver.o Deck.o -o Copy.exe
	
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
	
Deck.o: Deck.cpp
	g++ -c Deck.cpp -o Deck.o
	
clean:
	rm -rf *.o Copy.exe
	
run:
	Copy.exe