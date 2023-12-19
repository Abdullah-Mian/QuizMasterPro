# Compile each source file into object files
g++ -c main.cpp -o main.o
g++ -c Sleep.cpp -o Sleep.o
g++ -c Admin.cpp -o Admin.o
g++ -c SubAdmin.cpp -o SubAdmin.o
g++ -c SuperAdmin.cpp -o SuperAdmin.o
g++ -c Student.cpp -o Student.o
g++ -c ClearScreen.cpp -o ClearScreen.o  # Add this line to compile ClearScreen.cpp

# Link the object files to create the executable
g++ main.o Sleep.o Admin.o SubAdmin.o SuperAdmin.o Student.o ClearScreen.o -o QuizMasterPro  # Include ClearScreen.o

# For Execution
./QuizMasterPro
