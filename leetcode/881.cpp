/* Approach:
- at most two people
- sort and minimize the boats
- so two pointer approach

if two people can fit then good, otherwise fit the heavy one from end and proceed.
*/

#include "lib/commonImport.hpp"

using namespace std;

class Solution 
{
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(), people.end());
        
        int remaining_people = people.size();
        int count = 0;
        int beg = 0, end = people.size() -1;
        while(remaining_people)
        {
            count++;
            if(beg != end && people[beg] + people[end] <= limit)
            {
                remaining_people -= 2;
                beg++;
                end--;
            }
            else
            {
                remaining_people--;
                end--;
            }
        }
        return count;
    }
};

int main()
{
    int num;
    LOG("Enter the number of people");
    std::cin >> num;
    
    vector<int>people;
    int limit;
    int weight;

    for(int i = 0; i < num; i++)
    {
        LOG("Enter the person's weight");
        std::cin >> weight;
        people.push_back(weight);
    }

    LOG("Enter the limit(less than max weight)");
    std::cin >> limit;

    Solution obj;
    int ans = obj.numRescueBoats(people, limit);
    LOG("Boats = " << ans);
    return 0;
}


/* Question

You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
*/
