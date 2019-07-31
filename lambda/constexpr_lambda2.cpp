#include <iostream>

using namespace std;

namespace A{
    namespace B{
        namespace C{
            int i;
        }
    }
}

namespace A::B::C {
    int a;
}

int main()
{
    return 0;
}