# === Configuration ===
SRC_DIR := src
BUILD_DIR := ../build/win
RES_DIR := res

INCLUDE_DIRS := -ID:/Developement/TestGame1/SandboxGame/headers \
                -ID:/Developement/TestGame1/SandboxGame/headers/imgui \
                -IC:/sdl2/include/SDL2

LIB_DIRS := -LC:/sdl2/lib
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

CXXFLAGS := -g -ggdb -c $(INCLUDE_DIRS)
LDFLAGS := $(LIB_DIRS) $(LIBS)

# === Collect Source Files ===
# Use wildcards to collect all the .cpp files in src and its subdirectories
SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/**/*.cpp)
# Object files corresponding to the source files
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)


TARGET := $(BUILD_DIR)/main.exe

# === Default target: build everything ===
all: $(TARGET)

# Link object files into the executable
$(TARGET): $(OBJS)
	@echo "Linking..."
	@mkdir -p $(BUILD_DIR)
	g++ $(OBJS) -o $@ $(LDFLAGS)
	@echo "Copying resources..."
	@rm -rf $(BUILD_DIR)/res
	@cp -r $(RES_DIR) $(BUILD_DIR)/res
	@echo "Launching..."
	@start $(TARGET)

# Rule to compile individual source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $<"
	@mkdir -p $(dir $@)
	g++ $(CXXFLAGS) -o $@ $<
	@touch $@  # Mark the object file as up-to-date

# Clean up build files
clean:
	@echo "Cleaning up..."
	@rm -rf $(BUILD_DIR)

# .PHONY tells make that these are not files but commands
.PHONY: all clean
