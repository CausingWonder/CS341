GPA.exe: driver.o Student.o
	g++ Student.o driver.o -o GPA.exe

Student.o: Student.cpp
	g++ -c Student.cpp -o Student.o

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

run:
	./GPA.exe

clean:
	rm -f *.o *.exe