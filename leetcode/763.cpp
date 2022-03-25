#include "lib/commonImport.hpp"

class Solution 
{
public:
    std::vector<int> partitionLabels(std::string s) 
    {
        int beg = 0, end = 0;
        std::vector<int> result;
        
        // store the last index of each character
        std::vector<int> index(26,-1);
        for(int i = 0; i < s.length(); i++)
            index[s[i] - 'a'] = i;
        
        // traverse and check now
        for(int i = 0; i < s.length(); i++)
        {
            end = end > index[s[i] - 'a'] ? end : index[s[i] - 'a'];
            
            if(i == end)
            {
                result.push_back(end - beg + 1);
                beg = end + 1;
            }
        }
        return result;
    }
};

int main()
{
    std::string s = "ababcbacadefegdehijhklij";
    Solution obj;
    std::vector<int> result = obj.partitionLabels(s);
    for(const int& ch : result)
        LOG("index : " << ch);
    return 0;
} 


/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
*/
