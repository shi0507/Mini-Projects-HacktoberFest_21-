//TOTALLY WRONG XD WRONG IDEA

#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int countDist(int arr[], int n){
  unordered_set<int> s;

  for(int i=0;i<n;i++){
    s.insert(arr[i]);
  }

  unordered_set<int> :: iterator itr;
  for (itr = s.begin(); itr != s.end(); itr++)
        cout << (*itr) << endl;

  return arr[1];
}

int main(){
  int count;
  cout<<"Enter the size of the array";
  cin>>count;
  int arr[count];
  cout<<"Enter the array elements"<<endl;
  for(int i=0;i<count;i++){
    cin>>arr[i];
  }
  countDist(arr, count);

}
