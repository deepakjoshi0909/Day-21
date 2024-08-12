#include <vector>
#include <queue>

class Solution {
public:
    int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int n = heights.size();

        for (int i = 0; i < n - 1; ++i) {
            int climb = heights[i + 1] - heights[i];
            if (climb > 0) {
                pq.push(climb); 
                bricks -= climb; 
                
                if (bricks < 0) {
                    bricks += pq.top();  
                    pq.pop();  
                    --ladders;
                }
                
                if (ladders < 0) {
                    return i;
                }
            }
        }

        
        return n - 1;
    }
};
