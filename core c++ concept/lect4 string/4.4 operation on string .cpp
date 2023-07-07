 #include <bits/stdc++.h>
using namespace std ;
int main(){
    // Initializing string 
    string str = "geeksforgeeks is for geeks"; 
  
    // Displaying string 
    cout << "The initial string is : "; 
    cout << str << endl; 
  
    // Resizing string using resize() 
    str.resize(10); 
  
    // Displaying string 
    cout << "The string after resize operation is : "; 
    cout << str << endl; 
  
    // Displaying capacity of string 
    cout << "The capacity of string is : "; 
    cout << str.capacity() << endl; 

    /*capacity()	:-This function returns the capacity allocated to the string, 
    which can be equal to or more than the size of the string. Additional space 
    is allocated so that when the new characters are added to the string, the 
    operations can be done efficiently.*/
  
    // Displaying length of the string 
    cout << "The length of the string is :" << str.length() 
         << endl; 
  
    // Decreasing the capacity of string 
    // using shrink_to_fit() 
    str.shrink_to_fit(); 
  
    // Displaying string 
    cout << "The new capacity after shrinking is : "; 
    cout << str.capacity() << endl; 
  
}