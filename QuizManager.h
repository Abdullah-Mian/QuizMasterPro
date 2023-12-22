// Include the necessary header files
#include <iostream>
#include <string>
#include <map>

using namespace std;

// Include the header file for the Quiz class
#include "Quiz.h"

// Use header guards to prevent multiple inclusion
#ifndef QUIZMANAGER_H
#define QUIZMANAGER_H

// Declare a class to manage the quizzes for different courses
class QuizManager
{
    map<string, Quiz> quizzes; // A map of quizzes that maps the course names to the Quiz objects
public:
    // Declare the constructor that takes the map of quizzes as a parameter
    QuizManager(map<string, Quiz> quizzes);

    // Declare the method to display the courses
    // void displayCourses();

    // Declare the method to select a course
    Quiz *selectCourse(string SelectedCourse);

    // Declare the method to start the quiz
    void startQuiz(Quiz *quiz);
};

// End the header guard
#endif
