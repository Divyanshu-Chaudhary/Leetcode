#include <iostream>
#include <vector>

// Crawler Log Folder

int minOperations(vector<string> &logs)
{
    int op = 0;
    for (int i = 0; i < logs.size(); i++)
    {
        if (logs[i] == "./")
        {
            continue;
        }
        else if (logs[i] == "../")
        {
            op--;
            if (op < 0)
            {
                op = 0;
            }
        }
        else
        {
            op++;
        }
    }
    return op;
}
