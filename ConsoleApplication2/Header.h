#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
using namespace std;

int check_time = 1;
string password;
string user_name;
string ReadPassword();

string ReadEnvironmentVariable(const char* name)
{
    char* value = nullptr;
    size_t length = 0;
    if (_dupenv_s(&value, &length, name) != 0 || value == nullptr)
    {
        free(value);
        return "";
    }

    string result(value);
    free(value);
    return result;
}

void getUserName()
{
    const string configuredUserName = ReadEnvironmentVariable("STUDENT_ADMIN_USERNAME");
    const string configuredPassword = ReadEnvironmentVariable("STUDENT_ADMIN_PASSWORD");
    if (configuredUserName.empty() || configuredPassword.empty())
    {
        cerr << "Set STUDENT_ADMIN_USERNAME and STUDENT_ADMIN_PASSWORD before starting the application.\n";
        exit(1);
    }

    system("cls");
    system("color e");
    cout << "\n\n\n\n\n\t\t\t\t\t****************************************\n"
        "\t\t\t\t\t *\tLog in\t\t\t    *\n"
        "\t\t\t\t\t****************************************" << endl;
    cout << "\t\t\t\t\t\t Enter username: ";
    getline(cin, user_name);
    bool usernameMatch = user_name == configuredUserName;
    while (!usernameMatch)
    {
        if (check_time == 5)
        {
            cout << "OPPs, Wrong username\nToo many attempts..";
            exit(0);
        }
        cout << "\t\t\t\t\t\t Wrong username. Try again: ";
        getline(cin, user_name);
        usernameMatch = user_name == configuredUserName;
        check_time++;
    }
    cout << "\t\t\t\t\t\t Enter Password: ";
    password = ReadPassword();
    check_time = 1;
    bool passwordMatch = password == configuredPassword;
    while (!passwordMatch)
    {
        if (check_time == 5)
        {
            cout << "Wrong Password\nToo many attempts. Try again.";
            exit(0);
        }
        cout << "\t\t\t\t\t\t Wrong Password. Try again: ";
        password = ReadPassword();
        passwordMatch = password == configuredPassword;
        check_time++;
    }
    system("cls");
}

string ReadPassword()
{
    string password = "";
    char ch;
    while ((ch = _getch()) != '\r')
    {
        if (ch == '\b')
        {
            if (password.length() > 0)
            {
                password.pop_back();
                cout << "\b \b";
            }
        } 
        else
        {
            password += ch;
            cout << "*";
        }
    }
    cout << endl;
    return password;
}
   
