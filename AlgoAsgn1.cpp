/* 
 * File:   AlgoAsgn1
 * Author: benwa_000
 *
 * Created on January 15, 2015, 3:19 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// function to reverse the string
void reverse_string(string &param) {
    // hold the original string
    string temp;
    temp = param;
    
    // use length to start copying from
    int length;
    length = temp.length();
    
    // upcount is second counter
    int upcount = 0;
    for (int i = length - 1; i >= 0; i--) {
        // copy from end of temp into param
        param[upcount] = temp[i];
        upcount++;
    }
}

// function to rotate the string
void rotate_string(string &param, int dist) {
    dist = dist % 28;
    int length = param.length();
    
    char target;
    int temp = 0;
    
    for (int i = 0; i < length; i++) {
        target = param[i];
        // subtract away to put everything into the right order
        // add in the distance to rotate
        // mod divide by 28 to handle rollover
        if (target >= 65 && target <= 90) { // ALPHABET
            temp = ((target - 64) + dist) % 28;
        }
        else if (target == 46) {    // PERIOD
            temp = ((target - 18) + dist) % 28;
        }
        else if (target == 95) {  // UNDERSCORE
            temp = ((target - 68) + dist) % 28;
        }
        
        // mod division gave a zero so temp must be set to 28
        if (temp == 0) {temp = 28;}
        
        // add back to restore the ascii letters
        if (temp >= 1 && temp <= 26) { // ALPHABET
            temp += 64;
        }
        else if (temp == 27) {  // UNDERSCORE
            temp += 68;
        }
        else if (temp == 28) {  // PERIOD
            temp += 18;
        }
        target = temp;
        param[i] = target;
    }
}

int main(int argc, char** argv) {
    string input;
    string str_dist;
    int sploc;
    int dist;
    
    //cout << "Enter string: ";
    getline(cin, input);
    
    while (input != "0") {
        // find the space
        sploc = input.find(" ");
        
        // pick out the distance
        str_dist = input.substr(0, sploc);
        // convert it to an int
        dist = atoi(str_dist.c_str());
        // cut off the rotate amount
        input.erase(0, sploc + 1);
        
        
        reverse_string(input);
        rotate_string(input, dist);
        
        cout << input << endl;
        
        //cout << "\nEnter string: ";
        getline(cin, input);
    }
    
    return 0;
}

