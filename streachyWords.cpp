#include <iostream>
#include <vector>
using namespace std;

void displayVectors(vector<pair<char, int>>& v){
    for(auto it: v){
        cout << it.first << ": " << it.second << endl;
    }
    cout << "done" << endl;
}


vector<pair<char, int>> getCharCountPairs(const string& str) {
    vector<pair<char, int>> charCountPairs;
    int n = str.size();
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            ++count;
            ++i;
        }
        charCountPairs.push_back({str[i], count});
    }
    return charCountPairs;
}

bool isStreachy(const vector<pair<char, int>> sv, const vector<pair<char, int>> wv){
    if(sv.size() != wv.size()) return false;
    
    for(int i = 0; i <  sv.size(); ++i){
        if(sv[i].first != wv[i].first) return false;
        int sc = sv[i].second;
        int wc = wv[i].second;
        if((sc != wc && sc < 3) || (sc >= 3 && sc < wc)) return false;
    }
    return true;
}

int expressiveWords(string s, vector<string>& words) {
    vector<pair<char, int>> sv = getCharCountPairs(s);
    cout << "string is:" << s << endl;
    displayVectors(sv);

    int answer = 0;
    for(string w: words){
        if(s[0] == w[0] && s.back() == w.back()){
            vector<pair<char, int>> wv = getCharCountPairs(w);
            cout << endl << w << endl;
            displayVectors(wv);
            if(isStreachy(sv,wv)) answer++;            
        }
    }

    return answer;
}



int main(){
    // string s = "heeellooo";
    // vector<string> words = {"hello", "hi", "helo"};
    string s = "zzzzzyyyyy";
    vector<string> words = {"zzyy","zy","zyy"};

    cout << "\n Answer is: " << expressiveWords(s, words);

    return 0;
}
