#include <iostream>
#include <string>
using namespace std;

int main()
{
    // ADMIN ACCOUNT
    string adminID;
    string adminPassword;

    string questions[5];
    string options[5][4];
    int correctAnswers[5];
    int studentAnswers[5];
    string studentNames[10];
int rollNumbers[10];
string studentPasswords[10];
int studentcount=0;
int choice;
cout<<"==================================\n";
cout<<"        QUIZE APPLICATION\n";
cout<<"==================================\n";
cout<<"\n=======ADMIN REGISTERATION=======\n";
cout<<"Create Admin Id";
cin>>adminId;
cout<<"Create Admin Password: ";
cin>>adminPassword;
cout<<"\nAdmin Account Created Successfully!\n";
cout<<"\n=====================================\n";
cout<<"1.Question Setter Login\n2.Student Register\n3.Student Login\n4.Exit\n";
cout<<"Enter Choice: ";
cin>>choice;
if(choice==1){
string username,password;
cout<<"\n===== ADMIN LOGIN ======\n";
cout<<"Enter Admin ID: ";
cin>>username;
cout<<"Enter Password: ";
cin>>password;
if(username==adminId && password == adminPassword){
cout<<"\nAdmin Login Successful!\n";
for(int i=0;i<5;i++){
cin.ignore();
cout<<"\nEnter Question "<<i+1<<": ";
getline(cin,question[i];
for(int j=0;j<4;j++){
for(int j=0;ij<4;j++{
cout<<"Enter Looption " <<j+1<<": "0;
getline(cin, options[i][j]);
                }

                cout << "Enter Correct Option (1-4): ";
                cin >> correctAnswers[i];
            }

            cout << "\nQuestions Added Successfully!\n";
        }
        else
        {
            cout << "\nInvalid Admin ID or Password!\n";
        }
    }

    // STUDENT REGISTER
    else if (choice == 2)
    {
        cout << "\n====== STUDENT REGISTRATION ======\n";

        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, studentNames[studentCount]);

        cout << "Enter Roll Number: ";
        cin >> rollNumbers[studentCount];

        cout << "Set Password: ";
        cin >> studentPasswords[studentCount];

        cout << "\nStudent Account Created Successfully!\n";

        studentCount++;
    }

    // STUDENT LOGIN
    else if (choice == 3)
    {
        int roll;
        string pass;

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
                cout << "Welcome "
                     << studentNames[i] << endl;

                // QUIZ START
                int score = 0;
                int ans;

                cout << "\n====== QUIZ STARTED ======\n";

                for (int q = 0; q < 5; q++)
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

                    studentAnswers[q] = ans;

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
                     << score << "/5\n";

                float percentage =
                    (score / 5.0) * 100;

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

                // ANALYSIS
                cout << "\n=====================================\n";
                cout << "           QUIZ ANALYSIS\n";
                cout << "=====================================\n";

                for (int q = 0; q < 5; q++)
                {
                    cout << "\nQuestion "
                         << q + 1 << ": "
                         << questions[q]
                         << endl;

                    cout << "Your Answer: "
                         << options[q][studentAnswers[q] - 1]
                         << endl;

                    cout << "Correct Answer: "
                         << options[q][correctAnswers[q] - 1]
                         << endl;

                    if (studentAnswers[q] ==
                        correctAnswers[q])
                    {
                        cout << "Status: Correct\n";
                    }
                    else
                    {
                        cout << "Status: Wrong\n";
                    }
                }
            }
        }

        if (!found)
        {
            cout << "\nInvalid Roll Number or Password!\n";
        }
    }

    // EXIT
    else if (choice == 4)
    {
        cout << "\nThank You!\n";
    }

    else
    {
        cout << "\nInvalid Choice!\n";
    }

    return 0;
}




