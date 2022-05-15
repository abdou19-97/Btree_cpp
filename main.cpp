//main.cpp
#include <iostream>
#include "Btree.h"
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
    int N;
    cout << "Enter a Key: " << endl;
    cin >> N;

    while(N)
   {
     if(N < 400)
    {   cout << "Key must be >= 400" <<endl;
       cin>>N;
 
    } 
    else
     { //create a vector with sie N and 0 values
       vector<int> vec(N, 0);

       BTreeFriend m(vec.size());
    
       m.generateRV(vec);
   
       m.buildTree(m, vec);
      //check if the key is present 
      (m.search(N) != NULL)? cout << "\nPresent ": cout<<"\nNot Present"<<endl;
       
       m.traverse();
      
       break;
     } 

  }
    return 0;
  
}
