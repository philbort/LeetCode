/*

295. Find Median from Data Stream

Median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2

*/

class MedianFinder {

public:

    // Adds a number into the data structure.
    void addNum(int num) {
    	
        if( small.empty() || num < small.top() )
            small.push(num);
        else
            large.push(num);
            
        // The sizes should differ at most by 1
        if ( small.size() > large.size() + 1 )
        {
            large.push(small.top());
            small.pop();
        }
        else if ( large.size() > small.size() + 1 )
        {
            small.push(large.top());
            large.pop();
        }

    }

    // Returns the median of current data stream
    double findMedian() {
        return small.size() == large.size() ?
               ( small.top()+large.top() )/2.0 :
               small.size() > large.size() ?
               small.top() : large.top();
    }
private:
    priority_queue<int> small;  // max_heap
    priority_queue<int, std::vector<int>, std::greater<int>> large;  // min_heap
    
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
