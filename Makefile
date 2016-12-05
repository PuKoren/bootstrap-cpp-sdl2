.PHONY: build

build:
	mkdir -p build
	cd build && cmake .. -DCMAKE_BUILD_TYPE=DEBUG && make

release:
	mkdir -p build
	cd build && cmake .. -DCMAKE_BUILD_TYPE=RELEASE && make

lint:
	cd build && make clang-tidy

format:
	cd build && make clang-format

tests: build
	./build/test/tests

run:
	./build/{project-name}

init:
	sed -i 's/{project-name}/$(NAME)/g' Makefile
	sed -i 's/{project-name}/$(NAME)/g' CMakeLists.txt