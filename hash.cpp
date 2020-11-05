#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>


using namespace std;

string exec(string command,map<string,string> &m) {
   char buffer[128];
   string result = "";
     
   FILE* pipe = popen(command.c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   while (!feof(pipe)) {

      if (fgets(buffer, 128, pipe) != NULL)
      {
          string s(buffer);
          size_t found = s.find("\t"); 
          string temp=s.substr(found+1);
          m[s.substr(0,found)]=temp;
        //   cout<< s.substr(0,found)<<endl;
          result += buffer;

      }
   }

   pclose(pipe);
   return result;
}

int main() {
    map<string,string> m;
   string ls = exec("find . -name '*' -printf '%TY-%Tm-%Td %TT %Tz\t%p\n'",m);
//    cout << ls.size();
}