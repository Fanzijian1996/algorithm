all:main random
.PHONY:all
main:algorithm.cpp readfile.cpp main.cpp
	c++ -o main algorithm.cpp readfile.cpp main.cpp -std=c++11
random:random.cpp
	c++ -o random random.cpp -std=c++11
.PHONY:clean
clean:
	rm -f  main random
