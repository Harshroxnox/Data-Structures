#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    // we can get iterators with .begin() and .end()
    // iterator is a pointer 
    // *(it+2) = s[2]
    string s = "hello";
    auto it = s.begin();

    while(it != s.end()){
        cout << *it;
        it++;
    }
    cout << endl;


    // we also have .size()or.length() .empty() .push_back() 
    cout << "Size: " << endl;
    cout << s.size() << endl;
    cout << "Is Empty: "<< endl;
    cout << s.empty() << endl;
    s.push_back(' ');

    // gets added to the end of string
    cout << "Appending world: "<< endl;
    s.append("world");
    cout << s << endl;


    // Insert a space at index 5
    // Insert str.insert(index, string) or str.insert(itr, char)
    string str = "HelloWorld";
    it = str.begin() + 5;
    
    cout << "Inserting spaces:" << endl;
    str.insert(5, "  ");
    // NOTE: You can only insert chars using iterator
    str.insert(it, ' ');
    cout << str << endl;


    // Erase str.erase(position(index), no. of char) or str.erase(iterator)
    str = "Hello World!";
    cout << str << endl;

    // erases hello
    cout << "Erase Hello: " << endl;
    str.erase(0, 6);
    cout << str << endl;

    // NOTE: can only erase the given char with iterator
    cout << "Erasing !:" << endl;
    str.erase(str.begin()+5);
    cout << str << endl;


    // Replace str.replace(index, no. of char, string) or str.replace(it1, it2, string)
    cout << "Replace World with Hello! :" << endl;
    str.replace(0, 5, "Hello!");
    cout << str << endl;

    cout << "Replace Hello! back with World: " << endl;
    str.replace(str.begin(), str.end(), "World");
    cout << str << endl;


    // substr str.substr(index, no. of chars) or str2(itr1, itr2)
    // substr returns a new string
    cout << "Stripping W from World: " << endl;
    str = str.substr(1, 4);
    cout << str << endl;

    cout << "Stripping o from orld: " << endl;
    string str2(str.begin()+1, str.end());
    cout << str2 << endl;

    // swaps the value of s and str
    cout << "swaping strings: " << endl;
    s.swap(str);
    cout << str << endl;

    // string streams
    // Ex: suppose we have to extract {0,1,2} vector from "id0 id1 id2" string
    string input = "id0 id1 id2";
    cout << "Input: " << input << endl;
    istringstream iss(input);
    string token;
    vector<int> ids;

    while (iss >> token)
    {
        string num = token.substr(2, 1);
        ids.push_back(stoi(num)); 
    }
    cout << "Output: ";
    for(auto i: ids){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}