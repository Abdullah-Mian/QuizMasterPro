# Compile each source file separately
g++ -c Student.cpp -o Student.o
g++ -c Admin.cpp -o Admin.o
g++ -c SubAdmin.cpp -o SubAdmin.o
g++ -c SuperAdmin.cpp -o SuperAdmin.o
g++ -c main.cpp -o main.o  # Add this line to compile main.cpp

# Link the object files to create an executable
g++ Student.o Admin.o SubAdmin.o SuperAdmin.o main.o -o QuizMasterPro

# Run the executable
./QuizMasterPro
