CC = gcc

TARGET = main

SRC = main.cpp Particle.cpp CommonFunctions.cpp

FLAGS = -I/usr/include/raylib -L/usr/lib -lstdc++ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC) $(FLAGS)
