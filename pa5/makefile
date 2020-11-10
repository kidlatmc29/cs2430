pa5: pa5.o hash.o book.o
	g++ -o pa5 pa5.o hash.o book.o

pa5.o: pa5.cpp 
	g++ -c -pedantic -Wall -Werror pa5.cpp

hash.o: hash.cpp
	g++ -c -pedantic -Wall -Werror hash.cpp

book.o: book.cpp
	g++ -c -pedantic -Wall -Werror book.cpp

clean:
	rm *.o