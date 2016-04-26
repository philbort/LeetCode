/*

121. Best Time to Buy and Sell Stock 

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
 design an algorithm to find the maximum profit.

*/


 class Solution {

public:

    // Same as the maximum sub-array question
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        int current_max = 0, final_max = 0;
        
        for (int i = 0; i < n-1; i++)
        {
            // current sum along the path
            current_max = max(current_max+prices[i+1] - prices[i],0);
            // maximum sum
            final_max = max(current_max, final_max);
        }
        return final_max;
    }
};

/*
Even better solution:

int maxProfit(vector<int> &prices) {
    int maxPro = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    return maxPro;
}
*/
