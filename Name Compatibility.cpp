#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void add(vector<int> values){
    int n = values.size();
    vector<int> added;

    if (n==2 || (n == 3 && values[0] == 1 && values[1] == 0 && values[2] == 0) ){
        for(int num : values) cout<<num;
        cout<<"%"<<endl;
    }
    else if(n>2){
        for(int i = 0; i<(n/2); i++) 
            added.push_back(values[i]+values[n-1]);
        if(n%2 != 0) 
            added.push_back(values[(n/2)]);
        
        add(added);
    }
}

int main(){
    string name1, name2;
    cin>>name1>>name2; //first name only, seperated by space, both must be either lowercase or uppercase

    unordered_map<char, int> map1;
    unordered_map<char, int> map2;

    vector<int> number;
    int result;

    for(char c: name1) map1[c]++;
    for(char c: name2) map2[c]++;

    for(char c: name1){
        if(map1[c]>0 && map2[c]>0){
            result = map1[c] + map2[c];
            map1.erase(c);
            map2.erase(c);
            number.push_back(result);
        }
        else if(map1[c] > 0) {
            result = map1[c];
            map1.erase(c);
            number.push_back(result);
        }
    }

    if(!map2.empty()){  
        for(char c: name2){
            if(map2[c]>0){
                result = map2[c];
                map2.erase(c);
                number.push_back(result);
            }
        }
    }
    add(number);
}
