CC=gcc
CFLAGS=-g
LFLAGS=-lm

SRC=src
SRCS=$(wildcard $(SRC)/*.c)

OBJ=obj
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BIN_DIR=bin
BIN=$(BIN_DIR)/solution

INPUT_DIR=input
INPUT=$(INPUT_DIR)/input.txt

run: $(BIN) $(INPUT)
	$< < $(INPUT)

$(BIN): $(BIN_DIR) $(OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $@

$(SRC):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

$(INPUT_DIR):
	mkdir -p $@

$(INPUT): $(INPUT_DIR)
	touch $@

clean:
	rm -rf $(BIN_DIR)
	rm -rf $(OBJ)
