# Calculator_program
This code uses a stack-based algorithm to parse and evaluate arithmetic expressions. It supports parentheses to define the order of operations. The evaluateExpression function takes an arithmetic expression as input and returns the evaluated result.

To use the arithmetic parser, the program prompts the user to enter an arithmetic expression. After parsing and evaluating the expression, the result is displayed. The code handles integer and floating-point numbers as operands and supports addition, subtraction, multiplication, and division operators.

# How to compile the program
The CXX variable specifies the C++ compiler (in this case, g++).

The CXXFLAGS variable defines the compiler flags, including the C++ version (-std=c++11) and additional warning options (-Wall -Wextra).

The SRCS variable lists the source files (calculator.cpp in this case).

The OBJS variable generates the corresponding object file names from the source files.

The EXEC variable specifies the name of the executable (calculator in this case).

The all target builds the executable by linking the object files.

The $(EXEC): $(OBJS) rule specifies the dependencies and the command to link the object files into the executable.

The %.o: %.cpp rule specifies the compilation of individual source files into object files.

The clean target removes the object files and the executable.

To use this Makefile, save it in the same directory as calculator_lib.h and calculator.cpp. Then, open a terminal, navigate to the directory, and run the make command to build the executable.
