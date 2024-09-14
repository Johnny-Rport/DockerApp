# Makefile for visualizer
#
INPUT_SRC=./src/*.cpp
INPUT_OBJ=./*.o
OUTPUT=algoVisual
FLAGS=-Wall -std=c++11
SFML_LIB=./SFML/lib
SFML_INC=./SFML/include

all: compile clean
	
compile: $(INPUT_OBJ) 
	g++ $(FLAGS) $(INPUT_OBJ) -o $(OUTPUT) -L$(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system 

$(INPUT_OBJ): 
	g++ -c $(INPUT_SRC) -I$(SFML_INC)

clean:
	rm -f $(INPUT_OBJ)




###################
