/*
http://www.devx.com/tips/Tip/12684


Unspecified behavior, on the other hand, is a consistent and documented behavior that a certain 
implementation employs in cases that are left intentionally unspecified by the C++ Standard--usually,
to allow efficient and simple compiler implementation on various platforms. Examples for unspecified 
behaviors include: 
 -> the size of an int (?) ("int" or "long int"?)
 -> whether a char is unsigned or signed by default, 
 -> the size of a pointer, 
 -> or the underlying type representing a bool. 
 
It is guaranteed that the behavior of a certain implementation 
in such cases is consistent. For instance, all variables of type int are guaranteed to have the same size 
on the same machine. It is not guaranteed, however, that on another machine, int variables will occupy the same size. */