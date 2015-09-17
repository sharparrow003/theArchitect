all: group compiler

group:
	@echo "Lalit Sudarshan, Michael Loh"
compiler:
	@mkdir -p build
	@mkdir -p generated
	@flex src/Micro.l
	@bison -d src/Micro.y
	@g++ Micro.tab.c lex.yy.c -lfl -o Micro
	@mv lex.yy.c generated/lex.yy.c
	@mv Micro.tab.c generated/Micro.tab.c
	@mv Micro.tab.h generated/Micro.tab.h
	@mv Micro build/Micro

clean:
	@rm -rf build
	@rm -rf generated

.PHONY: all group compiler clean