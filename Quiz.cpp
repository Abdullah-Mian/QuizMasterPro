// Include the header file for the Quiz class
#include "Quiz.h"
#include "ClearScreen.h"

using namespace std;

int score = 0; // Variable to keep track of the score
// Define the map of quizzes
map<string, Quiz> quizzes = {
    {"CS 101", Quiz("CS 101", {{"What is the output of the following C++ code?\n\n#include <iostream>\nusing namespace std;\n\nint main() {\n    int x = 10;\n    int y = 20;\n    cout << x + y << endl;\n    return 0;\n}\n", {"10", "20", "30", "40"}, 'C'},

                               {"What is the name of the process that converts high-level programming languages into machine code?", {"Compilation", "Interpretation", "Execution", "Translation"}, 'A'},

                               {"What is the name of the data type that can store only two values: true or false?", {"Boolean", "Binary", "Bit", "Byte"}, 'A'},

                               {"What is the name of the operator that performs logical AND operation on two operands?", {"&&", "||", "&", "|"}, 'A'},

                               {"What is the name of the control structure that executes a block of code repeatedly while a condition is true?", {"For loop", "While loop", "Do-while loop", "If statement"}, 'B'},

                               {"What is the name of the function that prints a message to the standard output stream?", {"cout", "cin", "printf", "scanf"}, 'C'},

                               {"What is the name of the symbol that is used to mark the end of a statement in C++?", {";", ":", ".", ","}, 'A'},

                               {"What is the name of the keyword that is used to declare a constant variable in C++?", {"const", "final", "static", "immutable"}, 'A'},

                               {"What is the name of the data structure that stores elements in a key-value pair and allows fast retrieval by the key?", {"Array", "List", "Map", "Set"}, 'C'},

                               {"What is the name of the concept that allows a function to have different forms based on the number or type of parameters?", {"Encapsulation", "Inheritance", "Polymorphism", "Abstraction"}, 'C'}})},

    {"CS 201", Quiz("CS 201", {{"What is the output of the following C++ code?\n\n#include <iostream>\nusing namespace std;\n\nint main() {\n    int x = 10;\n    int y = 20;\n    cout << x + y << endl;\n    return 0;\n}\n", {"10", "20", "30", "40"}, 'C'},

                               {"What is the name of the technique that divides a problem into smaller subproblems and solves them recursively?", {"Divide and conquer", "Dynamic programming", "Greedy method", "Backtracking"}, 'A'},

                               {"What is the name of the data structure that represents a collection of nodes and edges, where each node can have zero or more adjacent nodes?", {"Graph", "Tree", "Heap", "Array"}, 'A'},

                               {"What is the name of the algorithm that sorts an array by repeatedly finding the minimum element and swapping it with the first unsorted element?", {"Selection sort", "Insertion sort", "Bubble sort", "Merge sort"}, 'A'},

                               {"What is the name of the problem that asks to find the longest common subsequence of two given sequences?", {"Longest common subsequence", "Longest increasing subsequence", "Longest common substring", "Longest palindromic subsequence"}, 'A'},

                               {"What is the name of the data structure that supports insertion and deletion at both ends, and allows constant time access to the first and last elements?", {"Deque", "Queue", "Stack", "List"}, 'A'},

                               {"What is the name of the algorithm that finds the shortest path from a single source node to all other nodes in a weighted graph?", {"Dijkstra's algorithm", "Floyd-Warshall algorithm", "Bellman-Ford algorithm", "Kruskal's algorithm"}, 'A'},

                               {"What is the name of the problem that asks to find the optimal way to cut a rod of length n into smaller pieces, such that the sum of the prices of the pieces is maximized?", {"Rod cutting", "Knapsack", "Coin change", "Matrix chain multiplication"}, 'A'},

                               {"What is the name of the data structure that represents a set of disjoint sets, and supports efficient operations to create, merge, and find sets?", {"Disjoint-set", "Hash-set", "Bit-set", "Tree-set"}, 'A'},

                               {"What is the name of the algorithm that finds a matching pair of parentheses in an expression, given the index of an opening parenthesis?", {"Stack-based algorithm", "Recursion-based algorithm", "Counter-based algorithm", "None of the above"}, 'C'}})},

    {"SE 101", Quiz("SE 101", {{"What is the name of the software development process that consists of four phases: inception, elaboration, construction, and transition?", {"Waterfall", "Agile", "Spiral", "Rational Unified Process"}, 'D'},

                               {"What is the definition of software engineering according to IEEE?", {"The application of a systematic, disciplined, quantifiable approach to the development, operation, and maintenance of software", "The process of designing, implementing, testing, and documenting software systems", "The discipline of creating high-quality software products that meet user needs and expectations", "The art and science of applying computer science principles and techniques to solve real-world problems"}, 'A'},

                               {"What are the four fundamental activities of a generic software process?", {"Specification, development, validation, and evolution", "Planning, analysis, design, and implementation", "Requirements, design, coding, and testing", "Modeling, construction, deployment, and maintenance"}, 'A'},

                               {"What are the three types of software maintenance according to ISO/IEC 14764?", {"Corrective, adaptive, and perfective", "Preventive, corrective, and adaptive", "Perfective, preventive, and corrective", "Adaptive, perfective, and preventive"}, 'C'},

                               {"What is the name of the software development methodology that is based on iterative and incremental development, where requirements and solutions evolve through collaboration between self-organizing, cross-functional teams?", {"Agile", "Waterfall", "Spiral", "V-Model"}, 'A'},

                               {"What are the four values of the Agile Manifesto?", {"Individuals and interactions over processes and tools, working software over comprehensive documentation, customer collaboration over contract negotiation, responding to change over following a plan", "Communication and feedback over documentation and contracts, quality and testing over features and deadlines, collaboration and trust over hierarchy and control, flexibility and adaptability over stability and predictability", "People and relationships over resources and tasks, functionality and usability over specifications and standards, involvement and satisfaction over negotiation and agreement, evolution and improvement over planning and execution", "Vision and mission over goals and objectives, prototypes and demos over reports and charts, teamwork and cooperation over roles and responsibilities, innovation and creativity over conformity and compliance"}, 'A'},

                               {"What are the five phases of the waterfall model of software development?", {"Requirements analysis, design, implementation, testing, and maintenance", "Feasibility study, requirements specification, design, coding, and testing", "Planning, analysis, design, implementation, and evaluation", "Initiation, definition, construction, transition, and delivery"}, 'A'},

                               {"What is the name of the graphical notation for modeling various aspects of software systems, such as structure, behavior, and interactions?", {"Unified Modeling Language (UML)", "Entity-Relationship Diagram (ERD)", "Data Flow Diagram (DFD)", "Structured Analysis and Design Technique (SADT)"}, 'A'},

                               {"What is the name of the software quality attribute that measures the degree to which a software system or component can be modified without introducing defects or degrading existing quality?", {"Maintainability", "Reliability", "Reusability", "Portability"}, 'A'},

                               {"What is the name of the software testing technique that involves executing the software system or component with the intent of finding failures?", {"Dynamic testing", "Static testing", "White-box testing", "Black-box testing"}, 'A'}})},

    {"SE 201", Quiz("SE 201", {{"What is the name of the software development process that consists of four phases: inception, elaboration, construction, and transition?", {"Waterfall", "Agile", "Spiral", "Rational Unified Process"}, 'D'},

                               {"What is the name of the feature that allows an object to have different forms or behaviors depending on the context?", {"Encapsulation", "Inheritance", "Polymorphism", "Abstraction"}, 'C'},

                               {"What is the name of the relationship between two classes where one class is a specialized version of another class?", {"Association", "Aggregation", "Composition", "Inheritance"}, 'D'},

                               {"What is the name of the principle that states that a class should have a single responsibility and a single reason to change?", {"Single responsibility principle", "Open-closed principle", "Liskov substitution principle", "Interface segregation principle"}, 'A'},

                               {"What is the name of the mechanism that allows a class to hide its internal details and only expose its interface to the outside world?", {"Encapsulation", "Inheritance", "Polymorphism", "Abstraction"}, 'A'},

                               {"What is the name of the concept that allows a subclass to override the behavior of a superclass method with the same name and signature?", {"Method overloading", "Method overriding", "Method hiding", "Method chaining"}, 'B'},

                               {"What is the name of the keyword that is used to access the members of the current object in C++?", {"this", "self", "me", "current"}, 'A'},

                               {"What is the name of the technique that allows a class to have more than one superclass and inherit features from all of them?", {"Multiple inheritance", "Multilevel inheritance", "Hierarchical inheritance", "Hybrid inheritance"}, 'A'},

                               {"What is the name of the operator that is used to access the members of an object or a class in C++?", {"::", ".", "->", "&"}, 'B'},

                               {"What is the name of the design pattern that defines a family of algorithms, encapsulates each one, and makes them interchangeable?", {"Strategy", "Observer", "Factory", "Singleton"}, 'A'}})},

    {"ECE 201", Quiz("ECE 201", {{"What is the name of the device that converts digital signals to analog signals and vice versa?", {"Modem", "Router", "Switch", "Hub"}, 'A'},

                                 {"What is the name of the logic gate that produces a 1 output only when both of its inputs are 1?", {"AND", "OR", "NOT", "XOR"}, 'A'},

                                 {"What is the name of the number system that uses only 0 and 1 to represent any value?", {"Binary", "Decimal", "Hexadecimal", "Octal"}, 'A'},

                                 {"What is the name of the circuit that can add two bits and produce a sum and a carry bit?", {"Half adder", "Full adder", "Half subtractor", "Full subtractor"}, 'A'},

                                 {"What is the name of the device that can store one bit of information and has two stable states?", {"Flip-flop", "Latch", "Register", "Counter"}, 'A'},

                                 {"What is the name of the method that simplifies a Boolean expression by eliminating redundant terms?", {"Karnaugh map", "Quine-McCluskey", "De Morgan's laws", "Boolean algebra"}, 'A'},

                                 {"What is the name of the code that uses four bits to represent the decimal digits 0 to 9?", {"BCD", "Gray", "ASCII", "Hamming"}, 'A'},

                                 {"What is the name of the circuit that can compare two binary numbers and produce an output that indicates their relationship?", {"Comparator", "Encoder", "Decoder", "Multiplexer"}, 'A'},

                                 {"What is the name of the circuit that can select one of several input signals and forward it to the output based on a control signal?", {"Multiplexer", "Demultiplexer", "Decoder", "Encoder"}, 'A'},

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

                                 {"What are the two types of embedded software testing techniques?", {"White-box and black-box", "Unit and integration", "Functional and non-functional", "All of the above"}, 'D'}})},

    {"CHE 101", Quiz("CHE 101", {{"What is the name of the law that states that the total mass of the reactants is equal to the total mass of the products in a chemical reaction?", {"Boyle's Law", "Charles' Law", "Avogadro's Law", "Law of Conservation of Mass"}, 'D'},

                                 {"What is the name of the branch of engineering that applies the principles of chemistry, physics, mathematics, and biology to design and operate processes that convert raw materials into useful products?", {"Chemical engineering", "Chemical technology", "Chemical science", "Chemical industry"}, 'A'},

                                 {"What are the three main sectors of the chemical industry?", {"Basic chemicals, specialty chemicals, and consumer chemicals", "Organic chemicals, inorganic chemicals, and biochemicals", "Petrochemicals, pharmaceuticals, and polymers", "None of the above"}, 'A'},

                                 {"What are the three main types of chemical reactions?", {"Synthesis, decomposition, and displacement", "Combustion, oxidation, and reduction", "Acid-base, precipitation, and neutralization", "All of the above"}, 'D'},

                                 {"What are the three main types of unit operations?", {"Mechanical, thermal, and mass transfer", "Fluid flow, heat transfer, and mass transfer", "Separation, reaction, and transport", "None of the above"}, 'B'},

                                 {"What are the three main types of unit processes?", {"Chemical, biochemical, and electrochemical", "Synthesis, analysis, and purification", "Batch, continuous, and semi-continuous", "None of the above"}, 'A'},

                                 {"What are the three main types of chemical reactors?", {"Batch, plug flow, and continuous stirred tank", "Reversible, irreversible, and equilibrium", "Exothermic, endothermic, and isothermic", "None of the above"}, 'A'},

                                 {"What are the three main types of separation processes?", {"Distillation, extraction, and crystallization", "Filtration, sedimentation, and centrifugation", "Adsorption, absorption, and desorption", "All of the above"}, 'D'},

                                 {"What are the three main types of heat transfer processes?", {"Conduction, convection, and radiation", "Evaporation, condensation, and boiling", "Heating, cooling, and phase change", "None of the above"}, 'A'},

                                 {"What are the three main types of mass transfer processes?", {"Diffusion, osmosis, and dialysis", "Drying, humidification, and dehumidification", "Leaching, washing, and stripping", "All of the above"}, 'D'}})},

    {"CHE 201", Quiz("CHE 201", {{"What is the name of the law that states that the total mass of the reactants is equal to the total mass of the products in a chemical reaction?", {"Boyle's Law", "Charles' Law", "Avogadro's Law", "Law of Conservation of Mass"}, 'D'},

                                 {"What is the name of the branch of thermodynamics that deals with the relations between heat and other forms of energy in chemical systems?", {"Chemical thermodynamics", "Thermochemistry", "Chemical kinetics", "Chemical equilibrium"}, 'A'},

                                 {"What is the name of the state function that measures the degree of disorder or randomness of a system?", {"Entropy", "Enthalpy", "Gibbs free energy", "Helmholtz free energy"}, 'A'},

                                 {"What is the name of the law of thermodynamics that states that the total energy of an isolated system is constant?", {"Zeroth law", "First law", "Second law", "Third law"}, 'B'},

                                 {"What is the name of the law of thermodynamics that states that the entropy of an isolated system can never decrease over time?", {"Zeroth law", "First law", "Second law", "Third law"}, 'C'},

                                 {"What is the name of the law of thermodynamics that states that the entropy of a perfect crystal at absolute zero is zero?", {"Zeroth law", "First law", "Second law", "Third law"}, 'D'},

                                 {"What is the name of the thermodynamic process that occurs at constant pressure?", {"Isothermal", "Isobaric", "Isochoric", "Adiabatic"}, 'B'},

                                 {"What is the name of the thermodynamic process that occurs without any heat transfer between the system and the surroundings?", {"Isothermal", "Isobaric", "Isochoric", "Adiabatic"}, 'D'},

                                 {"What is the name of the thermodynamic potential that is minimized when a system reaches equilibrium at constant pressure and temperature?", {"Entropy", "Enthalpy", "Gibbs free energy", "Helmholtz free energy"}, 'C'},

                                 {"What is the name of the thermodynamic potential that is minimized when a system reaches equilibrium at constant volume and temperature?", {"Entropy", "Enthalpy", "Gibbs free energy", "Helmholtz free energy"}, 'D'}})},

    {"EE 101", Quiz("EE 101", {{"What is the unit of electric current?", {"Volt", "Ohm", "Ampere", "Watt"}, 'C'},

                               {"What is the name of the law that states that the algebraic sum of the currents entering a node is zero?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Norton's theorem"}, 'A'},

                               {"What is the name of the law that states that the algebraic sum of the voltages around a closed loop is zero?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Thevenin's theorem"}, 'B'},

                               {"What is the name of the law that states that the voltage across a resistor is proportional to the current through it?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Superposition principle"}, 'C'},

                               {"What is the name of the theorem that states that any linear circuit with a single voltage source and several resistors can be replaced by an equivalent circuit with a single voltage source and a single resistor?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Thevenin's theorem"}, 'D'},

                               {"What is the name of the theorem that states that any linear circuit with a single current source and several resistors can be replaced by an equivalent circuit with a single current source and a single resistor?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Norton's theorem"}, 'D'},

                               {"What is the name of the principle that states that the response of a linear circuit with multiple sources can be obtained by adding the responses due to each source acting alone?", {"Kirchhoff's current law", "Kirchhoff's voltage law", "Ohm's law", "Superposition principle"}, 'D'},

                               {"What is the name of the circuit element that stores energy in an electric field and has the unit of farad?", {"Resistor", "Capacitor", "Inductor", "Diode"}, 'B'},

                               {"What is the name of the circuit element that stores energy in a magnetic field and has the unit of henry?", {"Resistor", "Capacitor", "Inductor", "Diode"}, 'C'},

                               {"What is the name of the device that allows current to flow in only one direction and has the symbol of a triangle with a line?", {"Resistor", "Capacitor", "Inductor", "Diode"}, 'D'}})},

    {"EE 204", Quiz("EE 204", {{"What is the unit of electric current?", {"Volt", "Ohm", "Ampere", "Watt"}, 'C'},

                               {"What is the name of the logic gate that produces a 1 output only when both of its inputs are 1?", {"AND", "OR", "NOT", "XOR"}, 'A'},

                               {"What is the name of the logic gate that produces a 1 output only when at least one of its inputs is 1?", {"AND", "OR", "NOT", "XOR"}, 'B'},

                               {"What is the name of the logic gate that produces a 1 output only when its input is 0?", {"AND", "OR", "NOT", "XOR"}, 'C'},

                               {"What is the name of the logic gate that produces a 1 output only when its inputs are different?", {"AND", "OR", "NOT", "XOR"}, 'D'},

                               {"What is the name of the number system that uses only 0 and 1 to represent any value?", {"Binary", "Decimal", "Hexadecimal", "Octal"}, 'A'},

                               {"What is the name of the number system that uses 16 symbols (0-9 and A-F) to represent any value?", {"Binary", "Decimal", "Hexadecimal", "Octal"}, 'C'},

                               {"What is the name of the code that uses four bits to represent the decimal digits 0 to 9?", {"BCD", "Gray", "ASCII", "Hamming"}, 'A'},

                               {"What is the name of the code that uses four bits to represent 16 values, where only one bit changes between consecutive values?", {"BCD", "Gray", "ASCII", "Hamming"}, 'B'},

                               {"What is the name of the code that uses seven bits to represent 128 characters, such as letters, digits, and symbols?", {"BCD", "Gray", "ASCII", "Hamming"}, 'C'}})}};

// Define the constructor that takes the course name and the questions as parameters
Quiz::Quiz(string course, std::vector<Question> questions) : course(course), questions(questions) {}

// Define the method to display the quiz
void Quiz::display()
{
    int i = 0;
    cout << "Quiz for " << course << endl;
    cout << "---------------------" << endl;
    // Loop over the questions vector and print each question with its options
    for (i; i < questions.size(); i++)
    {
        cout << i + 1 << ". " << questions[i].text << endl;
        // Loop over the options vector and print each option with a letter
        for (int j = 0; j < questions[i].options.size(); j++)
        {
            cout << char('A' + j) << ") " << questions[i].options[j] << endl;
        }
        cout << endl;
        take(i);
        clearScreen();
    }
    cout << "Your score is " << score << " out of " << i << endl;
}

// Define the method to take the quiz
void Quiz::take(int i)
{

    cout << "Enter your answer for question " << i + 1 << ": ";
    char answer;
    cin >> answer;
    // Convert the answer to uppercase
    answer = toupper(answer);
    // Compare the answer with the correct answer and print feedback
    switch (answer)
    {
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
        if (answer == questions[i].answer)
        {
            cout << "Correct! " << questions[i].answer << " is the correct Option" << endl;
            score++;
        }
        else
        {
            cout << "Wrong! The correct answer is " << questions[i].answer << endl;
        }
        break;
    default:
        cout << "Invalid answer!" << endl;
        break;
    }
    cout << endl;
}

// method to get Questions vector
vector<Question> Quiz::getQuestions()
{
    return questions;
}