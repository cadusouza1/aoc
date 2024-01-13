CC=gcc
# CFLAGS=-Wall -Werror -g
CFLAGS=-g

SRC=src
SRCS=$(wildcard $(SRC)/*.c)

OBJ=obj
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BIN_DIR=bin
BIN=$(BIN_DIR)/day1

run: $(BIN)
	$<

$(BIN): $(OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $@

$(SRC):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@
