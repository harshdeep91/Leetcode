class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> eqs;
        for (const auto& word : words) {
            string sEven;
            string sOdd;
            for (int i = 0; i < word.size(); ++i) {
                if (i % 2) {
                    sOdd.push_back(word[i]);
                } else {
                    sEven.push_back(word[i]);
                }
            }
            
            sort(sEven.begin(), sEven.end());
            sort(sOdd.begin(), sOdd.end());
            eqs.insert(sEven + sOdd);
        }
        return eqs.size();
    }
};