#include <iostream>
#include <vector>
#include <stack>
#include <time.h>
#include <utility>
#include <fstream>
#include <algorithm>
#include <string>
#include <fstream>
#include <thread>

using namespace std;

int  LENGTH = 16;
vector<vector<char>> maze(LENGTH, vector<char>(LENGTH, '.'));
vector<int> player(2, 0);
string cmd = "", chars = "abcdefghijklmnpqrstuvwxyzE,*{}!@#%^&=\";";

void level();
void print_info();
bool player_move();
void put_alphabet();

int main(){
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    srand(time(NULL));
    maze[0][0] = 'o';
    level();
    return 0;
}

void level(){
    time_t start = time(NULL);
    cmd = "";
    cout << "You are 'o'. Now input \"u\", \"d\", \"l\", \"r\" to move up, down, left, and right.\n";
    cout << "Echo anything you want. Go to E to enter command." << endl;
    put_alphabet();
    while(true){
        cout << "\nNow Command: echo \"" << cmd << "\"" << endl;
        print_info();
        if(player_move()){
            put_alphabet();    
        }
    }
}

void print_info(){
    for(auto row: maze){
        for(auto col: row){
            cout << col << " ";
        }
        cout << endl;
    }
}

bool player_move(){
    string input;
    cout << "> ";
    cin >> input;
    bool ret = false;
    int direc;
    maze[player[0]][player[1]] = '.';
    if(input == "u" && player[0] > 0)
        player[0]--;
    else if(input == "r" && player[1] < LENGTH - 1)
        player[1]++;
    else if(input == "d" && player[0] < LENGTH - 1)
        player[0]++;
    else if(input == "l" && player[1] > 0)
        player[1]--;
    else{
        cout << "invalid move" << endl;
    }
    
    if(maze[player[0]][player[1]] == 'E'){
        cmd = "echo \"" + cmd + "\"";
        cout << "Output: ";
        system(cmd.c_str());
        cmd = "";
        ret = true;
    }
    else if(maze[player[0]][player[1]] != '.'){
        cmd.push_back(maze[player[0]][player[1]]);
        ret = true;
    }
    maze[player[0]][player[1]] = 'o';
    return ret;
}

void put_alphabet(){
    for(int i=0; i<LENGTH; i++){
        for(int j=0; j<LENGTH; j++){
            if(maze[i][j] != '.' && maze[i][j] != 'o') maze[i][j] = '.';
        }
    }

    random_shuffle(chars.begin(), chars.end());
    int count = 0;
    for(int i=1; i<LENGTH; i+=3){
        for(int j=1; j<LENGTH; j+=2){
            if(maze[i][j] != 'o'){
                maze[i][j] = chars[count];
                count++;
                if(count >= chars.length()) return;
            }
        }
    }
}

