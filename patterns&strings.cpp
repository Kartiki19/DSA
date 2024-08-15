#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



bool solution(vector<string> strings, vector<string> patterns) {
    unordered_map<string, int> unique_str;
    
    for(int i = 0; i < strings.size(); ++i){
        if(unique_str.find(strings[i]) != unique_str.end()){
            if(patterns[i] != patterns[unique_str[strings[i]]]) return false;
        }
        else unique_str[strings[i]] = i;
    }
    
    for(int i = 0; i < patterns.size(); ++i){
        if(unique_str.find(patterns[i]) != unique_str.end()){
            if(strings[i] != strings[unique_str[patterns[i]]]) return false;
        }
        else unique_str[patterns[i]] = i;
    }
    
    return true;
}

int main(){
    vector<string> strings = 
                            {"syf", 
                            "syf", 
                            "oxerkx", 
                            "oxerkx", 
                            "syf", 
                            "xgwatff", 
                            "pmnfaw", 
                            "t", 
                            "ajyvgwd", 
                            "xmhb", 
                            "ajg", 
                            "syf", 
                            "syf", 
                            "wjddgkopae", 
                            "fgrpstxd", 
                            "t", 
                            "i", 
                            "psw", 
                            "wjddgkopae", 
                            "wjddgkopae", 
                            "oxerkx", 
                            "zf", 
                            "jvdtdxbefr", 
                            "rbmphtrmo", 
                            "syf", 
                            "yssdddhyn", 
                            "syf", 
                            "jvdtdxbefr", 
                            "funnd", 
                            "syf", 
                            "syf", 
                            "wd", 
                            "syf", 
                            "vnntavj", 
                            "wjddgkopae", 
                            "yssdddhyn", 
                            "wcvk", 
                            "wjddgkopae", 
                            "fh", 
                            "zf", 
                            "gpkdcwf", 
                            "qkbw", 
                            "zf", 
                            "teppnr", 
                            "jvdtdxbefr", 
                            "fmn", 
                            "i", 
                            "hzmihfrmq", 
                            "wjddgkopae", 
                            "syf", 
                            "vnntavj", 
                            "dung", 
                            "kn", 
                            "qkxo", 
                            "ajyvgwd", 
                            "fs", 
                            "kanixyaepl", 
                            "syf", 
                            "tl", 
                            "yzhaa", 
                            "dung", 
                            "wa", 
                            "syf", 
                            "jtucivim", 
                            "tl", 
                            "kanixyaepl", 
                            "oxerkx", 
                            "wjddgkopae", 
                            "ey", 
                            "ai", 
                            "zf", 
                            "di", 
                            "oxerkx", 
                            "dung", 
                            "i", 
                            "oxerkx", 
                            "wmtqpwzgh", 
                            "t", 
                            "beascd", 
                            "me", 
                            "akklwhtpi", 
                            "nxl", 
                            "cnq", 
                            "bighexy", 
                            "ddhditvzdu", 
                            "funnd", 
                            "wmt", 
                            "dgx", 
                            "fs", 
                            "xmhb", 
                            "qtcxvdcl", 
                            "thbmn", 
                            "pkrisgmr", 
                            "mkcfscyb", 
                            "x", 
                            "oxerkx", 
                            "funnd", 
                            "iesr", 
                            "funnd", 
                            "t"};

vector<string> patterns = 
                            {"enrylabgky", 
                            "enrylabgky", 
                            "dqlqaihd", 
                            "dqlqaihd", 
                            "enrylabgky", 
                            "ramsnzhyr", 
                            "tkibsntkbr", 
                            "l", 
                            "bgtws", 
                            "xwuaep", 
                            "o", 
                            "enrylabgky", 
                            "enrylabgky", 
                            "e", 
                            "auljuhtj", 
                            "l", 
                            "d", 
                            "jfzokgt", 
                            "e", 
                            "e", 
                            "dqlqaihd", 
                            "fgglhiedk", 
                            "nj", 
                            "quhv", 
                            "enrylabgky", 
                            "oadats", 
                            "enrylabgky", 
                            "nj", 
                            "zwupro", 
                            "enrylabgky", 
                            "enrylabgky", 
                            "pyw", 
                            "enrylabgky", 
                            "bedpuycdp", 
                            "e", 
                            "oadats", 
                            "i", 
                            "e", 
                            "fobyfznrxm", 
                            "fgglhiedk", 
                            "irxtd", 
                            "oyvf", 
                            "fgglhiedk", 
                            "ebpp", 
                            "nj", 
                            "p", 
                            "d", 
                            "cufxylz", 
                            "e", 
                            "enrylabgky", 
                            "bedpuycdp", 
                            "mitzb", 
                            "shsnw", 
                            "papmvh", 
                            "bgtws", 
                            "chtp", 
                            "pze", 
                            "enrylabgky", 
                            "klp", 
                            "wpx", 
                            "mitzb", 
                            "fo", 
                            "enrylabgky", 
                            "bvcigrirhe", 
                            "klp", 
                            "pze", 
                            "dqlqaihd", 
                            "e", 
                            "iufunacwjo", 
                            "bubgww", 
                            "fgglhiedk", 
                            "og", 
                            "dqlqaihd", 
                            "mitzb", 
                            "d", 
                            "dqlqaihd", 
                            "mysidv", 
                            "l", 
                            "naj", 
                            "clftmrwl", 
                            "fjb", 
                            "zjjnrffb", 
                            "sh", 
                            "gcn", 
                            "ouispza", 
                            "zwupro", 
                            "c", 
                            "rdank", 
                            "chtp", 
                            "xwuaep", 
                            "jufhm", 
                            "iyntbgm", 
                            "sufs", 
                            "mkivpe", 
                            "bxdd", 
                            "dqlqaihd", 
                            "zwupro", 
                            "vzxbbculgv", 
                            "zwupro", 
                            "l"};

 cout << solution(strings, patterns);
    return 0;
}