#include "steps_description.h"

// Method to display the name of the step based on the step count
void StepDescription::stepsName(int step_count) {
    cout << "Step " << step_count << endl;
    cout << "0. HELP" << endl;
    cout << "1. TITLE step (1)" << endl;
    cout << "2. TEXT step (2)" << endl;
    cout << "3. TEXT INPUT step (3)" << endl;
    cout << "4. NUMBER INPUT step (4)" << endl;
    cout << "5. CALCULUS step (5)" << endl;
    cout << "6. DISPLAY steps (6)" << endl;
    cout << "7. TEXT FILE input step (7)" << endl; 
    cout << "8. CSV FILE input step (8)" << endl;
    cout << "9. OUTPUT step (9)" << endl;
    cout << "10. END step (10)" << endl;
}

// Method to display the description of the step
void StepDescription::stepsDescription() {
    int step;

    try {
    cout << "Please select a step to see its description: ";
    cin >> step;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input. Please enter a number.");
    }

    switch (step) {
        case 1:
            cout << "TITLE step: This step is used to set the title of the flow. The title should start with an uppercase letter." << endl;
            cout << "Parameters: title (string), subtitle (string)" << endl;
            break;
        case 2:
            cout << "TEXT step: This step is used to add a text block to the flow. You can enter any text you want." << endl;
            cout << "Parameters: title (string), copy (string)" << endl;
            break;
        case 3:
            cout << "TEXT INPUT step: This step is used to get a text input from the user. The user will be asked to enter some text." << endl;
            cout << "Parameters: description (string), text input (string)" << endl;
            break;
        case 4:
            cout << "NUMBER INPUT step: This step is used to get a numerical input from the user." << endl;
            cout << "Parameters: description (string), number input (float)" << endl;
            break;
        case 5:
            cout << "CALCULUS step: This step performs a mathematical operation on two previous numerical inputs." << endl;
            cout << "Parameters: steps (integer), operation (string)" << endl;
            break;
        case 6:
            cout << "DISPLAY step: This step displays the content of a specified file." << endl;
            cout << "Parameters: step (integer), name of file (string)" << endl;
            break;
        case 7:
            cout << "TEXT FILE input step: This step reads input from a text file." << endl;
            cout << "Parameters: description (string), file_name (string)" << endl;
            break;
        case 8:
            cout << "CSV FILE input step: This step reads input from a CSV file." << endl;
            cout << "Parameters: description (string), file_name (string)" << endl;
            break;
        case 9:
            cout << "OUTPUT step: This step outputs information to a file." << endl;
            cout << "Parameters: step (integer), name of file (string), title (text), description (text)" << endl;
            break;
        default:
            cout << "Invalid step number." << endl;
            break;
        }
    } catch (const invalid_argument& e) {
    cerr << e.what() << endl;
    }

}