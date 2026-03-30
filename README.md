# Neetcode 150 (cpp)
## 語法大全
### 1. hashmap - `std::unordered_map`
- 創立 e.g. `std::unordered_map<int, int> m`
- 新增、修改 `m[key] = value`
- 搜尋key `m.find(key)` 回傳index，若找不到就回傳`m.end()`
```cpp=
if (m.find("apple") != m.end()) {
    // 找到了！
}
```
- 檢查key是否存在 `m.count(key)` return 1(存在) 0(不存在) 
- 刪除 `m.erase(key)`

### 2. stack - `string::npos`
- `.find()` 用法比較

| 容器類型 | 回傳性質 | 沒找到回傳 | 有找到回傳 |
| -------- | -------- | -------- | -------- |
| `unordered_map`     | 指標/iterator     | `s.end()`     | 指向該鍵值對的迭代器 (it)     |
| `string`     | index(int/size_t)     | `string::npos`     | 元素所在的索引 (如 0, 3)     |

### 3. binary search - `matrix.size()`
若有一個mxn的matrix - `vector<vector<int> matrix`
- `matrix.size()` 是m (這邊注意不是mxn喔！)
- `matrix[m].size()` 是n

### 4. Linked list - `*`, `&`, `->`
- [you will never ask about pointers again after watching this video](https://www.youtube.com/watch?v=2ybLD6_2gKM&t)
- 基本Memory 構造: `[Address, value]`
```cpp=
int x = 4;
int* px = &x; //*在type旁邊
int y = *px; //*在var旁邊
```
- `&`：the address of
- `*` 在int旁邊：integer pointer
  - pointer通常是一個address
  - `ListNode` 只會用在要創建new node時(e.g. 創dummy node)
  - `ListNode*` 則是用來對address (同理`TreeNode*`也是一樣！)
    - `ListNode* curr = head` 現在curr有head的address，當 `curr->val` 改變，則 `head->val` 會跟著改變
- `*` 在var旁邊：go to the address and get the value
- `->`：通常接上`next`或`val`

### 5. (For C/C++) Class - Constructor
以下以leetcode 703. Kth Largest element為例:
- 在 `class KthLargest` 中，與類別名稱完全一樣的函數 `KthLargest(...)` 就是建構函式。
- 目的：初始化變數，且沒有回傳值
```cpp=
class KthLargest {
public:
    int K; //定義成global var.
    KthLargest(int k, vector<int>& nums) {K=k;} //Constructor 定義K的值是k
    int add(int val) {
        // 這裡的K就等於k了，可以拿K做運算（用k會錯誤，因為不在定義範圍內）
    }
};
```

## 1. Arrays & Hashing
### 217. Contains Duplicate (easy)
![image](https://hackmd.io/_uploads/HJZll1H8Ze.png)

1.我的解法(Brute Force)
time :O(n^2)/ space: O(1)
```cpp
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        for (int i=0 ; i<nums.size() ; i++) {
            for(int j=i+1 ; j<nums.size() ; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }       
};
```

2. 更好的解法(Hashset)
time/space complexity: O(n)
```cpp
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        return nums.size() > std::unordered_set<int>(nums.begin(), nums.end()).size();
    }
};
```
- 這裡的`std::unordered_set<int>`就像python的set()，而後面的`nums.begin() / nums.end()`就是這個set的範圍
- `.size()`就是python中的`len()`

### 242. Valid Anagram (easy)
![image](https://hackmd.io/_uploads/S1nvuprUWg.png)

1. 我的解法: sorting
> 這裡的 `sort()` 會直接改變原物件的值，且為void故不會回傳值。跟python的`.sort()`意思相近，而python中的sorted()則是不會改變原物件的值

Time: O(nlogn + mlogm) / Space: O(1) or O(n+m)
n: s length, m:t length
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end()); //std::sort是void，會直接修改s,t，不會回傳值
        return s == t;
    }
};
```

2. HashMap
> Hashmap就是一個**同時有key, value的map**，在c++裡面，通常會這樣命名
> `unordered_map<char,int> count_s`
> 這裡的char就是key；value就是int
> 如果用pseudo code理解大致上是 count_s[key] == value

Time: O(n+m) / Space: O(1) 因為最多只會有26個字母
n: s length, m:t length
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        //case 1: length不同
        if (s.size() != t.size()) return false;
        //case 2: length同，比較字母出現頻率(Hashmap)
        unordered_map<char,int> count_s;
        unordered_map<char,int> count_t;
        for (int i=0 ; i<s.size(); i++) {
            count_s[s[i]]++;
            count_t[t[i]]++;
        }
        return count_s == count_t;
    }
};
```

3. HashTable
> 在c++裡面，創建array用 `vector<int> count(26, 0)`

Time: O(n+m) / Space: O(1) 因為最多只會有26個字母
n: s length, m:t length
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        //case 1: length不同
        if (s.size() != t.size()) return false;
        //case 2: length同，比較字母出現頻率
        vector<int> count(26, 0);// create an array "count": size26, initialize to 0
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int val : count) {
            if (val != 0) return false;
        }
        return true;
    }
};
```

### 1. Two Sum (easy)
![image](https://hackmd.io/_uploads/S1j7NMvLbg.png)

1. 我的方法 Brute Force
> 在python中若要return一個array，可以直接return `[i,j,k]` 且i,j,k可以混搭，例如[3, True, "Yes"]
> 但在C++中要return `{i, j, k}`且前提是要先定義vector(int) array

**C++ array整理:**
```cpp=
vector<int>, return {i, j, k}
pair<int, int>,return {i, j} 剛好只有兩個變數
array<int, 3>,return {i, j, k} 固定三個變數
```

Time: O(n^2) / Space: O(1)
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) return {i, j};
            }
        }
        return {};
    }
};
```
    
2. Hashmap(one pass)
review: Hashmap = `unordered_map<int, int> hashmap;`
> 在C++中，`.find()`的功能就是尋找某物是否存在，並且回傳它的位置
> 最常見的就是找key值
> 例如：`array.find("apple")`
> 如果array中並沒有"apple"，則會回傳array最尾端 (i.e. `array.end()` )
> 所以可以用`array.find("apple") != array.end()`判斷有沒有找到！

Time/Space: O(n)
    
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap; //val, index
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (hashmap.find(diff) != hashmap.end()) {
            //有沒有在hashmap找到diff
                return {hashmap[diff], i}; //yes
            }
            hashmap.insert({nums[i], i});//no, 把當前值存進去hashmap
        }
        return {};
    }
};
```

### 49. Group Anagram (medium)
![image](https://hackmd.io/_uploads/rkvEefo8bl.png)

1. Sorting + HashMap－使用字母當作key

> 1. vector或list可以用`.push_back()`，跟python的`.append()`一樣
> 2. 記住sort用法: `sort(s.begin(), s.end())` 而s本身就會被排序
> 3. `for (auto const& [key, val] : hashmap)` 這個很好用，記住！
> 使用時機: 
> a. 需要看過所有hashmap的key, val且不需要修改他們時
> b. 一個vertor裡面裝著pair(本題) `{{1, 2}, {3, 4}}`

Time: O(nlogn * K) K:the biggest length
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //build hashmap
        unordered_map<string, vector<string>> hashmap;
        //build key, value (sorting)
        for (string i : strs) {
            string sort_i = i;
            sort(sort_i.begin(), sort_i.end());
            hashmap[sort_i].push_back(i);
            //key, value append in hashmap
        }
        //find and return results (hashmap)
        vector<vector<string>> result;
        for (auto const& [key, val] : hashmap) { //for key, val in hashmap.items()
            result.push_back(val); //result.append(val)
        }
        return result;

    }
};
```

2. 時間複雜度較低的方法 HashTable
Time: O(n*K) K:the biggest length
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashtable;
        
        for (auto const& s : strs) {
            // 建立字母表 a...z
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++; // 計算每個字母各出現幾次
            }
            //利用count array建立key
            string key = to_string(count[0]);
            for (int i=1 ; i<26; i++) {
                key += ',' + to_string(count[i]);
            }
            //把key相對應的val append進去hashtable
            hashtable[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto const& [key, val] : hashtable) {
            result.push_back(val);
        }
        return result;
    }
};
```

### 347. Top K Frequent Elements (medium)
![image](https://hackmd.io/_uploads/rkxgAtoUWe.png)

靠邀好難，這題蠻值得收藏

1.Sorting
> 只取前k頻率高必背函式：
```cpp=
partial_sort(vec.begin(), vec.begin()+k, vec.end(), [](auto const&a, auto const&b) {
            return a.second > b.second;
        });
```
> 1. `vec.begin()+k` 決定只排 從頭開始的k個
> 2. `[](auto const& a, auto const& b) { return a.second > b.second; }` 定義規則。因為本題vec是pair<int,int>，所以在partial sorting時一次比兩個pair的value(i.e. `[](auto const& a, auto const& b)`) 比較大的排前面 (i.e. `return a.second > b.second`)

Time: O(nlogk) k: top freq numbers 比直接sort的O(nlogn)好很多
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        //build hashmap [key, value]
        for (int c : nums) {
            hashmap[c]++;
        }
        //store in a vector vec[{k1, v1}, {k2, v2}, ...] to sort the freq
        vector<pair<int,int>> vec(hashmap.begin(), hashmap.end());
        partial_sort(vec.begin(), vec.begin()+k, vec.end(), [](auto const&a, auto const&b) {
            return a.second > b.second;
        });
        
        //build the result array
        vector<int> result;
        for (int i=0; i<k; i++) {
            result.push_back(vec[i].first);
            //vec[i].first就是key
        }
        return result;
    }
};
```

2. Optimal Solution: Bucket Sort
![image](https://hackmd.io/_uploads/rJhIfij8-x.png)

> 超屌，完全不用sort，直接把出現頻率當作index
> 表示"那些數字出現這麼多次"
> 在列印result時，從頻率最高的開始找，故 `int i = freq.size() - 1`


Time: O(n)
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);
        //the blue table {{100}, {2}, {1}, ...}
        
        //hashmap
        for (int c : nums) {
            count[c]++;
        }
        // hashmap append into the blue table
        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
            //entry.first是那個數字; entry.second是頻率
            //i.e. freq[頻率] = 那個數字
        }
        
        //result
        vector<int> res;
        for (int i = freq.size() - 1; i > 0; i--) {
            for (int n : freq[i]) { 
                res.push_back(n);
                if (res.size() == k) return res; //集滿前k多就停止
            }
        }
        return res;
    }
};
```

### 271. Encode and Decode Strings (medium)
詳細解說請看[Neetcode 150 python版本](https://hackmd.io/hM48clIwS-ymV8lRuDqifA?view#271-Encode-and-Decode-Strings-medium)

> 1. int to str: `to_string()` <-> str to int: `stoi()`
> 2. `s.substr(position, length)` 用來擷取字串，從s的position開始往右取length個，很像python的`s[i:j]`


```cpp
//e.g. input: ["Hello","World"]
class Solution {
public:

    string encode(vector<string>& strs) {
        // encode: ["Hello","World"] (vector) -> "5#Hello5#World" (str)
        string res = "";
        for (string token : strs) {
            res += to_string(token.length()) + '#' + token;
        }
        return res;
    }

    vector<string> decode(string s) { //s == "5#Hello5#World"
        // decode: str -> vector
        vector<string> res;
        int i = 0; //專找len用
        int j = 0; //專找#
        while (i < s.size()) { //s.size() == 14
            j=i;
            while (s[j] != '#') {
                j++; 
            }
            int length = stoi(s.substr(i,j-i)); 
            //to_string() <-> stoi() (str to int)
            res.push_back(s.substr(j+1, length));
            i = j + 1 + length;
        }
        return res;
    }
};
```

 ### 238. Products of Array Except Self (medium)
 詳細解說請看[Neetcode 150 python版本](https://hackmd.io/hM48clIwS-ymV8lRuDqifA?view#238-Products-of-Array-Except-Self-medium)
 
1.Brute Force
Time: O(n^2) / Space: O(n)
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i<nums.size(); i++) {
            int tmp = 1;
            for (int j = 0; j<nums.size(); j++) {
                if (i == j) continue;
                tmp *= nums[j];
            }
            res.push_back(tmp);
        }
        return res;
    }
};
```
2. Prefix & Suffix
Time/Space: O(n)
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<int> pref(n, 0);
        vector<int> suff(n, 0);
        pref[0] = 1;
        suff[n-1] = 1;
        for (int i = 1; i<n; i++) {
            pref[i] = pref[i-1] * nums[i-1]; //red
        }
        for (int j = n-2; j>-1; j--) {
            suff[j] = suff[j+1] * nums[j+1]; //green
        }
        for (int k = 0; k<n; k++) {
            res[k] = pref[k] * suff[k];
        }
        return res;
    }
};
```
 
3. Prefix & Suffix (Optimal)
Time:O(n)/ Space: O(1)
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1); //step1

        int prefix = 1;
        for (int i = 0; i<n; i++) {//step2
            res[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for (int j = n-1; j>-1; j--) {//step3
            res[j] *= postfix;
            postfix *= nums[j];
        }
        return res;
    }
};
```
### 36. Valid Sudoku (medium)
1. 我的解法 (Brute Force + Hashset)
- 使用hashset檢查row和col是否有重複的1-9，再用它獨立檢查9個square內是否有重複的1-9
```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row/col

        for (int i = 0; i<9; i++) {
            vector<char> col;
            vector<char> row;
            for (int j = 0; j<9; j++) {
                if (board[i][j] != '.') {
                    row.push_back(board[i][j]);
                }
                if (board[j][i] != '.') {
                    col.push_back(board[j][i]);
                }
                if (row.size() != unordered_set<char> (row.begin(), row.end()).size()
                || col.size() != unordered_set<char> (col.begin(), col.end()).size()) {
                    return false;
                }
            }
        }
        // square
        
        for (int start = 0; start<9; start++) {
            // start point each square: 00 03 06 30 33 36 60 63 66
            vector<char> squ;
            for (int i = 3*(start/3); i<3*(start/3)+3; i++) {
                for (int j = 3*(start%3) ; j<3*(start%3)+3; j++) {
                    if (board[i][j] != '.') {
                        squ.push_back(board[i][j]);
                    }
                    if (squ.size() != unordered_set<char> (squ.begin(), squ.end()).size()) {
                        return false;
                    }
                }
            }
        }
        //row, col, squ皆符合
        return true;
    }
};

```
2. Hashmap
> `.insert()`就是python的`.add()`

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row, col; //row key: r; col key:c
        map<pair<int, int>, unordered_set<char>> squ; //key: (r/3, c/3) (tuple)

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                if (row[r].count(board[r][c]) //if board[r][c] appear in col/row/squ
                || col[c].count(board[r][c]) 
                || squ[{r/3, c/3}].count(board[r][c])) {
                    return false;
                }
                row[r].insert(board[r][c]); //update 1-9 in cols
                col[c].insert(board[r][c]); //update 1-9 in rows
                squ[{r/3, c/3}].insert(board[r][c]); //update 1-9 in squares
            }
        }
        return true;
    }
};
```

### 128. Longest Consecutive Sequence (medium)
![image](https://hackmd.io/_uploads/HJAQ6ibvWg.png)

這題如果用sorting超級簡單，Time: O(nlogn)，但本題Time Complexity要求O(n)，所以我們要用別的方式：

**1.HashSet (Optimal)**
Time/Space: O(n)
![image](https://hackmd.io/_uploads/rJSlbVGvbe.png)

- 先建立`unordered_set`除掉一些重複的值
- 遍歷整個set，看(數字-1)存不存在，若不存在那(數字)就是車頭
- 查看(數字+1)、(數字+2)、...直到找到車尾，紀錄長度`length`
- 最後比較各長度，得到最長的車`longest = max(longest, length)`
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int longest = 0;//紀錄最長的車
        for (int i : nums_set) {
            if (nums_set.find(i-1) == nums_set.end()) { // i-1不在 ->車頭
                int length = 1;
                while (nums_set.find(i+length) != nums_set.end()) {
                    //i+1, i+2在 ->length增加直到看到車尾
                    length++;
                }
                longest = max(longest, length); //更新 衛冕者vs新挑戰者 誰的車長
            }
        }
        return longest;
    }  
};
```
2. Hashmap
Time/Space: O(n)
- 過濾重複的值 `hashmap[i] == 0`
- 利用左鄰右舍計算車子長度
- 更新車子長度，並和衛冕者比較
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int res = 0;

        for (int i : nums) {
            if (hashmap[i] == 0) { //數字i處理過就skip
                //車子長度 == 左鄰長度+右舍長度+自己
                hashmap[i] = hashmap[i-1] + hashmap[i+1] + 1;
                //update車頭 / 車尾 ->車子長度改變
                hashmap[i - hashmap[i-1]] = hashmap[i];
                hashmap[i + hashmap[i+1]] = hashmap[i];
                //衛冕者vs新挑戰者
                res = max(res, hashmap[i]);
            }
        }
        return res;
    }
};
```

## 2. Two Pointers

### 125. Valid Palindrome (easy)
![image](https://hackmd.io/_uploads/HJuUPEfP-l.png)

1. Reverse String
Time/Space: O(n)
- 檢驗是否是alpha numeric(數字/字母) `isalnum()`，如果是就轉小寫
- `.rbegin()`和`.rend()`的r是reverse，從尾到頭
```cpp
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
```


2. Two Pointers (Optimal)
Time: O(n) / Space: O(1)
- Two pointers: `l`, `r`
- 內圈的`l<r`是為了要make sure l++和r- -不會超過邊界
- 可運用`isalnum()`
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        //two pointers: left, right
        int l = 0, r = s.length()-1;

        while (l<r) {
            while (l<r && !isalnum(s[l])) l++;
            while (l<r && !isalnum(s[r])) r--;
            // l<r again, because i++ or r-- may surpass the bound
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
```

### 167. Two Sum II - Input array is sorted (medium)
![image](https://hackmd.io/_uploads/H1e0W6CMvZe.png)

Two pointers
Time: O(n) / Space: O(1)
- 注意：Return the indices (1-indexed) of two numbers，所以最後回傳時要記得+1（因為一般都是0-indexed)
- 因為input是sorted，所以可以很簡單：相加太大就找小一點的r；態小就找大一點的l，直到相加起來剛好等於target
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //return [index1, index2]
        int l = 0, r = numbers.size()-1;
        while (numbers[l] + numbers[r] != target) {
            if (numbers[l] + numbers[r] > target) r--;//too large
            if (numbers[l] + numbers[r] < target) l++; //too small
        }
        return {l+1, r+1}; //Return the indices (1-indexed) of two numbers
    }
};
```
### 15. 3Sum (medium)
1. Two Pointers
這個解法是延續 `167. Two Sum II`，複習一下Two Sum II的解法
:::success
1. sort (那一題已經sort了，略)
2. 令`l=0`, `r=len-1`
3. `sum > target`: 太大，`r--`讓sum變小；`sum < target`: 太小，`l++`讓sum變大
:::

> 本題解法也是類似概念
> 1. sort `sort(nums.begin(), nums.end());`
> 2. 與Two Sum II 不同的是，除了L和R，這題有會變動的第三者 `nums[a]`，而且這個數一定要是負數，不然越往右邊數字越大，三個相加就不可能會=0
> 3. `a>0 && nums[a] == nums[a-1]` 一樣的數就不用再跑一次了，記得要加上`a>0`不然 `a == 0` 的時候就會卡住
> 4. 處理LR－ `l = a+1` 且 `r = nums.size()-1` 
> - 若 `sum>0`，太大，`r--`
> - 若 `sum<0`，太小，`l++`，直到l比r大
> - 若 `sum == 0`，將結果放到res
![image](https://hackmd.io/_uploads/HyVhFLxuZx.png)

Time: O(n^2), Space: 
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //hashmap
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int a = 0 ; a<nums.size()-2; a++) {

            if (nums[a] > 0) break; // nums[a] must <=0
            if (a>0 && nums[a] == nums[a-1]) continue;
            
            int l = a+1, r = nums.size()-1;
            while (l<r) {
                int sum = nums[a] + nums[l] + nums[r];
                if (sum>0) r--;
                else if (sum<0) l++;
                else {
                    res.push_back({nums[a], nums[l], nums[r]});
                    r--; l++;
                    while (l<r && nums[l] == nums[l-1]) l++;
                }
            }
        }
        return res;
    }
};
```


## 3. Sliding window

### 121. Best Time to Buy and Sell Stock (easy)
:::warning
Sliding window大多可以用two pointers解決，算是two pointers的印用
- l=0
- r用迴圈跑，一直增加，等到不得已再l++
:::
![image](https://hackmd.io/_uploads/SyHnaI7DWl.png)

1. Two pointers
> two pointers: `l`(buy), `r`(sell)
> 若profit是負的(buy-sell<0): `l = r`
> 若profit是正的(buy-sell>0): 更新pro

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1; //l:buy, r:sell
        int pro = 0;
        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                pro = max(pro, prices[r] - prices[l]);
            }else{
                l = r;
            }
            r++;
        }
        return res;    
    }
};
```

### 3. Longest Substring Without Repeating Characters (medium)

1.Brute Force
![image](https://hackmd.io/_uploads/S14Tophwbg.png)

Time:O(nm) / Space:O(m)
n: length of the string, m:unique char in the string
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        for (int i = 0; i<s.length(); i++) {
            unordered_set<char> charSet;
            for (int j=i; j<s.length(); j++) {
                if (charSet.find(s[j]) != charSet.end()) break; //s[j] in set
                charSet.insert(s[j]); //s[j] not in set -> insert
            }
            res = max(res, (int)charSet.size());
        }
        return res;
    }  
};
```
2. Sliding Window (two pointer)
> 1. 創立`charSet`以及two pointers `l`, `r` (left/right side of the window)
> 2. For each `r`:
    > 當`s[r]`已經在set中，在set中移除`s[l]`並且l++
    > 當`s[r]`不在set中，加入`s[r]`
    > 更新window size: `r-l+1`

Time:O(n) / Space:O(m)
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0, res = 0;
        for (int r=0; r<s.length(); r++) {
            while (charSet.find(s[r]) != charSet.end()) {//s[r] in set
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]); // s[r] not in set
            res = max(res, r-l+1);
        }
        return res;
    }
};
```

### 424. Longest Repeating Character Replacement (medium)
![image](https://hackmd.io/_uploads/BJNxN6Cw-l.png)

:::warning
挖咧完全寫不出來==
:::

1. Sliding Window
> 1. 建立set `charSet`，把s中的所有字母記錄起來
> 2. `for (char c : charSet)` : 用來記錄每個字母分別有幾個
> 3. Sliding window: `l=0`, `for r`
> 4. 如果 `s[r] == c`，就count++
> 5. 只要 `(r-l+1) - count <= k` ，the window都還是valid，可以繼續使用，直到不能用再移動l (`l++`)

Time: O(mn) m:s的字母數量；Space: O(m)
Time最多能夠O(26n)
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> charSet(s.begin(), s.end()); // {X, Y}
        int res = 0;
        for (char c: charSet) { // 1.X 2.Y
            int count = 0, l = 0;
            for (int r=0; r<s.size(); r++) {
                if (s[r] == c) count++; //1. how many X in the window
                while ((r-l+1)-count > k) { // the window needs >k replacements
                    if (s[l] == c) count--;
                    l++;                    // move l right
                }
                res = max(res, r-l+1); //update result
            }
        }
        return res;
    }
};
```
2. Sliding Window (Optimal)
> 1. Sliding Window `l=0`, `for r`
> 2. 建立hashmap `count`，先記錄每個字母的頻率，再使用`maxf`找出出現最多幾次
> 3. 改成`(r-l+1) - maxf > k` 

Time: O(n), Space:O(m)
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int res = 0;
        int maxf = 0, l = 0;
        for (int r=0; r<s.size(); r++) { // how many X? how many Y?
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            while ((r-l+1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
```


## 4. Stack

### 20. Valid Parentheses (easy)
![image](https://hackmd.io/_uploads/Sk2-SY6uZx.png)


1. Brute Force
>1. 先定義`size_t pos` (size_t其實就是只有正數的int)，如果有找到`()`則pos是index，反之則是string::npos
>2. `s.erase(pos, 2)`是指說如果有`()`, `[]`, `{}`就把他們刪掉 (從s中第pos個字元開始刪掉兩個字)
>3. `return s.empty()`: 如果s刪一刪最後是空的那會回傳true，反之是false

Time: O(n^2) / Space:O(n)

```cpp
class Solution {
public:
    bool isValid(string s) {
        size_t pos;
        while (true) {
            pos = s.find("()");
            if (pos == string::npos) { //not found ()
                pos = s.find("[]");
                if (pos == string::npos) {//not found () []
                    pos = s.find("{}");
                    if (pos == string::npos) break; //not found () [] {}
                }
            }
            s.erase(pos, 2);
        }
        return s.empty();
    }
};
```

2. stack

> 使用Dictionary 將(), [], {}定義起來 -> key:value
> `if c in closeToOpen`
>   - 若c是右括號`)]}`：那就等著配對`([{`
>   - 若c是左括號`([{`：那就存到stack
> 
> stack採用LIFO，最後進來的，也就是最上面的，先`.pop()`

Time / Space: O(n)
```cpp
class Solution {
public:
    bool isValid(string s) {
        //build stack
        stack<char> stack;
        //dictionary: key(right brackets), value(left brackets)
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for (char c : s) {
            if (closeToOpen.count(c)) { //if the key 'c' is right brackets
                 
                if (!stack.empty() && stack.top() == closeToOpen[c]) {
                    stack.pop(); //if match a pair () [] {}
                } else {
                    return false;
                }
            } else { // if the key 'c' is left brackets -> store in stack
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
```
### 155. Min stack (medium)
![image](https://hackmd.io/_uploads/SJ8gEnZY-x.png)

最佳解法: Two Stacks
![image](https://hackmd.io/_uploads/rkox42WK-e.png =50%x)

1. 使用2個stack (定義在初始化函式外面！)
  - `stack` - stores all pushed values
  - `minStack` - stores the minimum so far at each level
    :::warning
    public的初始化函式幾乎都是空白的，不像python的 `__init__` 用self就能解決，所以通常寫C++時都是把變數定義在初始化函式外面，如 `std::stack<int> stack, minStack;`
    :::
2. 處理 `push(val)`
  - 把val放進去 `stack`
  - 更新val，`minStack最上面的` 跟 `現在的val` 兩者做比較，現在的val是目前最小的了
    :::warning
    炫技－ `minStack.empty() ? val : minStack.top()`
    - 若minStack為空，回傳val
    - 若minStack非空，回傳minStack.top()
    :::
  - 把最小val放進去 `minStack`
3. 處理 `pop()` 兩個stack都要清掉！
4. 處理 `top()` return `stack` 最上面
5. 處理 `getMin()` return `minStack` 最上面
Time: O(1) for all operations. / Space: O(n)
```cpp
class MinStack {
public:
    std::stack<int> stack, minStack;
    MinStack() {} // public的初始化函式幾乎都是空白的
    
    void push(int val) {
        stack.push(val);
        val = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
```

### 150. Evaluate Reverse Polish Notation (medium)
很開心，我自己用stack寫出來了，但本題還有Doubly Linked List / Recursion 的方式，複雜度和stack 一樣皆為O(n) 值得探討。
:::success
**比較** Postfix(本題): 34+ / Infix: 3+4 / Prefix: +34
:::
Stack (我的解法)
- 先建立一個stack準備存放數字
- 遇到運算符號時，把數字從stack挑出來做運算，算完再丟回stack裡面
Time / Space: O(n)
```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num1+num2);
                else if (tokens[i] == "-") st.push(num1-num2);
                else if (tokens[i] == "*") st.push(num1*num2);
                else if (tokens[i] == "/") st.push(num1/num2);
            }else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();   
    }
};
```
Stack (官方解法)
- `const string& c : tokens` c直接指向tokens這個vector（比string c從tokens複製的效率高很多）
- 減少`if`和`else if`使用量，改成分別看 `+-x/`
```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& c : tokens) {
            if (c == "+") {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                st.push(num1+num2);
            } else if (c == "-") {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                st.push(num1-num2);                
            } else if (c == "*") {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                st.push(num1*num2);                
            } else if (c == "/") {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                st.push(num1/num2);                
            } else {
                st.push(stoi(c));
            }
        }
        return st.top();   
    }
};
```

## 5. Binary Search
### 704. Binary Search (easy)
![image](https://hackmd.io/_uploads/HkPh4Cwt-l.png)

1. Iterative Binary Search
Time: O(logn) / Space: O(1)
- `int m = l + (r-l)/2;` 為了防止溢位，中間值採用**左指標+一半距離**
- 若`nums[m] > target`: 代表m到r的數字作廢－`r=m-1`
- 若`nums[m] < target`: 代表l到m的數字作廢－`l=m+1`
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while (l<=r) {
            int m = l + (r-l)/2;
            if (nums[m] > target) r=m-1;
            else if (nums[m] < target) l=m+1;
            else return m;
        }
        return -1;
    }
};
```
2. Recursive Binary Search
- 需要額外定義`binary_search` 函式
Time / Space: O(logn)
```cpp
class Solution {
public:
    int binary_search(int l, int r, vector<int>& nums, int target) {
        if (l>r) return -1;
        int m = l + (r-l)/2;
        if (nums[m] == target) return m;
        return (nums[m]>target ?
            binary_search(l, m-1, nums, target) :
            binary_search(m+1, r, nums, target)
            );
    }

    int search(vector<int>& nums, int target) {
        return binary_search(0, nums.size()-1, nums, target);
    }
};
```
### 74. Search a 2D Matrix (medium)

![image](https://hackmd.io/_uploads/ByklSAPtWx.png)


1. Brute Force (不符合題目要求)
- `matrix.size()` 會return 有幾列
- `matrix[r].size()` 會return 有幾行

Time: O(mxn) / Space: O(1)
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int r = 0; r<matrix.size(); r++) {
            for (int c = 0; c<matrix[r].size(); c++) {
                if (matrix[r][c] == target) return true;
                else continue;
            }
        }
        return false;
    }
};
```
2. Binary Search
因為是二維向量(矩陣)，因此要做兩次binary search:
- 第一次做"列"的binary search (`top`, `bot` )，找出target在哪一列
- 第二次做"同一列"的binary search (`l`, `r` )，找出target

Time: O(logm+logn) = O(log(mxn)) / Space: O(1)
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        // 1.Binary Search for ROWS
        int top = 0, bot = ROW - 1;
        while (top<=bot) {
            int row = top + (bot-top)/2;
            if (target > matrix[row][COL-1]) top = row+1;
            else if (target < matrix[row][0]) bot = row-1;
            else break; 
        }

        if (top>bot) return false;
        // 2.Binary Search for THE ROW WHERE EXISTS TARGET
        int l = 0, r = COL-1;
        int row = top + (bot-top)/2;

        while (l<=r) {
            int m = l + (r-l)/2;
            if (target > matrix[row][m]) l=m+1;
            else if (target < matrix[row][m]) r=m-1;
            else return true;
        }
        return false;
    }
};
```
3. Binary Search (one pass)
這是2.的變異版，直接把二維向量flatten成一維向量來解，但我覺得有點多此一舉，因為到了 `matrix[row][col]` 時還是要用到矩陣的概念
Time: O(logm+logn) = O(log(mxn)) / Space: O(1)
![image](https://hackmd.io/_uploads/HysAK1_FWe.png)

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size(), COLS = matrix[0].size();

        int l = 0, r = ROWS * COLS - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int row = m / COLS, col = m % COLS;
            if (target > matrix[row][col]) {
                l = m + 1;
            } else if (target < matrix[row][col]) {
                r = m - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
```
### 875. Koko Eating Bananas (medium)
![image](https://hackmd.io/_uploads/rJIcxWuYWg.png)

- 每小時能挑一串香蕉，吃k根，共有h小時可以吃
- 若那一串<k個，那妳可以吃完整串，但剩下的時間不能去吃別串
- 注意: `1 <= piles[i] <= 1,000,000,000`，當k超級小時，`time` 會變超級大，為了防止Integer overflow，可以 `long long代替int`
1.Brute Force

Time: O(mxn) / Space: O(1)
```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 1;
        while (true) {
            long long time = 0;// avoid integer overflow
            for (int num : piles) {
                if (num <= k) {
                    time++;
                } else {
                    if (num % k == 0) time += num/k;
                    else time += (num/k)+1;
                }
            }
            if (time <= h) return k;
            k++;
        }
    }
};
```
2. Binary Search
- `*max_element(piles.begin(), piles.end())` 星號一定要加！
  - `max_element`會回傳地址，加上星號代表叫他找那個地址的值
- 如果 `time<=h` 代表k或許還能再更小，直到 `time>h`
![image](https://hackmd.io/_uploads/SJz0VMOKbl.png)

Time: O(nlogm) / Space: O(1)
```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int k = l + (r-l)/2;

            long long time = 0;
            for (int p : piles) {
                if (p%k==0) time += p/k;
                else time += (p/k)+1;
            }
            // binary search
            if (time <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};

```

## 6. Linked List
:::success
- 同時包含data/pointer，可能需要紙筆demo一下思緒會比較清楚
- 若list資料型別為`ListNode*` (python是`list = Optional[ListNode]`)
->這個list預設值是他的頭
- 只要**回傳list node的head**，基本上就是**回傳一整串以head當頭的串列**
:::

### 206. Reversed linked list (easy)
詳細解題步驟詳見 [Python版本](https://hackmd.io/hM48clIwS-ymV8lRuDqifA?view#206-Reversed-Linked-listeasy)

1. Iteration
- 使用 `ListNode*` 定義且更改node的值
Time: O(n) / Space: O(1)
```cpp!
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //nullptr -> 0 -> 1 -> 2 -> 3 -> nullptr
        //          head
        // prev     curr next
        if(head == nullptr) return nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};
```

2. Recursion
Time: O(n) / Space: O(n)
```cpp!
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* newHead = head;
        if (head->next) {
            newHead = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
        }
        return newHead;
    }
};
```

### 21. Merge Two Sorted Linked Lists (easy)
![image](https://hackmd.io/_uploads/HyBRIXBoZx.png)

Iteration

1. 新增節點ListNode `dummy(0)` (應該只有這一題是這樣用ListNode)
2. 讓pointer `tail` 指向 dummy addr.
3. Dummy: 不用判斷「第一個接誰」，整個流程統一由 tail 來接新節點，最後直接回傳 dummy.next 就是頭
4. list1 和 list2 非空：看list1和list2誰的值比較小，就接到 tail->next，最後要記得更新tail的位置 `tail = tail->next`
5. 需考慮list1, list2長度不同的情形
6. 回傳head `dummy.next`
  - `dummy.next`用在dummy是一個節點 (`ListNode dummy(0)`)
  - `dummy->next`用在dummy是一個pointer (`ListNode* dummy = &x`)

Time: O(n+m) (n: len of list1; m: len of list2) / Space: O(1)
```cpp!
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        //若list1, list2長度不同：將剩下的nodes全部接在tail後面
        if (list1) tail->next = list1;
        else if (list2) tail->next = list2;
        return dummy.next;
    }
};
```

## 7. Tree
:::success
DFS常用技巧：
```cpp
height = 1 + max(left_height, right_height)
diameter = left_height + right_height
```
BFS常用技巧：
- `queue<TreeNode*> queue`, `queue.push(root)` (暫存)
- `TreeNode* node = queue.front()` , `queue.pop()`(操作用)
:::
### 226. Invert Binary Tree (easy)
![image](https://hackmd.io/_uploads/ByoLzZQP-e.png)

1. DFS
Time/Space: O(n)
- 注意：防止空的測資，無論DFS/BFS都要附上`if(!root) return nullptr`
- 互換當前root(treenode)的左右children
```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr; //等同None(不回傳)
        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```
2. BFS
Time/Space: O(n)
> 1. `.push()`專用在queue, stack；`.push_back`專用在vector, list
> 2. 建立暫存`queue`，且把root push進去
> 3. 建立操作`node`，先進去queue的先被丟到 `node` (FIFO)
> 4. 在node交換
> 5. 如果左邊小孩存在，丟到queue下一步處理，同理右邊小孩也是

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> queue; //cache
        queue.push(root);
        //push the root of the whole tree (the key to explore the tree)

        while (!queue.empty()) { //non empty
            TreeNode* node = queue.front();
            queue.pop();
            swap(node->left, node->right); //swap via node
            if (node->left) queue.push(node->left);
            if (node->right) queue.push(node->right);
        }

        return root;
    }
};
```

:::warning
**為何都在node上操作，但最後還是可以return root?**
因為`TreeNode*`有地址的觀念，所以可想成root就代表整個tree，所以通常在做BFS時，都會額外新增
- `queue<TreeNode*> queue`, `queue.push(root)` (暫存)
- `TreeNode* node = queue.front()` , `queue.pop()`(操作用)
:::

### 104. Maximum Depth of Binary Tree (easy)
![image](https://hackmd.io/_uploads/Hy79BisYbe.png)

1.DFS
```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //Depth == height == 1 + max(lh, rh)
        if (!root) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};
```
2.BFS
> `int queue_size = queue.size();` 超重要！因為`queue.size()`會隨著BFS的過程一直變動，如果沒有在進入迴圈之前就儲存好，for迴圈在使用時就會出錯

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        //cache
        queue<TreeNode*> queue;
        queue.push(root);

        int depth = 0;
        while(!queue.empty()) {
            int queue_size = queue.size(); //重要！
            for (int i = 0; i<queue_size ; i++) {
                //operate
                TreeNode* node = queue.front();
                queue.pop();
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};
```

### 543. Diameter of Binary Tree (easy)

DFS
- 沿用上一題Maximum Depth of Binary Tree (easy) 的方法，額外新增一個函數 `height`，用來記錄深度(高度) `1+max(l,r)`
- 藉著`height`順便紀錄 `length = max(length, l+r);` 得到長度

Time: O(n) / Space: O(h) h:tree的高度
- 在最壞的情況下（樹呈鏈狀），空間複雜度為 $O(N)$
- 在最好的情況下（平衡樹），空間複雜度為 $O(\log N)$
```cpp!
class Solution {
public:
    int length = 0;
    int height(TreeNode* root) {
        if (!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        length = max(length, l+r);
        return 1 + max(l,r);
        }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return length;
    }
};
```

### 110. Balanced Binary Tree (easy)
![image](https://hackmd.io/_uploads/S1hG7HCtbx.png)

1. Brute Force
- 沿用Maximum Depth of Binary Tree (easy) 的方法，額外新增一個函數 `height`，用來記錄深度(高度) `1+max(l,r)`
- 在 `isBalanced` 中，`abs(lh-rh)>1` 代表不平衡
- 最後要進行recursive check `isBalanced(root->left) && isBalanced(root->right);`
Time: O(n^2) / Space: O(n)
```cpp!
class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        return 1 + max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int lh = height(root->left);
        int rh = height(root->right);
        if (abs(lh-rh)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
```

2. DFS
- Brute Force太慢，會重複計算。改用DFS則每個node只會被走訪一次
- 演算法: 遞迴計算left / right subtree -> 從leaf慢慢往上層計算
  - 若樹平衡－回傳正常高度
  - 若樹不平衡－回傳-1 (代表不正常)
  - 最後用`height(root) != -1;`得出布林值\

Time: O(n) / Space: O(h)
- 在最壞的情況下（樹呈鏈狀），空間複雜度為 $O(N)$
- 在最好的情況下（平衡樹），空間複雜度為 $O(\log N)$
```cpp!
class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (left == -1) return -1; //not balanced
        if (right == -1) return -1; //not balanced
        if (abs(right-left)>1) return -1; //not balanced
        return 1 + max(left, right); //balanced
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
```

### 100. Same Tree (easy)
![image](https://hackmd.io/_uploads/ByMhOLa5bg.png)

1.DFS
- `p`,`q`都是nullptr -> true
- `p`, `q`其一是nullptr -> false
- 值不一樣 -> false
- 最後要true and true才會回傳true

Time: O(n) / Space:O(h) h:the height of tree
- Best Case (balanced tree): O(log(n))
- Worst Case (degenerate tree): O(n)

```cpp!
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
```

2.BFS
:::success
- 起手式: `queue<TreeNode*> queue`, `queue.push(root)` (暫存)
- while(非空): `TreeNode* node = queue.front()` , `queue.pop()`(操作用)
:::
Time: O(n) / Space: O(n)
```cpp!
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p); // cache
        q2.push(q); // cache

        while(!q1.empty() && !q2.empty()) {
            for(int i = q1.size(); i>0; i--) {
                TreeNode* nodeP = q1.front();
                q1.pop();
                TreeNode* nodeQ = q2.front();
                q2.pop();
                if(!nodeP && !nodeQ) continue;
                if (!nodeP || !nodeQ) return false;
                if (nodeP->val != nodeQ->val) return false;

                q1.push(nodeP->left); q1.push(nodeP->right);
                q2.push(nodeQ->left); q2.push(nodeQ->right);
            }
        }
        return true;
    }
};
```

## 8. Heap / Priority Queue
:::warning
1. Heap是實現Priority Queue的資料結構，簡單來說就是一棵Binary tree
2. Priority Queue可以想成是會自動排序的Queue，只要有new entry進入queue，他會自動找到屬於他的位置
3. Heap 有兩種：
  - **MaxHeap**: root最大，越來越小，code: `priority_queue<int>`
  - **MinHeap**: root最小，越來越大，code: `priority_queue<int, vector<int>, greater<int>>`
:::
這方法比 `sort()` 有效率太多了：
- Sorting: `sort()`: O(nlogn)
- Heap: 1.`.push()`: O(logn) 2.`.pop()`: O(logn) 3.`.top()`: O(1)
- 
### 703. Kth Largest Element in a Stream (easy)
MinHeap
```cpp
class KthLargest {
public:
    //global var/heap
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    //constructeor: define K and pq
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int n : nums){
            pq.push(n);
            if (pq.size() > K) {
                pq.pop();
            }
        }
    }
    //add func
    int add(int val) {
        pq.push(val);
        while (pq.size() > K) {
            pq.pop();
        }
        return pq.top();
    }
};
```

Time: O(mlogk)) / Space: O(k)