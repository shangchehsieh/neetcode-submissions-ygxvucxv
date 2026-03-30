class Solution {
public:
    bool isPalindrome(string s) {
        // alphanumeric(consists of A-Z/a-z/0-9) -> isalnum(s)
        string alnum = "";
        for (char c : s) {
            if (isalnum(c)) {
                alnum += tolower(c);
            }
        }
        return alnum == string(alnum.rbegin(), alnum.rend());
    }
};
