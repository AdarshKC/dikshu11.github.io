#include<bits/stdc++.h>
using namespace std;

//Define linked list using struct
typedef struct n
{
  char a;
  struct n* next;
}node;

/*Function to allocate 
a new node which stores char a*/
node* allocate(char a)
{
  node* p = new node();
  p->a = a;
  p->next =NULL;
  return p;
}

int main()
{
  string s;
  while(cin>>s)
  {
    int len = s.length();
    /*head is pointer to start of list
      tail is pointer to end of list
      curr is arbitrary pointer*/
    node* head = NULL;  
    node* tail = NULL;
    node* curr = NULL;

    /*Traversing string*/
    for(int i=0; i<len; i++)
    {   
	
        if(s[i]!='[' && s[i]!=']')
        {
	    /*Char s[i] needs to be 
		inserted at end*/
            node* p = allocate(s[i]);
            if(tail==NULL)
            {
              tail = p;
              curr =p;
              head = p;
            } 
            else
            {
              tail->next = p;
              tail = tail->next;
            }
        }
        else if(s[i]=='[')
        {
		/*If char is '[' insertion starts before current head.
		 If char is ']' insertion should be done at end after that
		First char after '[' needs to be inserted
		before head. After that char needs to be inserted
		 after new head*/	
			  i++;
		          curr = NULL;
		          while(i<len)
		          {
				            if(s[i]==']')
				              break;
				            else if(s[i]=='[')
				             {
						curr = NULL;
						i++;
					     }
				            else
				            {
					              node* p = allocate(s[i]);
					              if(head== NULL)
					              {
					                head = p;
					                curr = p;
					                tail = p;
					              }
						      else if(curr == NULL)
				         	      {
							p->next = head;
							head = p;
							curr = p;
						      }
						      else if(curr->next ==NULL)
						      {
							curr->next = p;
							tail = curr->next;
z							curr = curr->next;
						      }
					              else if(curr != NULL)
					              {
					                p->next = curr->next;
					                curr->next = p;
					                curr = curr->next;
					              }
									
						i++;

		            		  }
					
		          }
         }
    }
    /*Printing the list*/
    while(head!=NULL)
    {
        cout<<head->a;
        head = head->next;
    }
    cout<<endl;
  }

}
