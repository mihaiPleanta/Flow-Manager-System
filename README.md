# Flow Manager System
Overview
The Flow Manager System is a flexible framework designed to handle various steps in a flow process, allowing for different types of user inputs, validations, and processing. Each step in the flow can be configured with unique input requirements, from simple text inputs to file handling and mathematical calculations. This system is ideal for creating customizable flows where the user can define and manage sequential tasks efficiently.

Features
Step Definitions: Multiple types of steps such as title, text, number input, calculus operations, and file handling.
Error Handling: Robust error handling for invalid inputs and failures during step execution.
Dynamic Flow Management: Each step is processed sequentially, allowing users to create custom flows.
File Handling: Supports text and CSV file input/output steps.
Mathematical Operations: Performs basic arithmetic and logic operations like addition, subtraction, multiplication, division, and comparisons (min, max).
Steps in the Flow
TITLE step: Set the title and subtitle with validation.
TEXT step: Allows the addition of text content.
TEXT INPUT step: Requests a text input from the user.
NUMBER INPUT step: Requests a numerical input from the user.
CALCULUS step: Performs calculations on previous numerical inputs.
DISPLAY step: Displays content from a specified file.
TEXT FILE input step: Reads content from a text file.
CSV FILE input step: Reads data from a CSV file.
OUTPUT step: Writes data to a specified output file.
END step: Marks the end of the flow and confirms successful completion.

Usage
When you run the program, you will be prompted to select a step and provide the required inputs. The system will guide you through each step with appropriate instructions, and you will see success or error messages based on your inputs.

Example
Here’s an example of the flow steps:

Title Step: You will be prompted to enter a title and subtitle, which must start with an uppercase letter.
Text Input: The system will ask for a description, and you can enter your input.
Calculus Step: You can perform calculations by entering two numerical inputs and selecting an operator (e.g., +, -, *, /).
Output: The final step allows you to specify an output file where the flow data will be saved.







