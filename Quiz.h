// Include the necessary header files
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Use header guards to prevent multiple inclusion
#ifndef QUIZ_H
#define QUIZ_H

// Define a struct to represent a multiple choice question
struct Question
{
    string text;            // The question text
    vector<string> options; // The options
    char answer;            // The correct answer
};

// Declare a class to represent a quiz for a specific course
class Quiz
{
    string course;              // The course name
    vector<Question> questions; // The questions for the quiz
public:
    // Declare the constructor that takes the course name and the questions as parameters
    Quiz(string course, vector<Question> questions);

    // Declare the method to display the quiz
    void display();

    // Declare the method to take the quiz
    void take();

    // // method to get Questions vector
    // vector<Question> getQuestions();
};

// Declare the map of quizzes
extern map<string, Quiz> quizzes;


// End the header guard
#endif
