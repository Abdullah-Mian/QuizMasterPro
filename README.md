# Compile each source file separately
g++ -c main.cpp -o main.o
g++ -c Student.cpp -o Student.o
g++ -c Admin.cpp -o Admin.o
g++ -c SubAdmin.cpp -o SubAdmin.o
g++ -c SuperAdmin.cpp -o SuperAdmin.o
g++ -c CS_Student.cpp -o CS_Student.o
# ... (add other source files similarly)

# Link the object files to create an executable
g++ main.o Student.o Admin.o SubAdmin.o SuperAdmin.o CS_Student.o -o QuizMasterPro

# Run the executable
./QuizMasterPro
