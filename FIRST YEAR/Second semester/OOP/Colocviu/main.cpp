#include <iostream>
using namespace std;
class A {
    int x;

public:
    A(int i = 0) { x = i; }
    A operator+(const A& a) { return x + a.x; }
    template <class T>
    ostream& operator<<(ostream& o, T ob);
};
template <class T>
ostream& A::operator<<(ostream& o, T ob)
{
    o << ob.x;
    return o;
}
int main()
{
    A a1(33), a2(-21);
    cout << a1 + a2;
    return 0;
}