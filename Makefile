CC      = clang
CFLAGS  = -Wall -Wextra -std=c11 -Ilc-utils/include
LCLIB   = lc-utils/build/libleetcode.a

# Problema atual: exemplo PROB=35-search-insert-position
PROB    ?= 35-search-insert-position
MAIN    = leetcode/$(PROB)/main.c
TARGET  = build/$(PROB)

.PHONY: all run clean lc-utils

all: $(TARGET)

lc-utils:
	$(MAKE) -C lc-utils

build:
	@mkdir -p build

$(TARGET): $(MAIN) lc-utils | build
	$(CC) $(CFLAGS) $< $(LCLIB) -o $@

run: $(TARGET)
	@if [ -f "leetcode/$(PROB)/test.txt" ]; then \
		./$(TARGET) < leetcode/$(PROB)/test.txt; \
	else \
		echo "Sem leetcode/$(PROB)/test.txt; rodando com stdin normal."; \
		./$(TARGET); \
	fi

clean:
	rm -rf build
	$(MAKE) -C lc-utils clean
