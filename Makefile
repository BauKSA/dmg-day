# CONFIG
LCC = lcc
TARGET = ./build/game.gb
OBJDIR = build

SOURCES = $(shell find . -name *.c)

all:
	@make clean
	@mkdir -p build
	@$(LCC) -Wl-yt1 -Wl-yo4 -o $(TARGET) $(SOURCES) > ./build/logs.txt 2>&1
	@echo "--- ROM CREATED: $(TARGET) ---"

clean:
	@rm -f $(TARGET)
	@rm -rf build/
