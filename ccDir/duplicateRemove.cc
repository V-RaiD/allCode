#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string removeDuplicate(string str);

int main(){
  string str;
  cin >> str;
  cout << removeDuplicate(str) << endl;
  return 0;
}

string removeDuplicate(string str){
  string sorted = str;
  sort(sorted.begin(),sorted.end());
  for(int i = sorted.length() - 1; i >= 0 ; i--){
    if(!((i - 1) < 0)){
      if(sorted.at(i) == sorted.at(i-1)){
        sorted.erase(i,1);
      }
    }
  }

  return sorted;
}
