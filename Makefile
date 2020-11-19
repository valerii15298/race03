all: install clean

install:
	@cp src/main.c src/pairs.c src/combinations.c src/valid.c inc/header.h .
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o race03 main.c pairs.c combinations.c valid.c
	
uninstall: clean
	@rm -rf race03
	
clean:
	@rm -rf main.c pairs.c combinations.c valid.c header.h
	
reinstall: uninstall all
