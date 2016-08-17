/*

149. Max Points on a Line

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

 /**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if(n < 3)  return n;
        
        unordered_map<double, int> map;
        // At least two points are on a line
        int result = 2;
        // Go through every point combination O(n^2)
        for(int i = 0; i < n-1; i++) {
            // Clear the hash at start
            map.clear();
            // Track the duplicates
            int duplicate = 0;
            for(int j = i + 1; j < n; j++) {
                // Check for duplicates
                if(points[i].x == points[j].x &&
                   points[i].y == points[j].y) {
                       duplicate++;
                       continue;
                   }
                // Calculate slope
                double slope = (points[i].x == points[j].x) ? numeric_limits<double>::max() :
                               (double) (points[j].y - points[i].y)/(points[j].x - points[i].x);
                // If first found, two points are on the same slope
                if(map.find(slope) == map.end())
                    map[slope] = 2;
                // If not first found, add one point each time
                else
                    map[slope]++;
            }
            // Check the scenario where a lot of points are duplicates
            result = max(result, duplicate+1);
            // Update the result
            for(auto current : map) {
                if(current.second + duplicate > result)
                    result = current.second + duplicate;
            }
            /* If we have more points on a line than the points left,
               or more than half of the total points, we have our
               winner.
            */
            if(result > n - i &&
               result > n/2)
                return result;
        }

        return result;
    }
};
