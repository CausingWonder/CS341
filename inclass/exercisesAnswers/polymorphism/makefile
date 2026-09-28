# This is a sample makefile.
#
# By: Dr. Ryan Rybarczyk
#
# Note: If your makefile has an extension and/or isn't named makefile then you need to type the following:
# 		make -f NAME_OF_MAKEFILE.EXTENSION OF MAKEFILE (e.g., make -f makefile.txt)

Shapes.exe: driver.o Rectangle.o Triangle.o Square.o Shape.o
	g++ driver.o Rectangle.o Triangle.o Square.o Shape.o -o Shapes.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
	
Rectangle.o: Rectangle.cpp
	g++ -c Rectangle.cpp -o Rectangle.o

Square.o: Square.cpp
	g++ -c Square.cpp -o Square.o

Triangle.o: Triangle.cpp
	g++ -c Triangle.cpp -o Triangle.o

Shape.o: Shape.cpp
	g++ -c Shape.cpp -o Shape.o
	
run:
	Shapes.exe
	
clean:
	rm -f *.o *.exe *.txt 
# Inference Rules (*)
	
# Target: Dependency List
# <TAB>Shell Line(s)
# 
# Both Lines == Rule