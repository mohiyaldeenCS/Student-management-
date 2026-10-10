# Student Management System

A Windows console application for maintaining student records. The program supports adding, editing, deleting, searching, displaying, and sorting students by ID, name, surname, or grade.

## Technology

- C++
- Visual Studio 2022 / MSVC v143
- Local text-file persistence

## Prerequisites

- Windows 10 or later
- Visual Studio 2022 with the **Desktop development with C++** workload

## Setup and run

1. Clone the repository and open `ConsoleApplication2.sln` in Visual Studio.
2. Configure administrator credentials in the environment. Do not commit real values.

   ```powershell
   $env:STUDENT_ADMIN_USERNAME = "your-user-name"
   $env:STUDENT_ADMIN_PASSWORD = "your-strong-password"
   ```

3. Select `Release` and `x64`, then build and run the solution.

Student records are written to `Student Information.txt` in the working directory. The data file is intentionally ignored because it may contain personal information.

## Structure

- `ConsoleApplication2/ConsoleApplication2.cpp` — menus and student operations
- `ConsoleApplication2/Header.h` — login and masked password input
- `ConsoleApplication2/ConsoleApplication2.vcxproj` — Visual Studio project configuration

## Implemented features

- Administrator login with credentials supplied through environment variables
- Add, update, delete, list, and search student records
- Sort by ID, first name, last name, and grade
- Basic validation for menu choices and student input

## Current limitations

- The application is Windows-specific because it uses MSVC's `conio.h` and Windows console commands.
- Records use a whitespace-delimited text format and are not safe for concurrent writers.
- Phone numbers are stored as integers, so leading zeros are not preserved.

## Verification

Build the `Release|x64` configuration, then manually verify login, adding a student, searching by ID, editing, deleting, sorting an empty file, and restarting the application to confirm persistence.
