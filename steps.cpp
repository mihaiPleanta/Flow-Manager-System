#include "steps.h"

Step::Step() {
}

// Each method reads the necessary input from the user, checks if the input is valid, and throws an error if the input is not valid
// If an error occurs, it prints the error message and returns false
// If the step is successful, it prints a success message and returns true

bool TitleStep::step(int step_count) {
    cout << "=== Title Step ===" << endl;

    try {
        cout << "Enter title: ";
        if (!getline(cin, title)) {
        throw runtime_error("Failed to read title");
    }

    // Check if the first character of the title is not uppercase
    if (!isupper(title[0])) {
        throw runtime_error("Title must start with an uppercase letter");
    }

    cout << "Enter subtitle: ";
    if (!getline(cin, subtitle)) {
        throw runtime_error("Failed to read subtitle");
    }

    // Check if the first character of the subtitle is not uppercase
    if (!isupper(subtitle[0])) {
        throw runtime_error("Subtitle must start with an uppercase letter");
    }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    return false;
    }

    cout << "Title and subtitle have been successfully set for this step." << endl;
    cout << "===================" << endl;
    
    return true;
}

bool TextStep::step(int step_count) {
    cout << "=== Text Step ===" << endl;

    try {
        cout << "Enter text: ";
        if (!getline(cin, text)) {
            throw runtime_error("Failed to read text");
        }

        cout << "Copy text: ";
        if (!getline(cin, copy)) {
            throw runtime_error("Failed to read copy");
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return false;
    }

    cout << "Text and copy have been successfully set for this step." << endl;
    cout << "===================" << endl;

    return true;
}

bool TextInputStep::step(int step_count) {
    cout << "=== Text Input Step ===" << endl;

    try {
        cout << "Enter description: ";
        if (!getline(cin, description)) {
            throw runtime_error("Failed to read description");
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return false;
    }

    cout << "Text and description have been successfully set for this step." << endl;
    cout << "===================" << endl;

    return true;
}

bool NumberInputStep::step(int step_count) {
    cout << "=== Number Input Step ===" << endl;

    try {
        cout << "Enter description: ";
        getline(cin, description);
        if (cin.fail()) {
            throw runtime_error("Failed to read description");
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return false;
    }

    cout << "Text and description have been successfully set for this step." << endl;
    cout << "===================" << endl;

    return true;
}

bool CalculusStep::step(int step_count) {
    cout << "=== Calculus Step ===" << endl;

    try {
        cout << "Enter operator: ";
        getline(cin, operation);
        if (operation != "+" && operation != "-" && operation != "*" && operation != "/" && operation != "min" && operation != "max") {
            throw runtime_error("Invalid operator. Please enter one of the following: +, -, *, /, min, max");
        }

        cout << "Enter steps:" << endl;
        cout << "Enter step 1: ";
        cin >> step1;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw runtime_error("Invalid input. Please enter a number for step 1");
        }

        cout << "Enter step 2: ";
        cin >> step2;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw runtime_error("Invalid input. Please enter a number for step 2");
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return false;
    }

    cout << "Operation was successfully performed." << endl;
    cout << "===================" << endl;
    return true;
}

bool TextFileInputStep::step(int step_count) {
    cout << "=== Text File Input Step ===" << endl;

    try {
        cout << "Enter description: ";
        getline(cin, description);
        if (cin.fail()) {
            throw runtime_error("Failed to read description");
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return false;
    }

    cout << "Description have been successfully set for this step." << endl;
    cout << "===================" << endl;

    return true;
}

bool CsvFileInputStep::step(int step_count) {
    cout << "=== CSV File Input Step ===" << endl;

    try {
        cout << "Enter description: ";
        getline(cin, description);
        if (cin.fail()) {
            throw runtime_error("Failed to read description");
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return false;
    }

    cout << "Text and description have been successfully set for this step." << endl;
    cout << "===================" << endl;

    return true;
}

bool DisplayStep::step(int step_count) {
    cout << "=== Display Step ===" << endl;

    try {
        cout << "Enter step: ";
        cin >> step_id;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw runtime_error("Invalid input. Please enter an integer for step");
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return false;
    }

    return true;
}

bool OutputStep::step(int step_count) {
    cout << "=== Output Step ===" << endl;

    try {
        cout << "Enter file name to output to: ";
        getline(cin, file_name);
        if (cin.fail()) {
            throw runtime_error("Failed to read filename");
        }
        file_name += ".txt";  // Append .txt to the filename

        cout << "Enter title: ";
        getline(cin, title);
        if (cin.fail()) {
            throw runtime_error("Failed to read title");
        }

        if (!isupper(title[0])) {
            throw runtime_error("Title must start with an uppercase letter");
        }

        cout << "Description: ";
        getline(cin, description);
        if (cin.fail()) {
            throw runtime_error("Failed to read description");
        }

        cout << "Enter step: ";
        cin >> step_id;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw runtime_error("Invalid input. Please enter an integer for step");
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return false;
    }

    // If we get here, the file was successfully created
    cout << "File " << file_name << " created successfully." << endl;

    cout << "===================" << endl;

    return true;
}

bool EndStep::step(int step_count) {
    cout << "=== End Step ===" << endl;
    cout << "Flow created successfully." << endl;
    cout << "===================" << endl;
    
    return true;
}
