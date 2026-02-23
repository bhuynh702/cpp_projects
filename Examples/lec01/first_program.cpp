#include<iostream>
#include<string>

using namespace std; // not explain this at all

int main()
{
  // how do you output things?
  // bools, integers, floats, doubles 
  // int and long [technically short but don't]
  cout << 3 << " " << "a string" << endl;
  cout << 2.71828 << " " << true << 'c' << endl;

  cout << "\thello \n \n goodbye\n" << endl;

  /* Declaring Variables

     How do we do it?

  */
  
  int x = 3; // <- declaring integers 
  int y = 14, z = 2, k = 31;
  long big_num = 57812503;
  int other_big = big_num;
  
  cout << big_num << endl;
  cout << "This is a long number: " << big_num << endl;
  cout << "This is an int: " << other_big << endl;

  char my_character = 'a';
  cout << int(my_character) << endl;
  char tt = char(48);
  cout << tt << endl;

  float pi = 3.1415925;
  double dpi = 3.1415925;
  cout << pi << ' ' << dpi << endl;

  // the variable can be left unassigned;
  int varg;
  cout << varg << endl;

  cout << "Tell me an integer: ";
  cin >> varg;

  cout << varg << endl;

  float my_float;
  cin >> my_float;
  cout << my_float << endl;

  string s;
  cin >> s;
  cout << s << endl;
  
  return 0; // how'd it all go? ok == 0, not ok == not zero
}

int main()
{
  cout << "hi" << endl;
  int x = 2;
  cout << x << " " << 17 << " hello " << endl;

  char c;
  cout << "Enter a character, not a string: " << endl;
  cin >> c;

  string my_string;
  cout << "Now input a string: ";
  cin >> my_string;

  cout << my_string << " " << c << endl;
  return 0;

  // getline(cin, my_string);
  // cout << my_string << endl;

  double pi = 3.1415926;

  double other = 439.212313132;
  
  cout << setprecision(10) << pi << endl;
  
  return 0;
  
}
