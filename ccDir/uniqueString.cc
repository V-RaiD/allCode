#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool isUnique(string str);

int main(){
  string str;
   cin >> str;

   cout << "Is String " << str << " unique : " << (isUnique(str) ? "Yes" : "No") << endl;
  return 0;
}

bool isUnique(string str){
  string sorted = str;
  sort(sorted.begin(),sorted.end());

  for(int i = sorted.length() - 1; i >= 0 ; i--){
    if(!((i - 1) < 0)){
      if(sorted.at(i) == sorted.at(i-1)){
        return false;
      }
    }
  }
  return true;
}
