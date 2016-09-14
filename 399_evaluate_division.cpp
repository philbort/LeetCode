/*

399. Evaluate Division

Equations are given in the format A / B = k, where A and B are variables represented as strings, 
and k is a real number (floating point number). 
Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries,
where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

*/

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, 
                                vector<double>& values, 
                                vector<pair<string, string>> queries) {
        if(queries.empty())  return {};
        unordered_map<string,vector<pair<string,double>>> map;
        // Hash the adjacency list
        for(int i = 0; i < values.size(); i++) {
            map[equations[i].first].push_back(make_pair(equations[i].second, values[i]));
            map[equations[i].second].push_back(make_pair(equations[i].first, 1.0/values[i]));
        }
        vector<double> result(queries.size());
        // Go through the queries
        for(int i = 0; i < queries.size(); i++) {
            // Track the visited nodes
            unordered_set<string> visited;
            visited.insert(queries[i].first);
            double val = 1.0;
            // DFS
            if(dfs(map, visited, queries[i].first, queries[i].second, val))
                result[i] = val;
            else
                result[i] = -1.0;
        }
        return result;
    }
private:
    bool dfs(unordered_map<string, vector<pair<string,double>>>& map, 
             unordered_set<string>& visited,
             string& from, 
             string& to, 
             double& val) {
        // If we don't have the "from" node ...
        if(map.find(from) == map.end()) return false;
        // If "from" node is the same as "to" node ..
        if(from == to)  return true;
        // Go through all the neighbor nodes
        for(auto node: map[from]) {
            // If we haven't visited ...
            if(visited.find(node.first) == visited.end()) {
                visited.insert(node.first);
                val *= node.second;
                if(dfs(map, visited,node.first, to, val))
                    return true;
                val /= node.second;
                visited.erase(node.first);
            }
        }
        return false;
    }
};
