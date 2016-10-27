/*

319. Bulb Switcher   

There are n bulbs that are initially off. 
You first turn on all the bulbs. 
Then, you turn off every second bulb. 
On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). 
For the ith round, you toggle every i bulb. 
For the nth round, you only toggle the last bulb. 
Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.

*/

class Solution {

public:
	
    int bulbSwitch(int n) {
	// Starts with 0 since n can be 0
        int res = 0;
        /* find out how many perfect squared
           numbers smaller and equal to n.
           These numbers have odd number of 
           divisors. So they will be on eventually.
           (e.g., 9: 1(on), 3(off), 9(on); 
                  8: 1(on), 2(off), 4(on), 8(off).
  	*/
        while( res * res <= n)
        {
            res++;
        }
        // -1 here since we started with 0
        return (res - 1);
    }
};
