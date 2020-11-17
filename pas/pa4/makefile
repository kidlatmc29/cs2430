pa4: pa4.o heap.o 
	g++ -o pa4 pa4.o heap.o

pa4.o: pa4.cpp 
	g++ -c -pedantic -Wall -Werror pa4.cpp

heap.o: heap.cpp
	g++ -c -pedantic -Wall -Werror heap.cpp

clean:
	rm *.o