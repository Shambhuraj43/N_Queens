
output: N_Queens.o
	g++ N_Queens.o -o output

selectionSort.o: N_Queens.cpp
	g++ -c N_Queens.cpp -o N_Queens.o

clean:
	rm *.o output
