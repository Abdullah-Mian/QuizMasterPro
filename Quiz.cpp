// Include the header file for the Quiz class
#include "Quiz.h"

using namespace std;

// Define the map of quizzes
map<string, Quiz> quizzes = {
    {"CS 101", Quiz("CS 101", {{"What is the output of the following C++ code?\n\n#include <iostream>\nusing namespace std;\n\nint main() {\n    int x = 10;\n    int y = 20;\n    cout << x + y << endl;\n    return 0;\n}\n", {"10", "20", "30", "40"}, 'C'},

                               {"What is the name of the data structure that stores elements in a linear order and allows insertion and deletion at both ends?", {"Stack", "Queue", "Deque", "List"}, 'C'}})},

    {"CS 201", Quiz("CS 201", {{"What is the output of the following C++ code?\n\n#include <iostream>\nusing namespace std;\n\nint main() {\n    int x = 10;\n    int y = 20;\n    cout << x + y << endl;\n    return 0;\n}\n", {"10", "20", "30", "40"}, 'C'},

                               {"What is the name of the data structure that stores elements in a linear order and allows insertion and deletion at both ends?", {"Stack", "Queue", "Deque", "List"}, 'C'}})},

    {"SE 101", Quiz("SE 101", {{"What is the name of the software development process that consists of four phases: inception, elaboration, construction, and transition?", {"Waterfall", "Agile", "Spiral", "Rational Unified Process"}, 'D'},

                               {"What is the name of the programming paradigm that is based on the concept of objects that have attributes and methods?", {"Procedural", "Functional", "Object-Oriented", "Logic"}, 'C'}})},

    {"SE 201", Quiz("SE 201", {{"What is the name of the software development process that consists of four phases: inception, elaboration, construction, and transition?", {"Waterfall", "Agile", "Spiral", "Rational Unified Process"}, 'D'},

                               {"What is the name of the programming paradigm that is based on the concept of objects that have attributes and methods?", {"Procedural", "Functional", "Object-Oriented", "Logic"}, 'C'}})},

    {"CE 201", Quiz("CE 201", {{"What is the name of the device that converts digital signals to analog signals and vice versa?", {"Modem", "Router", "Switch", "Hub"}, 'A'},

                               {"What is the name of the system that consists of hardware and software that controls the execution of computer programs and provides services for the computer applications?", {"Operating System", "Database System", "Network System", "Embedded System"}, 'A'}})},

    {"CE 415", Quiz("CE 415", {{"What is the name of the device that converts digital signals to analog signals and vice versa?", {"Modem", "Router", "Switch", "Hub"}, 'A'},

                               {"What is the name of the system that consists of hardware and software that controls the execution of computer programs and provides services for the computer applications?", {"Operating System", "Database System", "Network System", "Embedded System"}, 'A'}})},

    {"CHE 101", Quiz("CHE 101", {{"What is the name of the law that states that the total mass of the reactants is equal to the total mass of the products in a chemical reaction?", {"Boyle's Law", "Charles' Law", "Avogadro's Law", "Law of Conservation of Mass"}, 'D'},

                                 {"What is the name of the process that separates a mixture of liquids based on their boiling points?", {"Distillation", "Filtration", "Crystallization", "Chromatography"}, 'A'}})},

    {"CHE 201", Quiz("CHE 201", {{"What is the name of the law that states that the total mass of the reactants is equal to the total mass of the products in a chemical reaction?", {"Boyle's Law", "Charles' Law", "Avogadro's Law", "Law of Conservation of Mass"}, 'D'},

                                 {"What is the name of the process that separates a mixture of liquids based on their boiling points?", {"Distillation", "Filtration", "Crystallization", "Chromatography"}, 'A'}})},

    {"EE 101", Quiz("EE 101", {{"What is the unit of electric current?", {"Volt", "Ohm", "Ampere", "Watt"}, 'C'},

                               {"What is the name of the circuit element that opposes the change in current?", {"Resistor", "Capacitor", "Inductor", "Diode"}, 'C'}})},

    {"EE 204", Quiz("EE 204", {{"What is the unit of electric current?", {"Volt", "Ohm", "Ampere", "Watt"}, 'C'},

                               {"What is the name of the circuit element that opposes the change in current?", {"Resistor", "Capacitor", "Inductor", "Diode"}, 'C'}})}};

// Define the constructor that takes the course name and the questions as parameters
Quiz::Quiz(string course, std::vector<Question> questions) : course(course), questions(questions) {}

// Define the method to display the quiz
void Quiz::display()
{
    cout << "Quiz for " << course << endl;
    cout << "---------------------" << endl;
    // Loop over the questions vector and print each question with its options
    for (int i = 0; i < questions.size(); i++)
    {
        cout << i + 1 << ". " << questions[i].text << endl;
        // Loop over the options vector and print each option with a letter
        for (int j = 0; j < questions[i].options.size(); j++)
        {
            cout << char('A' + j) << ") " << questions[i].options[j] << endl;
        }
        cout << endl;
    }
}

// Define the method to take the quiz
void Quiz::take()
{
    int score = 0; // Variable to keep track of the score
    // Loop over the questions vector and prompt the user to enter their answer
    for (int i = 0; i < questions.size(); i++)
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
                cout << "Correct!" << endl;
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
    // Print the score
    cout << "Your score is " << score << " out of " << questions.size() << endl;
}

// // method to get Questions vector
// vector<Question> Quiz::getQuestions()
// {
//     return questions;
// }