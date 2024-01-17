CC=gcc
CFLAGS=-g

SRC=src
SRCS=$(wildcard $(SRC)/*.c)

OBJ=obj
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BIN_DIR=bin
BIN=$(BIN_DIR)/day4

run: $(BIN)
	$<

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

clean:
	rm -rf $(BIN_DIR)
	rm -rf $(OBJ)
