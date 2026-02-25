# CONFIG
LCC = lcc
TARGET = ./build/game.gb
OBJDIR = build

SOURCES = $(shell find . -name *.c)

all:
	make clean
	@mkdir -p build
	$(LCC) -o $(TARGET) $(SOURCES) -Wl-yo4 > ./build/logs.txt 2>&1
	@echo "--- ROM CREATED: $(TARGET) ---"

clean:
	rm -f $(TARGET)
	rm -rf build/
