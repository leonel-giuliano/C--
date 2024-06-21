# Nombre del compilador
CXX = g++

# Directorios
SRC_DIR = .
OUT_DIR = ./output

# Archivos fuente y de encabezado
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OUT_DIR)/%.o, $(SRC_FILES))

# Nombre del ejecutable
EXEC = $(OUT_DIR)/main.exe

# Flags de compilación
CXXFLAGS = -Wall -I$(SRC_DIR)

# Regla para compilar el ejecutable
$(EXEC): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar archivos .cpp a .o
$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
.PHONY: clean
clean:
	rm -f $(OUT_DIR)/*.o $(EXEC)