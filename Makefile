CFLAGS = -g -Wall -ansi -pedantic -Wno-unused-function

parser: mini_l.lex mini_l.y
	bison -v -d --file-prefix=y mini_l.y
	flex mini_l.lex
	g++ $(CFLAGS) -std=c++11 -o parser y.tab.c lex.yy.c -lfl

clean:
	rm -f parser y.tab.c y.tab.h y.output lex.yy.c fibonacci.mil input.txt

test: 
	chmod +x mil_run
	cat fibonacci.min | parser > fibonacci.mil
	echo 5 > input.txt
	mil_run fibonacci.mil < input.txt

