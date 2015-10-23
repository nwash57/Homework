#include "hw7functions.h"

char getRandomAscii(char min, char max)
{
  int minVal = static_cast<int>(min);
  int maxVal = static_cast<int>(max);
  int range;
  //When the minimum value is non-zero, you must add one to keep the selection
  //inclusive.
  if (minVal > 0)
    range = maxVal - minVal + 1;
  else
    range = maxVal - minVal;

  int asciiVal = rand() % range + minVal;
  char randChar = static_cast<char>(asciiVal);

  return randChar;
}

int getRandomIndex(int min, int max)
{
  int range;
  if (min > 0)
    range = max - min + 1;
  else
    range = max - min;

  int num = rand() % range + min;
  return num;
}

license_plate generateLicense()
{
  license_plate plate;

  plate.firstLetter = getRandomAscii('A', 'C');
  plate.secondLetter = getRandomAscii('A', 'C');
  plate.thirdLetter = getRandomAscii('A', 'C');
  plate.firstNum = getRandomAscii('0', '9');
  plate.secondNum = getRandomAscii('0', '9');
  plate.thirdNum = getRandomAscii('0', '9');

  return plate;
}

registration generateRegistration()
{
  registration reg;

  reg.plate = generateLicense();
  reg.color = COLORS[getRandomIndex(0, NUM_COLORS)];
  reg.owner = NAMES[getRandomIndex(0, NUM_NAMES)];

  return reg;
}

bool platesEqual(license_plate plate1, license_plate plate2)
{
  bool result = false;

  if (plate1.firstLetter == plate2.firstLetter &&
      plate1.secondLetter == plate2.secondLetter &&
      plate1.thirdLetter == plate2.thirdLetter &&
      plate1.firstNum == plate2.firstNum &&
      plate1.secondNum == plate2.secondNum &&
      plate1.thirdNum == plate2.thirdNum)
    result = true;

  return result;
}

string plateToString(license_plate plate)
{
  string plateString;

  plateString = plate.firstLetter;
  plateString += plate.secondLetter;
  plateString += plate.thirdLetter;
  plateString += plate.firstNum;
  plateString += plate.secondNum;
  plateString += plate.thirdNum;

  return plateString;
}

int getIndexOfColor(string inputColor)
{
  int index;
  for (int i = 0; i < NUM_COLORS; i++)
  {
    if (COLORS[i] == inputColor)
      index = i;
  }
  return index;
}

bool isDuplicate(int regCount, registration reg,
                 registration database[])
{
  bool result = false;

  for (int j = 0; j < regCount; j++)
  {
    if (platesEqual(reg.plate, database[j].plate))
      result = true;
    if (result)
      break;
  }

  return result;
}

void generateDatabase(registration (&database)[NUM_REGISTRATIONS])
{
  int regCount = 0;
  while (regCount < NUM_REGISTRATIONS)
  {
    registration reg = generateRegistration();

    if (!isDuplicate(regCount, reg, database))
    {
      database[regCount] = reg;
      regCount++;
    }
  }
}

void printDatabase(registration database[NUM_REGISTRATIONS])
{
  cout << "CAR DATABASE" << endl;
  cout << "License\t\tColor\t\tName" << endl
  << "----------------------"
  << "--------------------" << endl;

  for (int i = 0; i < NUM_REGISTRATIONS; i++)
  {
    string owner = database[i].owner;
    string plate = plateToString(database[i].plate);
    string color = database[i].color;

    if (color == "dark blue")
      cout << plate << "\t\t" << color
      << "\t" << owner << endl;
    else
      cout << plate << "\t\t" << color
      << "\t\t" << owner << endl;
  }
}

string getColorInput()
{
  string input;
  bool valid = false;
  do
  {
    cout << "Input the color of the car: ";
    cin >> input;
    if (!isInArray(input, NUM_COLORS, COLORS) || input != QUIT)
      cout << "Your input must be in the list of available colors." << endl;
    else
      valid = true;
  } while (!valid);

  return input;
}

string getPlateInput()
{
  string input;
  bool valid = false;
  do
  {
    cout << "Input a license plate number, use * for unknowns: " << endl;
    cin >> input;
    if (!isValidPlate(input) || input != QUIT)
      cout << "Your input must be in the format ABC123" << endl;
    else
      valid = true;
  } while(!valid);

  return input;
}

bool isValidPlate(string plate)
{
  const int ASCII_A = 65;
  const int ASCII_Z = 90;
  const int ASCII_0 = 48;
  const int ASCII_9 = 57;
  const int ASCII_ASTERISK = 42;

  bool result = true;

  //Checks the first three characters to make sure they're A-Z
  for (int i = 0; i < 3; i++)
  {
    int indexAscii = static_cast<int>(plate[i]);
    if ((indexAscii < ASCII_A || indexAscii > ASCII_Z)
        && indexAscii != ASCII_ASTERISK)
    {
      result = false;
      break;
    }
  }
  //If it passed the first check
  if (result)
  {
    //Checks the last three characters to make sure they're 0-9
    for (int i = 3; i < 6; i++)
    {
      int indexAscii = static_cast<int>(plate[i]);
      if ((indexAscii < ASCII_0 || indexAscii > ASCII_9)
           && indexAscii != ASCII_ASTERISK)
      {
        result = false;
        break;
      }
    }
  }

  return result;
}

bool isInArray(string input, int arraySize, const string array[])
{
  bool result = false;

  for (int i = 0; i < arraySize; i++)
  {
    if (input == array[i])
      result = true;
    if (result)
      break;
  }

  return result;
}

void printRegistration(registration reg)
{
  cout << plateToString(reg.plate) << "\t\t" << reg.color << "\t\t"
       << reg.owner << endl;
}

void applyScores(registration (&database)[NUM_REGISTRATIONS],
                 string inputPlate, string inputColor)
{
  int inputColorIndex = getIndexOfColor(inputColor);

  for (int i = 0; i < NUM_REGISTRATIONS; i++)
  {
    string plate = plateToString(database[i].plate);

    int score = 0;
    if (inputColor == database[i].color)
    {
      score += 2;
    }
    else
      switch(inputColorIndex)
      {

        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
          if (COLORS[inputColorIndex - 1] == database[i].color ||
              COLORS[inputColorIndex + 1] == database[i].color)
            score += 1;
          break;

        case 0:
          if (COLORS[inputColorIndex + 1] == database[i].color)
            score += 1;
          break;

        case 6:
          if (COLORS[inputColorIndex] == database[i].color)
            score += 1;
          break;
      }

    for (int j = 0; j < 6; j++)
    {
      if (inputPlate[j] == plate[j])
        score += 2;
      else if (inputPlate[j] == '*')
        score += 1;
    }

    database[i].score = score;
  }
}

int getMinScore()
{
  int input;

  do
  {
    cout << "Input the minimum score to be reported (inclusive): ";
    cin >> input;
    if (input < 0 || input > 10)
      cout << "Input must be an integer between 0 and 10 (inclusive)." << endl;
  } while (input < 0 || input > 10);

  return input;
}

void printReport(int minScore, registration database[NUM_REGISTRATIONS])
{
  for (int i = 10; i >= minScore; i--)
  {
    cout << "Score " << i << ":" << endl;
    for (int j = 0; j < NUM_REGISTRATIONS; j++)
    {
      if (database[j].score == i)
      {
        cout << "\t";
        printRegistration(database[j]);
      }
    }
  }
}
