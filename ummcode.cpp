// Peter Bifone Jr.
// Kattis ummcode
// My favorite solution I have submitted
// Summary: A string is given to you with
// u's and m's. If a word only have u's m's and punctuation
// then there is a hidden message! The message is encoded
// with u==1 and m==0 in ascii.

// Include everything
#include <bits/stdc++.h>

using namespace std;

int main(){
    // there are 7-bits in a ascii char
    // We need to keep tract of it
    short cur =0;
    string s;
    char helper = 0;

    // Make I/O faster
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while( cin >> s ){

        bool check = false;
        for (auto c : s) {
            if ( ( c !='u' && c != 'm' )) {
                if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                    check = true;
                    break;
                }
            }
        }

        if ( check) continue;

        for (auto c : s){
            if ( c != 'u' && c != 'm') continue;
            if (cur == 7){
                cout << helper;
                cur = 0;
                helper = 0;
            }
            // Since a ascii char is just a byte - 1 bit, we can use
            // bit manip to reconstruct the char from
            // the u's and m's
            helper = (char)((helper << 1) | (c == 'u' ? 1 : 0));
            cur++;
        }
    }
    cout << helper << endl;
    return 0;
}

