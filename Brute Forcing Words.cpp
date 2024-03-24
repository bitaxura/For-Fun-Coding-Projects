#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

int main(){
    char letters[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
    string word = "HELLO WORLD";
    vector<char> words;
    int i = 0;

    for(char c : word){
        
        for(int i = 0; i<27;  i++){
            for(char d : words){
            cout<<d;
        }
        
            this_thread::sleep_for(chrono::milliseconds(30)); //Adjusts the delay added to change display speed
            cout<<letters[i]/*<<"\r"*/<<endl; //Uncomment and remove endl to update text on the same line
            cout.flush();

            if(letters[i] == c){
                words.push_back(letters[i]);
                break;
            }
        }
    }
    cout<<endl;
    system("pause");
}
