BIN=bin
bin:
	gcc -g trees.c queue.c -o bin
clean:
	rm -rf bin

