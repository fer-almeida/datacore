/* 
 * File:   main.cpp
 * Author: Fernando Almeida <fernando.almeida@me.com>
 *
 * Created on February 5, 2015, 11:15 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

class smallobj {
   private:
       static int total;
       int id;
       
      int somedata;
      int otherdata;
      
   public:
       smallobj() {
           total++;
           id = total;
           
           cout << "New object!" << endl;
       }
       
       ~smallobj() {
           total--;
           cout << "Matei o " << id << endl;
       }
       
      void setdata(int d)
         { somedata = d; }

      int ID(void) {
          return id;
      }

      void showdata() {
          cout << "Data is " << somedata << " Other is " << otherdata << endl;
      }
   };
   
   int smallobj::total = 0;           //definition of total
   

/*
 * 
 */
int main(int argc, char** argv) {
    smallobj test1;
    smallobj test2;
    test2.~smallobj();
    smallobj test3;
                
    cout << test1.ID() << endl;
    cout << test2.ID() << endl;
    cout << test3.ID() << endl;
    
    return 0;
}

