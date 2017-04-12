#include <iostream>
#include "library.h" 
int main(){

    start();// load the database // create an account
    bool flag = signup();
    char choice[6];
    while (flag && choice[0] != 'q'){
        finished();//save the data.
        cout << "Now you can sign up again.[s]" << endl;
        cout << "Or enter　'q' to quit [q]" << endl;
        cout << "enter[s/q]";

        cin >> choice;
        while (choice[0] != 'q'){
            if (choice[0] == 's'){
                flag = signup();
                break;
            }
            else
            {
                cout << "Your commond is invalid.Please try again.";
                cin >> choice;
            }
        }
    }
    cout << "Please enter any key to quit." << endl;
    return 0;
}

