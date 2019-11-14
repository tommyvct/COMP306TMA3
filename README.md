# COMP306: C++ for Programmers - Tutor Marked Assignment 2
## Overview

TMA3 requires you to write THREE C++ programs using the information you have studied in Units 8-12.

## C++ Programs

1. Write a program in which you create a **`const`** whose value is determined at runtime by reading the time when the program starts (Hint: use the `<ctime>` standard header). In a separate function, have the program create two arrays of 10 000 **`double`** s. Initialize the first array with sequential integral values starting with 100, and initialize the second array with the same numbers, but in reverse order (i.e., the first array would contain 100, 101, 102… while the second array contains 10099, 10098, 10097…). Loop through both arrays using a single loop, multiply the corresponding array elements from each array together, and display the result. Read the time when the program completes the multiplication, then compute and display the elapsed time. Do not use inline functions in this program.

2. Rewrite program #1 using an inline function to perform the calculation. In the test plan for this program (actual results section), compare the time required by this program to execute against the time required by the first (non-inline) program.


3. Create a simple class (**`DoStuff`**) containing an `int`, and overload the `operator+` as a member function. Also, provide a `print()` member function that takes an `ostream&` as an argument and prints to that `ostream&`. Add a binary `operator-` and `operator+` to the class as member functions. You should be able to use the objects in complex expressions such as `a + b – c`. Now add the `operator++` and `operator--`, both prefix and postfix versions. Overload the `<< operator` to provide the same functionality as the `print()` member function. Test the class to show that all requirements work correctly.

## Deliverables

The deliverables for this TMA are as per the TMA Requirements document.

All deliverables must be zipped into one file. You can upload the file via Moodle, or email the file directly to your tutor.

## Marking Scheme

The programs are marked using the marking scheme described in the TMA Requirements document.
