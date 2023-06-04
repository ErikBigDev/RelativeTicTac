CC = g++


SOURCE_FILES = src/main.cpp src/game.cpp src/renderSys.cpp src/controls.cpp

LFLAGS = -lglfw -lGL
CFLAGS = $(shell pkg-config --cflags gl glfw3) -g

.all: relative

relative $(SOURCE_FILES):
	$(CC) $(SOURCE_FILES) $(LFLAGS) $(CFLAGS) -o relative.out
