#include<iostream>
using namespace std;
string idToShortURL(long int n){
    char map[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};
    string answer = "";
    int reminder = 0;
    while(n){
        reminder = n % 62;
        n /= 62;
        answer += map[reminder];
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

int shortURLToID(string url){
    int id = 0;
    for(char c: url){
        if(c >= 'a' && c <= 'z') id = id * 62 + c - 'a';
        else if(c >= 'A' && c <= 'Z') id = id * 62 + c - 'A' + 26;
        else id = id * 62 + c - '0' + 52;
    }
    // for (char c: url) 
    // { 
    //     if ('a' <= c && c <= 'z') id = id*62 + c - 'a'; 
    //     else if ('A' <= c && c <= 'Z') id = id*62 + c - 'A' + 26; 
    //     else id = id*62 + c - '0' + 52; 
    // } 
    return id;
}
int main(){
    long int n = 12345;
    string shortUrl = idToShortURL(n);
    cout << shortUrl << endl;
    cout << shortURLToID(shortUrl) << endl;
    return 0;
}