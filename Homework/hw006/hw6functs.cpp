/* Programmer: Nathan Wash
 * User: nawhx8
 * Section: D
 * Description: New and improved Krusty-nigma Masheen
 * File: hw6functs.cpp */

#include "hw6functs.h"

char applyShift(const char input, const char prevInput)
{
  const int ASCII_A = 65;
  const int LETTERS_IN_ALPHABET = 26;

  int inputAsciiValue = static_cast<int>(input);
  int prevAsciiValue = static_cast<int>(prevInput);

  int shift = (prevAsciiValue - ASCII_A);
  int shiftedAsciiValue = (((inputAsciiValue - ASCII_A) + shift)
                           % LETTERS_IN_ALPHABET) + ASCII_A;
  char shiftedChar = static_cast<char>(shiftedAsciiValue);

  return shiftedChar;
}

char diskOne(const char input, const char prevInput)
{
  const int ASCII_A = 65;
  const int LETTERS_IN_ALPHABET = 26;
  const int ARBITRARY_CONSTANT = 3;

  char shiftedInput = applyShift(input, prevInput);
  int shiftedAsciiValue = static_cast<int>(shiftedInput);

  char output = static_cast<char>((((shiftedAsciiValue) + ARBITRARY_CONSTANT)
                                   % LETTERS_IN_ALPHABET) + ASCII_A);

  return output;
}

char diskTwo(const char input, const char prevInput)
{
  const int ASCII_A = 65;
  const int LETTERS_IN_ALPHABET = 26;
  const int ARBITRARY_CONSTANT = 17;

  char shiftedInput = applyShift(input, prevInput);
  int shiftedAsciiValue = static_cast<int>(shiftedInput);

  char output = static_cast<char>((((shiftedAsciiValue) + ARBITRARY_CONSTANT)
                                   % LETTERS_IN_ALPHABET) + ASCII_A);

  return output;
}

char diskThree(const char input, const char prevInput)
{
  char shiftedInput = applyShift(input, prevInput);
  char output;

  switch(shiftedInput)
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
    default:
      output = 'e';
      break;
  }

  return output;
}


char diskFour(const char input, const char prevInput)
{
  char shiftedInput = applyShift(input, prevInput);
  int shiftedAsciiValue = static_cast<int>(shiftedInput);

  const char NEXT_CHAR = static_cast<char>(shiftedAsciiValue + 1);
  const char PREV_CHAR = static_cast<char>(shiftedAsciiValue - 1);
  /*
   * Check if the ascii value of the input is even or odd. Since ascii values
   * for letters start on an odd number, to follow the pattern for A->B, B->A
   * etc, simply add 1 to the ascii value if the input is odd, and subtract 1
   * if the input is even.
   */
  char output;
  if (isMultiple(EVEN_DIVISOR, shiftedAsciiValue))
    output = PREV_CHAR;
  else
    output = NEXT_CHAR;

  return output;
}

char diskFive(const char input, const char prevInput)
{
  const int ASCII_A = 65;
  const int ASCII_B = 66;
  const int ASCII_W = 87;
  const int ASCII_Z = 90;

  char shiftedInput = applyShift(input, prevInput);
  int shiftedAsciiValue = static_cast<int>(shiftedInput);

  //Add 3 to ascii value to get next character with value divisible by 3
  const char NEXT_CHAR_DIV_BY_3 = static_cast<char>(shiftedAsciiValue + 3);
  const char NEXT_CHAR = static_cast<char>(shiftedAsciiValue + 1);
  const char PREV_CHAR = static_cast<char>(shiftedAsciiValue - 1);

  //If input is divisible by 3, add 3 to change input to the next letter
  //divisible by 3. Exclude Z b/c Z is an exception, so W is the last letter
  //that can follow this rule
  char output = 'e';
  if (shiftedAsciiValue >= ASCII_B && shiftedAsciiValue <= ASCII_W
      && isMultiple(TRIPLE_DIVISOR, shiftedAsciiValue))
  {
    output = NEXT_CHAR_DIV_BY_3;
  }
  else if (shiftedAsciiValue > ASCII_B && shiftedAsciiValue < ASCII_Z)
  {
  /* If a letter is not divisible by 3, you can check if it should be swapped
   * with the next or previous letter in the alphabet by testing whether the
   * letter before it is divisible by 3. If so then that means the tested
   * letter is the first of the two between 2 letters divisible by 3, and so
   * should be swapped with the second of the two by adding 1. Otherwise
   * subtract 1 to swap with the previous. */
    if (isMultiple(TRIPLE_DIVISOR, PREV_CHAR))
      output = NEXT_CHAR;
    else output = PREV_CHAR;
  }
  //if the input is Z it is divisible by 3, but needs to wrap, so just
  //set it to B
  else if (shiftedAsciiValue == ASCII_Z)
    output = static_cast<char>(ASCII_B);
  //A does not change
  else if (shiftedAsciiValue == ASCII_A)
    output = static_cast<char>(ASCII_A);

  return output;
}

bool isMultiple(const int multipleOf, const int input)
{
  const int NO_REMAINDER = 0;

  bool result;
  result = (input % multipleOf == NO_REMAINDER) ? true : false;

  return result;
}

int getInput(const string prompt, const int minVal, const int maxVal)
{
  int input;
  cout << endl << prompt << endl;

  do
  {
    cin >> input;
    if (input < minVal || input > maxVal)
      cout << "Input must be between " << minVal << " and " << maxVal
      << " (Inclusive)." << endl;
  } while (input < minVal || input > maxVal);

  return input;
}

bool isValidDiskSelection(const int rotorL, const int rotorM, const int rotorR)
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

char getRotorOutputForDiskNum(const int diskNum, const char input,
                              const char prevInput)
{
  char output;

  switch (diskNum)
  {
    case DISK_ONE:
      output = diskOne(input, prevInput);
      break;
    case DISK_TWO:
      output = diskTwo(input, prevInput);
      break;
    case DISK_THREE:
      output = diskThree(input, prevInput);
      break;
    case DISK_FOUR:
      output = diskFour(input, prevInput);
      break;
    case DISK_FIVE:
      output = diskFive(input, prevInput);
      break;
    default:
      output = 'e';
      break;
  }

  return output;
}