CC = gcc
FLAGS = -O3
CFLAGS = -Wall -Wextra -DGLFW_DLL -Ilib/GLFW
LDFLAGS = -Llib/GLFW
LDLIBS  = -lglfw3dll -lopengl32 -lgdi32

TARGET  = program
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS) $(LDLIBS)
	cp lib/GLFW/glfw3.dll ./

launch:
	./program.exe

clean:
	$(RM) $(TARGET)

run: all launch clean

.PHONY: all clean