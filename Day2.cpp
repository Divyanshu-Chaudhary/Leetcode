#include <iostream>
#include <vector>
using namespace std;

int closestTarget(vector<string> &words, string target, int startIndex)
{
    int n = words.size();

    for (int step = 0; step < n; step++)
    {
        int forward = (startIndex + step) % n;
        int backward = (startIndex - step + n) % n;

        if (words[forward] == target || words[backward] == target)
        {
            return step;
        }
    }

    return -1;
}

int main()
{
    return 0;
}