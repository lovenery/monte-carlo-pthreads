// Name of program mainreturn.cpp 
#include <iostream> 
using namespace std; 
  
int main(int argc, char** argv) 
{ 
    cout << "You have entered " << argc 
         << " arguments:" << "\n"; 
  
    for (int i = 0; i < argc; ++i) 
        cout << argv[i] << "\n"; 

    return 0; 
}

/*
Input:
$ g++ mainreturn.cpp -o main 
$ ./main geeks for geeks

Output:
You have entered 4 arguments:
./main
geeks
for
geeks
*/