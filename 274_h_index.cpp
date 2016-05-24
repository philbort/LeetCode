/*

274. H-Index

Given an array of citations (each citation is a non-negative integer) of a researcher, 
write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia:
"A scientist has index h if h of his/her N papers have at least h citations each, 
and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], 
which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. 
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

*/

class Solution {

public:
	
    int hIndex(vector<int>& citations) {
        
        int size = citations.size();
        if(!size)   return 0;
        
        /* hIndex can only be between 0
           and size, so let's hash it
        */
        vector<int> count(size+1, 0);
        
        for (int i = 0; i < size; i++)
        {
            if( citations[i] > size)
                count[size]++;
            else
                count[citations[i]]++;
        }
        
        int NumOfPaper = 0;
        for (int i = size; i >= 0; i--)
        {
            NumOfPaper += count[i];
            if(NumOfPaper >= i)
                return i;
        }
        return 0;
    }
};

/*  sort first:

    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if(!size)   return 0;
        sort(citations.begin(),citations.end());
        for ( int i = 0; i < size; i++)
        {
            if (citations[i] >= size - i)
                return size - i;
        }
        return 0;
    }
*/
