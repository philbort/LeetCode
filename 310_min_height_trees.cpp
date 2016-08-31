/*

310. Minimum Height Trees

For a undirected graph with tree characteristics, we can choose any node as the root. 
The result graph is then a rooted tree. 
Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). 
Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. 
You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. 
Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]

*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> leaf;
        if(!n)  return leaf;
        if(n == 1)  { leaf.push_back(0); return leaf; }
        vector<unordered_set<int>> map(n, unordered_set<int>());
        for (int i = 0; i < edges.size(); i++) {
            map[edges[i].first].insert(edges[i].second);
            map[edges[i].second].insert(edges[i].first);
        }
        vector<int> degree(n);
        for (int i = 0; i < n; i++)
            degree[i] = map[i].size();
        for (int i = 0; i < n; i++) {
            if(degree[i] == 1)
                leaf.push_back(i);
        }
        while(true) {
            vector<int> next;
            for (int node: leaf) {
                degree[node]--;
                for (int neighbor: map[node]){
                    if( --degree[neighbor]== 1) {
                        next.push_back(neighbor);
                    }
                }
            }
            if(next.empty())  return leaf;
            leaf = next;
        }
        
    }
};