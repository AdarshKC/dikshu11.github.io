/*Given a string, Print
all the possible permutations
of string in sorted order*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<unordered_map>
using namespace std;


void print(int len, char* str, int* numb, int level, char* res, int length)
{
    
    if(level==length)
    {
        for(int i=0; i<length; i++)
            cout<<res[i];
        cout<<endl;
        return;
    }
    for(int i=0; i<len; i++)
    {
        if(numb[i]==0)
            continue;
        
            res[level] = str[i];
            numb[i]--;
            print(len,str,numb,level+1,res,length);
            numb[i]++;
        
    }
}

int main() 
{
    string s;
    cin>>s;
    map<char, int> m;
    int size = s.length();
    for(int i=0; i<size; i++)
        m[s[i]]++;  
    map<char, int>:: iterator it;
    int i=0;
    int len = 0;
    char str[26];
    int numb[26];
    for(it=m.begin(); it!=m.end(); it++)
    {
            str[i] = it->first;
            numb[i] = it->second;
            i++;
            len += it->second;
        
    }
    char res[i];
    print(i,str,numb,0,res,len);
    
}
