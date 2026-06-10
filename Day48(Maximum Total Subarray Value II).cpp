#include<iostream>
#include<vector>

// Maximum Total Subarray Value II

long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Precompute logarithms for Sparse Table
        vector<int> lg(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }
                
        int k_log = lg[n] + 1;
        
        // Use flat 1D vectors for cache efficiency and to avoid stack overflow
        vector<int> st_max(n * k_log);
        vector<int> st_min(n * k_log);
        
        // Helper lambda for 2D-like access in a flat array
        auto get_idx = [&](int i, int j) {
            return i * k_log + j;
        };
        
        // Initialize base cases (intervals of length 1)
        for (int i = 0; i < n; i++) {
            st_max[get_idx(i, 0)] = nums[i];
            st_min[get_idx(i, 0)] = nums[i];
        }
        
        // Build Sparse Tables
        for (int j = 1; j < k_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                int left_idx = get_idx(i, j - 1);
                int right_idx = get_idx(i + (1 << (j - 1)), j - 1);
                st_max[get_idx(i, j)] = max(st_max[left_idx], st_max[right_idx]);
                st_min[get_idx(i, j)] = min(st_min[left_idx], st_min[right_idx]);
            }
        }

        // O(1) query function
        auto getValue = [&](int l, int r) {
            int j = lg[r - l + 1];
            int left_idx = get_idx(l, j);
            int right_idx = get_idx(r - (1 << j) + 1, j);
            int mx = max(st_max[left_idx], st_max[right_idx]);
            int mn = min(st_min[left_idx], st_min[right_idx]);
            return (long long)mx - mn;
        };

        // Priority Queue stores: {value, {start_index, end_index}}
        priority_queue<pair<long long, pair<int, int>>> pq;
        
        // STEP 1: Insert the absolute maximum interval for every starting index 'i'
        for (int i = 0; i < n; i++) {
            pq.push({getValue(i, n - 1), {i, n - 1}});
        }

        long long totalValue = 0;
        
        // STEP 2: Greedily extract the top K elements
        while (k > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            totalValue += top.first;
            int i = top.second.first;
            int r = top.second.second;
            
            // For the same left endpoint 'i', the next highest possible value 
            // is guaranteed to be the subarray shrunk by 1 on the right.
            if (r - 1 >= i) {
                pq.push({getValue(i, r - 1), {i, r - 1}});
            }
            k--;
        }
        
        return totalValue;
    }
