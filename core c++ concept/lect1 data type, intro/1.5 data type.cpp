/*                                  ***data type***
All variables use data-type during declaration to restrict the type of data to be stored. 
Therefore, we can say that data types are used to tell the variables the type of data it 
can store. Whenever a variable is defined in C++, the compiler allocates some memory for 
that variable based on the data type with which it is declared. Every data type requires 
a different amount of memory.

C++ supports a wide variety of data types and the programmer can select the data type 
appropriate to the needs of the application. Data types specify the size and types of value 
to be stored. However, storage representation and machine instructions to manipulate each 
data type differ from machine to machine, although C++ instructions are identical on all 
machines.


C++ supports the following data types:

1.Primary or Built in or Fundamental data type
2.Derived data types
3.User defined data types


1. Primitive Data Types: These data types are built-in or predefined data types and can be 
                         used directly by the user to declare variables. example: int, char, 
                         float, bool, etc. Primitive data types available in C++ are: 

a.Integer:      done                        The keyword used for integer data types is int. Integers typically require 4 bytes of memory space and range from -2147483648 to 2147483647.  
b.Character:      done                         Character data type is used for storing characters. The keyword used for the character data type is char. Characters typically require 1 byte of memory space and range from -128 to 127 or 0 to 255.  
c.Boolean:          done                     Boolean data type is used for storing Boolean or logical values. A Boolean variable can store either true or false. The keyword used for the Boolean data type is bool. 
d.Floating Point:     done                          Floating Point data type is used for storing single-precision floating-point values or decimal values. The keyword used for the floating-point data type is float. Float variables typically require 4 bytes of memory space. 
e.Double Floating Point:     done                          Double Floating Point data type is used for storing double-precision floating-point values or decimal values. The keyword used for the double floating-point data type is double. Double variables typically require 8 bytes of memory space. 
f.Valueless or Void:      done                         Void means without any value. void data type represents a valueless entity. A void data type is used for those function which does not return a value. 
g.Wide Character:        done                       Wide character data type is also a character data type but this data type has a size greater than the normal 8-bit datatype. Represented by wchar_t. It is generally 2 or 4 bytes long.

2. Derived Data Types: The data types that are derived from the primitive or built-in datatypes 
                       are referred to as Derived Data Types. These can be of four types namely: 

a.Function(syntax of function)   done
b.Array([])      done
c.Pointer(*)    done
d.Reference(&)  done


3. Abstract or User-Defined Data Types: These data types are defined by the user itself. Like, as 
                                        defining a class in C++ or a structure. C++ provides the 
                                        following user-defined datatypes: 

a.Class  (done)
b.Structure (done)
c.Union    (done)
d.Enumeration  (done)
e.Typedef defined Datatype   (done)

*/

/*                               *** datatype modifiers***

As the name suggests, datatype modifiers are used with the built-in data types to modify the length of 
data that a particular data type can hold. 

Data type modifiers available in C++ are: 

Signed(used before int, char)
unSigned(used before int, char)
Short(int)
Long(int , double)
*/


/* example of enumaration*/
#include <bits/stdc++.h>
using namespace std ;
  int main(){
    //it define the value 0,1,2,3...
    enum meal {breakfast,lunch, dinner };
    //cout<< breakfast; output we get is 0
    meal k =lunch ;
    // data type of k is meal 
    // meal is user defined data type
   // cout<< k ;output we get is 1
    cout<<typeid(k).name() ;//typeinfo lib is used
  }