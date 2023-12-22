// Include the header file for the QuizManager class
#include "QuizManager.h"

using namespace std;

// Define the constructor that takes the map of quizzes as a parameter
QuizManager::QuizManager(map<string, Quiz> quizzes) : quizzes(quizzes) {}

// Define the method to display the courses
// void QuizManager::displayCourses()
// {
//     cout << "Available courses: " << endl;
//     // Loop over the map of quizzes and print the course names
//     for (auto &pair : quizzes)
//     {
//         cout << pair.first << endl;
//     }
//     cout << endl;
// }

// Define the method to select a course
Quiz *QuizManager::selectCourse(string selectedCourse)
{
    cout << "selectCourse Called!" << endl;
    string course = selectedCourse;
    // Use the map's find method to check if the course name exists in the map
    auto it = quizzes.find(course);
    if (it != quizzes.end())
    {
        // Return the Quiz object
        return &(it->second);
    }
    else
    {
        // Print an error message and return nullptr
        cout << "Course not found!" << endl;
        return nullptr;
    }
}

// Define the method to start the quiz
void QuizManager::startQuiz(Quiz *quiz)
{
    // Check if the quiz is not nullptr
    if (quiz != nullptr)
    {   
        // int index = 0;
        // Call the quiz's display and take methods
        quiz->display();
        quiz->take();
        // index = quiz->getQuestions().size();
    }
}
