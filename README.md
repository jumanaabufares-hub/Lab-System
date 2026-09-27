# Lab-System
A backend lab management system that manages patients, lab technicians, and lab work. The system allows lab technicians to process lab work and keeps track of the lab work associated with patients.

# Files and Descriptions

Entity.h / Entity.cc — Base class that stores the name and ID shared by patients and lab technicians.

LabWork.h / LabWork.cc — Stores information about lab work, including the lab work code, cost, and lab technician ID.

LabWorkList.h / LabWorkList.cc — Data structure used to store and manage LabWork objects.

LabTech.h / LabTech.cc — Inherits from Entity and represents lab technicians who process lab work.

Lab.h / Lab.cc — Manages collections of patients and lab technicians.

Patient.h / Patient.cc — Inherits from Entity and stores information about patients and their required lab work.

Control — Handles user input and controls the program's main operations.

TestControl — Controls the testing program and runs test cases.

View — Handles the display of information to the user.

Tester — Contains functions used to test the program's functionality.

# Compilation and Execution

The program is compiled and linked using a Makefile. The .cc source files are compiled into .o object files, which are then linked together to create the executables.

Run the Main Program
make clean
make a3
./a3
Run the Testing Program
make clean
make a3test
./a3test
Build Both Programs

To compile both the main program and the testing program:

make all
