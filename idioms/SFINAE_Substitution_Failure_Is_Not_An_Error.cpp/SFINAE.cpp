// Substitution Failure Is Not An Error - https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/SFINAE

/*

Strictly, SFINAE is a language feature and not an idiom. However, this language feature is exploited in 
a very idiomatic fashion using enable-if.

In the process of template argument deduction, a C++ compiler attempts to instantiate signatures of 
a number of candidate overloaded functions to make sure that exactly one overloaded function is available 
as a perfect match for a given function call. If an invalid argument or return type is formed during 
the instantiation of a function template, the instantiation is removed from the overload resolution 
set instead of causing a compilation error. As long as there is one and only one function to which 
the call can be dispatched, the compiler issues no errors.

Only declarations are sufficient to trigger SFINAE rule in the compiler. 
Those functions themselves must be templates, however. That is, a class template with regular 
functions will not participate in SFINAE. The functions that participate in SFINAE must be templates.
 */