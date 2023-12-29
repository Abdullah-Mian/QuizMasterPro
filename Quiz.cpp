// Include the header file for the Quiz class
#include "Quiz.h"
#include "ClearScreen.h"
#include "Init.h"
#include "Sleep.h"
using namespace std;

int score = 0; // Variable to keep track of the score
bool uniqueNumber = false;

// Define the map of quizzes
map<string, Quiz> quizzes = {
    {"CS 101", Quiz("CS 101", {{"What is the output of the following C++ code?\n\n#include <iostream>\nusing namespace std;\n\nint main() {\n    int x = 10;\n    int y = 20;\n    cout << x + y << endl;\n    return 0;\n}\n",
                                {"10", "20", "30", "40"},
                                'C'},

                               {"Which C++ keyword is used to dynamically allocate memory for a single variable in the heap?",
                                {"malloc", "new", "allocate", "heap"},
                                'B'},

                               {"How does the 'sizeof' operator work in C++?",
                                {"It returns the size of an object or data type in bytes", "It returns the address of a variable", "It calculates the sum of elements in an array", "None of the above"},
                                'A'},

                               {"Explain the concept of function overloading in C++.",
                                {"It allows multiple functions with the same name but different parameters", "It restricts a function to have only one definition", "It is used to overload the system with unnecessary functions", "None of the above"},
                                'A'},

                               {"What is the purpose of the 'const' keyword in C++?",
                                {"To declare a constant variable", "To indicate that a function does not modify the object", "To create an immutable object", "All of the above"},
                                'D'},

                               {"What is the difference between a shallow copy and a deep copy in C++?",
                                {"A shallow copy copies the values of the data members, and a deep copy copies the addresses of the data members", "A shallow copy creates a new object with the same values, and a deep copy creates a new object with new copies of the data members", "A shallow copy creates a new object with the same addresses, and a deep copy creates a new object with the same addresses", "None of the above"},
                                'B'},

                               {"What is the purpose of the 'explicit' keyword in C++?",
                                {"To declare a variable with an explicit type", "To specify that a constructor should not be implicitly called", "To enforce type checking", "Both B and C"},
                                'D'},

                               {"What is the difference between a template function and a regular function in C++?",
                                {"A template function can accept different data types, and a regular function can only accept a specific data type", "A template function can have multiple parameters, and a regular function can have only one parameter", "A template function is defined at compile time, and a regular function is defined at run time", "All of the above"},
                                'A'},

                               {"What is the purpose of the 'friend' keyword in C++?",
                                {"To declare a function that is a friend of a class", "To declare a class that is a friend of another class", "To declare a variable that is a friend of a function", "None of the above"},
                                'B'},

                               {"What is the difference between 'std::vector' and 'std::array' in C++?",
                                {"std::vector is a dynamic array, and std::array is a static array", "std::vector is a container class, and std::array is a built-in array type", "std::vector can change its size dynamically, and std::array has a fixed size", "All of the above"},
                                'C'},

                               {"What is the purpose of the 'namespace' keyword in C++?",
                                {"To define a new scope for variables", "To declare a set of related functions and classes", "To create a namespace for a class", "None of the above"},
                                'B'},

                               {"What is the difference between 'const_iterator' and 'iterator' in C++?",
                                {"const_iterator can modify the values of the elements, and iterator cannot", "const_iterator can be used to iterate over constant containers, and iterator can be used to iterate over non-constant containers", "const_iterator is used for constant pointers, and iterator is used for non-constant pointers", "None of the above"},
                                'B'},

                               {"What is the purpose of the 'typeid' operator in C++?",
                                {"To get the type information of an object", "To check if an object is of a specific type", "To perform type casting", "All of the above"},
                                'A'},

                               {"What is the difference between 'reinterpret_cast' and 'static_cast' in C++?",
                                {"reinterpret_cast is used for low-level casting between unrelated types, and static_cast is used for safe casting between related types", "reinterpret_cast is used for safe casting between related types, and static_cast is used for low-level casting between unrelated types", "reinterpret_cast performs implicit type conversions, and static_cast performs explicit type conversions", "None of the above"},
                                'A'},

                               {"What is the purpose of the 'nothrow' parameter in C++ memory allocation?",
                                {"To throw an exception if memory allocation fails", "To return a null pointer if memory allocation fails", "To allocate memory without checking for failures", "None of the above"},
                                'C'},

                               {"What is the difference between 'auto' and 'decltype' in C++?",
                                {"auto is used for automatic type deduction, and decltype is used for declaring the type of an expression", "auto is used for declaring the type of a variable, and decltype is used for automatic type deduction", "auto is used for constant variables, and decltype is used for non-constant variables", "None of the above"},
                                'A'},

                               {"What is the purpose of the 'std::move' function in C++?",
                                {"To move the contents of one object to another", "To create a new object with the same contents", "To swap the contents of two objects", "None of the above"},
                                'A'},

                               {"What is the difference between 'std::mutex' and 'std::unique_lock' in C++?",
                                {"std::mutex is used for fine-grained locking, and std::unique_lock is used for coarse-grained locking", "std::mutex is a lightweight lock, and std::unique_lock is a heavyweight lock", "std::mutex is a scoped lock, and std::unique_lock is a non-scoped lock", "None of the above"},
                                'A'},

                               {"What is the purpose of the 'const_cast' operator in C++?",
                                {"To add const qualifier to a variable", "To remove const qualifier from a variable", "To cast between unrelated types", "Both A and B"},
                                'D'},

                               {"What is the difference between 'std::sort' and 'std::stable_sort' in C++?",
                                {"std::sort is faster than std::stable_sort", "std::sort does not guarantee the stability of equal elements, and std::stable_sort does", "std::stable_sort is an unstable sorting algorithm", "None of the above"},
                                'B'},

                               {"What is the purpose of the 'std::forward' function in C++?",
                                {"To forward the arguments of a function to another function", "To move the contents of an object", "To swap the contents of two objects", "None of the above"},
                                'A'},

                               {"What is the difference between 'std::unique_ptr' and 'std::shared_ptr' in C++?",
                                {"std::unique_ptr allows only one pointer to own the object, and std::shared_ptr allows multiple pointers to share ownership of the object", "std::unique_ptr provides garbage collection, and std::shared_ptr does not", "std::unique_ptr is thread-safe, and std::shared_ptr is not", "None of the above"},
                                'A'},

                               {"What is the name of the process that converts high-level programming languages into machine code?",
                                {"Compilation", "Interpretation", "Execution", "Translation"},
                                'A'},

                               {"What is the difference between a pointer and a reference in C++?",
                                {"A pointer can be null, but a reference cannot", "A pointer can be reassigned, but a reference cannot", "A pointer can point to multiple variables, but a reference cannot", "All of the above"},
                                'D'},

                               {"What is the difference between a class and an object in C++?",
                                {"A class is a blueprint for creating objects", "An object is an instance of a class", "A class can have data members and member functions", "All of the above"},
                                'D'},

                               {"What is the difference between public, private, and protected access specifiers in C++?",
                                {"Public members can be accessed by anyone, private members can only be accessed by the class itself, and protected members can be accessed by the class and its subclasses", "Public members can only be accessed by the class itself, private members can be accessed by anyone, and protected members can be accessed by the class and its friends", "Public members can be accessed by the class and its subclasses, private members can only be accessed by the class itself, and protected members can be accessed by anyone", "None of the above"},
                                'A'},

                               {"What is the difference between static and dynamic memory allocation in C++?",
                                {"Static memory allocation is done at compile time, and dynamic memory allocation is done at run time", "Static memory allocation uses the stack, and dynamic memory allocation uses the heap", "Static memory allocation has a fixed size, and dynamic memory allocation can change its size", "All of the above"},
                                'D'},

                               {"What is the difference between the delete and delete[] operators in C++?",
                                {"Delete is used to deallocate a single object, and delete[] is used to deallocate an array of objects", "Delete is used to deallocate an array of objects, and delete[] is used to deallocate a single object", "Delete and delete[] are interchangeable", "None of the above"},
                                'A'},

                               {"What is the difference between the ++ operator and the -- operator in C++?",
                                {"The ++ operator increments the value of a variable by one, and the -- operator decrements the value of a variable by one", "The ++ operator adds one to the value of a variable, and the -- operator subtracts one from the value of a variable", "The ++ operator appends a one to the value of a variable, and the -- operator removes a one from the value of a variable", "All of the above"},
                                'B'},

                               {"What is the difference between the prefix and postfix forms of the ++ and -- operators in C++?",
                                {"The prefix form returns the value of the variable after the operation, and the postfix form returns the value of the variable before the operation", "The prefix form returns the value of the variable before the operation, and the postfix form returns the value of the variable after the operation", "The prefix form performs the operation before the expression is evaluated, and the postfix form performs the operation after the expression is evaluated", "Both A and C"},
                                'D'},

                               {"What is the difference between the = operator and the == operator in C++?",
                                {"The = operator is used for assignment, and the == operator is used for comparison", "The = operator is used for comparison, and the == operator is used for assignment", "The = operator is used for both assignment and comparison, and the == operator is not valid in C++", "None of the above"},
                                'A'},

                               {"What is the difference between the && operator and the || operator in C++?",
                                {"The && operator returns true if both operands are true, and the || operator returns true if either operand is true", "The && operator returns true if either operand is true, and the || operator returns true if both operands are true", "The && operator returns false if both operands are false, and the || operator returns false if either operand is false", "Both A and C"},
                                'D'},

                               {"What is the difference between the & operator and the * operator in C++?",
                                {"The & operator returns the address of a variable, and the * operator returns the value stored at an address", "The & operator returns the value stored at an address, and the * operator returns the address of a variable", "The & operator is used for bitwise AND, and the * operator is used for multiplication", "Both A and C"},
                                'D'},

                               {"What is the difference between the . operator and the -> operator in C++?",
                                {"The . operator is used to access the members of an object, and the -> operator is used to access the members of a pointer to an object", "The . operator is used to access the members of a pointer to an object, and the -> operator is used to access the members of an object", "The . operator is used for concatenation, and the -> operator is used for dereferencing", "None of the above"},
                                'A'},

                               {"What is the difference between a function declaration and a function definition in C++?",
                                {"A function declaration specifies the name, parameters, and return type of a function, and a function definition provides the body of the function", "A function declaration provides the body of the function, and a function definition specifies the name, parameters, and return type of a function", "A function declaration is used to call a function, and a function definition is used to create a function", "None of the above"},
                                'A'},

                               {"What is the difference between a function call and a function prototype in C++?",
                                {"A function call invokes a function with some arguments, and a function prototype declares a function with some parameters", "A function call declares a function with some parameters, and a function prototype invokes a function with some arguments", "A function call is used to define a function, and a function prototype is used to declare a function", "None of the above"},
                                'A'},

                               {"What is the difference between a function parameter and a function argument in C++?",
                                {"A function parameter is a variable that is declared in the function prototype or definition, and a function argument is a value that is passed to the function when it is called", "A function parameter is a value that is passed to the function when it is called, and a function argument is a variable that is declared in the function prototype or definition", "A function parameter is a variable that is used in the function body, and a function argument is a variable that is used in the function call", "None of the above"},
                                'A'},

                               {"What is the difference between pass by value and pass by reference in C++?",
                                {"Pass by value copies the value of the argument into the parameter, and pass by reference creates an alias for the argument that can be modified by the parameter", "Pass by value creates an alias for the argument that can be modified by the parameter, and pass by reference copies the value of the argument into the parameter", "Pass by value passes the address of the argument to the parameter, and pass by reference passes the value of the argument to the parameter", "None of the above"},
                                'A'},

                               {"What is the difference between a constructor and a destructor in C++?",
                                {"A constructor is a special member function that is invoked when an object is created, and a destructor is a special member function that is invoked when an object is destroyed", "A constructor is a special member function that is invoked when an object is destroyed, and a destructor is a special member function that is invoked when an object is created", "A constructor is a special member function that is used to initialize the data members of an object, and a destructor is a special member function that is used to release the resources used by an object", "Both A and C"},
                                'D'},

                               {"What is the difference between inheritance and polymorphism in C++?",
                                {"Inheritance is the process of creating new classes from existing classes, and polymorphism is the ability of objects to behave differently depending on their type", "Inheritance is the ability of objects to behave differently depending on their type, and polymorphism is the process of creating new classes from existing classes", "Inheritance is the process of sharing data and functions between classes, and polymorphism is the process of overriding functions in derived classes", "Both A and C"},
                                'D'},

                               {"What is the difference between a virtual function and a pure virtual function in C++?",
                                {"A virtual function is a member function that can be overridden by a derived class, and a pure virtual function is a member function that must be overridden by a derived class", "A virtual function is a member function that must be overridden by a derived class, and a pure virtual function is a member function that can be overridden by a derived class", "A virtual function is a member function that has a default implementation, and a pure virtual function is a member function that has no implementation", "Both A and C"},
                                'D'},

                               {"What is the difference between a syntax error and a semantic error in programming?",
                                {"A syntax error is a mistake in the grammar of the language, while a semantic error is a mistake in the logic of the program", "A syntax error is a mistake in the logic of the program, while a semantic error is a mistake in the grammar of the language", "A syntax error is a mistake that can be detected by the compiler, while a semantic error is a mistake that can only be detected at run time", "A syntax error is a mistake that can only be detected at run time, while a semantic error is a mistake that can be detected by the compiler"},
                                'C'},

                               {"What is the name of the data type that can store only two values: true or false?",
                                {"Boolean", "Binary", "Bit", "Byte"},
                                'A'},

                               {"What is the name of the operator that performs logical AND operation on two operands?",
                                {"&&", "||", "&", "|"},
                                'A'},

                               {"What is the name of the control structure that executes a block of code repeatedly while a condition is true?",
                                {"For loop", "While loop", "Do-while loop", "If statement"},
                                'B'},

                               {"What is the name of the function that prints a message to the standard output stream?",
                                {"cout", "cin", "printf", "scanf"},
                                'C'},

                               {"What is the name of the symbol that is used to mark the end of a statement in C++?",
                                {";", ":", ".", ","},
                                'A'},

                               {"What is the name of the keyword that is used to declare a constant variable in C++?",
                                {"const", "final", "static", "immutable"},
                                'A'},

                               {"What is the name of the data structure that stores elements in a key-value pair and allows fast retrieval by the key?",
                                {"Array", "List", "Map", "Set"},
                                'C'},

                               {"What is the name of the concept that allows a function to have different forms based on the number or type of parameters?",
                                {"Encapsulation", "Inheritance", "Polymorphism", "Abstraction"},
                                'C'}})},

    {"CS 201", Quiz("CS 201", {{"What is the output of the following C++ code?\n\n#include <iostream>\nusing namespace std;\n\nint main() {\n    int x = 10;\n    int y = 20;\n    cout << x + y << endl;\n    return 0;\n}\n",
                                {"10", "20", "30", "40"},
                                'C'},

                               {"What is the name of the technique that divides a problem into smaller subproblems and solves them recursively?",
                                {"Divide and conquer", "Dynamic programming", "Greedy method", "Backtracking"},
                                'A'},

                               {"What is the name of the data structure that represents a collection of nodes and edges, where each node can have zero or more adjacent nodes?",
                                {"Graph", "Tree", "Heap", "Array"},
                                'A'},

                               {"What is the name of the algorithm that sorts an array by repeatedly finding the minimum element and swapping it with the first unsorted element?",
                                {"Selection sort", "Insertion sort", "Bubble sort", "Merge sort"},
                                'A'},

                               {"What is the name of the problem that asks to find the longest common subsequence of two given sequences?",
                                {"Longest common subsequence", "Longest increasing subsequence", "Longest common substring", "Longest palindromic subsequence"},
                                'A'},

                               {"What is the name of the data structure that supports insertion and deletion at both ends, and allows constant time access to the first and last elements?",
                                {"Deque", "Queue", "Stack", "List"},
                                'A'},

                               {"What is the name of the algorithm that finds the shortest path from a single source node to all other nodes in a weighted graph?",
                                {"Dijkstra's algorithm", "Floyd-Warshall algorithm", "Bellman-Ford algorithm", "Kruskal's algorithm"},
                                'A'},

                               {"What is the name of the problem that asks to find the optimal way to cut a rod of length n into smaller pieces, such that the sum of the prices of the pieces is maximized?",
                                {"Rod cutting", "Knapsack", "Coin change", "Matrix chain multiplication"},
                                'A'},

                               {"What is the name of the data structure that represents a set of disjoint sets, and supports efficient operations to create, merge, and find sets?",
                                {"Disjoint-set", "Hash-set", "Bit-set", "Tree-set"},
                                'A'},

                               {"What is the name of the algorithm that finds a matching pair of parentheses in an expression, given the index of an opening parenthesis?",
                                {"Stack-based algorithm", "Recursion-based algorithm", "Counter-based algorithm", "None of the above"},
                                'C'},

                               {"Explain the concept of recursion in programming.",
                                {"Recursion is a process where a function calls itself", "Recursion is not allowed in programming languages", "Recursion is limited to mathematical calculations", "None of the above"},
                                'A'},

                               {"What is the purpose of the 'nullptr' keyword in C++?",
                                {"To represent a null pointer", "To check if a pointer is null", "To allocate memory for a pointer", "All of the above"},
                                'A'},

                               {"What is the difference between a stack and a queue in data structures?",
                                {"Stack follows the Last In First Out (LIFO) principle, and queue follows the First In First Out (FIFO) principle", "Stack follows the FIFO principle, and queue follows the LIFO principle", "Both stack and queue follow the LIFO principle", "Both stack and queue follow the FIFO principle"},
                                'A'},

                               {"How does the 'sizeof' operator work in C++?",
                                {"It returns the size of a data type in bytes", "It returns the size of an array in elements", "It returns the size of a pointer in bytes", "All of the above"},
                                'D'},

                               {"What is the purpose of the 'break' statement in C++?",
                                {"To terminate the loop and move to the next iteration", "To exit a switch statement prematurely", "To exit a function prematurely", "All of the above"},
                                'D'},

                               {"Explain the concept of operator overloading in C++.",
                                {"Operator overloading allows defining multiple behaviors for the same operator based on the types of its operands", "Operator overloading is not allowed in C++", "Operator overloading is limited to arithmetic operators", "None of the above"},
                                'A'},

                               {"What is the role of a destructor in C++?",
                                {"A destructor is called when an object is about to be destroyed, and it is used to release resources", "A destructor is called when an object is created, and it is used to initialize the object", "A destructor is used to create objects", "None of the above"},
                                'A'},

                               {"What is the difference between 'while' and 'do-while' loops in C++?",
                                {"The 'while' loop checks the condition before the loop body is executed, while the 'do-while' loop checks the condition after the loop body is executed", "The 'while' loop and 'do-while' loop are interchangeable", "The 'while' loop can only be used for numerical iteration, while the 'do-while' loop can be used for any type of iteration", "None of the above"},
                                'A'},

                               {"What is the significance of the 'const' qualifier in function declarations?",
                                {"It indicates that the function does not modify the object on which it is called", "It indicates that the function cannot be called with constant objects", "It indicates that the function returns a constant value", "All of the above"},
                                'A'},

                               {"What is the purpose of the 'static' keyword in C++?",
                                {"To declare a variable that retains its value between function calls", "To declare a constant variable", "To indicate that a function does not modify the object", "Both A and C"},
                                'D'},

                               {"What is the difference between 'const' and 'constexpr' in C++?",
                                {"'const' is used to declare constant variables, while 'constexpr' is used to declare variables with constant values at compile time", "'const' and 'constexpr' are interchangeable", "'const' is used for compile-time constants, while 'constexpr' is used for runtime constants", "None of the above"},
                                'A'},

                               {"What is the name of the process that converts high-level programming languages into machine code?",
                                {"Compilation", "Interpretation", "Execution", "Translation"},
                                'A'},

                               {"What is the name of the operator that performs logical AND operation on two operands?",
                                {"&&", "||", "&", "|"},
                                'A'},

                               {"What is the name of the control structure that executes a block of code repeatedly while a condition is true?",
                                {"For loop", "While loop", "Do-while loop", "If statement"},
                                'B'},

                               {"What is the name of the function that prints a message to the standard output stream?",
                                {"cout", "cin", "printf", "scanf"},
                                'C'},

                               {"What is the name of the symbol that is used to mark the end of a statement in C++?",
                                {";", ":", ".", ","},
                                'A'},

                               {"What is the name of the keyword that is used to declare a constant variable in C++?",
                                {"const", "final", "static", "immutable"},
                                'A'},

                               {"What is the name of the data structure that stores elements in a key-value pair and allows fast retrieval by the key?",
                                {"Array", "List", "Map", "Set"},
                                'C'},

                               {"What is the name of the concept that allows a function to have different forms based on the number or type of parameters?",
                                {"Encapsulation", "Inheritance", "Polymorphism", "Abstraction"},
                                'C'}})},

    {"SE 101", Quiz("SE 101", {
                                  {"What is the name of the software development process that consists of four phases: inception, elaboration, construction, and transition?",
                                   {"Waterfall", "Agile", "Spiral", "Rational Unified Process"},
                                   'D'},

                                  {"What is the definition of software engineering according to IEEE?",
                                   {"The application of a systematic, disciplined, quantifiable approach to the development, operation, and maintenance of software", "The process of designing, implementing, testing, and documenting software systems", "The discipline of creating high-quality software products that meet user needs and expectations", "The art and science of applying computer science principles and techniques to solve real-world problems"},
                                   'A'},

                                  {"What are the four fundamental activities of a generic software process?",
                                   {"Specification, development, validation, and evolution", "Planning, analysis, design, and implementation", "Requirements, design, coding, and testing", "Modeling, construction, deployment, and maintenance"},
                                   'A'},

                                  {"What are the three types of software maintenance according to ISO/IEC 14764?",
                                   {"Corrective, adaptive, and perfective", "Preventive, corrective, and adaptive", "Perfective, preventive, and corrective", "Adaptive, perfective, and preventive"},
                                   'C'},

                                  {"What is the name of the software development methodology that is based on iterative and incremental development, where requirements and solutions evolve through collaboration between self-organizing, cross-functional teams?",
                                   {"Agile", "Waterfall", "Spiral", "V-Model"},
                                   'A'},

                                  {"What are the four values of the Agile Manifesto?",
                                   {"Individuals and interactions over processes and tools, working software over comprehensive documentation, customer collaboration over contract negotiation, responding to change over following a plan", "Communication and feedback over documentation and contracts, quality and testing over features and deadlines, collaboration and trust over hierarchy and control, flexibility and adaptability over stability and predictability", "People and relationships over resources and tasks, functionality and usability over specifications and standards, involvement and satisfaction over negotiation and agreement, evolution and improvement over planning and execution", "Vision and mission over goals and objectives, prototypes and demos over reports and charts, teamwork and cooperation over roles and responsibilities, innovation and creativity over conformity and compliance"},
                                   'A'},

                                  {"What are the five phases of the waterfall model of software development?",
                                   {"Requirements analysis, design, implementation, testing, and maintenance", "Feasibility study, requirements specification, design, coding, and testing", "Planning, analysis, design, implementation, and evaluation", "Initiation, definition, construction, transition, and delivery"},
                                   'A'},

                                  {"What is the name of the graphical notation for modeling various aspects of software systems, such as structure, behavior, and interactions?",
                                   {"Unified Modeling Language (UML)", "Entity-Relationship Diagram (ERD)", "Data Flow Diagram (DFD)", "Structured Analysis and Design Technique (SADT)"},
                                   'A'},

                                  {"What is the name of the software quality attribute that measures the degree to which a software system or component can be modified without introducing defects or degrading existing quality?",
                                   {"Maintainability", "Reliability", "Reusability", "Portability"},
                                   'A'},

                                  {"What is the name of the software testing technique that involves executing the software system or component with the intent of finding failures?",
                                   {"Dynamic testing", "Static testing", "White-box testing", "Black-box testing"},
                                   'A'},

                                  {"What is the name of the process that involves reviewing and inspecting the software work products and identifying defects early in the development process?",
                                   {"Code review", "Testing", "Debugging", "Quality assurance"},
                                   'A'},

                                  {"What is the term for a software development approach that combines elements of both predictive and adaptive methodologies?",
                                   {"Incremental development", "Spiral model", "Agile development", "Hybrid model"},
                                   'D'},

                                  {"What is the primary goal of software configuration management?",
                                   {"To manage the project schedule", "To control changes to the software work products", "To allocate resources effectively", "To monitor software performance"},
                                   'B'},

                                  {"What is the name of the software development model that is based on the idea of building a system through repeated cycles and iterations?",
                                   {"Spiral model", "V-Model", "Incremental model", "Waterfall model"},
                                   'C'},

                                  {"What is the purpose of a software design pattern?",
                                   {"To provide a reusable solution to a common problem in software design", "To enforce coding standards", "To document the software development process", "To ensure compliance with industry regulations"},
                                   'A'},

                                  {"What is the name of the technique that involves breaking down a complex system into smaller, more manageable subsystems?",
                                   {"Abstraction", "Decomposition", "Aggregation", "Integration"},
                                   'B'},

                                  {"What is the term for the process of converting a high-level software design into code?",
                                   {"Coding", "Testing", "Debugging", "Implementation"},
                                   'D'},

                                  {"What is the name of the software development approach that emphasizes the importance of individuals and interactions, working software, customer collaboration, and responding to change?",
                                   {"Waterfall model", "Agile development", "Spiral model", "Incremental model"},
                                   'B'},

                                  {"What is the name of the testing level that focuses on verifying that the software system meets the specified requirements?",
                                   {"Unit testing", "Integration testing", "System testing", "Acceptance testing"},
                                   'C'},

                                  {"What is the term for the process of identifying, categorizing, and managing software defects?",
                                   {"Testing", "Debugging", "Quality assurance", "Defect tracking"},
                                   'D'},

                                  {"What is the purpose of a software prototype?",
                                   {"To serve as the final version of the software", "To simulate the functionality of the final system", "To document the software design", "To automate the testing process"},
                                   'B'},

                                  {"What is the name of the software development model that involves the repeated testing and refinement of a prototype until it eventually evolves into the final product?",
                                   {"Spiral model", "V-Model", "Incremental model", "Prototyping model"},
                                   'D'},

                                  {"What is the term for the process of removing defects and errors from software code?",
                                   {"Testing", "Debugging", "Quality assurance", "Refactoring"},
                                   'B'},

                                  {"What is the primary goal of software testing?",
                                   {"To ensure the absence of defects", "To meet project deadlines", "To maximize developer productivity", "To control software costs"},
                                   'A'},

                                  {"What is the name of the software development model that emphasizes the use of extensive documentation, detailed planning, and sequential stages of development?",
                                   {"Agile development", "Waterfall model", "Incremental model", "Spiral model"},
                                   'B'},

                                  {"What is the term for the process of analyzing software code to ensure compliance with coding standards and best practices?",
                                   {"Code review", "Static analysis", "Code inspection", "Linting"},
                                   'B'},

                              })},

    {"SE 201", Quiz("SE 201", {{"What is the name of the software development process that consists of four phases: inception, elaboration, construction, and transition?", {"Waterfall", "Agile", "Spiral", "Rational Unified Process"}, 'D'},

                               {"What is the name of the feature that allows an object to have different forms or behaviors depending on the context?", {"Encapsulation", "Inheritance", "Polymorphism", "Abstraction"}, 'C'},

                               {"What is the name of the relationship between two classes where one class is a specialized version of another class?", {"Association", "Aggregation", "Composition", "Inheritance"}, 'D'},

                               {"What is the name of the principle that states that a class should have a single responsibility and a single reason to change?", {"Single responsibility principle", "Open-closed principle", "Liskov substitution principle", "Interface segregation principle"}, 'A'},

                               {"What is the name of the mechanism that allows a class to hide its internal details and only expose its interface to the outside world?", {"Encapsulation", "Inheritance", "Polymorphism", "Abstraction"}, 'A'},

                               {"What is the name of the concept that allows a subclass to override the behavior of a superclass method with the same name and signature?", {"Method overloading", "Method overriding", "Method hiding", "Method chaining"}, 'B'},

                               {"What is the name of the keyword that is used to access the members of the current object in C++?", {"this", "self", "me", "current"}, 'A'},

                               {"What is the name of the technique that allows a class to have more than one superclass and inherit features from all of them?", {"Multiple inheritance", "Multilevel inheritance", "Hierarchical inheritance", "Hybrid inheritance"}, 'A'},

                               {"What is the name of the operator that is used to access the members of an object or a class in C++?", {"::", ".", "->", "&"}, 'B'},

                               {"What is the name of the design pattern that defines a family of algorithms, encapsulates each one, and makes them interchangeable?", {"Strategy", "Observer", "Factory", "Singleton"}, 'A'},

                               {"What is the term for a set of rules that specify how objects interact and communicate with each other?", {"Design principles", "Design patterns", "Design rules", "Design conventions"}, 'B'},

                               {"What is the name of the process that involves designing the structure and organization of a system's components or modules?", {"Coding", "Testing", "Debugging", "Architectural design"}, 'D'},

                               {"What is the purpose of a use case diagram in UML?", {"To show the interactions between different components of a system", "To visualize the sequence of steps in an algorithm", "To represent the flow of control in a system", "To model the interactions between users and a system"}, 'D'},

                               {"What is the term for the process of converting a high-level software design into code?", {"Coding", "Testing", "Debugging", "Implementation"}, 'A'},

                               {"What is the name of the software development model that emphasizes the use of extensive documentation, detailed planning, and sequential stages of development?", {"Agile development", "Waterfall model", "Incremental model", "Spiral model"}, 'B'},

                               {"What is the name of the diagram in UML that shows the relationships between classes, interfaces, and their collaborations?", {"Class diagram", "Sequence diagram", "Use case diagram", "Activity diagram"}, 'A'},

                               {"What is the term for a design pattern that restricts the instantiation of a class to a single instance?", {"Factory pattern", "Singleton pattern", "Observer pattern", "Decorator pattern"}, 'B'},

                               {"What is the purpose of the 'protected' access modifier in C++?", {"To allow access only within the same class", "To allow access from any other class", "To allow access only within the same package", "To allow access within the same class and its subclasses"}, 'D'},

                               {"What is the term for a design pattern that defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically?", {"Observer pattern", "Adapter pattern", "Decorator pattern", "Strategy pattern"}, 'A'},

                               {"What is the name of the process that involves reviewing and inspecting the software work products and identifying defects early in the development process?", {"Code review", "Testing", "Debugging", "Quality assurance"}, 'A'},

                               {"What is the name of the process that involves breaking down a complex system into smaller, more manageable subsystems?", {"Abstraction", "Decomposition", "Aggregation", "Integration"}, 'B'},

                               {"What is the term for a design pattern that allows a class to alter its behavior when its internal state changes?", {"Observer pattern", "Decorator pattern", "State pattern", "Command pattern"}, 'C'},

                               {"What is the primary goal of software testing?", {"To ensure the absence of defects", "To meet project deadlines", "To maximize developer productivity", "To control software costs"}, 'A'},

                               {"What is the name of the technique that involves executing the software system or component with the intent of finding failures?", {"Dynamic testing", "Static testing", "White-box testing", "Black-box testing"}, 'A'},

                               {"What is the name of the software testing level that focuses on verifying that the software system meets the specified requirements?", {"Unit testing", "Integration testing", "System testing", "Acceptance testing"}, 'C'},

                               {"What is the name of the software quality attribute that measures the degree to which a software system or component can be modified without introducing defects or degrading existing quality?", {"Maintainability", "Reliability", "Reusability", "Portability"}, 'A'},

                               {"What is the term for the process of identifying, categorizing, and managing software defects?", {"Testing", "Debugging", "Quality assurance", "Defect tracking"}, 'D'},

                               {"What is the name of the software development approach that combines elements of both predictive and adaptive methodologies?", {"Incremental development", "Spiral model", "Agile development", "Hybrid model"}, 'D'},

                               {"What is the name of the software development model that involves the repeated testing and refinement of a prototype until it eventually evolves into the final product?", {"Spiral model", "V-Model", "Incremental model", "Prototyping model"}, 'D'},

                               {"What is the name of the testing technique that involves comparing the actual output of a program with the expected output?", {"Unit testing", "Integration testing", "Regression testing", "Comparison testing"}, 'D'},

                               {"What is the purpose of a software prototype?", {"To serve as the final version of the software", "To simulate the functionality of the final system", "To document the software design", "To automate the testing process"}, 'B'},

                               {"What is the primary goal of software configuration management?", {"To manage the project schedule", "To control changes to the software work products", "To allocate resources effectively", "To monitor software performance"}, 'B'},

                               {"What is the term for a software development approach that emphasizes the importance of individuals and interactions, working software, customer collaboration, and responding to change?", {"Waterfall model", "Agile development", "Spiral model", "Incremental model"}, 'B'},

                               {"What is the name of the design pattern that defines a family of algorithms, encapsulates each one, and makes them interchangeable?", {"Strategy", "Observer", "Factory", "Singleton"}, 'A'},

                               {"What is the term for a set of related classes and interfaces that define a specific kind of functionality?", {"Package", "Module", "Library", "Namespace"}, 'C'},

                               {"What is the name of the process that involves analyzing, planning, and managing the requirements for a software system?", {"Coding", "Testing", "Requirement engineering", "Debugging"}, 'C'},

                               {"What is the purpose of a use case diagram in UML?", {"To show the interactions between different components of a system", "To visualize the sequence of steps in an algorithm", "To represent the flow of control in a system", "To model the interactions between users and a system"}, 'D'},

                               {"What is the name of the design pattern that defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically?", {"Observer pattern", "Adapter pattern", "Decorator pattern", "Strategy pattern"}, 'A'},

                               {"What is the term for a design pattern that allows a class to alter its behavior when its internal state changes?", {"Observer pattern", "Decorator pattern", "State pattern", "Command pattern"}, 'C'},

                               {"What is the name of the process that involves designing the structure and organization of a system's components or modules?", {"Coding", "Testing", "Debugging", "Architectural design"}, 'D'},

                               {"What is the term for a set of rules that specify how objects interact and communicate with each other?", {"Design principles", "Design patterns", "Design rules", "Design conventions"}, 'B'},

                               {"What is the name of the diagram in UML that shows the relationships between classes, interfaces, and their collaborations?", {"Class diagram", "Sequence diagram", "Use case diagram", "Activity diagram"}, 'A'},

                               {"What is the name of the principle that states that a class should have a single responsibility and a single reason to change?", {"Single responsibility principle", "Open-closed principle", "Liskov substitution principle", "Interface segregation principle"}, 'A'},

                               {"What is the name of the keyword that is used to access the members of the current object in C++?", {"this", "self", "me", "current"}, 'A'},

                               {"What is the name of the concept that allows a subclass to override the behavior of a superclass method with the same name and signature?", {"Method overloading", "Method overriding", "Method hiding", "Method chaining"}, 'B'},

                               {"What is the name of the relationship between two classes where one class is a specialized version of another class?", {"Association", "Aggregation", "Composition", "Inheritance"}, 'D'},

                               {"What is the name of the mechanism that allows a class to hide its internal details and only expose its interface to the outside world?", {"Encapsulation", "Inheritance", "Polymorphism", "Abstraction"}, 'A'},

                               {"What is the name of the feature that allows an object to have different forms or behaviors depending on the context?", {"Encapsulation", "Inheritance", "Polymorphism", "Abstraction"}, 'C'},

                               {"What is the name of the software development process that consists of four phases: inception, elaboration, construction, and transition?", {"Waterfall", "Agile", "Spiral", "Rational Unified Process"}, 'D'},

                               {"What is the name of the design pattern that restricts the instantiation of a class to a single instance?", {"Factory pattern", "Singleton pattern", "Observer pattern", "Decorator pattern"}, 'B'},

                               {"What is the term for a set of related classes and interfaces that define a specific kind of functionality?", {"Package", "Module", "Library", "Namespace"}, 'C'},

                               {"What is the name of the process that involves analyzing, planning, and managing the requirements for a software system?", {"Coding", "Testing", "Requirement engineering", "Debugging"}, 'C'},

                               {"What is the purpose of a use case diagram in UML?", {"To show the interactions between different components of a system", "To visualize the sequence of steps in an algorithm", "To represent the flow of control in a system", "To model the interactions between users and a system"}, 'D'}})},

    {"ECE 201", Quiz("ECE 201", {{"What is the name of the device that converts digital signals to analog signals and vice versa?", {"Modem", "Router", "Switch", "Hub"}, 'A'},

                                 {"What is the name of the logic gate that produces a 1 output only when both of its inputs are 1?", {"AND", "OR", "NOT", "XOR"}, 'A'},

                                 {"What is the name of the number system that uses only 0 and 1 to represent any value?", {"Binary", "Decimal", "Hexadecimal", "Octal"}, 'A'},

                                 {"What is the name of the circuit that can add two bits and produce a sum and a carry bit?", {"Half adder", "Full adder", "Half subtractor", "Full subtractor"}, 'A'},

                                 {"What is the name of the device that can store one bit of information and has two stable states?", {"Flip-flop", "Latch", "Register", "Counter"}, 'A'},

                                 {"What is the name of the method that simplifies a Boolean expression by eliminating redundant terms?", {"Karnaugh map", "Quine-McCluskey", "De Morgan's laws", "Boolean algebra"}, 'A'},

                                 {"What is the name of the code that uses four bits to represent the decimal digits 0 to 9?", {"BCD", "Gray", "ASCII", "Hamming"}, 'A'},

                                 {"What is the name of the circuit that can compare two binary numbers and produce an output that indicates their relationship?", {"Comparator", "Encoder", "Decoder", "Multiplexer"}, 'A'},

                                 {"What is the name of the circuit that can select one of several input signals and forward it to the output based on a control signal?", {"Multiplexer", "Demultiplexer", "Decoder", "Encoder"}, 'A'},

                                 {"What is the name of the circuit that can perform arithmetic and logical operations on binary numbers?", {"Arithmetic logic unit", "Control unit", "Memory unit", "Input/output unit"}, 'A'},

                                 {"What is the name of the circuit that can store multiple bits of information and has multiple stable states?", {"Flip-flop", "Latch", "Register", "Counter"}, 'A'},

                                 {"What is the term for a sequential circuit that changes its state only in response to a clock signal?", {"Combinational circuit", "Synchronous circuit", "Asynchronous circuit", "Static circuit"}, 'B'},

                                 {"What is the name of the logic gate that produces a 1 output when either of its inputs is 1?", {"AND", "OR", "NOT", "XOR"}, 'B'},

                                 {"What is the name of the number system that uses the digits 0 to 9 and the base 10?", {"Binary", "Decimal", "Hexadecimal", "Octal"}, 'B'},

                                 {"What is the name of the circuit that can add two binary numbers and produce a sum and a carry bit?", {"Half adder", "Full adder", "Half subtractor", "Full subtractor"}, 'B'},

                                 {"What is the name of the device that can store multiple bits of information and has multiple stable states?", {"Flip-flop", "Latch", "Register", "Counter"}, 'A'},

                                 {"What is the name of the method that simplifies a Boolean expression by eliminating redundant terms?", {"Karnaugh map", "Quine-McCluskey", "De Morgan's laws", "Boolean algebra"}, 'A'},

                                 {"What is the name of the code that uses seven bits to represent characters, including letters and numbers?", {"BCD", "Gray", "ASCII", "Hamming"}, 'C'},

                                 {"What is the name of the circuit that can compare two binary numbers and produce an output that indicates their relationship?", {"Comparator", "Encoder", "Decoder", "Multiplexer"}, 'A'},

                                 {"What is the name of the circuit that can select one of several output signals and forward it to the input based on a control signal?", {"Multiplexer", "Demultiplexer", "Decoder", "Encoder"}, 'A'},

                                 {"What is the name of the circuit that can perform arithmetic and logical operations on binary numbers?", {"Arithmetic logic unit", "Control unit", "Memory unit", "Input/output unit"}, 'A'},

                                 {"What is the name of the circuit that can store multiple bits of information and has multiple stable states?", {"Flip-flop", "Latch", "Register", "Counter"}, 'A'},

                                 {"What is the term for a sequential circuit that changes its state only in response to a clock signal?", {"Combinational circuit", "Synchronous circuit", "Asynchronous circuit", "Static circuit"}, 'B'},

                                 {"What is the name of the logic gate that produces a 1 output when either of its inputs is 1?", {"AND", "OR", "NOT", "XOR"}, 'B'},

                                 {"What is the name of the number system that uses the digits 0 to 9 and the base 10?", {"Binary", "Decimal", "Hexadecimal", "Octal"}, 'B'},

                                 {"What is the name of the circuit that can add two binary numbers and produce a sum and a carry bit?", {"Half adder", "Full adder", "Half subtractor", "Full subtractor"}, 'B'},

                                 {"What is the name of the device that can store multiple bits of information and has multiple stable states?", {"Flip-flop", "Latch", "Register", "Counter"}, 'A'},

                                 {"What is the name of the method that simplifies a Boolean expression by eliminating redundant terms?", {"Karnaugh map", "Quine-McCluskey", "De Morgan's laws", "Boolean algebra"}, 'A'},

                                 {"What is the name of the code that uses seven bits to represent characters, including letters and numbers?", {"BCD", "Gray", "ASCII", "Hamming"}, 'C'},

                                 {"What is the name of the circuit that can compare two binary numbers and produce an output that indicates their relationship?", {"Comparator", "Encoder", "Decoder", "Multiplexer"}, 'A'},

                                 {"What is the name of the circuit that can select one of several output signals and forward it to the input based on a control signal?", {"Multiplexer", "Demultiplexer", "Decoder", "Encoder"}, 'A'},

                                 {"What is the name of the circuit that can perform arithmetic and logical operations on binary numbers?", {"Arithmetic logic unit", "Control unit", "Memory unit", "Input/output unit"}, 'A'},

                                 {"What is the name of the circuit that can store multiple bits of information and has multiple stable states?", {"Flip-flop", "Latch", "Register", "Counter"}, 'A'},

                                 {"What is the term for a sequential circuit that changes its state only in response to a clock signal?", {"Combinational circuit", "Synchronous circuit", "Asynchronous circuit", "Static circuit"}, 'B'},

                                 {"What is the name of the logic gate that produces a 1 output when either of its inputs is 1?", {"AND", "OR", "NOT", "XOR"}, 'B'},

                                 {"What is the name of the number system that uses the digits 0 to 9 and the base 10?", {"Binary", "Decimal", "Hexadecimal", "Octal"}, 'B'},

                                 {"What is the name of the circuit that can add two binary numbers and produce a sum and a carry bit?", {"Half adder", "Full adder", "Half subtractor", "Full subtractor"}, 'B'},

                                 {"What is the name of the device that can store multiple bits of information and has multiple stable states?", {"Flip-flop", "Latch", "Register", "Counter"}, 'A'},

                                 {"What is the name of the method that simplifies a Boolean expression by eliminating redundant terms?", {"Karnaugh map", "Quine-McCluskey", "De Morgan's laws", "Boolean algebra"}, 'A'},

                                 {"What is the name of the code that uses seven bits to represent characters, including letters and numbers?", {"BCD", "Gray", "ASCII", "Hamming"}, 'C'},

                                 {"What is the name of the circuit that can compare two binary numbers and produce an output that indicates their relationship?", {"Comparator", "Encoder", "Decoder", "Multiplexer"}, 'A'},

                                 {"What is the name of the circuit that can select one of several output signals and forward it to the input based on a control signal?", {"Multiplexer", "Demultiplexer", "Decoder", "Encoder"}, 'A'},

                                 {"What is the name of the circuit that can perform arithmetic and logical operations on binary numbers?", {"Arithmetic logic unit", "Control unit", "Memory unit", "Input/output unit"}, 'A'}})},

    {"ECE 415", Quiz("ECE 415", {{"What is the name of the device that converts digital signals to analog signals and vice versa?", {"Modem", "Router", "Switch", "Hub"}, 'A'},

                                 {"What is the definition of an embedded system according to IEEE?", {"A system that has hardware and software components, is part of a larger system, and performs some specific functions", "A system that is designed to perform a dedicated function, often with real-time constraints, and is embedded as a part of a complete device", "A system that is composed of electronic, mechanical, and software components, and interacts with its environment through sensors and actuators", "A system that is integrated with a physical process, and has a microcontroller or microprocessor that executes a fixed set of pre-programmed instructions"}, 'B'},

                                 {"What are the three main characteristics of an embedded system?", {"Reliability, performance, and power consumption", "Functionality, usability, and security", "Scalability, modularity, and interoperability", "Flexibility, adaptability, and robustness"}, 'A'},

                                 {"What are the two types of embedded software architectures?", {"Monolithic and layered", "Sequential and concurrent", "Client-server and peer-to-peer", "Event-driven and time-triggered"}, 'D'},

                                 {"What are the two types of embedded processors?", {"General-purpose and application-specific", "Single-core and multi-core", "RISC and CISC", "DSP and FPGA"}, 'A'},

                                 {"What are the two types of embedded memory?", {"Volatile and non-volatile", "Static and dynamic", "Random and sequential", "Cache and register"}, 'A'},

                                 {"What are the two types of embedded communication interfaces?", {"Serial and parallel", "Wired and wireless", "Synchronous and asynchronous", "Simplex and duplex"}, 'B'},

                                 {"What are the two types of embedded operating systems?", {"Real-time and non-real-time", "Single-tasking and multi-tasking", "Preemptive and non-preemptive", "Proprietary and open-source"}, 'A'},

                                 {"What are the two types of embedded software development tools?", {"Compilers and debuggers", "Editors and simulators", "Emulators and testers", "All of the above"}, 'D'},

                                 {"What are the two types of embedded software testing techniques?", {"White-box and black-box", "Unit and integration", "Functional and non-functional", "All of the above"}, 'D'},

                                 {"What is the definition of fault tolerance in the context of embedded systems?", {"The ability of a system to resist unexpected faults or failures and continue to operate properly", "The process of identifying faults in the system and eliminating them before deployment", "The level of tolerance a system has for intentional faults introduced for testing purposes", "The ability to recognize and tolerate user errors in the system"}, 'A'},

                                 {"What is the purpose of a watchdog timer in embedded systems?", {"To monitor the system and reset it if a malfunction or hang is detected", "To keep track of time in the system", "To provide a secure channel for communication between embedded devices", "To synchronize the operation of multiple embedded devices"}, 'A'},

                                 {"What is the name of the programming paradigm that emphasizes the use of functions and avoids changing state and mutable data?", {"Object-oriented programming", "Functional programming", "Procedural programming", "Imperative programming"}, 'B'},

                                 {"What is the role of a Real-Time Operating System (RTOS) in embedded systems?", {"To provide a graphical user interface for embedded applications", "To manage the system's memory and optimize storage", "To ensure that tasks and processes meet their deadlines and run in a timely manner", "To facilitate communication between embedded devices"}, 'C'},

                                 {"What is the purpose of DMA (Direct Memory Access) in embedded systems?", {"To perform arithmetic and logic operations directly on memory", "To allow peripherals to communicate with each other without involving the CPU", "To provide a direct connection between the CPU and the hard drive", "To facilitate debugging and testing in embedded applications"}, 'B'},

                                 {"What is the significance of the term 'bare-metal' in the context of embedded systems?", {"Refers to systems with a metal casing for protection against environmental factors", "Indicates systems without an operating system, running directly on hardware", "Describes the high-performance capabilities of embedded processors", "Signifies the use of metal-based components in embedded devices"}, 'B'},

                                 {"What is the purpose of an interrupt in embedded systems?", {"To pause the execution of a program and transfer control to a special code segment", "To terminate the program in case of an error", "To speed up the execution of time-critical tasks", "To allocate memory for new processes in the system"}, 'A'},

                                 {"What is the term for the process of converting analog signals to digital signals in embedded systems?", {"Analog modulation", "Digital modulation", "Analog-to-digital conversion", "Digital-to-analog conversion"}, 'C'},

                                 {"What is the name of the programming language commonly used for embedded systems programming?", {"Java", "Python", "C++", "C"}, 'D'},

                                 {"What is the purpose of flash memory in embedded systems?", {"To provide temporary storage for data in the system", "To store the system's firmware or program code", "To enhance the system's graphics performance", "To increase the speed of data processing in embedded devices"}, 'B'},

                                 {"What is the name of the method used to conserve power in embedded systems by putting certain components into a low-power state?", {"Power throttling", "Power conservation", "Power profiling", "Power management"}, 'D'},

                                 {"What is the term for the capability of an embedded system to communicate and interact with other embedded systems or devices?", {"Connectivity", "Interoperability", "Networking", "Compatibility"}, 'B'},

                                 {"What is the name of the component in embedded systems that provides a stable clock signal for timing operations?", {"Clock generator", "Pulse-width modulator", "Crystal oscillator", "Frequency synthesizer"}, 'C'},

                                 {"What is the role of an FPGA (Field-Programmable Gate Array) in embedded systems?", {"To provide secure communication between embedded devices", "To act as a watchdog timer for the system", "To implement custom digital circuits and logic functions", "To manage the system's memory and storage"}, 'C'},

                                 {"What is the name of the protocol commonly used for communication between embedded devices in the Internet of Things (IoT)?", {"Bluetooth", "Zigbee", "MQTT", "Wi-Fi"}, 'C'},

                                 {"What is the significance of the term 'JTAG' in embedded systems?", {"Joint Test Action Group, a standard for testing and debugging embedded systems", "Java Targeting and Graphics, a programming framework for embedded devices", "Just-in-Time Adaptive Garbage collection, a memory management technique for embedded applications", "Jitter Tolerance Analysis Group, a protocol for real-time communication in embedded systems"}, 'A'},

                                 {"What is the term for the practice of creating multiple instances of a component or system to improve reliability and performance in embedded systems?", {"Redundancy", "Scalability", "Parallelism", "Diversity"}, 'A'},

                                 {"What is the name of the process that involves examining and validating each component of an embedded system to ensure it meets the specified requirements?", {"Verification", "Validation", "Testing", "Debugging"}, 'A'},

                                 {"What is the term for the process of identifying and eliminating errors or defects in embedded systems?", {"Verification", "Validation", "Testing", "Debugging"}, 'D'},

                                 {"What is the purpose of an analog-to-digital converter (ADC) in embedded systems?", {"To convert digital signals to analog signals", "To interface with digital sensors and convert analog signals to digital signals", "To enhance the graphics performance of embedded devices", "To provide a stable clock signal for timing operations"}, 'B'},

                                 {"What is the name of the design pattern commonly used to represent objects in an embedded system as a hierarchical tree structure?", {"Singleton pattern", "Composite pattern", "Observer pattern", "Factory pattern"}, 'B'},

                                 {"What is the purpose of a buffer in embedded systems?", {"To store and manage data temporarily during the communication between components", "To enhance the processing speed of the CPU", "To provide additional power to the system", "To convert analog signals to digital signals"}, 'A'},

                                 {"What is the term for the process of updating the firmware or software of an embedded system to add new features or fix issues?", {"Debugging", "Refactoring", "Flashing", "Optimization"}, 'C'},

                                 {"What is the name of the technique used to protect sensitive information in embedded systems by converting it into unreadable characters?", {"Cryptography", "Hashing", "Obfuscation", "Compression"}, 'A'},

                                 {"What is the significance of the term 'RTOS' in embedded systems?", {"Real-Time Operating System, specialized for time-critical tasks in embedded applications", "Random Testing and Observation System, a debugging tool for embedded systems", "Redundant Time Optimization Service, a technique for improving reliability in embedded systems", "Real-Time Observation and Testing Standard, a set of guidelines for embedded system development"}, 'A'},

                                 {"What is the name of the method used to conserve power in embedded systems by selectively turning off certain components when not in use?", {"Power throttling", "Power conservation", "Power profiling", "Power management"}, 'D'},

                                 {"What is the role of a bootloader in embedded systems?", {"To load the operating system into memory during the system startup", "To manage the system's power supply and consumption", "To provide a secure channel for communication between embedded devices", "To regulate the temperature of the system"}, 'A'},

                                 {"What is the term for the process of converting digital signals to analog signals in embedded systems?", {"Analog modulation", "Digital modulation", "Analog-to-digital conversion", "Digital-to-analog conversion"}, 'D'},

                                 {"What is the significance of the term 'IoT' in embedded systems?", {"Internet of Things, connecting embedded devices to the internet for data exchange", "Input/output Techniques, a method for interfacing with external devices in embedded systems", "Integrated Optimization Tools, software for improving performance in embedded applications", "Internet over Technology, a networking protocol for embedded systems"}, 'A'},

                                 {"What is the name of the programming language commonly used for developing real-time systems in embedded applications?", {"Java", "Python", "C++", "Ada"}, 'D'},

                                 {"What is the term for the process of converting analog signals to digital signals in embedded systems?", {"Analog modulation", "Digital modulation", "Analog-to-digital conversion", "Digital-to-analog conversion"}, 'C'},

                                 {"What is the name of the component in embedded systems responsible for managing and controlling other components?", {"Microcontroller", "Microprocessor", "Sensor", "Actuator"}, 'A'},

                                 {"What is the purpose of an actuator in embedded systems?", {"To sense and gather data from the environment", "To convert digital signals to analog signals", "To process and analyze data in the system", "To perform actions or movements based on the system's output"}, 'D'},

                                 {"What is the significance of the term 'RTOS' in embedded systems?", {"Real-Time Operating System, specialized for time-critical tasks in embedded applications", "Random Testing and Observation System, a debugging tool for embedded systems", "Redundant Time Optimization Service, a technique for improving reliability in embedded systems", "Real-Time Observation and Testing Standard, a set of guidelines for embedded system development"}, 'A'},

                                 {"What is the purpose of a watchdog timer in embedded systems?", {"To monitor the system and reset it if a malfunction or hang is detected", "To keep track of time in the system", "To provide a secure channel for communication between embedded devices", "To synchronize the operation of multiple embedded devices"}, 'A'},

                                 {"What is the term for the practice of creating multiple instances of a component or system to improve reliability and performance in embedded systems?", {"Redundancy", "Scalability", "Parallelism", "Diversity"}, 'A'},

                                 {"What is the name of the protocol commonly used for communication between embedded devices in the Internet of Things (IoT)?", {"Bluetooth", "Zigbee", "MQTT", "Wi-Fi"}, 'C'},

                                 {"What is the purpose of an analog-to-digital converter (ADC) in embedded systems?", {"To convert digital signals to analog signals", "To interface with digital sensors and convert analog signals to digital signals", "To enhance the graphics performance of embedded devices", "To provide a stable clock signal for timing operations"}, 'B'},

                                 {"What is the role of an FPGA (Field-Programmable Gate Array) in embedded systems?", {"To provide secure communication between embedded devices", "To act as a watchdog timer for the system", "To implement custom digital circuits and logic functions", "To manage the system's memory and storage"}, 'C'},

                                 {"What is the term for the process of updating the firmware or software of an embedded system to add new features or fix issues?", {"Debugging", "Refactoring", "Flashing", "Optimization"}, 'C'},

                                 {"What is the name of the technique used to protect sensitive information in embedded systems by converting it into unreadable characters?", {"Cryptography", "Hashing", "Obfuscation", "Compression"}, 'A'},

                                 {"What is the name of the design pattern commonly used to represent objects in an embedded system as a hierarchical tree structure?", {"Singleton pattern", "Composite pattern", "Observer pattern", "Factory pattern"}, 'B'}})},

    {"CHE 101", Quiz("CHE 101", {{"What is the name of the law that states that the total mass of the reactants is equal to the total mass of the products in a chemical reaction?", {"Boyle's Law", "Charles' Law", "Avogadro's Law", "Law of Conservation of Mass"}, 'D'},

                                 {"What is the name of the branch of engineering that applies the principles of chemistry, physics, mathematics, and biology to design and operate processes that convert raw materials into useful products?", {"Chemical engineering", "Chemical technology", "Chemical science", "Chemical industry"}, 'A'},

                                 {"What are the three main sectors of the chemical industry?", {"Basic chemicals, specialty chemicals, and consumer chemicals", "Organic chemicals, inorganic chemicals, and biochemicals", "Petrochemicals, pharmaceuticals, and polymers", "None of the above"}, 'A'},

                                 {"What are the three main types of chemical reactions?", {"Synthesis, decomposition, and displacement", "Combustion, oxidation, and reduction", "Acid-base, precipitation, and neutralization", "All of the above"}, 'D'},

                                 {"What are the three main types of unit operations?", {"Mechanical, thermal, and mass transfer", "Fluid flow, heat transfer, and mass transfer", "Separation, reaction, and transport", "None of the above"}, 'B'},

                                 {"What are the three main types of unit processes?", {"Chemical, biochemical, and electrochemical", "Synthesis, analysis, and purification", "Batch, continuous, and semi-continuous", "None of the above"}, 'A'},

                                 {"What are the three main types of chemical reactors?", {"Batch, plug flow, and continuous stirred tank", "Reversible, irreversible, and equilibrium", "Exothermic, endothermic, and isothermic", "None of the above"}, 'A'},

                                 {"What are the three main types of separation processes?", {"Distillation, extraction, and crystallization", "Filtration, sedimentation, and centrifugation", "Adsorption, absorption, and desorption", "All of the above"}, 'D'},

                                 {"What are the three main types of heat transfer processes?", {"Conduction, convection, and radiation", "Evaporation, condensation, and boiling", "Heating, cooling, and phase change", "None of the above"}, 'A'},

                                 {"What are the three main types of mass transfer processes?", {"Diffusion, osmosis, and dialysis", "Drying, humidification, and dehumidification", "Leaching, washing, and stripping", "All of the above"}, 'D'},

                                 {"What is the name of the law that describes the behavior of gases and states that the pressure of a gas is inversely proportional to its volume at constant temperature?", {"Boyle's Law", "Charles' Law", "Avogadro's Law", "Dalton's Law"}, 'A'},

                                 {"What is the term for the ratio of the actual yield of a chemical reaction to the theoretical yield expressed as a percentage?", {"Mole ratio", "Stoichiometry", "Yield efficiency", "Percent yield"}, 'D'},

                                 {"What is the name of the instrument used to measure the amount of heat released or absorbed during a chemical reaction?", {"Spectrophotometer", "Calorimeter", "Refractometer", "Barometer"}, 'B'},

                                 {"What is the name of the law that states that the total pressure of a mixture of gases is equal to the sum of the partial pressures of its individual gases?", {"Boyle's Law", "Charles' Law", "Avogadro's Law", "Dalton's Law"}, 'D'},

                                 {"What is the term for a substance that speeds up the rate of a chemical reaction without being consumed in the process?", {"Catalyst", "Inhibitor", "Reactant", "Product"}, 'A'},

                                 {"What is the name of the process in which a substance changes from a gas to a liquid state?", {"Vaporization", "Condensation", "Evaporation", "Sublimation"}, 'B'},

                                 {"What is the term for a substance that neutralizes an acid to form water and a salt?", {"Base", "Salt", "Alkali", "Acid"}, 'A'},

                                 {"What is the name of the law that states that the volume of a given mass of gas is directly proportional to its temperature at constant pressure?", {"Boyle's Law", "Charles' Law", "Avogadro's Law", "Dalton's Law"}, 'B'},

                                 {"What is the term for a chemical reaction in which two substances combine to form a new substance?", {"Decomposition", "Synthesis", "Displacement", "Combustion"}, 'B'},

                                 {"What is the name of the process in which a substance changes directly from a solid to a gas without passing through the liquid state?", {"Vaporization", "Condensation", "Evaporation", "Sublimation"}, 'D'},

                                 {"What is the term for the study of the relationships between the composition and properties of substances?", {"Chemistry", "Physics", "Biology", "Mathematics"}, 'A'}})},

    {"CHE 201", Quiz("CHE 201", {{"What is the name of the law that states that the total mass of the reactants is equal to the total mass of the products in a chemical reaction?", {"Boyle's Law", "Charles' Law", "Avogadro's Law", "Law of Conservation of Mass"}, 'D'},

                                 {"What is the name of the branch of thermodynamics that deals with the relations between heat and other forms of energy in chemical systems?", {"Chemical thermodynamics", "Thermochemistry", "Chemical kinetics", "Chemical equilibrium"}, 'A'},

                                 {"What is the name of the state function that measures the degree of disorder or randomness of a system?", {"Entropy", "Enthalpy", "Gibbs free energy", "Helmholtz free energy"}, 'A'},

                                 {"What is the name of the law of thermodynamics that states that the total energy of an isolated system is constant?", {"Zeroth law", "First law", "Second law", "Third law"}, 'B'},

                                 {"What is the name of the law of thermodynamics that states that the entropy of an isolated system can never decrease over time?", {"Zeroth law", "First law", "Second law", "Third law"}, 'C'},

                                 {"What is the name of the law of thermodynamics that states that the entropy of a perfect crystal at absolute zero is zero?", {"Zeroth law", "First law", "Second law", "Third law"}, 'D'},

                                 {"What is the name of the thermodynamic process that occurs at constant pressure?", {"Isothermal", "Isobaric", "Isochoric", "Adiabatic"}, 'B'},

                                 {"What is the name of the thermodynamic process that occurs without any heat transfer between the system and the surroundings?", {"Isothermal", "Isobaric", "Isochoric", "Adiabatic"}, 'D'},

                                 {"What is the name of the thermodynamic potential that is minimized when a system reaches equilibrium at constant pressure and temperature?", {"Entropy", "Enthalpy", "Gibbs free energy", "Helmholtz free energy"}, 'C'},

                                 {"What is the name of the thermodynamic potential that is minimized when a system reaches equilibrium at constant volume and temperature?", {"Entropy", "Enthalpy", "Gibbs free energy", "Helmholtz free energy"}, 'D'},

                                 {"What is the name of the law that quantitatively relates the pressure and volume of a gas at constant temperature?", {"Boyle's Law", "Charles' Law", "Avogadro's Law", "Gay-Lussac's Law"}, 'A'},

                                 {"In chemical reactions, what term is used to describe the minimum energy required to initiate a reaction?", {"Activation energy", "Reaction energy", "Catalytic energy", "Threshold energy"}, 'A'},

                                 {"What is the name of the process where a substance transitions directly from a solid to a gas without passing through the liquid phase?", {"Sublimation", "Evaporation", "Condensation", "Deposition"}, 'A'},

                                 {"In thermodynamics, what term is used for the maximum amount of work that can be obtained from a system at constant temperature and pressure?", {"Gibbs free energy", "Helmholtz free energy", "Internal energy", "Enthalpy"}, 'A'},

                                 {"What is the term for a reaction that releases heat to its surroundings?", {"Exothermic", "Endothermic", "Isothermal", "Adiabatic"}, 'A'},

                                 {"In a chemical equation, what is the term for the substances on the left side of the arrow?", {"Reactants", "Products", "Coefficients", "Catalysts"}, 'A'},

                                 {"What is the name of the law that states that the pressure of a gas is directly proportional to its absolute temperature, provided the volume remains constant?", {"Boyle's Law", "Charles' Law", "Avogadro's Law", "Gay-Lussac's Law"}, 'B'},

                                 {"In a chemical reaction, what is the term for the species that is formed when the reactants react with each other?", {"Catalyst", "Product", "Intermediate", "Byproduct"}, 'B'},

                                 {"What is the term for a process that occurs with no change in temperature?", {"Adiabatic", "Isobaric", "Isothermal", "Isentropic"}, 'C'},

                                 {"In chemical kinetics, what term is used to describe the rate of a reaction at the very beginning, where concentrations are highest?", {"Initial rate", "Instantaneous rate", "Steady-state rate", "Average rate"}, 'A'},

                                 {"What is the term for the point in a titration where the amount of added titrant is stoichiometrically equivalent to the amount of analyte?", {"Equivalence point", "Endpoint", "Inflection point", "Transition point"}, 'A'},

                                 {"In chemical equilibrium, what is the term for the ratio of the concentrations of products to reactants, each raised to the power of their respective coefficients?", {"Equilibrium constant", "Reaction quotient", "Rate constant", "Stability constant"}, 'A'},

                                 {"What is the term for the measure of the average kinetic energy of particles in a substance?", {"Temperature", "Pressure", "Volume", "Density"}, 'A'},

                                 {"In electrochemistry, what is the term for a substance that undergoes oxidation and loses electrons in a redox reaction?", {"Oxidizing agent", "Reducing agent", "Electrolyte", "Conductor"}, 'A'},

                                 {"What is the term for a reaction in which two or more substances combine to form a new compound?", {"Synthesis reaction", "Decomposition reaction", "Replacement reaction", "Combustion reaction"}, 'A'},

                                 {"In chemical kinetics, what term is used to describe the maximum rate a reaction can achieve under certain conditions?", {"Rate constant", "Catalyst rate", "Maximum rate", "Reaction rate"}, 'C'},

                                 {"What is the name of the process in which a solid changes directly into a gas without passing through the liquid state?", {"Sublimation", "Evaporation", "Condensation", "Vaporization"}, 'A'},

                                 {"In a voltaic cell, what is the term for the electrode where oxidation occurs?", {"Anode", "Cathode", "Electrolyte", "Salt bridge"}, 'A'},

                                 {"What is the term for the minimum amount of energy required for a chemical reaction to occur?", {"Threshold energy", "Activation energy", "Reaction energy", "Enthalpy change"}, 'B'},

                                 {"In nuclear chemistry, what is the process of a heavy nucleus splitting into two or more lighter nuclei?", {"Fusion", "Fission", "Transmutation", "Decay"}, 'B'},

                                 {"What is the term for a substance that speeds up a chemical reaction without being consumed in the process?", {"Catalyst", "Inhibitor", "Reactant", "Product"}, 'A'},

                                 {"In thermodynamics, what term is used for the measure of the disorder or randomness of a system?", {"Entropy", "Enthalpy", "Gibbs free energy", "Helmholtz free energy"}, 'A'},

                                 {"What is the term for a reaction that involves the exchange of ions between reactants in aqueous solution?", {"Precipitation reaction", "Neutralization reaction", "Redox reaction", "Ionic reaction"}, 'C'},

                                 {"In chemical equilibrium, what is the term for a change in concentration that has no effect on the equilibrium constant?", {"Dynamic change", "Irreversible change", "Equilibrium shift", "Le Chatelier's principle"}, 'C'},

                                 {"What is the term for the ratio of the actual yield of a reaction to the theoretical yield, expressed as a percentage?", {"Reaction efficiency", "Yield ratio", "Reaction yield", "Percent yield"}, 'D'},

                                 {"In spectroscopy, what is the term for the range of electromagnetic radiation absorbed by a substance?", {"Absorption spectrum", "Emission spectrum", "Reflectance spectrum", "Transmission spectrum"}, 'A'},

                                 {"What is the term for the process of a gas changing directly into a solid without passing through the liquid phase?", {"Deposition", "Sublimation", "Condensation", "Solidification"}, 'A'},

                                 {"In nuclear chemistry, what is the term for the time required for half of a radioactive substance to decay?", {"Decay time", "Half-life", "Radioactive time", "Nuclear time"}, 'B'}})},

    {"EE 101", Quiz("EE 101", {{"What is the unit of electric current?", {"Volt", "Ohm", "Ampere", "Watt"}, 'C'},

                               {"What is the name of the law that states that the algebraic sum of the currents entering a node is zero?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Norton's theorem"}, 'A'},

                               {"What is the name of the law that states that the algebraic sum of the voltages around a closed loop is zero?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Thevenin's theorem"}, 'B'},

                               {"What is the name of the law that states that the voltage across a resistor is proportional to the current through it?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Superposition principle"}, 'C'},

                               {"What is the name of the theorem that states that any linear circuit with a single voltage source and several resistors can be replaced by an equivalent circuit with a single voltage source and a single resistor?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Thevenin's theorem"}, 'D'},

                               {"What is the name of the theorem that states that any linear circuit with a single current source and several resistors can be replaced by an equivalent circuit with a single current source and a single resistor?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Norton's theorem"}, 'D'},

                               {"What is the name of the principle that states that the response of a linear circuit with multiple sources can be obtained by adding the responses due to each source acting alone?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Superposition principle"}, 'D'},

                               {"What is the name of the circuit element that stores energy in an electric field and has the unit of farad?", {"Resistor", "Capacitor", "Inductor", "Diode"}, 'B'},

                               {"What is the name of the circuit element that stores energy in a magnetic field and has the unit of henry?", {"Resistor", "Capacitor", "Inductor", "Diode"}, 'C'},

                               {"What is the name of the device that allows current to flow in only one direction and has the symbol of a triangle with a line?", {"Resistor", "Capacitor", "Inductor", "Diode"}, 'D'},

                               {"What is the SI unit of resistance?", {"Volt", "Ohm", "Ampere", "Watt"}, 'B'},

                               {"What is the name of the law that relates the voltage, current, and resistance in an electrical circuit?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Norton's theorem"}, 'C'},

                               {"What is the unit of electric potential difference?", {"Volt", "Ohm", "Ampere", "Watt"}, 'A'},

                               {"What is the name of the circuit element that opposes the flow of current and has the unit of ohm?", {"Resistor", "Capacitor", "Inductor", "Diode"}, 'A'},

                               {"What is the name of the process of converting alternating current (AC) to direct current (DC)?", {"Rectification", "Amplification", "Oscillation", "Modulation"}, 'A'},

                               {"What is the term for the electrical potential energy per unit charge in an electric circuit?", {"Voltage", "Resistance", "Current", "Power"}, 'A'},

                               {"What is the name of the circuit element that amplifies or increases the voltage of a signal?", {"Resistor", "Capacitor", "Inductor", "Transistor"}, 'D'},

                               {"What is the unit of electrical power?", {"Volt", "Ohm", "Ampere", "Watt"}, 'D'},

                               {"What is the name of the electrical device that stores electrical energy in a chemical form?", {"Battery", "Resistor", "Capacitor", "Inductor"}, 'A'},

                               {"What is the term for the rate of flow of electric charge?", {"Voltage", "Resistance", "Current", "Power"}, 'C'},

                               {"What is the name of the circuit element that stores electrical energy temporarily and releases it back when needed?", {"Resistor", "Capacitor", "Inductor", "Diode"}, 'B'},

                               {"What is the name of the circuit element that stores energy in a magnetic field when current flows through it?", {"Resistor", "Capacitor", "Inductor", "Diode"}, 'C'},

                               {"What is the term for the opposition that a circuit presents to the flow of alternating current?", {"Resistance", "Reactance", "Impedance", "Conductance"}, 'B'},

                               {"What is the name of the device that allows current to flow in one direction while blocking it in the reverse direction?", {"Rectifier", "Amplifier", "Oscillator", "Modulator"}, 'A'},

                               {"What is the name of the electrical device used to measure electric current?", {"Voltmeter", "Ammeter", "Ohmmeter", "Multimeter"}, 'B'},

                               {"What is the term for the measure of the opposition to the flow of direct current in a circuit?", {"Voltage", "Resistance", "Current", "Power"}, 'B'},

                               {"What is the name of the circuit element that produces an electromotive force (EMF) by electromagnetic induction?", {"Resistor", "Capacitor", "Inductor", "Generator"}, 'C'},

                               {"What is the term for the process of increasing the amplitude of a signal in an electronic circuit?", {"Amplification", "Rectification", "Oscillation", "Modulation"}, 'A'},

                               {"What is the name of the law that states that the total electric charge in a closed system is constant?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Conservation of charge"}, 'D'},

                               {"What is the SI unit of electric charge?", {"Coulomb", "Ampere-hour", "Farad", "Volt"}, 'A'},

                               {"What is the name of the circuit element that allows current to flow when its terminals are connected to a higher potential?", {"Resistor", "Capacitor", "Inductor", "Switch"}, 'D'},

                               {"What is the term for a complete path that an electric current can flow through?", {"Circuit", "Node", "Loop", "Branch"}, 'A'},

                               {"What is the name of the process of converting direct current (DC) to alternating current (AC)?", {"Rectification", "Amplification", "Inversion", "Modulation"}, 'C'},

                               {"What is the term for the ability of a circuit element to store electrical energy in an electric field?", {"Capacitance", "Inductance", "Resistance", "Conductance"}, 'A'},

                               {"What is the name of the electrical device used to measure voltage?", {"Voltmeter", "Ammeter", "Ohmmeter", "Multimeter"}, 'A'},

                               {"What is the term for the measure of the opposition to the flow of alternating current in a circuit?", {"Voltage", "Resistance", "Reactance", "Power"}, 'C'},

                               {"What is the name of the circuit element that allows current to flow when its terminals are connected to a lower potential?", {"Resistor", "Capacitor", "Inductor", "Switch"}, 'D'},

                               {"What is the term for the process of producing an oscillating or alternating voltage in an electronic circuit?", {"Amplification", "Oscillation", "Rectification", "Modulation"}, 'B'},

                               {"What is the name of the law that states that the current through a conductor between two points is directly proportional to the voltage across the two points?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Faraday's law"}, 'C'},

                               {"What is the SI unit of power?", {"Volt", "Ohm", "Ampere", "Watt"}, 'D'},

                               {"What is the name of the circuit element that opposes the change in current flow and has the unit of henry?", {"Resistor", "Capacitor", "Inductor", "Diode"}, 'C'},

                               {"What is the term for the process of converting mechanical energy into electrical energy?", {"Conversion", "Transformation", "Transduction", "Generation"}, 'D'},

                               {"What is the name of the device that protects an electrical circuit from excessive current?", {"Fuse", "Switch", "Resistor", "Capacitor"}, 'A'},

                               {"What is the term for the flow of electric charge per unit time?", {"Voltage", "Resistance", "Current", "Power"}, 'C'},

                               {"What is the name of the circuit element that stores energy in a magnetic field and has the unit of tesla?", {"Resistor", "Capacitor", "Inductor", "Diode"}, 'C'},

                               {"What is the term for the process of decreasing the amplitude of a signal in an electronic circuit?", {"Amplification", "Rectification", "Attenuation", "Modulation"}, 'C'},

                               {"What is the name of the law that states that the electromotive force (EMF) induced in a circuit is proportional to the rate of change of magnetic flux?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Faraday's law"}, 'D'},

                               {"What is the SI unit of capacitance?", {"Ohm", "Farad", "Coulomb", "Henry"}, 'B'},

                               {"What is the name of the circuit element that allows current to flow in one direction only and has a constant voltage drop?", {"Resistor", "Capacitor", "Inductor", "Zener diode"}, 'D'},

                               {"What is the term for the process of changing an electrical signal into a corresponding variation in resistance?", {"Conversion", "Transformation", "Transduction", "Modulation"}, 'C'},

                               {"What is the name of the device that stores electrical energy in an electrostatic field and has the unit of farad?", {"Battery", "Resistor", "Capacitor", "Inductor"}, 'C'},

                               {"What is the term for a device that changes electrical energy into mechanical energy?", {"Generator", "Motor", "Transformer", "Converter"}, 'B'},

                               {"What is the name of the law that states that the electromotive force (EMF) induced in a closed loop is equal to the negative rate of change of magnetic flux through the loop?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Lenz's law"}, 'D'},

                               {"What is the SI unit of inductance?", {"Ohm", "Farad", "Coulomb", "Henry"}, 'D'},

                               {"What is the name of the circuit element that controls the flow of current between two electrodes in a semiconductor?", {"Resistor", "Capacitor", "Inductor", "Transistor"}, 'D'},

                               {"What is the term for the process of converting electrical energy into mechanical energy?", {"Conversion", "Transformation", "Transduction", "Generation"}, 'B'},

                               {"What is the name of the device that increases or decreases the voltage of an alternating current?", {"Rectifier", "Transformer", "Inverter", "Converter"}, 'B'},

                               {"What is the term for the process of encoding information in a carrier wave by varying its amplitude?", {"Amplification", "Oscillation", "Modulation", "Rectification"}, 'C'},

                               {"What is the name of the circuit element that stores electrical energy in a magnetic field and has the unit of ampere-turns?", {"Resistor", "Capacitor", "Inductor", "Transformer"}, 'C'},

                               {"What is the term for the process of converting electrical energy into electromagnetic waves?", {"Conversion", "Transmission", "Transduction", "Modulation"}, 'B'},

                               {"What is the name of the law that states that the total electric charge in a closed system is constant?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Conservation of charge"}, 'D'}})},

    {"EE 204", Quiz("EE 204", {{"What is the unit of electric current?", {"Volt", "Ohm", "Ampere", "Watt"}, 'C'},

                               {"What is the name of the logic gate that produces a 1 output only when both of its inputs are 1?", {"AND", "OR", "NOT", "XOR"}, 'A'},

                               {"What is the name of the logic gate that produces a 1 output only when at least one of its inputs is 1?", {"AND", "OR", "NOT", "XOR"}, 'B'},

                               {"What is the name of the logic gate that produces a 1 output only when its input is 0?", {"AND", "OR", "NOT", "XOR"}, 'C'},

                               {"What is the name of the logic gate that produces a 1 output only when its inputs are different?", {"AND", "OR", "NOT", "XOR"}, 'D'},

                               {"What is the name of the number system that uses only 0 and 1 to represent any value?", {"Binary", "Decimal", "Hexadecimal", "Octal"}, 'A'},

                               {"What is the name of the number system that uses 16 symbols (0-9 and A-F) to represent any value?", {"Binary", "Decimal", "Hexadecimal", "Octal"}, 'C'},

                               {"What is the name of the code that uses four bits to represent the decimal digits 0 to 9?", {"BCD", "Gray", "ASCII", "Hamming"}, 'A'},

                               {"What is the name of the code that uses four bits to represent 16 values, where only one bit changes between consecutive values?", {"BCD", "Gray", "ASCII", "Hamming"}, 'B'},

                               {"What is the name of the code that uses seven bits to represent 128 characters, such as letters, digits, and symbols?", {"BCD", "Gray", "ASCII", "Hamming"}, 'C'},

                               {"What is the unit of electric charge?", {"Ampere-hour", "Coulomb", "Farad", "Ohm"}, 'B'},

                               {"What is the name of the logic gate that produces a 1 output only when either of its inputs is 1, but not both?", {"AND", "OR", "NAND", "XOR"}, 'D'},

                               {"What is the name of the logic gate that produces a 1 output only when both of its inputs are 0?", {"AND", "OR", "NOR", "XOR"}, 'C'},

                               {"What is the name of the logic gate that produces a 1 output only when its inputs are the same?", {"AND", "OR", "NAND", "XOR"}, 'A'},

                               {"What is the name of the logic gate that produces a 1 output only when its inputs are both 1 or both 0?", {"AND", "OR", "NOR", "XOR"}, 'B'},

                               {"What is the name of the number system that uses only the digits 0-7 to represent any value?", {"Binary", "Decimal", "Octal", "Hexadecimal"}, 'C'},

                               {"What is the name of the number system that uses 8 symbols (0-7) to represent any value?", {"Binary", "Decimal", "Octal", "Hexadecimal"}, 'C'},

                               {"What is the name of the code that uses eight bits to represent characters, allowing for 256 different characters?", {"BCD", "Gray", "ASCII", "Hamming"}, 'C'},

                               {"What is the name of the code that uses three bits to represent 8 values, where only one bit changes between consecutive values?", {"BCD", "Gray", "Excess-3", "Hamming"}, 'C'},

                               {"What is the name of the code that uses six bits to represent uppercase letters, lowercase letters, digits, and special characters?", {"BCD", "Gray", "ASCII", "Hamming"}, 'C'},

                               {"What is the SI unit of electrical resistance?", {"Ampere", "Ohm", "Volt", "Watt"}, 'B'},

                               {"What is the name of the logic gate that produces a 1 output only when either of its inputs is 0?", {"AND", "OR", "NAND", "XOR"}, 'C'},

                               {"What is the name of the logic gate that produces a 1 output only when both of its inputs are 1?", {"AND", "OR", "NOR", "XOR"}, 'A'},

                               {"What is the name of the logic gate that produces a 1 output only when both of its inputs are 0?", {"AND", "OR", "NOR", "XOR"}, 'C'},

                               {"What is the name of the logic gate that produces a 1 output only when its inputs are different?", {"AND", "OR", "NOR", "XOR"}, 'D'},

                               {"What is the name of the number system that uses only 0 and 1 to represent any value?", {"Binary", "Decimal", "Hexadecimal", "Octal"}, 'A'},

                               {"What is the name of the number system that uses 16 symbols (0-9 and A-F) to represent any value?", {"Binary", "Decimal", "Hexadecimal", "Octal"}, 'C'},

                               {"What is the name of the code that uses four bits to represent the decimal digits 0 to 9?", {"BCD", "Gray", "ASCII", "Hamming"}, 'A'},

                               {"What is the name of the code that uses four bits to represent 16 values, where only one bit changes between consecutive values?", {"BCD", "Gray", "ASCII", "Hamming"}, 'B'},

                               {"What is the name of the code that uses seven bits to represent 128 characters, such as letters, digits, and symbols?", {"BCD", "Gray", "ASCII", "Hamming"}, 'C'},

                               {"What is the SI unit of electric potential?", {"Ampere", "Ohm", "Volt", "Watt"}, 'C'},

                               {"What is the name of the logic gate that produces a 1 output only when either of its inputs is 1?", {"AND", "OR", "NAND", "XOR"}, 'A'},

                               {"What is the name of the logic gate that produces a 1 output only when either of its inputs is 0?", {"AND", "OR", "NAND", "XOR"}, 'C'},

                               {"What is the name of the logic gate that produces a 1 output only when its inputs are 1?", {"AND", "OR", "NAND", "XOR"}, 'B'},

                               {"What is the name of the logic gate that produces a 1 output only when its inputs are the same?", {"AND", "OR", "NAND", "XOR"}, 'A'},

                               {"What is the name of the logic gate that produces a 1 output only when its inputs are both 1 or both 0?", {"AND", "OR", "NOR", "XOR"}, 'B'},

                               {"What is the name of the number system that uses only the digits 0-7 to represent any value?", {"Binary", "Decimal", "Octal", "Hexadecimal"}, 'C'},

                               {"What is the name of the number system that uses 8 symbols (0-7) to represent any value?", {"Binary", "Decimal", "Octal", "Hexadecimal"}, 'C'},

                               {"What is the name of the code that uses eight bits to represent characters, allowing for 256 different characters?", {"BCD", "Gray", "ASCII", "Hamming"}, 'C'},

                               {"What is the name of the code that uses three bits to represent 8 values, where only one bit changes between consecutive values?", {"BCD", "Gray", "Excess-3", "Hamming"}, 'C'},

                               {"What is the name of the code that uses six bits to represent uppercase letters, lowercase letters, digits, and special characters?", {"BCD", "Gray", "ASCII", "Hamming"}, 'C'},

                               {"What is the SI unit of electrical current?", {"Ampere", "Ohm", "Volt", "Watt"}, 'A'},

                               {"What is the name of the logic gate that produces a 1 output only when both of its inputs are 0?", {"AND", "OR", "NAND", "XOR"}, 'C'},

                               {"What is the name of the logic gate that produces a 1 output only when both of its inputs are 1?", {"AND", "OR", "NOR", "XOR"}, 'A'},

                               {"What is the name of the logic gate that produces a 1 output only when its inputs are 0?", {"AND", "OR", "NOR", "XOR"}, 'C'}})}};

// Define the constructor that takes the course name and the questions as parameters
Quiz::Quiz(string course, std::vector<Question> questions) : course(course), questions(questions) {}

// Define the method to display the quiz
void Quiz::display()
{
    int i = 0;
    int QuestionNumber = 0;
    vector<int> TenQuestions;
    cout << "Quiz for " << course << endl;
    cout << "---------------------" << endl;
    // Loop over the questions vector and print each question with its options

    // for (i; i < questions.size(); i++)
    for (i; i < 10; i++)
    {
        // Generate a random number between 0 and the size of the questions vector
        do
        {

            QuestionNumber = generateRandomNumber(questions.size());
            for (int ii = 0; ii < TenQuestions.size(); ii++)
            {
                if (TenQuestions[ii] == QuestionNumber)
                {
                    uniqueNumber = false;
                    break;
                }
            }
            uniqueNumber = true;
            TenQuestions.push_back(QuestionNumber);

        } while (!uniqueNumber);

        cout << i + 1 << ". " << questions[QuestionNumber].text << endl;
        // Loop over the options vector and print each option with a letter
        for (int j = 0; j < questions[QuestionNumber].options.size(); j++)
        {
            cout << char('A' + j) << ") " << questions[QuestionNumber].options[j] << endl;
        }
        cout << endl;
        take(i, QuestionNumber);
        clearScreen();
    }

    TenQuestions.clear();
    cout << "Your score is " << score << " out of " << i << endl;
}

// Define the method to take the quiz
void Quiz::take(int i, int Qnum)
{

    char answer;

    // Compare the answer with the correct answer and print feedback
    do
    {
        cout << "Enter your answer for question " << i + 1 << ": ";
        cin >> answer;
        // Convert the answer to uppercase
        answer = toupper(answer);

        uniqueNumber = true;
        switch (answer)
        {
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
            if (answer == questions[Qnum].answer)
            {
                cout << "Correct! " << questions[Qnum].answer << " is the correct Option" << endl;
                cout << "vector number" << Qnum << endl;
                uniqueNumber = true;
                score++;
                mySleep(1);
            }
            else
            {
                cout << "Wrong! The correct answer is " << questions[Qnum].answer << endl;
                cout << "vector number" << Qnum << endl;
                uniqueNumber = true;
                mySleep(1);
            }
            break;
        default:
            cout << "Invalid answer!" << endl;
            mySleep(1);
            uniqueNumber = false;
            break;
        }
    } while (!uniqueNumber);
    cout << endl;
}

// method to get Questions vector
vector<Question> Quiz::getQuestions()
{
    return questions;
}