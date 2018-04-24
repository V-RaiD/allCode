#include<iostream>
#include<string>

using namespace std;

string reverseString(string str);

int main(){
  string str;
  cin >> str;
  cout << reverseString(str) << endl;
  return 0;
}

string reverseString(string str){
  int x =str.length();
  int t = x;
  for(int i = 0; i <= x/2; i++){
    char a = str.at(--t);
    str.replace(t,1,1,str.at(i));
    str.replace(i,1,1,a);
  }

  return str;
}
