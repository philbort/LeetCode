/*

332. Reconstruct Itinerary

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], 
reconstruct the itinerary in order. 
All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, 
you should return the itinerary that has the smallest lexical order when read as a single string. 
For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.

Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].

Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.

*/

class Solution {

public:
	
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        if(tickets.empty()) return vector<string> ();
        unordered_map<string, multiset<string>> graph;
        vector<string> itinerary;
        stack<string> dfs;
        for (int i = 0; i < tickets.size(); i++)
            // The strings in multiset are sorted as we need.
            // So we will always try the smaller lexical order one
            graph[tickets[i].first].insert(tickets[i].second);
        dfs.push("JFK");
        while(!dfs.empty()) {
            // Get the current airport
            string next = dfs.top();
            // If the airport is not a "from", add to itinerary
            // and pop it form the stack
            if(graph[next].empty()){
                itinerary.push_back(next);
                dfs.pop();
            }
            // If the airport has a "to", add the destination to the stack
            // and erase from the graph
            else {
                dfs.push(*graph[next].begin());
                graph[next].erase(graph[next].begin());
            }
        }
        // Reverse it before return since "JFK" is at the buttom of the stack
        return vector<string>(itinerary.rbegin(), itinerary.rend());
    }
};
