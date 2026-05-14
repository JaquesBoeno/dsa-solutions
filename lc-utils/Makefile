CC     = clang
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
SRC    = $(wildcard src/*.c)
OBJ    = $(patsubst src/%.c, build/%.o, $(SRC))
LIB    = build/libleetcode.a

.PHONY: all clean

all: $(LIB)

build:
	@mkdir -p build

build/%.o: src/%.c include/leetcode.h | build
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB): $(OBJ)
	ar rcs $@ $^

clean:
	rm -rf build
