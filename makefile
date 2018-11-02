CC := g++
FLAGS := -std=c++11 -w
INC_DIR := include
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
INCLUDE := -I./$(INC_DIR)

$(BIN_DIR)/main: $(BUILD_DIR)/E-expand.o $(BUILD_DIR)/Feistel.o $(BUILD_DIR)/fill.o $(BUILD_DIR)/IP.o $(BUILD_DIR)/key.o $(BUILD_DIR)/P-displace.o $(BUILD_DIR)/S-box.o $(BUILD_DIR)/main.o
	@mkdir -p $(BIN_DIR)
	@$(CC) $(FLAGS) $(INCLUDE) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(FLAGS) $(INCLUDE) -c -o $@ $<

clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BIN_DIR)