all:
	g++ *.cc -std=c++11 -O2 -DNDEBUG -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -Wshadow
	./a.out < jp_public_entrada.txt > out.dat
	diff jp_public_sortida.txt out.dat
