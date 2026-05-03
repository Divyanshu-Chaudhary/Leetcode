#include <iostream>
using namespace std;

bool rotateString(string s, string goal)
{
    if (s.length() != goal.length())
    {
        return false;
    }
    return (s + s).find(goal) != string::npos;
}

int main()
{
    return 0;
}