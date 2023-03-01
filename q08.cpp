#include<iostream>
#include <bits/stdc++.h>
#include<fstream>
using namespace std;

int main (int argc, char *argv[])
{
  if(argc!= 3){
    cout << "Invalid Number of Arguments!" << endl;
    return -1;
  }
  ifstream f1,f2;
  string fname1 = argv[1];
  string fname2 = argv[2];

  f1.open(fname1);
  f2.open(fname2);

  ofstream f3;
  f3.open("merge.txt");
  string line1;
  string line2;
  while (getline(f1,line1) && getline(f2,line2))
  {
   f3 << line1 << endl;
   f3 << line2 << endl;
  }

  f1.close();
  f2.close();
  f3.close();

  cout << "Contents of Merge.txt:" << endl;
  ifstream f4;
  f4.open("merge.txt");
  while(getline(f4,line1)){
    cout << line1 << endl;
  }
  f4.close();
  return 0;
}
