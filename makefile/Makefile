
compile: main.o function1.o function2.o
	g++ main.o function1.o function2.o -o fact

main.o: main.cpp
	g++ -c -o main.o main.cpp

function1.o: function1.cpp functions.h
	g++ -c -o function1.o function1.cpp 

function2.o: function2.cpp functions.h
	g++ -c -o function2.o function2.cpp 

clean:
	rm -rf *.o fact
