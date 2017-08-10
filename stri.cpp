#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
/*
 * 标点符号分割字符串
 * */
vector<string> split(const string &line, const char delim)
{
    vector<string> ret;
    string::const_iterator it = line.cbegin();
    string::const_iterator delim_it = it;
    while((delim_it = find(it, line.cend(), delim)) != line.cend()){
        string word(it, delim_it);
        ret.push_back(std::move(word));
        it = delim_it+1;
    }
    string word(it, line.cend());
    ret.push_back(std::move(word));
    return ret;
}
/*
 * 删除字符串首尾空格
 * */
string& trim(string &line)
{
    line.erase(0, line.find_first_not_of(" "));
    line.erase(line.find_last_not_of(" ")+1);
    return line;
}

/*
 * 删除所有空格
 * */
void  elima_space(string &line, const char *delim)
{
    string::size_type pos = 0;
    while((pos = line.find_first_of(*delim, pos)) != string::npos){
        line.erase(pos,1);
    }
}


void elima_str(string &line, const char *delim, int n)
{
    string::size_type pos = 0;
    while((pos = line.find(delim, pos, n)) != string::npos){
        line.erase(pos, n);
    }
    cout << line << endl;
}

vector<int> Num_of_Str(const string &line)
{
    vector<int> numVec;
    string::size_type pos = 0;
    string::size_type posAf = 0;
    while((pos = line.find_first_of("+-0123456789", pos)) != string::npos){
        int num = stoi(line.substr(pos), &posAf, 10);
        numVec.push_back(num);
        pos += posAf;
    }
    return numVec;

}
int main(){
    string line;
    while(getline(cin, line)){
        if(!line.compare("q")) break;
        vector<int> ivec = Num_of_Str(line);
        for_each(ivec.cbegin(), ivec.cend(), [](const int &i){cout << i << endl;});
    }
    return 0;
}
