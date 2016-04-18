//Author: Travis Hoover
//Date: April 14, 2016
//CSCI 3080; Dr. Pettey
//This program is a finite state machine regonizer for the regular expression a*b*ab

#include <iostream>

using namespace std;

void S0(char); //prototype for state 0
void S1(char); //prototype for state 1
void S2(char); //prototype for state 2
void S3(char); //prototype for state 3
void S4(char); //prototype for state 4
void S5(char); //prototype for state 5
void S6(char); //prototype for state 6

int main() {

    char x; //initialize input (will be either 'a' or 'b')
    cin.get(x); //cin.get will handle file redirection
    cout << "0"; //initial state is never recognizer, will output 0
    S0(x); //begin stepping through states, at initial state
    cout << endl; //formatting for output

    return 0;
}

//initial state
void S0(char x) {
    cout << "0";
    cin.get(x);
    if(x == 'a') {
        S1(x);
    }
    else if(x == 'b')
        S2(x);
    else
        return; //return if input is anything other than 'a' or 'b'
}

//State 1
void S1(char x) {
    cout << "0";
    cin.get(x);
    if(x == 'a') {
        S1(x); //recursive call to self if input is 'a'
    }
    else if(x == 'b')
        S2(x);
    else
        return;
}

//State 2; recognizing state
void S2(char x) {
    cout << "1";
    cin.get(x);
    if(x == 'a') {
        S3(x);
    }
    else if(x == 'b')
        S4(x);
    else
        return;
}

//State 3
void S3(char x) {
    cout << "0";
    cin.get(x);
    if(x == 'a') {
        S6(x);
    }
    else if(x == 'b')
        S5(x);
    else
        return;
}

//State 4
void S4(char x) {
    cout << "0";
    cin.get(x);
    if(x == 'a') {
        S3(x);
    }
    else if(x == 'b')
        S4(x); //recursive call to self if 'b', handles 'b' loop
    else
        return;
}

//State 5; recognizing state
void S5(char x) {
    cout << "1";
    cin.get(x);
    if(x == 'a') {
        S6(x); //directs to sink
    }
    else if(x == 'b')
        S6(x); //directs to sink
    else
        return;
}

//State 6; input sink
void S6(char x) {
    cout << "0";
    cin.get(x);
    if(x == 'a') {
        S6(x); //recursive call to self to act as sink
    }
    else if(x == 'b')
        S6(x); //recursive call to self to act as sink
    else
        return;
}