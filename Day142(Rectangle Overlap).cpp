#include <iostream>
#include <vector>

// Rectangle Overlap

bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
{
    // Check horizontal overlap
    bool x_overlap = min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]);

    // Check vertical overlap
    bool y_overlap = min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]);

    // Both must overlap for the rectangles to intersect with positive area
    return x_overlap && y_overlap;
}
