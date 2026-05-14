CC      = clang
CFLAGS  = -Wall -Wextra -std=c23 -Ilc-utils/include
LCLIB   = lc-utils/build/libleetcode.a

PROB    ?= 0035-search-insert-position
MAIN    = leetcode/$(PROB)/main.c
TARGET  = build/$(PROB)
TESTER_BIN = build/tester

.PHONY: all run clean lc-utils list

all: $(TARGET)

lc-utils:
	$(MAKE) -C lc-utils

build:
	@mkdir -p build

$(TARGET): $(MAIN) lc-utils | build
	$(CC) $(CFLAGS) $< $(LCLIB) -o $@

$(TESTER_BIN): tester.c
	$(CC) $(CFLAGS) tester.c -o $(TESTER_BIN)

run: $(TARGET)
	@echo ""
	@echo "==== Saída de $(PROB) ===="
	@echo ""
	@if [ -f "leetcode/$(PROB)/test.txt" ]; then \
		./$(TARGET) < leetcode/$(PROB)/test.txt; \
	else \
		echo "Sem leetcode/$(PROB)/test.txt; rodando com stdin normal."; \
		./$(TARGET); \
	fi

test: $(TARGET)
	@if [ ! -f "leetcode/$(PROB)/test.txt" ] || [ ! -f "leetcode/$(PROB)/expected.txt" ]; then \
		echo "Preciso de leetcode/$(PROB)/test.txt e expected.txt"; \
		exit 1; \
	fi; \
	tmp_out="$$(mktemp)"; \
	./$(TARGET) < leetcode/$(PROB)/test.txt > "$$tmp_out"; \
	echo ""; \
	echo "==== icdiff (esperado vs atual) ===="; \
	icdiff --cols=120 leetcode/$(PROB)/expected.txt "$$tmp_out" || true; \
	rm -f "$$tmp_out"

tester: $(TARGET) $(TESTER_BIN)
	@if [ ! -f "leetcode/$(PROB)/test.txt" ] || [ ! -f "leetcode/$(PROB)/expected.txt" ]; then \
		echo "Preciso de leetcode/$(PROB)/test.txt e expected.txt"; \
		exit 1; \
	fi; \
	out_file="leetcode/$(PROB)/output.txt"; \
	./$(TARGET) < leetcode/$(PROB)/test.txt > "$$out_file"; \
	echo ""; \
	./$(TESTER_BIN) leetcode/$(PROB)/expected.txt "$$out_file"

list:
	@echo "Problemas com diretório próprio (main.c):"
	@find leetcode -mindepth 2 -maxdepth 2 -type f -name 'main.c' \
		| sed 's|leetcode/||; s|/main.c||' \
		| sort
	@echo ""
	@echo "Arquivos .c soltos em leetcode/:"
	@find leetcode -maxdepth 1 -type f -name '*.c' \
		| sed 's|leetcode/||' \
		| sort

clean:
	rm -rf build
	$(MAKE) -C lc-utils clean
