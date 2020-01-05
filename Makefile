exec = a.out
sources = $(filter-out src/main.c, $(wildcard src/*.c))
objects = $(sources:.c=.o)
flags = -g -lm -ldl -fPIC -rdynamic


#$(exec): $(objects)
#	gcc $(objects) $(flags) -o $(exec)

libmaze.a: $(objects)
	ar rcs $@ $^

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	make libmaze.a
	mkdir -p /usr/local/include/maze
	cp -r ./src/include/* /usr/local/include/maze/.
	cp ./libmaze.a /usr/local/lib/.
	cp ./maze.out /usr/local/bin/maze

clean:
	-rm *.out
	-rm *.o
	-rm *.a
	-rm src/*.o

lint:
	clang-tidy src/*.c src/include/*.h
