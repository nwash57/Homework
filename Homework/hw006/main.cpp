//
// Created by nathan on 10/11/15.
//

#include "main.h"
#include <iostream>

using namespace std;

int main()
{
  char input;
  char output;

  int rotorL, rotorM, rotorR;

  cout << "Welcome to the new and improved Krusty-nigma Masheen" << endl;

  do
  {
    const static int MIN_DISK_NUM = 1;
    const static int MAX_DISK_NUM = 5;

    rotorL = getInput("Please enter disk number for Left rotor.",
        MIN_DISK_NUM, MAX_DISK_NUM);
    rotorM = getInput("Please enter disk number for Middle rotor.",
        MIN_DISK_NUM, MAX_DISK_NUM);
    rotorR = getInput("Please enter disk number for Right rotor.",
        MIN_DISK_NUM, MAX_DISK_NUM);

    if (!(isValidDiskSelection(rotorL, rotorM, rotorR)))
      cout << "You may not select the same disk twice. Try again.";
  } while (!(isValidDiskSelection(rotorL, rotorM, rotorR)));




  while (input != '.')
  {
    cout << "input char:    ";
    cin >> input;
    cout << "\033[F" << "input char:    " << input;



    cout << "  ->  " << output << endl;


  }
}