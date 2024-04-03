FLAGS = -Werror -std=c++11

main.exe: main.o init.o list.o create.o add.o
	g++ main.o init.o list.o create.o add.o -o main.exe

main.o: main.cpp
	g++ ${FLAGS} -c main.cpp

init.o: init.cpp
	g++ ${FLAGS} -c init.cpp

list.o: list.cpp
	g++ ${FLAGS} -c list.cpp
create.o: create.cpp
	g++ ${FLAGS} -c create.cpp
add.o: add.cpp
	g++ ${FLAGS} -c add.cpp

clean:
	rm *.o
	rm main