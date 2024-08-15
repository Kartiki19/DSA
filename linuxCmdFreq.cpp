#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
unordered_map<int, string> history;
void displayVector(vector<int>& v){
    for(int i: v){
        cout << i << "\t";
    }
    cout << endl;
}
string calculateCmd(string cmd){
    int cmdId = stoi(cmd.substr(1, cmd.size()-1));
    if(history[cmdId][0] == '!' ) return calculateCmd(history[cmdId]);
    return history[cmdId];
}
vector<int> calculateFrequency(const vector<string>& commands){
    vector<int> output;
    unordered_map<string, int> frequency;
    for(int i = 0; i < commands.size(); ++i){
        string cmd = commands[i];
        if(cmd[0] == '!') cmd = calculateCmd(cmd);
        frequency[cmd]++;
        history[i+1] = cmd;
    }
    output.push_back(frequency["ls"]);
    output.push_back(frequency["cp"]);
    output.push_back(frequency["mv"]);
    return output;
}
int main(){
    vector<string> commands = {"ls", "cp", "mv", "!2", "!1", "!4"};
    vector<int> output = calculateFrequency(commands);
    displayVector(output);
    return 0;
}