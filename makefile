OBJS_EXEMPLE = $(OBJ_DIR)/mainExemple.o $(OBJ_DIR)/Pixel.o $(OBJ_DIR)/Image.o
OBJS_TEST = $(OBJ_DIR)/mainTest.o $(OBJ_DIR)/Pixel.o $(OBJ_DIR)/Image.o
OBJS_AFFICHAGE = $(OBJ_DIR)/mainAffichage.o $(OBJ_DIR)/Pixel.o $(OBJ_DIR)/Image.o

SDL1 = -lSDL2 -lSDL2_ttf -lSDL2_image
SDL2 = -ISDL2
FLAGS = -ggdb -Wall
CC = g++
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj
DATA_DIR = ./data

all: $(BIN_DIR)/exemple $(BIN_DIR)/test $(BIN_DIR)/affichage

$(BIN_DIR)/affichage: $(OBJS_AFFICHAGE)
	$(CC) $(FLAGS) $(OBJS_AFFICHAGE) -o $(BIN_DIR)/affichage $(SDL1)

$(BIN_DIR)/exemple: $(OBJS_EXEMPLE)
	$(CC) $(FLAGS) $(OBJS_EXEMPLE) -o $(BIN_DIR)/exemple $(SDL1)

$(BIN_DIR)/test: $(OBJS_TEST)
	$(CC) $(FLAGS) $(OBJS_TEST) -o $(BIN_DIR)/test $(SDL1)

$(OBJ_DIR)/mainAffichage.o: $(SRC_DIR)/mainAffichage.cpp $(SRC_DIR)/Image.h $(SRC_DIR)/Pixel.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/mainAffichage.cpp -o $(OBJ_DIR)/mainAffichage.o $(SDL2)

$(OBJ_DIR)/mainExemple.o: $(SRC_DIR)/mainExemple.cpp $(SRC_DIR)/Image.h $(SRC_DIR)/Pixel.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/mainExemple.cpp -o $(OBJ_DIR)/mainExemple.o $(SDL2)

$(OBJ_DIR)/mainTest.o: $(SRC_DIR)/mainTest.cpp $(SRC_DIR)/Image.h $(SRC_DIR)/Pixel.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/mainTest.cpp -o $(OBJ_DIR)/mainTest.o $(SDL2)
	
$(OBJ_DIR)/Image.o: $(SRC_DIR)/Image.cpp $(SRC_DIR)/Image.h $(SRC_DIR)/Pixel.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/Image.cpp -o $(OBJ_DIR)/Image.o $(SDL2)
	
$(OBJ_DIR)/Pixel.o: $(SRC_DIR)/Pixel.cpp $(SRC_DIR)/Pixel.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/Pixel.cpp -o $(OBJ_DIR)/Pixel.o $(SDL2)

clean:
	rm -f $(OBJS_EXEMPLE) $(OBJS_TEST) $(OBJS_AFFICHAGE) $(BIN_DIR)/exemple $(BIN_DIR)/test $(BIN_DIR)/affichage $(DATA_DIR)/*
