# Makefile - CMP2003 BST Lab (Catch2 Autograding)
# Files:
#   - MainProgram.cpp          (student submission, contains BST + a main)
#   - test_bst.cpp             (Catch2 tests)
#   - catch_amalgamated.cpp/.hpp

CXX      = g++
CXXFLAGS = -Wall --std=c++17
TARGET   = runTests

all: $(TARGET)

# Build Catch2 + tests into one executable.
# -Dmain=student_main renames the student's main() so Catch2 can have its own main
$(TARGET): test_bst.cpp catch_amalgamated.cpp MainProgram.cpp
	$(CXX) $(CXXFLAGS) -c catch_amalgamated.cpp -o catch_amalgamated.o
	$(CXX) $(CXXFLAGS) -Dmain=student_main -c test_bst.cpp -o test_bst.o
	$(CXX) $(CXXFLAGS) catch_amalgamated.o test_bst.o -o $(TARGET)

# Run all tests
test: $(TARGET)
	./$(TARGET) --success --durations yes

# Run by rubric sections (optional convenience targets)
task1: $(TARGET)
	./$(TARGET) "[task1]" --success --durations yes

task2: $(TARGET)
	./$(TARGET) "[task2]" --success --durations yes

task3: $(TARGET)
	./$(TARGET) "[task3]" --success --durations yes

task4: $(TARGET)
	./$(TARGET) "[task4]" --success --durations yes

task5: $(TARGET)
	./$(TARGET) "[task5]" --success --durations yes

clean:
	rm -f *.o $(TARGET)
