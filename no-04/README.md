# Generic Linked List (GLL) Implementation and Testing

## Project Description
This project involves the implementation and extensive testing of a Generic Linked List (GLL) template class in C++. The GLL class supports various data types, including `int`, `string`, and a custom `Thing` class. The project also includes operations like merging, appending, prepending, and handling of 'goofy' elements. The testing framework ensures that the GLL functions correctly under different scenarios, such as self-assignment, merging, and element removal based on specific criteria.

## Files
- `gll_int_test.cpp`: Extensive tests for the GLL class, focusing on operations like appending, prepending, merging, and handling of 'goofy' elements.
- `gll_limited.cpp`: Instantiates GLL templates for specific types like `int`, `string`, and `Thing`.
- `gll.cpp`: Implements the GLL class and provides basic operations like appending, prepending, and merging linked lists.
- `GLL.h`: Header file for the GLL class template.
- `goofy.cpp`: Implements the `isGoofy` functions for `int` and `string`.
- `goofy.h`: Header file for the `isGoofy` functions.
- `mygll.cpp`: Demonstrates the use of GLL with `int`, `string`, and `Thing` types.
- `Thing.cpp`: Implements the `Thing` class, including operator overloading and the `isGoofy` function for `Thing` objects.
- `Thing.h`: Header file for the `Thing` class.
- `Makefile`: A makefile to compile the project, including different modes of template instantiation.

## Usage
To compile and run the program:

1. **Compile the program**:
   ```bash
   make
   ```
## Run the Executable

- **Run `./gll`**:  
  To see the basic functionality of the GLL class with different data types.

- **Run `./gll_int_test`**:  
  To execute the comprehensive tests for the GLL class.

- **Run `./gll_implicit`**:  
  For flexible template instantiation.

- **Run `./gll_explicit`**:  
  For limited template instantiation.
## What I Learned

- **Template Programming**: I deepened my understanding of template programming in C++, learning how to create generic data structures that work with multiple data types.
- **Linked List Implementation**: I gained experience implementing a doubly linked list in C++, managing nodes with pointers, and handling edge cases such as empty lists and self-assignment.
- **Memory Management**: I reinforced best practices for dynamic memory management, particularly in ensuring proper allocation, reallocation, and deallocation of memory to prevent leaks.
- **Testing Frameworks**: I developed a comprehensive testing framework to validate the functionality of the GLL class, ensuring robustness through various test scenarios.
- **Operator Overloading**: I practiced operator overloading to extend the functionality of the GLL class, such as with the `+=` and `-=` operators for merging and subtracting linked lists.
- **Handling Goofy Elements**: I implemented specialized functions to handle 'goofy' elements, demonstrating how to incorporate custom logic into generic data structures.
- **Template Instantiation**: I learned the differences between explicit and implicit template instantiation and how to apply each method depending on the use case.