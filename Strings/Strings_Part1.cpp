#include<iostream>
#include<string>
using namespace std;

int main(){
    // char str[] = {'a','b','c','\0'};
 
    // int arr[]={1, 2, 3};
    // cout<<arr<<endl; 

    // cout << str << endl; // constant pointers

    // char str[]="Hello";//string literals
    // // cout <<strlen(str)<< endl;

    // // cout<<str[2]<<endl;
    // cout<<str[5]<<endl;// Null character
   
    // char str[6];

    // cout<<"enter character array : "<<endl;
    // // cin>>str;//if we use hello world output will be hello

    // cin.getline(str,6);
    // // cin.getline(str,100,'$');//if we want to stop after a special character

    // // cout<<"output : "<<str<<endl;
   
    // for(char ch : str){//if we want to print individual value in a string
    //     cout<<ch<<" ";
    // }

    // char str[] = "jahid";

    // int len=0;
    // for(int i=0 ; i< str[i]!='\0' ; i++){
    //     len++;
    // }
    // cout<<len<<endl;


    // string str ="jahid"; // dynamic ==> runtime resize
    //                      // contiguous

    // cout<<str<<endl;

    // str = "hello";

    // cout<<str<<endl;

    // char chArr[]="jahid";
    // chArr = "cse";//error


    // string str1="jahid";
    // string str2="ul";

    // string str3 =str1 + str2;

    // cout<<str3<<endl;//concatenation

    // cout<<(str1 == str2) << endl;
    //cout<<(str1 < str2) << endl;

    // cout<<str1.length()<<endl;

    // string str;

    // // cin>>str;
    // getline(cin,str);
    
    // cout<<"output = "<<str<<endl;

    // string str="jahid";

//     for(int i=0 ; i<str.length() ; i++){
//         cout<<str[i]<<" ";
//     }
//    cout<<endl;

// for(char ch : str){
//     cout<<ch<<" ";
// }
// cout<<endl;
    

string str = "jahid";

reverse(str.begin(),str.end());//iterators

cout<<str<<endl;

    return 0;
}