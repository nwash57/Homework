//
// Created by nathan on 10/11/15.
//

#ifndef HOMEWORK_MAIN_H
#define HOMEWORK_MAIN_H

#include <iostream>

using namespace std;

bool isMultiple(int, int);

char diskOne(char input)
{
  int asciiValue = static_cast<int>(input);
  char output;

  output = static_cast<char>((((asciiValue) + 3) % 26) + 65);

  return output;
}

char diskTwo(char input)
{
  int asciiValue = static_cast<int>(input);
  char output;

  output = static_cast<char>((((asciiValue) + 17) % 26) + 65);

  return output;
}

char diskThree(char input)
{
  char output;

  switch(input)
  {
    case 'A':
      output = 'H';
      break;
    case 'B':
      output = 'U';
      break;
    case 'C':
      output = 'I';
      break;
    case 'D':
      output = 'P';
      break;
    case 'E':
      output = 'N';
      break;
    case 'F':
      output = 'W';
      break;
    case 'G':
      output = 'C';
      break;
    case 'H':
      output = 'K';
      break;
    case 'I':
      output = 'E';
      break;
    case 'J':
      output = 'X';
      break;
    case 'K':
      output = 'Q';
      break;
    case 'L':
      output = 'Z';
      break;
    case 'M':
      output = 'O';
      break;
    case 'N':
      output = 'V';
      break;
    case 'O':
      output = 'S';
      break;
    case 'P':
      output = 'B';
      break;
    case 'Q':
      output = 'L';
      break;
    case 'R':
      output = 'J';
      break;
    case 'S':
      output = 'D';
      break;
    case 'T':
      output = 'Y';
      break;
    case 'U':
      output = 'F';
      break;
    case 'V':
      output = 'R';
      break;
    case 'W':
      output = 'A';
      break;
    case 'X':
      output = 'G';
      break;
    case 'Y':
      output = 'T';
      break;
    case 'Z':
      output = 'M';
      break;
  }

  return output;
}

char diskFour(char input)
{
  int asciiValue = static_cast<int>(input);
  char output;

  /*
   * Check if the ascii value of the input is even or odd. Since ascii values
   * for letters start on an odd number, to follow the pattern for A->B, B->A
   * etc, simply add 1 to the ascii value if the input is odd, and subtract 1
   * if the input is even.
   */
  if (isMultiple(2, asciiValue))
    output = static_cast<char>(asciiValue + 1);
  else
    output = static_cast<char>(asciiValue - 1);

  return output;
}

char diskFive(char input)
{
  const int ASCII_A = 65;
  const int ASCII_B = 66;
  const int ASCII_W = 87;
  const int ASCII_Z = 90;

  int asciiValue = static_cast<int>(input);
  int output;

  if (asciiValue >= ASCII_B && asciiValue <= ASCII_W && isMultiple(3, asciiValue))
  {
    output = static_cast<char>(asciiValue + 3);
  }
  else if (asciiValue > ASCII_B && asciiValue < ASCII_W)
  {
    if (isMultiple(2, asciiValue))
      output = static_cast<char>(asciiValue + 1);
    else output = static_cast<char>(asciiValue - 1);
  }
  else if (asciiValue == ASCII_Z)
    output = static_cast<char>(ASCII_B);
  else if (asciiValue == ASCII_A)
    output = static_cast<char>(ASCII_A);

  return output;
}

char applyShift(char lastChar)
{
  int asciiValue = static_cast<int>(lastChar);
  char output = static_cast<char>(asciiValue - 65);

  return output;
}

/*
 * Description: Checks if an input number is a multiple of "multipleOf"
 * Pre:  Number to check if input is a multiple of, and input number
 * Post: True if input is a multiple of "multipleOf", otherwise returns false
 */
bool isMultiple(int multipleOf, int input)
{
  bool result;
  result = (input % multipleOf == 0) ? true : false;

  return result;
}

template<typename T_inputType>
T_inputType getInput(string prompt, T_inputType minVal, T_inputType maxVal)
{
  T_inputType input;
  cout << endl << prompt << endl;

  do
  {
    cin >> input;
    if (input < minVal || input > maxVal)
      cout << "Input must be between " << minVal << " and " << maxVal
      << " (Inclusive)." << endl;
  } while (input < minVal || input > maxVal);
}

bool isValidDiskSelection(int rotorL, int rotorM, int rotorR)
{
  bool result;

  if (rotorL == rotorM ||
      rotorL == rotorR ||
      rotorM == rotorR)
  {
    result = false;
  }
  else result = true;

  return result;
}

#endif //HOMEWORK_MAIN_H
