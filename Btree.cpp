//BTree.cpp
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "Btree.h"
//#include "BTreeFriend.h"
using namespace std;

//BTreeNode constructure 
BTreeNode::BTreeNode(int _m, bool l)
{
    m = _m;
    leaf = l;
   //allocate memory for both keys and child class
   keys = new int[2*m-1];
   C = new BTreeNode *[2*m];

  //the key counter
  Kcount = 0;
}

//traverse function
void BTreeNode::traverse()
{
    int i;
    for(i = 0; i < Kcount; i++)
    {
       if(leaf == false)
          C[i]->traverse();
          cout<<" "<<keys[i];
      
    }
    cout <<endl;
  if(leaf == false)
        C[i]->traverse(); 
}

//search function
BTreeNode *BTreeNode::search(int k)
{
   //search for the key
   int i = 0;
   while(i<Kcount && k > keys[i])
      i++;
    
   //if the key is found
   //then return it
   if(keys[i] == k)
      return this;

   //otherwise return NULL
   else
  { return NULL;}
  
  //look into the appropriate child
  return C[i]->search(k);
}

//insert function

void BTreeFriend::insert(int k)
{

          
     if(root == NULL)     //check if the rrot is empty
     {
        root = new BTreeNode(m, true); //allocate memory for the root
        root->keys[0] = k; //insert the first key
        root->Kcount = 1; //increase the number of keys 
     }
 
    
    else                       //otherwise if the root is full 
   {
     if(root->Kcount == 2*m-1)
      {
       
         BTreeNode* new_root = new BTreeNode(m, true); //allocate a memory for the new root
       
        
         new_root->C[0] = root;   //make the old root as a child
  
       
         new_root->split(0, root);     //call the split funciton

         int i = 0;
         if (new_root->keys[0] < k)  //check if the new root is less than the key entered
             i++;       //increase index
         new_root->C[i]->internalInsert(k); //call the subtree insertion  
        
         root = new_root; //assign the new root to the old one
         
      }
     else
      root->internalInsert(k);  //class subtree insertion otherwise
   }
}

//internalInsertion
void BTreeNode::internalInsert(int k)
{ 
    int i = Kcount - 1;

    if(leaf == true)   //if we are at the root level insert keys in an incresing order
   {
      while(i >= 0 && keys[i] > k)
      {   keys[i + 1] = keys[i];
          i--;
      }

     keys[i + 1] = k;
     Kcount++;

  }

  else            //otherwise find the child where k belong
 {
    while(i >= 0 && keys[i] > k) 
        i--;

    if(C[i + 1]->Kcount == 2*m-1) //check if the child is full
   {
       split(i + 1, C[i+1]);  //call the split
        
       if(keys[i+1] < k) //after spliting check where the key belong
           i++;
   }
   C[i+1]->internalInsert(k); //call this function recursivly 
 }
}

//split function
void BTreeNode::split(int n, BTreeNode* y)
{
   
     BTreeNode *z = new BTreeNode(y->m, y->leaf); //allocate the node z
    
     z->Kcount = m-1;  //since the leaf is full then thw new node must be m-1

     for (int j = 0; j < m-1; j++) //copy the right half of y into z 
     {
        z->keys[j] = y->keys[j+m];
     } 
     if (y->leaf == false)   //copy over the child pointer if y isn't leaf
    {
        for (int j = 0; j < m; j++)
            z->C[j] = y->C[j+m];
    }
    y->Kcount = m-1;  //y will left with m-1
   
    for (int j = Kcount; j >= n+1; j--) //create space for the new child
    {   C[j+1] = C[j];
    }

    C[n+1] = z; //link the child to the new node

    for (int j = Kcount-1; j >= n; j--) //find a location for the new key and shift the greater keys
    {
       keys[j+1] = keys[j];
    }
    Kcount++;
}

//random genrater function
void BTreeFriend::generateRV(vector<int> &arr)
{
    srand(time(0));  
    int i;
    for (i = 0; i < arr.size(); i++)   //generate a random from [0 to 3*N]
    {
        arr[i] = rand() % (3 * arr.size());
    }
    
}

//build tree funciton
void BTreeFriend::buildTree(BTreeFriend &m, vector<int> &arr)
{
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) //insert from the random generated keys
    {
        m.insert(arr[i]);
    }
    return;
}





