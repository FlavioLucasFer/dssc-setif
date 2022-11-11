build:
	@echo compiling list.cpp and tests.cpp
	g++ -o tests list.cpp tests.cpp

run:
	@./tests

clean:
	@echo deleting tests binary
	rm -f tests

rebuild: clean build

build-run: build run

rebuild-run: clean build-run 