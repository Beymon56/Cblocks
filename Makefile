CC = gcc
FLAGS = -O3
CFLAGS = -Wall -Wextra -DGLFW_DLL -Ilib/GLFW -Iglad/lib/GLAD/glad
LDFLAGS = -Llib/GLFW
LDLIBS  = -lglfw3dll -lopengl32 -lgdi32

TARGET  = program
SRC = src/main.c src/glad.c src/window.h src/input.h

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS) $(LDLIBS)

launch:
	./program.exe

clean:
	$(RM) $(TARGET)

run: all launch clean

.PHONY: all clean