# Variáveis para o compilador e opções
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Nome do executável
TARGET = forca

# Fontes
SOURCES = forca.c++

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
