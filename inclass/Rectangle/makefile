Shapes.exe: Driver.o Rectangle.o
	g++ Rectangle.o driver.o -o Shapes.exe

Rectangle.o: Rectangle.cpp
	g++ -c Rectangle.cpp -o Rectangle.o

Driver.o: Driver.cpp
	g++ -c Driver.cpp -o Driver.o

run:
	./Shapes.exe

clean:
	rm -f *.o *.exe