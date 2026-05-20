#include <iostream>
#include <vector>

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    int n = students.size();
    int arr[2] = {0};

    for (int &stu : students)
    {
        arr[stu]++;
    }
    for (int i = 0; i < n; i++)
    {
        int san = sandwiches[i];
        if (arr[san] == 0)
        {
            return n - i;
        }
        arr[san]--;
    }
    return 0;
}
