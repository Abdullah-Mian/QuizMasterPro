# Compile each source file into object files
g++ -c main.cpp -o main.o
g++ -c Sleep.cpp -o Sleep.o
g++ -c Admin.cpp -o Admin.o
g++ -c SubAdmin.cpp -o SubAdmin.o
g++ -c SuperAdmin.cpp -o SuperAdmin.o
g++ -c Student.cpp -o Student.o

# Link the object files to create the executable
g++ main.o Sleep.o Admin.o SubAdmin.o SuperAdmin.o Student.o -o YourExecutableName

# For Execution
./YourExecutableName
