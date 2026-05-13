#include <iostream>
#include <string>
using namespace std;

int main()
{
    // ADMIN STORAGE
    string adminID;
    string adminPassword;

    bool adminCreated = false;

    // QUIZ CODE
    string quizCode;

    // QUESTION STORAGE
    string questions[100];
    string options[100][4];
    int correctAnswers[100];

    int totalQuestions = 0;

    // STUDENT STORAGE
    string studentNames[50];
    int rollNumbers[50];
    string studentPasswords[50];

    int studentCount = 0;

    int choice;

    cout << "=====================================\n";
    cout << "         QUIZ APPLICATION\n";
    cout << "=====================================\n";

    cout << "1. Admin Registration\n";
    cout << "2. Admin Login\n";
    cout << "3. Student Register\n";
    cout << "4. Student Login\n";
    cout << "5. Exit\n";

    cout << "Enter Choice: ";
    cin >> choice;

    // ADMIN REGISTRATION
    if (choice == 1)
    {
        cout << "\n====== ADMIN REGISTRATION ======\n";

        cout << "Create Admin ID: ";
        cin >> adminID;

        // PASSWORD LOOP
        while (true)
        {
            cout << "Create Password (Max 6 Characters): ";
            cin >> adminPassword;

            if (adminPassword.length() <= 6)
            {
                break;
            }
            else
            {
                cout << "\nPassword exceeded limit!\n";
                cout << "Please Enter Password Again.\n\n";
            }
        }

        adminCreated = true;

        cout << "\nAdmin Account Created Successfully!\n";
    }

    // ADMIN LOGIN
    else if (choice == 2)
    {
        if (adminCreated == false)
        {
            cout << "\nPlease Create Admin Account First!\n";
            return 0;
        }

        string username, password;

        cout << "\n====== ADMIN LOGIN ======\n";

        cout << "Enter Admin ID: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        // LOGIN CHECK
        if (username == adminID &&
            password == adminPassword)
        {
            cout << "\nAdmin Login Successful!\n";

            // CREATE QUIZ CODE
            cout << "\nCreate Quiz Code: ";
            cin >> quizCode;

            cout << "\nEnter Number of Questions: ";
            cin >> totalQuestions;

            cin.ignore();

            // ADD QUESTIONS
            for (int i = 0; i < totalQuestions; i++)
            {
                cout << "\nEnter Question "
                     << i + 1 << ": ";

                getline(cin, questions[i]);

                // OPTIONS
                for (int j = 0; j < 4; j++)
                {
                    cout << "Enter Option "
                         << j + 1 << ": ";

                    getline(cin, options[i][j]);
                }

                cout << "Enter Correct Option (1-4): ";
                cin >> correctAnswers[i];

                cin.ignore();
            }

            cout << "\nQuestions Added Successfully!\n";
            cout << "Quiz Code Created: "
                 << quizCode << endl;
        }
        else
        {
            cout << "\nInvalid Admin ID or Password!\n";
        }
    }

    // STUDENT REGISTER
    else if (choice == 3)
    {
        cout << "\n====== STUDENT REGISTRATION ======\n";

        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, studentNames[studentCount]);

        cout << "Enter Roll Number: ";
        cin >> rollNumbers[studentCount];

        // PASSWORD LOOP
        while (true)
        {
            cout << "Set Password (Max 6 Characters): ";
            cin >> studentPasswords[studentCount];

            if (studentPasswords[studentCount].length() <= 6)
            {
                break;
            }
            else
            {
                cout << "\nPassword exceeded limit!\n";
                cout << "Please Enter Password Again.\n\n";
            }
        }

        cout << "\nStudent Account Created Successfully!\n";

        studentCount++;
    }

    // STUDENT LOGIN
    else if (choice == 4)
    {
        int roll;
        string pass;
        string enteredQuizCode;

        bool found = false;

        cout << "\n====== STUDENT LOGIN ======\n";

        cout << "Enter Roll Number: ";
        cin >> roll;

        cout << "Enter Password: ";
        cin >> pass;

        // LOGIN CHECK
        for (int i = 0; i < studentCount; i++)
        {
            if (roll == rollNumbers[i] &&
                pass == studentPasswords[i])
            {
                found = true;

                cout << "\nLogin Successful!\n";

                // QUIZ CODE CHECK
                cout << "\nEnter Quiz Code: ";
                cin >> enteredQuizCode;

                if (enteredQuizCode != quizCode)
                {
                    cout << "\nInvalid Quiz Code!\n";
                    return 0;
                }

                cout << "\nQuiz Code Verified!\n";

                int score = 0;
                int ans;

                cout << "\n====== QUIZ STARTED ======\n";

                // DISPLAY QUESTIONS
                for (int q = 0; q < totalQuestions; q++)
                {
                    cout << "\nQuestion "
                         << q + 1 << ": "
                         << questions[q] << endl;

                    for (int j = 0; j < 4; j++)
                    {
                        cout << j + 1 << ". "
                             << options[q][j]
                             << endl;
                    }

                    cout << "Enter Your Answer: ";
                    cin >> ans;

                    if (ans == correctAnswers[q])
                    {
                        cout << "Correct Answer!\n";
                        score++;
                    }
                    else
                    {
                        cout << "Wrong Answer!\n";
                    }
                }

                // RESULT
                cout << "\n=====================================\n";
                cout << "             QUIZ RESULT\n";
                cout << "=====================================\n";

                cout << "Student Name: "
                     << studentNames[i] << endl;

                cout << "Score: "
                     << score << "/"
                     << totalQuestions << endl;

                float percentage =
                    (score * 100.0) / totalQuestions;

                cout << "Percentage: "
                     << percentage << "%\n";

                if (percentage >= 50)
                {
                    cout << "Result: PASS\n";
                }
                else
                {
                    cout << "Result: FAIL\n";
                }
            }
        }

        if (!found)
        {
            cout << "\nInvalid Roll Number or Password!\n";
        }
    }

    // EXIT
    else if (choice == 5)
    {
        cout << "\nThank You!\n";
    }

    else
    {
        cout << "\nInvalid Choice!\n";
    }

    return 0;
}
