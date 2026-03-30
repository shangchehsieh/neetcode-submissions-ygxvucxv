class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //build hashmap
        unordered_map<string, vector<string>> hashmap;
        //build key, value
        for (string i : strs) {
            string sort_i = i;
            sort(sort_i.begin(), sort_i.end());
            hashmap[sort_i].push_back(i);
            //key, value append in hashmap
        }
        //find and return results
        vector<vector<string>> result;
        for (auto const& pair : hashmap) { //for key, val in hashmap.items()
            result.push_back(pair.second); //result.append(val)
        }
        return result;

    }
};