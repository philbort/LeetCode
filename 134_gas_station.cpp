/*

134. Gas Station

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). 
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int end = 0, start = gas.size() - 1;
       int sum = gas[start] - cost[start];
       while (start > end) {
          // If we have enough, move "end" forward
          if (sum >= 0) {
             sum += gas[end] - cost[end];
             ++end;
          }
          // If we don't have enough, move "start"
          // back to get potentially more gas
          else {
             --start;
             sum += gas[start] - cost[start];
          }
       }
       return sum >= 0 ? start : -1;
    }
};

/* Another way, we can get there if  the total gas is no smaller 
   than the total cost

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, tank = 0, total = 0;
        for (int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            if(tank < 0) {
                start = i + 1;
                total += tank;
                tank = 0;
            }
        }
        return ( (total + tank) < 0 ? -1 : start );
    }
    
*/
