#include<iostream>
using namespace std;

int horseCount(string input){
    /// neigh
    int n = 0, e = 0, i = 0, g = 0, h = 0;
    int activeHorses = 0;
    int answer = 0;

    for(const char c : input){
        switch(c){
            case 'n':
                n++;
                activeHorses++;
                break;
            
            case 'e':
                e++;
                break;

            case 'i':
                i++;
                break;

            case 'g':
                g++;
                break;

            case 'h':
                h++;
                activeHorses--;
                break;
        }
        answer = max(answer, activeHorses);
        if(n < e || e < i || i < g || g < h) return -1;
    }
    return (activeHorses != 0) ? -1 : answer;
}

int main(){
    string input = "nnenigeeihighneingeighhgh";
    int answer = horseCount(input);
    cout << "\nNumber of horses are: " << answer << endl;
    return 0;
}