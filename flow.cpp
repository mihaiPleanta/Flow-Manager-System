#include "flow.h"

Flow::Flow() {
}

// Method to add a vector of steps to the flows vector  
void Flow::addSteps(const vector<Step*>& steps) {
    flows.push_back(steps);
}

// Method to get the vector of vectors of steps in the flow
const vector<vector<Step*>>& Flow::getFlows() const {
    return flows;
}

// Method to display and run a flow
void Flow::displayFlow() {
    if (flows.empty()) {
        cout << "No flows to display." << endl;
        return;
    }

    int flowNumber;

    cout << "Please enter the number of the flow to display: ";
    cin >> flowNumber;   
    cout << "Timestamp for this flow: " << getTimestamps()[flowNumber] << endl;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number." << endl;
        errorCount++;
        return;
    }

    if (flowNumber < 0 || flowNumber >= flows.size()) {
        cout << "Invalid flow number. Please enter a number between 0 and " << flows.size() - 1 << "." << endl;
        errorCount++;
        return;
    }

    for (int i = 0; i < flows[flowNumber].size()-1; i++) {
        Step* step = flows[flowNumber][i];

        // Ask the user if they want to stay at this step or skip to the next one
        char choice;
        cout << "Do you want to stay at this step (s) or skip to the next one (n)?: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // If the user chooses to skip, continue to the next iteration
        if (choice == 'n' || choice == 'N') {
            continue;
        }

        TitleStep* titleStep = dynamic_cast<TitleStep*>(step);
        if (titleStep != nullptr) {
            cout << "Step " << i+1 << " title: " << titleStep->getTitle() << endl;
            cout << setw(7) << " subtitle: " << titleStep->getSubtitle() << endl;
            continue;
        }

        TextStep* textStep = dynamic_cast<TextStep*>(step);
        if (textStep != nullptr) {
            cout << "Step " << i+1 << " text: " << textStep->getText() << endl;
            cout << setw(7) << " " << "copy: " << textStep->getCopy() << endl;
            continue;
        }

        TextInputStep* textInputStep = dynamic_cast<TextInputStep*>(step);
        if (textInputStep != nullptr) {
            string text;

            cout << "Step " << i+1 << " description: " << textInputStep->getDescription() << endl;
            cout << setw(7) << " " << "text_input: ";

            try {
                cin.ignore();  // Ignore leftover newline character
                getline(cin, text);
                if (cin.fail()) {
                    throw runtime_error("Failed to read text input");
                }
            } catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl; 
                errorCount++;

            }

            textInputStep->setTextInput(text);
            continue;
        }

        NumberInputStep* numberInputStep = dynamic_cast<NumberInputStep*>(step);
        if (numberInputStep != nullptr) {
            cout << "Step " << i+1 << " description: " << numberInputStep->getDescription() << endl;
            cout << setw(7) << " " << "number_input: ";

            int number;
            try {
                cin >> number;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Failed to read number input");
                }
            } catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl;
                errorCount++;
            }

            numberInputStep->setNumberInput(number);
            continue;
        }   

        CalculusStep* calculusStep = dynamic_cast<CalculusStep*>(step);
        if (calculusStep != nullptr) {
            int step1 = calculusStep->getStep1();
            int step2 = calculusStep->getStep2();

            NumberInputStep* numberInputStep1 = dynamic_cast<NumberInputStep*>(flows[flowNumber][step1-1]);
            NumberInputStep* numberInputStep2 = dynamic_cast<NumberInputStep*>(flows[flowNumber][step2-1]);

            cout << "Step " << i+1 << " step1: " << step1 << endl;
            cout << setw(7) << " " << "step2: " << step2 << endl;
            cout << setw(7) << " " << "operation: " << calculusStep->getOperation() << endl;

            int operand1 = numberInputStep1->getNumber();
            int operand2 = numberInputStep2->getNumber();

            int result = 0;
            string operation = calculusStep->getOperation();

            if (operation == "+") {
                result = operand1 + operand2;
            } else if (operation == "-") {
                result = operand1 - operand2;
            } else if (operation == "*") {
                result = operand1 * operand2;
            } else if (operation == "/") {
                if (operand2 != 0) {
                    result = operand1 / operand2;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                    continue;
                }
            } else if (operation == "min") {
                result = min(operand1, operand2);
            } else if (operation == "max") {
                result = max(operand1, operand2);
            } else {
                cout << "Error: Unknown operation '" << operation << "'." << endl;
                continue;
            }

            cout << setw(7) << " " << "result: " << result << endl;
            continue;
        }

        DisplayStep* displayStep = dynamic_cast<DisplayStep*>(step);
        if (displayStep != nullptr) {
            cout << "Step " << i+1 << " step: " << displayStep->getStepId() << endl;
            cout << "The following content has been retrieved from the specified file:\n";
            int step_id = displayStep->getStepId();

            TextFileInputStep* textFileInputStep = dynamic_cast<TextFileInputStep*>(flows[flowNumber][step_id-1]);
            CsvFileInputStep* csvFileInputStep = dynamic_cast<CsvFileInputStep*>(flows[flowNumber][step_id-1]);

            if (textFileInputStep != nullptr) {
            string filename = textFileInputStep->getFileName();

            ifstream file(filename);
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            } else {
                cerr << "Error: Unable to open file '" << filename << "'." << endl;
                errorCount++;
            }
        } else if (csvFileInputStep != nullptr) {
            string filename = csvFileInputStep->getFileName();

            ifstream file(filename);
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    stringstream ss(line);
                    string field;
                    while (getline(ss, field, ',')) {
                        cout << field << " ";
                    }
                    cout << endl;
                }
                file.close();
            } else {
                cerr << "Error: Unable to open file '" << filename << "'." << endl;
                errorCount++;
            }
        } else {
            cerr << "Error: Step " << step_id << " is not a FileInputStep." << endl;
            errorCount++;
            }
        }

        TextFileInputStep* textFileInputStep = dynamic_cast<TextFileInputStep*>(step);
        if (textFileInputStep != nullptr) {
            cout << "Step " << i+1 << " description: " << textFileInputStep->getDescription() << endl;
            cout << setw(7) << " " << "file_name: ";

            string file;

            if (textFileInputStep->getFileName() == "") {
                try {
                getline(cin, file);
                if (cin.fail()) {
                    throw runtime_error("Failed to read filename");
                }

                if (file.substr(file.find_last_of(".") + 1) != "txt") {
                    throw runtime_error("Invalid filename. The file should end with .txt");
                }


                ifstream inFile(file);
                if (!inFile.is_open()) {
                    cout << "Unable to open file: " << file << endl;
                }
            } catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl;
                errorCount++;
            }
                textFileInputStep->setFileName(file);
            } else {
                cout << textFileInputStep->getFileName() << endl;
            }
        
            continue;
        }   

        CsvFileInputStep* csvFileInputStep = dynamic_cast<CsvFileInputStep*>(step);
        if (csvFileInputStep != nullptr) {
            cout << "Step " << i+1 << " description: " << csvFileInputStep->getDescription() << endl;
            cout << setw(7) << " " << "file_name: ";

            string file;

            if(csvFileInputStep->getFileName() == "") {
                try {
                getline(cin, file);
                if (cin.fail()) {
                    throw runtime_error("Failed to read filename");
                }

                if (file.substr(file.find_last_of(".") + 1) != "csv") {
                    throw runtime_error("Invalid filename. The file should end with .csv");
                }

                ifstream inFile(file);
                if (!inFile.is_open()) {
                    cout << "Unable to open file: " << file << endl;
                }
            } catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl;
                errorCount++;
            }

            csvFileInputStep->setFileName(file);
            } else {
                cout << csvFileInputStep->getFileName() << endl;
            }

            continue;
        }

        OutputStep* outputStep = dynamic_cast<OutputStep*>(step);
        if (outputStep != nullptr) {
            cout << "Step " << i+1 << " title: " << outputStep->getTitle() << endl;
            cout << setw(7) << " " << "description: " << outputStep->getDescription() << endl;
            cout << setw(7) << " " << "file_name: " << outputStep->getFileName() << endl;   

             int step_count = outputStep->getStepId();

            // Get the step from the flow using the step_id
            Step* step = flows[flowNumber][step_count-1];


            // Open the output file
            ofstream file(outputStep->getFileName());

            // Check if the file is open
            if (!file.is_open()) {
                cerr << "Error: Unable to open file '" << outputStep->getFileName() << "'." << endl;
                errorCount++;
            }

            // Write the step information to the file
            file << "Step ID: " << outputStep->getStepId() << "\n";

            // Use dynamic casting to identify the type of the step
            if (TitleStep* titleStep = dynamic_cast<TitleStep*>(step)) {
                file << "Title: " << titleStep->getTitle() << "\n";
                file << "Subtitle: " << titleStep->getSubtitle() << "\n";
            } else if (TextStep* textStep = dynamic_cast<TextStep*>(step)) {
                file << "Text: " << textStep->getText() << "\n";
                file << "Copy: " << textStep->getCopy() << "\n";
            } else if (TextInputStep* textInputStep = dynamic_cast<TextInputStep*>(step)) {
                file << "Description: " << textInputStep->getDescription() << "\n";
                file << "Text Input: " << textInputStep->getText() << "\n";
            } else if (NumberInputStep* numberInputStep = dynamic_cast<NumberInputStep*>(step)) {
                file << "Description: " << numberInputStep->getDescription() << "\n";
                file << "Number Input: " << numberInputStep->getNumber() << "\n";
            } else if (CalculusStep* calculusStep = dynamic_cast<CalculusStep*>(step)) {
                file << "Step 1: " << calculusStep->getStep1() << "\n";
                file << "Step 2: " << calculusStep->getStep2() << "\n";
                file << "Operation: " << calculusStep->getOperation() << "\n";
            } else if (DisplayStep* displayStep = dynamic_cast<DisplayStep*>(step)) {
                file << "Step: " << displayStep->getStepId() << "\n";
            } else if (TextFileInputStep* textFileInputStep = dynamic_cast<TextFileInputStep*>(step)) {
                file << "Description: " << textFileInputStep->getDescription() << "\n";
                file << "File Name: " << textFileInputStep->getFileName() << "\n";
            } else if (CsvFileInputStep* csvFileInputStep = dynamic_cast<CsvFileInputStep*>(step)) {
                file << "Description: " << csvFileInputStep->getDescription() << "\n";
                file << "File Name: " << csvFileInputStep->getFileName() << "\n";
            } else {
                cerr << "Error: Unknown step type." << endl;
            }

            // Close the file
            file.close();

            continue;
        }
    }
}


// Method to add a timestamp to the timestamps vector
void Flow::addTimestamp() {
    // Get the current date and time
    time_t now = time(0);
    char* dt = ctime(&now);

    // Remove the newline character from the end of the timestamp
    dt[strlen(dt) - 1] = '\0';

    // Add the timestamp to the vector
    timestamps.push_back(dt);
}

// Method to get the timestamps vector
const vector<string>& Flow::getTimestamps() const {
    return timestamps;
}

// Method to delete a flow
void Flow::deleteFlow() {
    if (flows.empty()) {
        cout << "No flows to delete." << endl;
        return;
    }

    int flowNumber;

    cout << "Please enter the number of the flow to delete: ";
    cin >> flowNumber;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number." << endl;
        errorCount++;
        return;
    }

    if (flowNumber < 0 || flowNumber >= flows.size()) {
        cout << "Invalid flow number. Please enter a number between 0 and " << flows.size() - 1 << "." << endl;
        errorCount++;
        return;
    }

    flows.erase(flows.begin() + flowNumber);
    timestamps.erase(timestamps.begin() + flowNumber);
}