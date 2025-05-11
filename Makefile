# === Configuration ===
SRC_DIR := src
HEADER_DIR := headers
IMGUI_SRC_DIR := $(SRC_DIR)/imgui
IMGUI_HEADER_DIR := $(HEADER_DIR)/imgui
BUILD_DIR := build
RES_DIR := res

INCLUDE_DIRS := -I$(SRC_DIR) -I$(HEADER_DIR) -I$(IMGUI_HEADER_DIR) \
                -IC:/sdl2/include/SDL2

LIB_DIRS := -LC:/sdl2/lib
LIBS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

CXXFLAGS := -g -std=c++17 $(INCLUDE_DIRS)

# === Source Files ===
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) \
             $(wildcard $(SRC_DIR)/imgui/imgui*.cpp) \
             $(SRC_DIR)/imgui/imgui_impl_sdl2.cpp \
             $(SRC_DIR)/imgui/imgui_impl_sdlrenderer2.cpp

OBJ_FILES := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

TARGET := $(BUILD_DIR)/main.exe

# === Default target ===
all: $(TARGET)

# === Link the executable ===
$(TARGET): $(OBJ_FILES)
	@echo "Linking..."
	@mkdir -p $(BUILD_DIR)/res
	$(CXX) $^ -o $@ $(CXXFLAGS) $(LIB_DIRS) $(LIBS)

# === Compile each file ===
$(BUILD_DIR)/%.o: %.cpp
	@echo "Compiling $<"
	@mkdir -p $(dir $@)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# === Clean ===
clean:
	@echo "Cleaning..."
	rm -rf $(BUILD_DIR)

.PHONY: all clean run
