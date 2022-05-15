//BTree.h
#ifndef BTreeNode_B_EXISTS
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdlib>
using namespace std;

class BTreeNode
{
  //private member 
  private:
    int m;
    bool leaf;
    int* keys;
    BTreeNode **C;  //pointed to an array of root children
    int Kcount;    //count how many keys inserted 
  
  public:
    //constructor
    BTreeNode(int _m, bool l);
    //function that insert in the subtree
    //as long as it's not exceeding the order
    void internalInsert(int k);
   //function that split the nodes when the leaf
   //reach 5
    void split(int n, BTreeNode* y);
   //Traverse function
    void traverse();

   //function that search for the key
    BTreeNode *search(int k);
   //using a friend class that can access 
   //the BTreeNode member
   #ifndef BTreeFriend_B_EXISTS  
    friend class BTreeFriend;
   #endif
};
//Friend class
class BTreeFriend
{
    private:
     BTreeNode *root;
     int m;
    public:

     BTreeFriend(int n) //constructor
     {  root = NULL;
        m = n;
     }

    void traverse()
    {
       if(root != NULL)
          root->traverse();
    }

   //search function
    BTreeNode* search(int k)
    {
      if(root == NULL)
        return root;
      else
     { return root->search(k);}
   }
  //insert function
  void insert(int k);
  //function that generate a squence of numbers
  void generateRV(vector<int> &arr);
  //build tree function
  void buildTree(BTreeFriend &m, vector<int> &arr);
};

 
        
#endif   
