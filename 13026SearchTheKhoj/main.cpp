#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;


int main() {
  int T = 0;
  int c = 1;
  scanf("%d\n", &T);
  while(T--){
    int nums;
    scanf("%d\n", &nums);
    vector<string> phones;
    for(int i = 0; i < nums; i++){
      string s;
      cin >> s;
      phones.push_back(s);
    }
    string memory;
    cin >> memory;
    cout << "Case " << c++ << ":" << endl; 
    for(int i = 0; i < nums; i++){
      string s = phones[i];
      int count = 0;
      for(int j = 0; j < s.length(); j++){
        if(s[j] != memory[j]){
          if(count++ == 1) break;
        }
        if(j == s.length() - 1){
          cout << s << endl;
        }
      }
    }
  }
}
