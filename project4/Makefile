
sequence_exam3: sequence3.o sequence_exam3.o node1.o
	g++ sequence_exam3.o sequence3.o node1.o -o sequence_exam3

sequence3.o: sequence3.cpp
	g++ -Wall -c sequence3.cpp

sequence_exam3.o: sequence_exam3.cxx
	g++ -Wall -c sequence_exam3.cxx

node1.o: node1.cxx
	g++ -Wall -c node1.cxx

clean:
	rm *.o sequence_exam3.o
