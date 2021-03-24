#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";
    transform(new_id.begin(),new_id.end(),new_id.begin(),::tolower);
    for(int i=0;i<new_id.size();i++){
        if(islower((int)new_id[i])||new_id[i]=='-'||new_id[i]=='_'||isdigit(new_id[i])) {
            answer.push_back(new_id[i]);
        }else if(new_id[i]=='.'){
            if(answer[answer.size()-1]=='.')continue;
            if(!answer.empty()) answer.push_back('.');
        }
        if(answer.size()==15) break;
    }
    while(answer[answer.size()-1]=='.') {
        answer.pop_back();
    }
    if(answer.empty()){
        answer.push_back('a');
    }
    int index=answer.size()-1;
    for(int i=0;i<3;i++){
        if(answer.size()>=3) break;
        answer.push_back(answer[index]);
    }
    cout<<answer<<endl;
    return answer;
}

int main(){
    string temp;
    cin>>temp;
    solution(temp);
}