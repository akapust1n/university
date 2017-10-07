.PHONY: all clean install uninstall

all: lab1
	
clean:
			rm -rf lab1 *.o
lab1: main.c
	gcc -o lab1 main.c -lusb
install:
			install ./lab1 /usr/local/bin
uninstall:
			rm -rf /usr/local/bin/lab1