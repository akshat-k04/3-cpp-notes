 #include <bits/stdc++.h>
using namespace std ;
int main(){
    string name ;
    cin>> name ; // write akshat hello
    cout<< name ; // get akshat
    // this method will only store 1st word of the sentance 
    // to store full sentance do this 


    string str ;

    // Taking string input using getline() 
    getline(cin, str); 

    // Displaying string 
    cout << "The initial string is : "; 
    cout << str << endl; 
  
    // Inserting a character 
    str.push_back('s'); // s will add at the last
  
    // Displaying string 
    cout << "The string after push_back operation is : "; 
    cout << str << endl; 
  
    // Deleting a character 
    str.pop_back(); //delete the last character
  
    // Displaying string 
    cout << "The string after pop_back operation is : "; 
    cout << str << endl; 
}