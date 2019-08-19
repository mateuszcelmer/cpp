/*
https://stackoverflow.com/questions/2397984/undefined-unspecified-and-implementation-defined-behavior

Undefined behavior is one of those aspects of the C and C++ language that can be surprising to programmers coming from other languages (other languages try to hide it better). Basically, it is possible to write C++ programs that do not behave in a predictable way, even though many C++ compilers will not report any errors in the program!

examples of undefined behavior include:
-> attempting to modify the string literal
-> accessing an array beyond its bounds, 
-> dereferencing the null pointer, 
-> accessing objects after their lifetime ended
-> or writing allegedly clever expressions like i++ + ++i.


Attempting to modify the string literal is undefined behavior:

#### Noncompliant Code Example #### 
                                    - In this noncompliant code example, the char pointer str is initialized to the address of a string literal.

char *str  = "string literal";
str[0] = 'S';


#### Compliant Solution #### 
                                - As an array initializer, a string literal specifies the initial values of characters in an array as well as the size of the array. (See STR11-C. Do not specify the bound of a character array initialized with a string literal.) This code creates a copy of the string literal in the space allocated to the character array str. The string stored in str can be modified safely.

char str[] = "string literal";
str[0] = 'S';

 */