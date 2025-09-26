COMPILER := g++
FLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D _DEBUG -D _EJUDGE_CLIENT_SIDE

TARGET := onegin.exe
SOURCES := main.cpp poem_processing.cpp string_comparison.cpp bubble_sort.cpp output.cpp
OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: all clean bubble qsort

all: $(TARGET)

bubble: FLAGS += -DUSE_BUBBLE_SORT
bubble: $(TARGET)

qsort: FLAGS += -DUSE_QSORT
qsort: $(TARGET)

$(TARGET): $(OBJECTS)
	$(COMPILER) $(FLAGS) $^ -o $@

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
