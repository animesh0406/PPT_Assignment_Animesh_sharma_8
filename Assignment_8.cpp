#include<bits/stdc++.h>
using namespace std;
/*
Question 1
Given two strings s1 and s2, return *the lowest **ASCII** sum of deleted characters to make two strings equal*.

**Example 1:**

**Input:** s1 = "sea", s2 = "eat"

**Output:** 231

**Explanation:** Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.

Deleting "t" from "eat" adds 116 to the sum.

At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
*/
int minimumDeleteSum(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i)
      dp[i][0] = dp[i - 1][0] + s1[i - 1];

    for (int j = 1; j <= n; ++j)
      dp[0][j] = dp[0][j - 1] + s2[j - 1];

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (s1[i - 1] == s2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);

    return dp[m][n];
}


/*
<aside>
💡 **Question 2**

Given a string s containing only three types of characters: '(', ')' and '*', return true *if* s *is **valid***.

The following rules define a **valid** string:

- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

**Example 1:**

**Input:** s = "()"

**Output:**

true

</aside>
*/

bool checkValidString(string s) {
        stack<int> st, st1;
        
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(' || s[i] == '*')
                st.push(s[i]);
            else
                if (st.empty())
                    return false;
                else {
                    while (!st.empty() && st.top() == '*') { 
                        
                        st1.push(st.top()); 
                        st.pop();   
                    }
                    
                    if (st.empty())  
                        st1.pop();
                    else 
                        st.pop();
                    
                    while (!st1.empty()) { 
                        
                        st.push(st1.top());
                        st1.pop();
                    }
                }
        }
        
        int sc = 0; 
        char c;
        
        while (!st.empty()) {
            c = st.top();
            st.pop();
            
            if (c=='*')
                sc++;
            else {
                if (sc>0) 
                    sc--;
                else 
                    return false;
            }
        }
        
        return true;
    }


/*
<aside>
💡 **Question 3**

Given two strings word1 and word2, return *the minimum number of **steps** required to make* word1 *and* word2 *the same*.

In one **step**, you can delete exactly one character in either string.

**Example 1:**

**Input:** word1 = "sea", word2 = "eat"

**Output:** 2

**Explanation:** You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

</aside>
*/
int lcs(string X, string Y,int m,int n){
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(X[i-1]==Y[j-1]) dp[i][j]= 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
int minDistance(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        return m+n-2*lcs(s1,s2,m,n) ;
}


/*
Question 4**

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.
You always start to construct the **left** child node of the parent first if it exists.

*/

/*
<aside>
💡 **Question 5**

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of **consecutive repeating characters** in chars:

- If the group's length is 1, append the character to s.
- Otherwise, append the character followed by the group's length.

The compressed string s **should not be returned separately**, but instead, be stored **in the input character array chars**. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done **modifying the input array,** return *the new length of the array*.

You must write an algorithm that uses only constant extra space.

**Example 1:**

**Input:** chars = ["a","a","b","b","c","c","c"]

**Output:** Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

**Explanation:**

The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

</aside>

*/
int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1) return 1;

        int i = 0, j = 0;

        while(i < n){
            int count = 1;
            while(i < n-1 && chars[i] == chars[i+1]){
                count++;
                i++;
            } 
            //add character to ans;
            chars[j++] = chars[i++];
            //add count to ans
            if(count > 1){
                //case for count > 10
                string charCount = to_string(count);
                for(auto c : charCount){
                    chars[j++] = c;
                }
            }
        }
        return j;
}
    
/*
<aside>
💡 **Question 6**

Given two strings s and p, return *an array of all the start indices of* p*'s anagrams in* s. You may return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**

**Input:** s = "cbaebabacd", p = "abc"

**Output:** [0,6]

**Explanation:**

The substring with start index = 0 is "cba", which is an anagram of "abc".

The substring with start index = 6 is "bac", which is an anagram of "abc".

</aside>
*/

vector<int> findAnagrams(string s, string p) {
        int i=0,j=0;
        vector<int>a(26,0),b(26,0);
        for(auto &i:p){
            a[i-'a']++;
        }
        vector<int>ans;
        while(j<s.length()){
            b[s[j]-'a']++;
            if(j-i+1==p.length()){
                if(b==a){
                  ans.push_back(i);
                }
                b[s[i]-'a']--;
                i++,j++;
            }
            else j++;
        }
        return ans;
}



/*
<aside>
💡 **Question 7**

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

**Example 1:**

**Input:** s = "3[a]2[bc]"

**Output:** "aaabcbc"

</aside>
*/
string decodeString(string str) {
        stack<char>s;
        for(int i=0; i<str.length(); i++){
            if(str[i] != ']'){
                s.push(str[i]);
            }else{
                string temp = "";
                while(s.empty() == false && s.top() != '['){
                    temp = s.top()+temp;
                    s.pop();
                }
                //pop the opening bracket
                s.pop();
                
                string numTemp = "";
                while(s.empty() == false && isdigit(s.top())){
                    numTemp = s.top() + numTemp;
                    s.pop();
                }
                
                //k is number of times temp has to be repeated
                int k = stoi(numTemp);
                
                while(k--){
                    for(char c:temp){
                        s.push(c);
                    }
                }
            }
        }
        
        string output = "";
        while(s.empty() == false){
            output += s.top();
            s.pop();
        }
        
        reverse(output.begin(), output.end());
        return output;
}

/*
<aside>
💡 **Question 8**

Given two strings s and goal, return true *if you can swap two letters in* s *so the result is equal to* goal*, otherwise, return* false*.*

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

- For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

**Example 1:**

**Input:** s = "ab", goal = "ba"

**Output:** true

**Explanation:** You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

</aside>
*/

bool buddyStrings(string s, string goal) {
        int cnt = 0;
        if(s.length()!=goal.length()){
            return false;
        }
        vector<int> a;
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]){
                cnt++;
                a.push_back(i);
                
            }
        }
        if(cnt>2 || cnt==1){
            return false;
        }
        else if(cnt == 2){
            swap(s[a[0]],s[a[1]]);
            if(s==goal){
                return true;
            }
            else{
                return false;
            }
        }

        else{
            unordered_set<int> st;
            for(int i=0;i<s.length();i++){
                st.insert(s[i]);
            }
            if(st.size()<s.length()){
                return true;
            }
            else{
                return false;
            }
        }
}