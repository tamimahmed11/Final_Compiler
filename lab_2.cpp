#include <bits/stdc++.h> 
using namespace std; 

void Tamim(const string& value) 
{ 
    regex p1("^a.*b$"); 
    regex p2("^a");       
    regex p3("b$");     
    regex p4("ab");   
    
    cout << "String: " << value << endl; 
    cout << "Shuru hby 'a' Diye ans Shes hby 'b': " 
         << regex_match(value, p1) << endl; 
    cout << "Sudu suru hby 'a' diye: " 
         << regex_search(value, p2) << endl; 
    cout << "Shes hby 'b' diye: " 
         << regex_search(value, p3) << endl; 
    cout << "Jekono Khany 'ab' thakby: " 
         << regex_search(value, p4) << endl; 
} 

int main() 
{ 
    string inp; 
    cout << "Enter any string: "; 
    cin >> inp; 
    Tamim(inp); 
    return 0; 
}