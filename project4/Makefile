
sequence_test: sequence3.o sequence_test.o node1.o
	g++ sequence_test.o sequence3.o node1.o -o sequence_test

sequence3.o: sequence3.cpp
	g++ -Wall -c sequence3.cpp

sequence_test.o: sequence_test.cxx
	g++ -Wall -c sequence_test.cxx

node1.o: node1.cxx
	g++ -Wall -c node1.cxx

clean:
	rm *.o sequence_test.o
