/*Print all subsequences of a given string
in a sorted order. */
#include <iostream>
using namespace std;

char result[10];
void print(char* str, int* ind, int pos, int index,int size)
{
    for(int i=index; i<size; i++)
    {
        if(ind[i]>0)
        {
            result[pos]= str[i];
            for(int j=0; j<=pos; j++)
                cout<<result[j];
            cout<<" ";
            
            ind[i]--;
            
            print(str, ind, pos+1,i,size);
            
            ind[i]++;
        }
    }
}
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int in[28]={0};
        int size =s.length();
        
        for(int i=0; i<size; i++)
        {
            int x = s[i]-'A';
            in[x]++;
        }
        int i=0;
        char str[28];
        int ind[28];
        for(int k=0; k<26; k++)
        {
            if(in[k]>0)
            {
                str[i]= char(k)+'A';
                ind[i]=in[k];
                i++;
            }
        }
        print(str,ind,0,0,i);
        cout<<endl;
    }
	
}
