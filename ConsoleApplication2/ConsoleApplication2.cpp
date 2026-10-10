#include <fstream>
#include <algorithm>
#include "Header.h"

using namespace std;
//count of subjects
const int SIZE = 6;
// names of failes
const char* FILE_NAME = "Student Information.txt";
const char* FILE_TEMP = "Temp file.txt";

// Define the structure for Students
struct Students {
    int id;
    string first_name;
    string last_name;
    int phone_number;
    string major;
    int level;
    int marks[SIZE];
    int total_marks;
    float grade;
};

void start();
bool student_is_found(int student_id);
void editStudent( );
void addStudent(int ,string);
void deleteStudent( );
void displayStudents( );
void searchById( );
void searchByName( );
void searchByLastName( );
void errorInVector();
void displayInformation(const Students& student);
vector<Students> getSortedStudentsById();
void displayAftrSortById(const vector<Students>& students);
vector<Students> getSortedStudentsByGrade();
void displayAftrSortByGrade(const vector<Students>& students);
vector<Students> getSortedStudentsByName();
void displayAftrSortByName(const vector<Students>& students);
vector<Students> getSortedStudentsByLastName();
void displayAftrSortByLastName(const vector<Students>& students);

// Function to validate input for positive numbers
bool checkValue(int value) 
{
    // Check if the input value is invalid (cin.fail()) or negative (value < 0)
    if (cin.fail() || value < 0)
    {
        // Clear the error state of the input stream
        cin.clear();
        // Ignore any remaining characters in the input stream until a newline character '\n'
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");
        system("color 4");
        cout << "\n\n\t\t\t\t You can just enter a positive number!\n\a";
        system("pause");
        system("color E");
        system("cls");
        return false;
    }
    return true;
}

// Function to check ID is Exists 
bool checkIdExists(int id)
{
    Students student;
    //fstream
    fstream file;
    file.open(FILE_NAME, ios::in);
    if (!file)
    {
        system("cls");
        system("color 4");
        cout << "\n\t\t\t\t (!_!) Error opening file (!_!)\n\a" << endl;
        system("pause");
        system("color E");
        system("cls");
        return false;
    }

    while (file >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
    {
        for (int i = 0; i < 6; i++)
        {
            file >> student.marks[i];
        }
        file >> student.total_marks >> student.grade;
        if (id == student.id)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Function to display the introduction screen
void introduction( )
{
    cout << "\n\n\n\n\t\t\t\t(^_^) Welcome " << "(^_^) You have successfully logged in.(^_^)" << endl;
a:  
    system("color 9f");
    cout << "\n\n";
    cout << "\t\t\t\t     +--------------------------------------------+ " << endl;
    cout << "\t\t\t\t     [        Student Management System           ] " << endl;
    cout << "\t\t\t\t   _ [            Dr : Anwar Abo Hadi             ] " << endl;
    cout << "\t\t\t\t  /o)[               Developed by:                ](o\\" << endl;
    cout << "\t\t\t\t / / [          Mohiy Al-Deen Al-Arjali           ] \\ \\" << endl;
    cout << "\t\t\t\t( (_ [   _          ID - 24164266               _ ] _) ) " << endl;
    cout << "\t\t\t\t((\\ \\)+-/o)------------------------------------(o\\-+(/ /))" << endl;
    cout << "\t\t\t\t(\\\\\\ \\_/ /                                      \\ \\_/ ///)" << endl;
    cout << "\t\t\t\t \\      /                                        \\      /" << endl;
    cout << "\t\t\t\t  \\____/                                          \\____/\n" << endl;
    int x;
    cout << "\t\t\t\t\t\t    to Continue press 1 \n";
    cout << "\t\t\t\t\t\t      to Exite press 0\n";
    cout << "\t\t\t\t\t\t      >>_";
    cin >> x;
    if (!checkValue(x))
    {
        goto a;
    }
    if (x == 1)
    {
        system("cls");
        start( );
    }
    else if (x == 0)
        exit(0);
}

// Function to start the student management system
void start()
{
    
   // Students student;
    system("cls");
    while (true)
    {
    repeat:
        system("Color 6");
        cout << "\n\n\n\n\n\n\n";
        cout << "\t\t\t\t****************************************************\n";
        cout << "\t\t\t\t*            [ STUDENT'S SYSTEM ]                  *\n";
        cout << "\t\t\t\t****************************************************\n";
        cout << "\t\t\t\t*   [1]    Add a student record.                   *\n";
        cout << "\t\t\t\t*   [2]    Edit a student record.                  *\n";
        cout << "\t\t\t\t*   [3]    Delete a student record.                *\n";
        cout << "\t\t\t\t*   [4]    Search for a student by ID.             *\n";
        cout << "\t\t\t\t*   [5]    Search for a student by first name.     *\n";
        cout << "\t\t\t\t*   [6]    Search for a student by last name.      *\n";
        cout << "\t\t\t\t*   [7]    Display all students.                   *\n";
        cout << "\t\t\t\t*   [8]    Display students sorting by ID.         *\n";
        cout << "\t\t\t\t*   [9]    Display students sorting by Grade.      *\n";
        cout << "\t\t\t\t*   [10]   Display students sorting by First Name. *\n";
        cout << "\t\t\t\t*   [11]   Display students sorting by Last Name.  *\n";
        cout << "\t\t\t\t*                                                  *\n";
        cout << "\t\t\t\t*   [0]    ->>-------->>> EXIT ------->>>          *\n";
        cout << "\t\t\t\t****************************************************\n";
        cout << "\t\t\t\t\t- Enter any choose you want it, Pleas :";

        int option;
        cin >> option;
        if (!checkValue(option))
        {
            goto repeat;
        }
        if (option == 1)
        {
            addStudent(24160000, "_id");
        }
        else if (option == 2)
        {
            editStudent();
        }
        else
        {
            vector<Students> sortedStudentsById = getSortedStudentsById();
            vector<Students> sortedStudentsByGrade = getSortedStudentsByGrade();
            vector<Students> sortedStudentsByName = getSortedStudentsByName();
            vector<Students> sortedStudentsByLastName = getSortedStudentsByLastName();
            switch (option)
            {
            case 3:
                deleteStudent();
                break;
            case 4:
                searchById();
                break;
            case 5:
                searchByName();
                break;
            case 6:
                searchByLastName();
                break;
            case 7:
                displayStudents();
                break;
            case 8:

                //getSortedStudentsById();
                displayAftrSortById(sortedStudentsById);
                break;
            case 9:
                //getSortedStudentsByGrade();
                displayAftrSortByGrade(sortedStudentsByGrade);
                break;
            case 10:
                //getSortedStudentsByName();
                displayAftrSortByName(sortedStudentsByName);
                break;
            case 11:
                //getSortedStudentsByLastName();
                displayAftrSortByLastName(sortedStudentsByLastName);
                break;
            case 0:
                cout << "\n\n\t\t\t\t[(^_^) THANKS FOR YOU (^_^)]\n\n";
                exit(0);
                break;
            default:
                system("cls");
                system("color 4");
                cout << "\n\t\t\t\t Invalid option.\a" << endl;
                system("pause");
                system("color E");
                system("cls");
            }
            cout << endl;
        }
    }
    return;
}

// Function to convert the first character of a string to uppercase and the rest to lowercase
void toCapital(string& str)
{
    // Check if the string is not empty
    if (!str.empty())
    {
        // Convert the first character to uppercase using toupper()
        str[0] = toupper(str[0]);
        for (int i = 1; i < str.length(); ++i)
        {//al-deen
            if (str[i] == '-')
            {
                str[i + 1] = toupper(str[i + 1]);
            }
            // Convert the rest of the characters to lowercase using tolower()
            else
            {
                str[i] = tolower(str[i]);
            }
        }
    }            

}

// Function to check if a string contains only alphabetic characters
bool isValidString(string& name)
{
    for (char c : name)
    {
        // Check if the character is not alphabetic
        //true//false
        if (!isalpha(c))
        { 
            if (c == ' ' || c == '-' )
            {
                return true;
            }
            return false;
        }
    }
    return true;
}

int getStudentCount() 
{
    Students student;
    int studentCount = 0;
    fstream file;
    file.open(FILE_NAME,ios::in);
    if(file.is_open())
    {
        //seekg  تستخدم للرجوع الى او لتحديد موضع الفراءة 
        file.seekg(0, ios::end);
        // tellg لاسترجاع الموضع الحالي لمؤشر القراءة 
        if (file.tellg() == 0) 
        {
            cout << "File is empty." << endl;
            return 0;
        }
        file.seekg(0, ios::beg);
        while (file >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level) 
        {
            for (int i = 0; i < 6; i++) 
            {
                file >> student.marks[i];
            }
            file >> student.total_marks >> student.grade;
            studentCount++;
        }
        //file.seekg(0, ios::end);
        file.close();
        return studentCount;
    }
    else
    {
        system("cls");
        system("color 4");
        cerr << "\n\t\t\t\t File is not found : \a" << endl;
        system("pause");
        system("color E");
        system("cls");
    }
}

bool checkMajor(const string& major)
{
    string validMajors[] = { "CYS", "CS", "IS", "IT" };

    for (const string& validMajor : validMajors) 
    {
        if (major == validMajor) 
        {
            return true;
        }
    }
    return false;
}

void addStudent(int ID,string edit)
{
    system("cls");
    fstream Student_Info;
    Student_Info.open(FILE_NAME, ios::out | ios::app);
    Students student;
    if (Student_Info.is_open())
    {
        if (edit == "Edit")
        {
            student.id = ID;
        }
        else
        {
            student.id = 24160000;
            int totalStudents = getStudentCount();
            if (totalStudents == 0)
            {
                student.id += 1;
            }
            else if (totalStudents == 1)
            {
                student.id += 2;
            }
            else
            {
                student.id += totalStudents + 1;
            }
            while (checkIdExists(student.id))
            {
                student.id++;
            }
        }
    
        cin.ignore();
F_name:
        cout << " FIRST NAME : ";
        getline(cin, student.first_name);
        
        if (!isValidString(student.first_name))
        {
            cin.clear();
            system("cls");
            system("color 4");
            cout << "\n\t\t\t\t (!_!) Error: Invalid Name (!_!)\n\t\t\t\t Please enter only alphabetical characters.\n\a" << endl;
            system("pause");
            system("color E");
            system("cls");
            goto F_name;
        }
        toCapital(student.first_name);
    l_name:
        cout << " LAST NAME : ";
        getline(cin, student.last_name);
        if (!isValidString(student.last_name))
        {
            cin.clear();
            system("cls");
            system("color 4");
            cout << "\n\t\t\t\t (!_!) Error: Invalid Name (!_!)\n\t\t\t\t Please enter only alphabetical characters.\n\a" << endl;
            system("pause");
            system("color E");
            system("cls");
            goto l_name;
        }
        toCapital(student.last_name);
    n_phon:
        cout << " Phone number : ";
        cin >> student.phone_number;

        if (!checkValue(student.phone_number))
        {
            goto n_phon;
        }
        if (student.phone_number <= 99999999 || student.phone_number > 999999999)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            system("color 4");
            cout << "\n\n\t\t\t\t You can just enter 9 numbers . ]!!\n\n\a";
            system("pause");
            system("color E");
            system("cls");
            goto n_phon;
        }
        cin.ignore();
    M:
        cout << "Enter major  in (CYS or CS or IS or IT) only: ";
        getline(cin, student.major);
        transform(student.major.begin(), student.major.end(), student.major.begin(), ::toupper);
        if (!isValidString(student.major))
        {
            cin.clear();
            system("cls");
            system("color 4");
            cout << "\n\t\t\t\t (!_!) Error: Invalid Major (!_!)\n\t\t\t\t Please enter only alphabetical characters.\n\a" << endl;
            system("pause");
            system("color E");
            system("cls");
            goto M;
        }
        if (!checkMajor(student.major))
        {
            system("cls");
            system("color 4");
            cout << "\n\t\t\t\t (!_!) Error: Invalid Major.(!_!)\n\t\t\t\t You can enter (CYS or CS or IS or IT) majors only.\n\a" << endl;
            system("pause");
            system("color E");
            system("cls");
            goto M;
        }
    back:
        cout << "Enter level (1-4): ";
        cin >> student.level;
        if (!checkValue(student.level))
        {
            goto back;
        }
        if (student.level < 1 || student.level > 4)
        {
            system("cls");
            system("color 4");
            cout << "\n\n\t\t\t\t You can just enter number between 1 and 4 only ]!!\n\n\a";
            system("pause");
            system("color E");
            system("cls");
            goto back;
        }

        cout << "Enter marks for " << SIZE << " subjects:" << endl;
        for (int i = 0; i < SIZE; ++i)
        {
        R:
            cout << "Subject " << (i + 1) << " : ";
            cin >> student.marks[i];
            if (!checkValue(student.marks[i]))
            {
                goto R;
            }
            if (student.marks[i] < 0 || student.marks[i] > 100)
            {
                system("cls");
                system("color 4");
                cout << "\n\n\t\t\t\t You can Entered Mark bettween 0 and 100 \n\n\a";
                system("pause");
                system("color E");
                system("cls");
                goto R;
            }
        }

        student.total_marks = 0;
        for (int i = 0; i < SIZE; ++i)
        {
            student.total_marks += student.marks[i];
        }
        student.grade = static_cast<float> (student.total_marks) / SIZE;
        //student.grade = student.total_marks / SIZE;
        Student_Info << student.id << ' ' << student.first_name << ' '
            << student.last_name << ' ' << student.phone_number << ' '
            << student.major << ' ' << student.level << ' ';
        for (int j = 0; j < SIZE; ++j)
        {
            Student_Info << student.marks[j] << ' ';
        }
        Student_Info << student.total_marks << ' ' << student.grade << "\n";
        Student_Info.close();
        if (edit!="Edit")
        {
            cout << "\n\t\t\t\t (^_^) Add student seccessfully (^_^)" << endl;
        }
        else
        {
            cout << "\n\t\t\t\t (^_^) Edit student seccessfully (^_^)" << endl;
        }
    }
    else
    {
        system("cls");
        system("color 4");
        cerr << "\n\t\t\t\t (!_!) Error in open file (!_!)\n\n\a";
        system("pause");
        system("color E");
        system("cls");
    }
}

void editStudent( )
{
    system("cls");
    Students student;
    fstream student_Info;
    fstream temp_file;
    student_Info.open(FILE_NAME, ios::in);
    temp_file.open(FILE_TEMP, ios::out);
    int id;
D:
    cout << "Enter the ID of the student whose data you want to edit. : ";
    cin >> id;
    if (!checkValue(id))
    {
        goto D;
    }
    if (student_is_found(id))
    {
        string is_Edit = "Edit";
        if (temp_file.is_open())
        {
            while (student_Info >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
            {
                for (int i = 0; i < 6; i++)
                {
                    student_Info >> student.marks[i];
                }
                student_Info >> student.total_marks >> student.grade;
                if (id != student.id)
                {
                    temp_file << student.id << ' ' << student.first_name << ' '
                        << student.last_name << ' ' << student.phone_number << ' '
                        << student.major << ' ' << student.level << ' ';
                    for (int j = 0; j < SIZE; ++j)
                    {
                        temp_file << student.marks[j] << ' ';
                    }
                    temp_file << student.total_marks << ' ' << student.grade << "\n";
                }
            }
            temp_file.close();
            student_Info.close();
        }
        else
        {
            cerr << "\n\t\t\t\t (!_!) Error in open the file. (!_!)" << endl;
        }
        fstream temp;
        fstream stud_Info;
        stud_Info.open(FILE_NAME, ios::out);
        temp.open(FILE_TEMP, ios::in);
        
        while (temp >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
        {
            for (int i = 0; i < 6; i++)
            {
                temp >> student.marks[i];
            }
            temp >> student.total_marks >> student.grade;
            //write to Student Information file from  Temp file
            stud_Info << student.id << ' ' << student.first_name << ' '
                << student.last_name << ' ' << student.phone_number << ' '
                << student.major << ' ' << student.level << ' ';
            for (int j = 0; j < SIZE; ++j)
            {
                stud_Info << student.marks[j] << ' ';
            }
            stud_Info << student.total_marks << ' ' << student.grade << "\n";
        }

        stud_Info.close();
        temp.close();
        addStudent(id,"Edit");
    }
    else
    {
        system("color 4");
        cerr << "\n\t\t\t\t This student not found \n";
        system("pause");
        system("color E");
        system("cls");
    }
    return;
}

bool student_is_found(int student_id)
{
    Students student;
    fstream student_Info;
    student_Info.open(FILE_NAME, ios::in);
    if (student_Info.is_open())
    {
        while (student_Info >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
        {
            for (int i = 0; i < 6; i++)
            {
                student_Info >> student.marks[i];
            }
            student_Info >> student.total_marks >> student.grade;
            if (student_id == student.id)
            {
                return true;
            }
        }
        student_Info.close();
    }
    else
    {
        cerr << "\n\t\t\t\t The file is not found \n";
    }
    return false;
}

bool student_is_found_name(string first_name)
{
    Students student;
    bool flag = false;
    fstream student_Info;
    student_Info.open(FILE_NAME, ios::in);
    if (student_Info.is_open())
    {
        while (student_Info >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
        {
            for (int i = 0; i < 6; i++)
            {
                student_Info >> student.marks[i];
            }
            student_Info >> student.total_marks >> student.grade;
            if (first_name == student.first_name)
            {
                flag = true;
                return flag;
            }
        }
        student_Info.close();
    }
    else
    {
        cerr << "\n\t\t\t\t The file is not found \n";
    }
    return flag;
}

bool student_is_found_last_name(string last_name)
{
    Students student;
    bool flag = false;
    fstream student_Info;
    student_Info.open(FILE_NAME, ios::in);
    if (student_Info.is_open())
    {
        while (student_Info >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
        {
            for (int i = 0; i < 6; i++)
            {
                student_Info >> student.marks[i];
            }
            student_Info >> student.total_marks >> student.grade;
            if (last_name == student.last_name)
            {
                flag = true;
                return flag;
            }
        }
        student_Info.close();
    }
    else
    {
        cerr << "\n\t\t\t\t The file is not found \n";
    }
    return flag;
}

void deleteStudent( )
{
    system("cls");
    Students student;
    fstream student_Info;
    fstream temp_file;
    student_Info.open(FILE_NAME, ios::in);
    temp_file.open(FILE_TEMP, ios::out);
    int id;
D:
    cout << "Enter the ID of the student whose data you want to delete it . : ";
    cin >> id;
    if (!checkValue(id))
    {
        goto D;
    }
    if (student_is_found(id))
    {
        if (temp_file.is_open())
        {
            while (student_Info >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
            {
                for (int i = 0; i < 6; i++)
                {
                    student_Info >> student.marks[i];
                }
                student_Info >> student.total_marks >> student.grade;
                if (id != student.id)
                {
                    temp_file << student.id << ' ' << student.first_name << ' '
                        << student.last_name << ' ' << student.phone_number << ' '
                        << student.major << ' ' << student.level << ' ';
                    for (int j = 0; j < SIZE; ++j)
                    {
                        temp_file << student.marks[j] << ' ';
                    }
                    temp_file << student.total_marks << ' ' << student.grade << "\n";
                }
                else
                {
                    repeat:
                    int x;
                    system("CLS");
                    cout << "\n\t\t[ Are you suer to delete " << student.first_name << ' ' << student.last_name << " information ]\n\a";
                    cout << "\t\t\t\t\t\t     to delete press 1 \n";
                    cout << "\t\t\t\t\t\t     to cancel press 0\n";
                    cin >> x;
                    if (!checkValue(x))
                    {
                        goto repeat;
                    }
                    if (x == 1)
                    {
                        system("cls");
                        cout << " Delete student " << student.first_name << " seccessfully \n\a";
                    }
                    else
                    {
                        start();
                    } 
                }
            }
            temp_file.close();
            student_Info.close();
        }
        else
        {
            cerr << "\n\t\t\t\t (!_!) Error in open the file.(!_!)" << endl;
        } 
        fstream temp;
        fstream stud_Info;
        stud_Info.open(FILE_NAME, ios::out);
        temp.open(FILE_TEMP, ios::in);
        while (temp >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
        {
            for (int i = 0; i < 6; i++)
            {
                temp >> student.marks[i];
            }
            temp >> student.total_marks >> student.grade;
            //write to Student Information file from  Temp file
            stud_Info << student.id << ' ' << student.first_name << ' '
                << student.last_name << ' ' << student.phone_number << ' '
                << student.major << ' ' << student.level << ' ';
            for (int j = 0; j < SIZE; ++j)
            {
                stud_Info << student.marks[j] << ' ';
            }
            stud_Info << student.total_marks << ' ' << student.grade << "\n";
        }

        stud_Info.close();
        temp.close();
        cout << "\n\t\t\t\t (^_^) Student record delete successfully. (^_^)" << endl;
    }
    else
    {
        cerr << "\n\t\t\t\t This student not found \n";
    }
    return;
}

void displayStudents( )
{
    system("cls");
    Students student;
    fstream student_Info;
    student_Info.open(FILE_NAME, ios::in);
    if (student_Info.is_open())
    {
        int foundStudent = getStudentCount();
        if (foundStudent == 0)
        {
            cout << " File is empty \n\a";
            cout << " Do you want add student if you want add student press 1 to back Main Menu press any Key \n\a";
            int option;
            cin >> option;
            if (option == 1)
            {
                addStudent(24160000, "_id");
            }
            else
            {
                return;
            }
        }
        
        cout << "\n\n\n\t\t\t\t**********************************************\n";
        cout << "\t\t\t\t\t     [ALL STUDENTS ]\n" ;
        cout << "\t\t\t\t**********************************************\n";
         while (student_Info >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
         {
                for (int i = 0; i < 6; i++)
                {
                    student_Info >> student.marks[i];
                }
                student_Info >> student.total_marks >> student.grade;

            cout << "\t\t\t\t\t| ID \t\t: " << student.id << endl;
            cout << "\t\t\t\t\t| FIRST NAME\t: " << student.first_name << endl;
            cout << "\t\t\t\t\t| LAST NAME\t: " << student.last_name << endl;
            cout << "\t\t\t\t\t| PHONE NUMBER\t: " << student.phone_number << endl;
            cout << "\t\t\t\t\t| MAJOR \t: " << student.major << endl;
            cout << "\t\t\t\t\t| LEVEL \t: " << student.level << endl;
            cout << "\t\t\t\t\t| TOTAL MARK \t: " << student.total_marks << endl;
            cout << "\t\t\t\t\t| GRADE \t: " << student.grade << endl;
            cout << "\n\n\t\t\t\t**********************************************\n\n";
         }
         student_Info.close();
         system("pause");
         system("cls");
    }
    else
    {
        cerr << "\n\t\t\t\t File is not found \n";
    }
}

void searchById( )
{
    system("cls");
    Students student;
    fstream student_Info;
    student_Info.open(FILE_NAME, ios::in);
    int id;
D:
    cout << "Enter the ID of the student whose data you want to search it . : ";
    cin >> id;
    if (!checkValue(id))
    {
        goto D;
    }
    if (student_Info.is_open())
    {
        if (student_is_found(id))
        {
            while (student_Info >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
            {
                for (int i = 0; i < 6; i++)
                {
                    student_Info >> student.marks[i];
                }
                student_Info >> student.total_marks >> student.grade;
                if (id == student.id)
                {
                    cout << "\n\n\n\t\t\t\t**********************************************\n";
                    cout << "\t\t\t\t\t     [ STUDENT INFORMATION ]\n";
                    cout << "\t\t\t\t**********************************************\n";
                    displayInformation(student);
                    break;
                }
            }
            student_Info.close();
            system("pause");
            system("CLS");
        }
        else
        {
            system("color 4");
            cerr << "\n\t\t\t\t The student is not found \n";
            system("pause");
            system("color e");
        }
    }
    else
    {
        cerr << "\n\t\t\t\t File is not found \n";
    }   
}

void searchByName( )
{
    system("cls");
    Students student;
    fstream student_Info;
    student_Info.open(FILE_NAME, ios::in);
    int id;
    string first_name;
D:
    cout << "Enter the first name of the student whose data you want to search it . : ";
    cin.ignore();
    getline(cin, first_name);
   
    if (!isValidString(first_name))
    {
        cin.clear();
        cout << "\n\t\t\t\t(!_!) Error: Invalid Name.(!_!) Please enter only alphabetical characters." << endl;
        goto D;
    }
    toCapital(first_name);
    if (student_Info.is_open())
    {
        if (student_is_found_name(first_name))
        {
            while (student_Info >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
            {
                for (int i = 0; i < 6; i++)
                {
                    student_Info >> student.marks[i];
                }
                student_Info >> student.total_marks >> student.grade;
                if (first_name == student.first_name)
                {
                    cout << "\n\n\n\t\t\t\t**********************************************\n";
                    cout << "\t\t\t\t\t     [ STUDENT INFORMATION ]\n";
                    cout << "\t\t\t\t**********************************************\n";
                    displayInformation(student);
                    break;
                }
            }
            student_Info.close();
            system("pause");
            system("CLS");
        }
        else
        {
            cerr << "\n\t\t\t\t The student is not found \n";
        }
    }
    else
    {
        cerr << "\n\t\t\t\t File is not found \n";
    }
}

void searchByLastName( )
{
    system("cls");
    Students student;
    fstream student_Info;
    student_Info.open(FILE_NAME, ios::in);
    int id;
    string last_name;
D:
    cout << "Enter the first name of the student whose data you want to search it . : ";
    cin.ignore();
    getline(cin, last_name);
    toCapital(last_name);
    if (!isValidString(last_name))
    {
        cin.clear();
        cout << "\n\t\t\t\t(!_!) Error: Invalid Name.(!_!) Please enter only alphabetical characters." << endl;
        goto D;
    }
    if (student_Info.is_open())
    {
        if (student_is_found_last_name(last_name))
        {
            while (student_Info >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
            {
                for (int i = 0; i < 6; i++)
                {
                    student_Info >> student.marks[i];
                }
                student_Info >> student.total_marks >> student.grade;
                if (last_name == student.last_name)
                {
                    cout << "\n\n\n\t\t\t\t**********************************************\n";
                    cout << "\t\t\t\t\t     [ STUDENT INFORMATION ]\n";
                    cout << "\t\t\t\t**********************************************\n";
                    displayInformation(student);
                    break;
                }
            }
            student_Info.close();
            system("pause");
            system("CLS");
        }
        else
        {
            cerr << "\n\t\t\t\t The student is not found \n";
        }
    }
    else
    {
        cerr << "\n\t\t\t\t File is not found \n";
    }
}

int main( )
{
    //start();
   getUserName();
    introduction();
    return 0;
}

vector<Students> getSortedStudentsById() 
{
    vector<Students> studentList;
    ifstream student_Info(FILE_NAME);
    if (student_Info.is_open()) 
    {
        Students student;

        while (student_Info >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level) 
        {
            for (int i = 0; i < 6; i++) 
            {
                student_Info >> student.marks[i];
            }
            student_Info >> student.total_marks >> student.grade;
            studentList.push_back(student);
        }

        student_Info.close();

        if (studentList.empty()) 
        {
            errorInVector();
        }
        else 
        {
            for (size_t i = 0; i + 1 < studentList.size(); ++i) 
            {
                for (size_t j = 0; j + 1 < studentList.size() - i; ++j)
                {
                    if (studentList[j].id > studentList[j + 1].id)
                    {
                        swap(studentList[j], studentList[j + 1]);
                    }
                }
            }
        }
    }
    else
    {
        cerr << "File is not found." << endl;
    }

    return studentList;
}

void displayAftrSortById(const vector<Students>& students)
{
    system("cls");
    if (students.empty()) 
    {
        cout << "(!_!) Not found students (!_!)." << endl;
    }
    else
    {
        cout << "\n\n\n\t\t\t\t**********************************************\n";
        cout << "\t\t\t\t     [ ALL STUDENTS AFTER SORT BY ID ]\n";
        cout << "\t\t\t\t**********************************************\n";

        for (const auto& student : students)
        {
            displayInformation(student);
        }
    }
    system("pause");
    system("cls");
}

vector<Students> getSortedStudentsByGrade()
{
    //فيكتور لتخزين بيانات الطلاب لفرزها وارجاعها ليتم عرضها
    vector<Students> studentList;

    ifstream student_Info(FILE_NAME);
    if (student_Info.is_open())
    {
        Students student;

        while (student_Info >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
        {
            for (int i = 0; i < 6; i++)
            {
                student_Info >> student.marks[i];
            }
            student_Info >> student.total_marks >> student.grade;
            // نضيف بيانات الطلاب الى الفيكتور
            studentList.push_back(student);
        }

        student_Info.close();
        if (studentList.empty())
        {
            // استدعاء دالة لعرض الاخطاء في حال كان الفيكتور فارغ
            errorInVector();
        }
        // خوارزمية الترتيب  
        for (size_t i = 0; i + 1 < studentList.size(); ++i)
        {
            for (size_t j = 0; j + 1 < studentList.size() - i; ++j)
            {
                if (studentList[j].grade < studentList[j + 1].grade)
                {
                    swap(studentList[j], studentList[j + 1]);
                }
            }
        }
    }
    else
    {
        cerr << "File is not found\n";
    }

    return studentList;
}

void displayAftrSortByGrade(const vector<Students>& students)
{
    system("cls");
    if (students.empty())
    {
        cout << "Not found students ." << endl;
    }
    else
    {
        cout << "\n\n\n\t\t\t\t**********************************************\n";
        cout << "\t\t\t\t     [ ALL STUDENTS AFTER SORT BY GRADE ]\n";
        cout << "\t\t\t\t**********************************************\n";

        for (const auto& student : students)
        {
            displayInformation(student);
        }
    }
    system("pause");
    system("cls");
}

vector<Students> getSortedStudentsByName()
{
    vector<Students> studentList;

    ifstream student_Info(FILE_NAME);
    if (student_Info.is_open())
    {
        Students student;

        while (student_Info >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
        {
            for (int i = 0; i < 6; i++)
            {
                student_Info >> student.marks[i];
            }
            student_Info >> student.total_marks >> student.grade;
            studentList.push_back(student);
        }

        student_Info.close();
        if (studentList.empty())
        {
            errorInVector();
        }
        for (size_t i = 0; i + 1 < studentList.size(); ++i)
        {
            for (size_t j = 0; j + 1 < studentList.size() - i; ++j)
            {
                if (studentList[j].first_name > studentList[j + 1].first_name)
                {
                    swap(studentList[j], studentList[j + 1]);
                }
            }
        }

    }
    else
    {
        cerr << "File is not found\n";
    }

    return studentList;
}

void displayAftrSortByName(const vector<Students>& students)
{
    system("cls");
    if (students.empty())
    {
        cout << "Not found students ." << endl;
    }
    else
    {
        cout << "\n\n\n\t\t\t\t**********************************************\n";
        cout << "\t\t\t\t     [ ALL STUDENTS AFTER SORT BY NAME ]\n";
        cout << "\t\t\t\t**********************************************\n";

        for (const auto& student : students)
        {
            displayInformation(student);
        }
    }
    system("pause");
    system("cls");
}

vector<Students> getSortedStudentsByLastName()
{
    system("cls");
    vector<Students> studentList;

    ifstream student_Info(FILE_NAME);
    if (student_Info.is_open())
    {
        Students student;
        while (student_Info >> student.id >> student.first_name >> student.last_name >> student.phone_number >> student.major >> student.level)
        {
            for (int i = 0; i < 6; i++)
            {
                student_Info >> student.marks[i];
            }
            student_Info >> student.total_marks >> student.grade;
            studentList.push_back(student);
        }

        student_Info.close();
        if (studentList.empty())
        {
            errorInVector();
        }

        for (size_t i = 0; i + 1 < studentList.size(); ++i)
        {
            for (size_t j = 0; j + 1 < studentList.size() - i; ++j)
            {
                if (studentList[j].last_name > studentList[j + 1].last_name)
                {
                    swap(studentList[j], studentList[j + 1]);
                }
            }
        }
    }
    else
    {
        system("color 4");
        cerr << "File is not found\n";
        system("color e");
    }

    return studentList;
    system("pause");
    system("cls");
}

void displayAftrSortByLastName(const vector<Students>& students)
{
    system("cls");
    if (students.empty())
    {
        cout << "(!_!) Not found students (!_!)." << endl;
    }
    else
    {
        cout << "\n\n\n\t\t\t\t**********************************************\n";
        cout << "\t\t\t\t     [ ALL STUDENTS AFTER SORT BY NAME ]\n";
        cout << "\t\t\t\t**********************************************\n";

        for (const auto& student : students)
        {
            displayInformation(student);
        }
    }
    system("pause");
    system("cls");
}

void displayInformation(const Students& student)
{
    //system("cls");
    cout << "\t\t\t\t\t| ID \t\t\t: " << student.id << endl;
    cout << "\t\t\t\t\t| FIRST NAME\t\t: " << student.first_name << endl;
    cout << "\t\t\t\t\t| LAST NAME\t\t: " << student.last_name << endl;
    cout << "\t\t\t\t\t| PHONE NUMBER\t\t: " << student.phone_number << endl;
    cout << "\t\t\t\t\t| MAJOR \t\t: " << student.major << endl;
    cout << "\t\t\t\t\t| LEVEL \t\t: " << student.level << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\t\t\t\t\t| MARK IN SUBJECT " << i + 1 << " = \t: " << student.marks[i] << endl;

    }
    cout << "\t\t\t\t\t| TOTAL MARK \t\t: " << student.total_marks << endl;
    cout << "\t\t\t\t\t| GRADE \t\t: " << student.grade << endl;
    cout << "\n\n\t\t\t\t**********************************************\n\n";
}

void errorInVector()
{
    Back:
        cerr << "The file is empty." << endl;
        cerr << " Not found any student. Do you want add student *_* "
            "\n\t\t\t\t to add student Enter 1 to exit enter 0\n";
        int choose;
        cin >> choose;
        if (!checkValue(choose))
        {
            goto Back;
        }
        if (choose == 1)
        {
            cout << " Enter student Information \n";
            addStudent(24160000, "_id");
        }
        else
        {
            cout << " \n\t\t\t(^_^)(^_^) Thank you for use our system (^_^)(^_^)\n";
            exit(0);
        }
}
  
