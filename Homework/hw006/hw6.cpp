/* Programmer: Nathan Wash
 * User: nawhx8
 * Section: D
 * Description: New and improved Krusty-nigma Masheen
 * File: main.cpp */

#include "hw6functs.h"

int _main()
{
  char input = 'e';
  char output;

  int rotorL, rotorM, rotorR;
  char prevInputL = 'A';
  char prevInputM = 'A';
  char prevInputR = 'A';

  cout << "Welcome to the new and improved Krusty-nigma Masheen" << endl;

  do
  {
    const static int MIN_DISK_NUM = DISK_ONE;
    const static int MAX_DISK_NUM = DISK_FIVE;

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
    cout << "Input:    ";
    cin >> input;
    cout << "\033[F" << "Input:    " << input;

    if (input == '.')
      break;
    if (input == '_')
      output = input;
    else
    {
      char rotorLOut = getRotorOutputForDiskNum(rotorL, input, prevInputL);
      prevInputL = input;
      char rotorMOut = getRotorOutputForDiskNum(rotorM, rotorLOut, prevInputM);
      prevInputM = rotorLOut;
      char rotorROut = getRotorOutputForDiskNum(rotorR, rotorMOut, prevInputR);
      prevInputR = rotorMOut;

      output = rotorROut;
    }
    cout << "  ->  " << output << endl;
  }

  cout << endl << endl
      << "Thank you for using the Krusty-nigma Masheen 2.0." << endl;

  return 0;
}