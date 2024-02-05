/*
Author: Omar-Bounawara

--------linked list implimentation---------

overview:

  basic integer linked list implimentation using c++, the program declare a struct

  node having 2 compenents : data & link

  node -------> data : the value in that node
       |
        -------> link : a pointer to the next node
  
  it's important to note that this data structure is meant for educational purposes,that's why:

    - no defining needed : the list is already created you just do operations
    - the program keeps track of the size and head pointer as a global variables 
   -> that's why it's only possible to use just 1 list; 




fonctions description:
              
  this implimentation provoide the basic linked operations wich are :

    inserting : it provoides 3 fonctions for insertion : 

        insert_start(value) : insert at the start of the list by creating a new node
                              modify the head value to it and making the node points at
                              the previous(first) node ;

        insert_end(value)   : insert at the end of the list by creating a new node with a NULL link
                              and pointing the previous node at the new node ;

        insert_at(index,value) : if index = 0 -----> insert_start(value)
                                 
                                 if index = size of list ------> insert_end(value)
                                 
                                 else : the fonction iterates through the list keeping the value of 
                                 current and previous node ; 
                                 when the loop ends, it creates a new node with link to current node
                                 then change previous node link to the created one's 
    
    removing : 2 focntions following the same insertion logic:
      
      note :  when a node is removed , the fonction automatically return it's data(value)

      remove_start()
      remove_at(index)
      
      - to remove the last node simply use return_at(size);


    accessing: 
      
      1 fonction to only return the node value without removing it:

      return_at(index)
    
    reprentaion : 
     
     print() : used to print the list values seperated by one space 
*/








#include<iostream>
using namespace std;

#define rep(var,start,end) for(int var=start;var<end;var++)


// NODE STRUCTURE
struct node{
     int data;
     node* link;
   };


//GLOBAL VARIABLES

int si=0;
node* head = NULL;





//FONCTIONS
//INSERTING

void insert_start(int data){
 node* temp=new node();
   temp->data=data;
   temp->link=head;
   head=temp;
   si++;
}


void insert_end(int data){
    node* end=head;
    node* prev=head;
    while(end!=NULL){
        prev=end;
        end=end->link;
    }
    node* temp=new node();
    prev->link=temp;
    temp->link=NULL;
    temp->data=data;
si++;
}

void isnert(int index ,int value){
  if(index==0){
    insert_start(value);
    
  }
  else if(index==si){
    insert_end(value);
  }
  else{
   node* temp=new node();
   
   node* current=head;
   rep(i,0,index-1){
    current=current->link;
   }
   temp->link=current->link;
   current->link=temp;
   
   temp->data=value;
  }
si++;
}





//REMOVING

int remove_first(){
  node* next=head->link;
  int value=head->data;
  free(head);
  head=next;
  return value;
}

int remove_at(int index){
  if(index==0){
   return remove_first();

  }
  else{
    node* current=head;
    node* prev;
    rep(i,0,index){
      prev=current;
      current=current->link;
    }
    int value=current->data;
    node* next=current->link;
    free(current);
    prev->link=next;
    return value;
  }
}







//ACCESSING


int return_at(int index){
  if(index==0){
   return head->data;

  }
  else{
    node* current=head;
    rep(i,0,index){
      current=current->link;
    }
    return current->data;
  }
}




//REPRESENTATION

void print(){
   node* start=head;
   while(start!=NULL){
    cout<< start->data<<" ";
    start=start->link;
   }
}





// MAIN : EXAMPLE USAGE


int main(){
   
  //USED TO MAKE INPUT AND OUTPUT MORE EFFICIENT

   ios::sync_with_stdio(0);
   cin.tie(0);

   //USING FILES FOR INPUT AND OUTPUT


   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   //VARIBALES AND SIZE INPUT
   int n,elm,popped;
   cin>>n;

   //INSETING :
   // note that here the input will be inversed in the list since we alawys insert at the start
   rep(i,0,n){
      cin>>elm;
      insert_start(elm);
   }
   
   //REMOVING AND REPR
   print();
   cout<<"\n";
   popped=remove_at(5);
   print();
   cout<<"\n returned :"<<popped;

   
 




    return 0;
}