/*

210. Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. 
To take course 3 you should have finished both courses 1 and 2. 
Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. 
Another correct ordering is[0,2,1,3].

*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(!numCourses)  
            return vector<int>();
            
        vector<int> result;
        
        // Queue for zero indegrees
        queue<int> zeroInDegree;
        // Hash table for indegree and outdegree
        unordered_map<int, unordered_set<int>> inDegree, outDegree;
        // Transform edge lists to adjacency lists
        for (int i = 0; i < prerequisites.size(); i++) {
            inDegree[prerequisites[i].first].insert(prerequisites[i].second);
            outDegree[prerequisites[i].second].insert(prerequisites[i].first);
        }
        // Find if we have zeroInDegree, and put them in the queue
        for (int i = 0; i < numCourses; i++) {
            if(inDegree.find(i) == inDegree.end())
                zeroInDegree.push(i);
        }
        
        while(!zeroInDegree.empty()) {
            // The current course
            int course = zeroInDegree.front();
            zeroInDegree.pop();
            
            result.push_back(course);
            
            // Find all the courses require the current course
            for (auto it = outDegree[course].begin(); it != outDegree[course].end(); it++) {
                // Erase it from InDegree since we already took it
                inDegree[*it].erase(course);
                // If a course doesn't have any indegrees, put it in the queue
                if(inDegree[*it].empty())
                    zeroInDegree.push(*it);
            }
            // Erase the current course from outdegree
            outDegree.erase(course);
        }
        
        // If we still have outdegree, we hace a cycle
        if(!outDegree.empty())
            return vector<int> ();
            
        // Othewsise we don't
        return result;
    }

};
