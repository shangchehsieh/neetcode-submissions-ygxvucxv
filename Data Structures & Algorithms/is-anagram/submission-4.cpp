class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end()); //std::sort是void，會直接修改s,t，不會回傳值
        return s == t;
    }
};
