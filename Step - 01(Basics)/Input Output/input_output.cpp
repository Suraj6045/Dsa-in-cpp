#include<iostream>
using namespace std;

int main(){


    // int x , y;
    // cout << "Enter x ";
    // cin >> x;
    // cout << "Enter y "; 
    // cin >> y;
    // cout << "x is " << x << " and y is " << y;


    int marks;
    cout << "Please Enter Your Marks - ";
    cin >> marks;
    if(marks>=0 && marks<=100){
        if(marks<25){
            cout << "F";
        }

        else if(marks<45){
            cout << "E";
        }

        else if(marks<50){
            cout << "D";
        }

        else if(marks<60){
            cout << "C";
        }

        else if(marks<80){
            cout << "B";
        }

        else {
            cout << "A";
        }
    }

    else {
        cout << "Enter Valid Marks";
    }

    return 0;

}
