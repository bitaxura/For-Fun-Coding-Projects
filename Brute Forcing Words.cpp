#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

int main(){
    string word = "HELLO WORLD"; //Change the Word Here, must be all lowercase or uppercase, change the for loop below accordingly
    vector<char> words;
    int i = 0;

    for(char c : word){
        for(int i = 65; i<=90;  i++){ //For UPPERCASE: i = 65 & i<=90, For lowercase i = 97 & i <=122
            for(char d : words){
                cout<<d;
            }
        
            this_thread::sleep_for(chrono::milliseconds(30)); //Adjusts the delay added to change display speed
            cout<<char(i)<</*" \r";*/endl; //Uncomment \r and comment endl to update text on the same line  

            if(char(i) == c){
                words.push_back(char(i));
                break;
            }
            else if(c == char(32)){
                words.push_back(char(32));
                break;
            }
        }
    }
    cout<<endl;
    system("pause");
}
