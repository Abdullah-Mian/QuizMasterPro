<!-- Obsolete Commands  -->
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

# QuizMasterPro

This is a Command Line Interface (CLI) based C++ application for quiz taking. The application supports multiple user roles, including Admin, SubAdmin, SuperAdmin, and Student. Users can log in, take quizzes, view progress, and perform administrative tasks based on their roles.

## Features
- **User Roles:**
  - **Admin:** Can manage SubAdmins, enroll students, and change credentials.
  - **SubAdmin:** Inherits some admin privileges.
  - **SuperAdmin:** Has additional privileges, including viewing SubAdmins.
  - **Student:** Can log in, take quizzes, view overall progress, and change password.

- **Authentication:** Users need to enter their username and password to log in.

- **Quiz Management:**
  - Courses are categorized by departments (e.g., CS, EE, SE, CE, CHE).
  - Students can view available courses, select a course, and take quizzes.

- **Admin Functions:**
  - Change username and password.
  - Add SubAdmins and manage them.
  - Enroll students in courses.

## Usage
1. **Compile the Program:**
   - Use a C++ compiler to compile the program:
     ```
    # Compile and link all the .cpp files in the current directory

        g++ *.cpp -o QuizMasterPro

     ```

2. **Run the Program:**
   - # Run the executable
        ./QuizMasterPro     ```

3. **Login:**
   - Choose the appropriate user role (Admin or Student).
   - Enter the username and password when prompted.

4. **Navigation:**
   - Admins have access to administrative functions.
   - Students can take quizzes, view progress, and change passwords.

5. **Logout:**
   - Logout to exit the program securely.

## Dependencies
- This application uses standard C++ libraries and requires a C++ compiler for compilation.

## Files
- `Admin.h`: Header file for the Admin class.
- `SubAdmin.h`: Header file for the SubAdmin class.
- `SuperAdmin.h`: Header file for the SuperAdmin class.
- `Student.h`: Header file for the Student class.
- `Sleep.h`: Header file for sleep-related functions.
- `ClearScreen.h`: Header file for clearing the console screen.
- `Init.h`: Header file for initializing the application.
- `Quiz.h`: Header file for the Quiz class.
- `QuizManager.h`: Header file for managing quizzes.

## Notes
- The application includes sleep functions for simulating real-time updates.
- The `clearScreen` function is used to clear the console screen for better user experience.
- For Changelogs, refer to the changelog.html file included.   

# Made with Love By Abdullah, Faizan, and Ali ♥‿♥
