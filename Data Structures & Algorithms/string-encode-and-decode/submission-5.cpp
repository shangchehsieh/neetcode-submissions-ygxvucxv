class Solution {
public:

    string encode(vector<string>& strs) {
        // encode: ["a","b","c"] -> "abc"(str)
        string res = "";
        for (string token : strs) {
            res += to_string(token.length()) + '#' + token;
        }
        return res;
    }

    vector<string> decode(string s) {
        // decode: "abc" -> ["a","b","c"](list)
        vector<string> res;
        int i = 0;
        int j = 0;
        while (i < s.size()) {
            j=i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i,j-i)); // len(s[i:j])
            res.push_back(s.substr(j+1, length));
            i = j + 1 + length;
            
        }
        return res;
    }
};
