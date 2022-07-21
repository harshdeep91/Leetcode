class Solution {
public:
//     Algorithm: Start from the last step, and go back to the first step.
// Our vector is [2,13,3,11,5,17,7].
// The last step is [17], which is the largest element. [17]
// Before 17, the number should be 13. Of course, the vector can be [13, 17], as we pop out 13, then there is 1 element in the vector, it does not matter whether we rotate the vector.[13 ,17]
// The next element should be 11. If we wanna make the vector like [13, 17] after popping out 11, then 17 should be the next element after 11. Because once we pop out 13, the 17 can be moved to the end of vector. so now the vector is [11, 17, 13]
// The next element is 7. Similar as previous step, if we want to make the vector to be [11, 17, 13] after popping out 7, then 13 is the next element after 7, so the vector is [7, 13, 11, 17]
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // Sort by increasing order.
        sort(deck.begin(), deck.end());
        
        // Return the ans if there are max 2 elements since it's already sorted.
        if (deck.size() <= 2)
        {
            return deck;
        }
        
        // For more than 2 elements.
        deque<int> ans;
        ans.push_front(deck.back());
        deck.pop_back();
        
        while (!deck.empty())
        {
            int temp = ans.back();
            ans.pop_back();
            ans.push_front(temp);
            ans.push_front(deck.back());
            deck.pop_back();
        }

        return vector<int>(ans.begin(), ans.end());
    }
};