#ifndef STEPS_H
#define STEPS_H

#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include "analytics.h"

using namespace std;

class Step {
public:
    Step();  // Constructor declaration
    virtual bool step(int step_count) = 0;  // Pure virtual function to be overridden by derived classes
};

// Define the TitleStep class, which is derived from the Step class
class TitleStep : public Step {
private:
    string title;  // Variable to store the title
    string subtitle;  // Variable to store the subtitle
public:
    bool step(int step_count);  // Function to perform the step
    string getTitle() { return title; }  // Getter for the title
    string getSubtitle() { return subtitle; }  // Getter for the subtitle
};

// TextStep class, derived from Step class
class TextStep : public Step {  
private:
    string text;  // Variable to store the text of the step
    string copy;  // Variable to store a copy of the text
public:
    bool step(int step_count);  // Function to perform the step
    string getText() { return text; }  // Getter for the text variable
    string getCopy() { return copy; }  // Getter for the copy variable
};

// TextInputStep class, derived from Step class
class TextInputStep : public Step {  
private:
    string description;  // Variable to store the description of the step
    string text_input;  // Variable to store the text input of the step
public:
    bool step(int step_count);  // Function to perform the step
    void setTextInput(string text_input) { this->text_input = text_input; }  // Setter for the text_input variable
    string getDescription() { return description; }  // Getter for the description variable
    string getText() { return text_input; }  // Getter for the text_input variable
};

// NumberInputStep class, derived from Step class
class NumberInputStep : public Step {  
private:
    string description;  // Variable to store the description of the step
    int number_input;  // Variable to store the number input of the step
public:     
    bool step(int step_count);  // Function to perform the step
    string getDescription() { return description; }  // Getter for the description variable
    void setNumberInput(int number_input) { this->number_input = number_input; }  // Setter for the number_input variable
    int getNumber() { return number_input; }  // Getter for the number_input variable
};  

// CalculusStep class, derived from Step class
class CalculusStep : public Step {  
private:
    int step1;  // Variable to store the first step
    int step2;  // Variable to store the second step
    string operation;  // Variable to store the operation
public:     
    bool step(int step_count);  // Function to perform the step
    int getStep1() { return step1; }  // Getter for the step1 variable
    int getStep2() { return step2; }  // Getter for the step2 variable
    string getOperation() { return operation; }  // Getter for the operation variable
};  

// DisplayStep class, derived from Step class
class DisplayStep : public Step {  
private:
    int step_id;  // Variable to store the step ID
public:
    bool step(int step_count);  // Function to perform the step
    int getStepId() { return step_id; }  // Getter for the step_id variable
};  

// TextFileInputStep class, derived from Step class
class TextFileInputStep : public Step {  
private:
    string description;  // Variable to store the description of the step
    string file_name;  // Variable to store the file name
public:
    bool step(int step_count);  // Function to perform the step
    void setFileName(string file_name) { this->file_name = file_name; }  // Setter for the file_name variable
    string getDescription() { return description; }  // Getter for the description variable
    string getFileName() { return file_name; }  // Getter for the file_name variable
};  

// CsvFileInputStep class, derived from Step class
class CsvFileInputStep : public Step {  
private:
    string description;  // Variable to store the description of the step
    string file_name;  // Variable to store the file name
public:
    bool step(int step_count);  // Function to perform the step
    void setFileName(string file_name) { this->file_name = file_name; }  // Setter for the file_name variable
    string getDescription() { return description; }  // Getter for the description variable
    string getFileName() { return file_name; }  // Getter for the file_name variable
};

// OutputStep class, derived from Step class
class OutputStep : public Step {  
private:
    int step_id;  // Variable to store the step ID
    string title;  // Variable to store the title of the step
    string description;  // Variable to store the description of the step
    string file_name;  // Variable to store the file name
public:
    string getDescription() { return description; }  // Getter for the description variable
    string getFileName() { return file_name; }  // Getter for the file_name variable
    string getTitle() { return title; }  // Getter for the title variable
    int getStepId() { return step_id; }  // Getter for the step_id variable
    bool step(int step_count);  // Function to perform the step
};   

class EndStep : public Step {  // EndStep class, derived from Step class
public:
    bool step(int step_count);  // Function to perform the step
};

#endif