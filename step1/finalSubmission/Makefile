all: group compiler

group:
	@echo "Lalit Sudarshan, Michael Loh"
compiler:
	@mkdir -p build
	@lex src/Micro.l
	@mv lex.yy.c build/lex.yy.c
	@cc build/lex.yy.c -o Micro -ll 
clean:
	@rm -rf build
	@rm Micro

.PHONY: all group compiler clean