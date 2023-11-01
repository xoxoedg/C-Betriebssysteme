CFLAGS = -g -Wall

all: main

pp: PointerToPointer.c
	gcc $(CFLAGS) PointerToPointer.c -o pointer

main: main.c
	gcc $(CFLAGS) main.c -o main

run: 
	echo "Running the programm"
	./main

runpointer: 
	echo "Running the programm"
	./pointer

clean:
	rm -f main.exe