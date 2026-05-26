#include <iostream>
#include <vector>

// Minimum Number of Moves to Seat Everyone

int minMovesToSeat(vector<int> &seats, vector<int> &students)
{
    int n = seats.size();
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int move = 0;
    for (int i = 0; i < n; i++)
    {
        move += abs(seats[i] - students[i]);
    }
    return move;
}
