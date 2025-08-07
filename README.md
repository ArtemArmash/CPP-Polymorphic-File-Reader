# Polymorphic File Reader in C++

This C++ project demonstrates the power of **polymorphism** and **inheritance** to create a flexible file viewing utility. The program defines a class hierarchy that allows a single file to be displayed in multiple formats: as plain text, as a sequence of ASCII character codes, and as a binary (0s and 1s) stream.

## About The Project

This project is an excellent example of applying Object-Oriented Programming (OOP) principles to solve a practical problem. Instead of writing separate, unrelated functions, it uses a base class `MainFile` to define a common interface (`Display`) and derived classes to provide specialized implementations.

### Concepts Demonstrated

*   **Polymorphism**: The ability to treat objects of different classes (`MainFile`, `FileASCII`, `File0101`) in a uniform way. Although not shown with base class pointers in `main`, the design is built entirely around this concept.
*   **Inheritance**: The `FileASCII` and `File0101` classes inherit from the `MainFile` class, inheriting its interface.
*   **Virtual Functions**: The `Display()` method is declared `virtual` in the base class, allowing derived classes to `override` it with their own specific logic. This is the key mechanism that enables polymorphism.
*   **File I/O**: The project makes extensive use of `std::ifstream` to read file data character by character or byte by byte.
*   **Bitwise Operations**: The `File0101` class uses bitwise right-shift (`>>`) and AND (`&`) operators to inspect individual bits within a byte.

## Project Structure

The code consists of a simple class hierarchy:

*   **`MainFile` (Base Class)**:
    *   Defines the default behavior for displaying a file: reading it line by line and printing it as plain text.
    *   Declares the `Display()` method as `virtual` so that it can be overridden by child classes.

*   **`FileASCII` (Derived Class)**:
    *   Inherits from `MainFile`.
    *   Overrides the `Display()` method to read the file character by character and print the integer ASCII value of each character.

*   **`File0101` (Derived Class)**:
    *   Inherits from `MainFile`.
    *   Overrides the `Display()` method to read the file byte by byte and print the 8-bit binary representation of each byte.

## How to Build and Run

You will need a C++ compiler (like G++, Clang, or MSVC) to run this project.

1.  **Create a Sample File**: In the same directory as your source code, create a text file named `artem.txt`. You can put any content inside it. For example:
    ```
    Hi
    ```
2.  **Save the Code**: Save the C++ source code as `FileConvert.cpp`.
3.  **Compile the Project**: Open a terminal or command prompt and run the following command:
    ```sh
    g++ FileConvert.cpp -o file_converter_app
    ```
4.  **Run the Executable**:
    ```sh
    ./file_converter_app
    ```

## Expected Output

Assuming the file `artem.txt` contains the word "Hi" followed by a newline, the output of the program will look similar to this:

```
Hi

72 105 10 
01001000 01101001 00001010 
```

*   **First Block**: The output from the `MainFile` object, which prints the file's text content as is.
*   **Second Block**: The output from the `FileASCII` object. `72` is the ASCII code for 'H', `105` is for 'i', and `10` is for the newline character.
*   **Third Block**: The output from the `File0101` object, showing the binary representation of each of those ASCII codes.
