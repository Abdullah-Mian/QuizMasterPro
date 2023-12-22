# Compile each source file into object files
g++ -c main.cpp -o main.o
g++ -c Sleep.cpp -o Sleep.o
g++ -c Admin.cpp -o Admin.o
g++ -c SubAdmin.cpp -o SubAdmin.o
g++ -c SuperAdmin.cpp -o SuperAdmin.o
g++ -c Student.cpp -o Student.o
g++ -c ClearScreen.cpp -o ClearScreen.o
g++ -c Init.cpp -o Init.o
g++ -c Quiz.cpp -o Quiz.o  # Add this line to compile Quiz.cpp
g++ -c QuizManager.cpp -o QuizManager.o  # Add this line to compile QuizManager.cpp

# Link the object files to create the executable
g++ main.o Sleep.o Admin.o SubAdmin.o SuperAdmin.o Student.o ClearScreen.o Init.o Quiz.o QuizManager.o -o QuizMasterPro  # Include Quiz.o and QuizManager.o

# Run the executable
./QuizMasterPro



<!-- # Compile and link all the .cpp files in the current directory
g++ *.cpp -o QuizMasterPro

# Run the executable
./QuizMasterPro -->
