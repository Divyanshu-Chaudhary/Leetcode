#include <iostream>
#include <vector>

// Earliest Finish Time for Land and Water Rides II

int findFinishTime(vector<int> &startTime1, vector<int> &duration1, vector<int> &startTime2, vector<int> &duration2)
{
    int finish1 = INT_MAX;
    int finish2 = INT_MAX;
    for (int i = 0; i < startTime1.size(); i++)
    {
        finish1 = min(finish1, startTime1[i] + duration1[i]);
    }
    for (int i = 0; i < startTime2.size(); i++)
    {
        finish2 = min(finish2, max(finish1, startTime2[i]) + duration2[i]);
    }
    return max(finish1, finish2);
}

int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
{
    int landWater = findFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
    int waterLand = findFinishTime(waterStartTime, waterDuration, landStartTime, landDuration);
    return min(landWater, waterLand);
}
