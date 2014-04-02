#include<iostream>
#include<string>
#include<cstring>

using namespace std;
const int MAXX = 2000;
int F[MAXX];
void build_failure_function(string pattern)
{
  // let m be the length of the pattern
  int m = pattern.size();
  F[0] = F[1] = 0;
  for(int i=2;i<=m;i++)
    {
      //j is the index of the largest next partial match
      //(the largest suffix/prefix) of the string under 
      // index i-1
      int j = F[i-1];
      for(; ;)
	{
	  //check to see if the last character of string i-
	  //- pattern[i-1] "expands" the current "candidate"
	  //best partial match - the prefix under index j
	  if(pattern[j] == pattern[i-1])
	    {
	      F[i] = j+1;
	      break;
	    }
	  //if we cannot "expand" even the empty string 
	  if(j==0)
	    {
	      F[i] = 0;
	      break;
	    }
	  //else go to the next best partial match
	  j = F[j];
	}
    }
}
void Knuth_Morris_Pratt(string text,string pattern)
{
  //let n be the len of the text, m the 
  // size of the pattern and F[] - the
  //failure function
  build_failure_function(pattern);
  int n = text.size(),m=pattern.size();
  int i=0;//the intial state of the automation is
          //the empty string
  int j=0;//the first character of the text;
  for(; ; )
    {
      if(j==n) break;//we reached the end of text
      
      //if the current character of the text "expands" the 
      //current match
      if(text[j]==pattern[i])
	{
	  i++;//change the state of the automation
	  j++;//get the next character from the text
	  if(i==m)
	    {
	      cout << "YES\n";
	      return;
	    }
	}
      //if the current state is not zero (we have not
      // reached the empty string yet) we try to
      // "expand" the next best largest match
      else if(i>0) 
	i = F[i];
      //if we reached the empty string and failed to
      //"expand" even it; we go to the next
      //character from the text, the state of the
      //automation remains zero
      else j++;
    }
  cout << "NO\n";
}
int main()
{
  string pattern,text;
  cin>>pattern>>text;
  Knuth_Morris_Pratt(text,pattern);
  return 0;
}
