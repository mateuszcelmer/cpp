/* 

Resource Acquisition Is Initialization - https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Resource_Acquisition_Is_Initialization

Also Known As
-> Execute-Around Object
-> Resource Release Is Finalization
-> Scope-Bound Resource Management


Resource Acquisition is Initialization (RAII) idiom allows us to acquire resources in the constructor 
and release them in the destructor when scope ends successfully or due to an exception. 
It will always release resources. This is not very flexible. Sometime we don't want to release 
resources if no exception is thrown but we do want to release them if an exception is thrown.

*/