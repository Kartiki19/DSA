#include<iostream>
#include<unordered_map>

using namespace std;

class Solution{
    public:
        string minimumWindowSubstr(string& s, string& t){
            int m = s.size();
            int n = t.size();

            unordered_map<char, int> sf;
            unordered_map<char, int> tf;

            for(char c : t){
                tf[c]++;
            }
            int i = 0, j = 0, min_count = 0, start = 0, min_len = INT_MAX;

            while(i < m){
                if(tf.find(s[i]) != tf.end()){
                    sf[s[i]]++;
                    if(sf[s[i]] <= tf[s[i]]) min_count++;
                }
                while(j <= i && min_count == n){
                    if(i-j+1 < min_len){
                        min_len = i-j+1;
                        start = j;
                    }
                    if(tf.find(s[j]) != tf.end()){
                        sf[s[j]]--;
                        if(sf[s[j]] < tf[s[j]]){
                            min_count--;
                        }
                    }
                    j++;
                }
                i++;
            }

            return (min_len == INT_MAX) ? "" : s.substr(start, min_len);
        }
};
int main(){
    // string s = "ADOBECODEBANC";
    // string t = "ABC";
    string s = "a";
    string t = "aa";
    Solution s1;
    cout << s1.minimumWindowSubstr(s, t);
    return 0;
}