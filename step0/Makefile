all: group compiler

group:
	echo "Lalit Sudarshan --> lsudarsh"
	echo "Michael Loh --> mloh"

compiler: helloworld

helloworld: helloworld.c
	$(CC) -o $@ $<

clean:
	rm helloworld