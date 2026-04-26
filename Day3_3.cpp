#include <iostream>
using namespace std;

string largestGoodInteger(string num)
{

    char maxChar = ' ';
    for (int i = 2; i < num.length(); i++)
    {
        if (num[i] == num[i - 1] && num[i] == num[i - 2])
        {
            maxChar = max(maxChar, num[i]);
        }
    }
    if (maxChar == ' ')
    {
        return "";
    }
    else
    {
        return string(3, maxChar);
    }
}

int main()
{
    return 0;
}