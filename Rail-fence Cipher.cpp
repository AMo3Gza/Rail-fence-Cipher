/*
FCAI – Programming 1 – 2022 - Assignment 2
Program Name: Rail-fence Cipher
Program Description: decoder and encoder by Rail-fence Cipher - Cipher 9
Last Modification Date: 3/23/2022
Author1 and ID and Group: Ayman Ashraf Mounir Kamel , 20210079 , A
Teaching Assistant: xxxxx xxxxx
Purpose: Encryption and decryptions
*/

#include <string>
#include <iostream>
#include<algorithm>
#include <sstream>


using namespace std;

// Declare and assign variables
string str,choice,finalResult,ctn;
int intChoice, key=3;

// Function to take string from user
void enterText(string type){
    cout << "Enter text to " << type << ": ";
    getline(cin,str);
    // Clear spaces of string
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
}

// Encryption Function
void encryption(){
    // Declare and assign variables
    int len = str.length();
    char arr[key][len];

    // 2d array maker
    // this for-loop assign elements by "."
    for (int i=0;i<key;i++){
        for (int j=0; j< len;j++){
            arr[i][j]='.';
        }
    }

    // zig-zag maker
    // this for-loop adds string elements in zig-zag
    for (int i=0; i <key;i++){
        if(i==0 || i == 2){
            for (int j = i; j<len;j+=4){
                arr[i][j]= str[j];
            }
        }else if (i == 1){
            for (int j = i; j<len;j+=2){
                arr[i][j]= str[j];
            }
        }
    }

    // 2d array printer
    // this for-loop for print elements of 2d array
    for (int i = 0; i < key; i++){
        for (int j = 0; j < len; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // final result
    // this for-loop takes everything in 2d array except "."
    for (int i=0; i <key;i++){
        for (int j=0; j< len;j++){
            if (arr[i][j] != '.'){
                finalResult+=arr[i][j];
            }
        }
    }
    // print final result
    cout << "The cipher-text is read off along the rows: \"" <<finalResult<<"\""<< endl;
}

// Decryption Function
void decryption(){
    // Declare and assign variables
    int len = str.length(),wordPosition =0;
    char arr[key][len];

    // 2d array maker
    // this for-loop assign elements by "."
    for (int i=0;i<key;i++){
        for (int j=0; j< len;j++){
            arr[i][j]='.';
        }
    }

    // zig-zag maker
    // this for-loop adds string elements in zig-zag
    for (int i=0;i<key;i++){
        if (i == 0 || i == 2){
            for (int j = i; j<len;j+=4){
                arr[i][j]= str[wordPosition++];
            }
        }else if (i == 1){
            for (int j = 1; j<len;j+=2){
                arr[i][j]= str[wordPosition++];
            }
        }
    }

    // this for-loop prints 2d array elements in zig-zag
    for (int i=0; i < key; i++){
        for (int j = 0; j < len; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // print final result
    // this for-loop takes everything in 2d array except "."
    for (int j=0; j< len;j++){
        for (int i=0; i <key;i++){
            if (arr[i][j] != '.'){
                finalResult+=arr[i][j];
            }
        }
    }
     cout << "The cipher-text is read off along the rows: \"" << finalResult<< "\""<<endl;
}

// Main Menu
int main(){
    cout << "Key 3 only\n"
            "1- Encryption \n"
            "2- Decryption \n"
            "3- Quit\n";
    getline(cin,choice);

    // Change string to integer
    stringstream x(choice);
    x >> intChoice;

    // Recall functions
    if (intChoice == 1){
        enterText("Encryption");
        encryption();

    }else if (intChoice == 2){
        enterText("Decryption");
        decryption();

    }else if (intChoice == 3){
        return EXIT_FAILURE;
    }else{
        // if user enters anything except 1,2,3 the cipher will work again
        cout << "Invalid input, Please enter (1,2,3)"<<endl;
        main();
    }
}
