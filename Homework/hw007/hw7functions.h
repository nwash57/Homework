
#ifndef HOMEWORK_HW7FUNCTIONS_H
#define HOMEWORK_HW7FUNCTIONS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_REGISTRATIONS = 20;

const int NUM_COLORS = 6;
const string COLORS[NUM_COLORS] = {"black", "dark blue", "blue",
                                   "grey", "silver", "white"};
const int NUM_NAMES = 25;
const string NAMES[NUM_NAMES] = {"Amelia", "Oliver", "Olivia", "Jack", "Emily",
                                 "Charlie", "Ava", "Harry", "Isla", "Jacob",
                                 "Jessica", "George", "Poppy", "Alfie", "Mia",
                                 "Noah", "Lily", "James", "Isabella", "Oscar",
                                 "Thomas", "Leo", "William", "Joshua", "Logan"};

const string QUIT = "quit";

struct license_plate
{
  char firstLetter;
  char secondLetter;
  char thirdLetter;
  int firstNum;
  int secondNum;
  int thirdNum;
};

struct registration
{
  license_plate plate;
  string color;
  string owner;
  int score;
};

int getIndexOfColor(string inputColor);
char getRandomLetter();
int getRandomNum();
bool isDuplicate(int regCount, registration reg,
                 registration database[]);
void generateDatabase(registration (&database)[NUM_REGISTRATIONS]);
void printDatabase(registration database[NUM_REGISTRATIONS]);
bool isInArray(string input, int arraySize, const string array[]);
string getColorInput();
string getPlateInput();
bool isValidPlate(string plate);
void printRegistration(registration reg);
void applyScores(registration (&database)[NUM_REGISTRATIONS],
                 string inputColor, string inputPlate);
int getMinScore();
void printReport(int minScore, registration database[NUM_REGISTRATIONS]);


license_plate generateLicense();
registration generateRegistration();

bool platesEqual(license_plate plate1, license_plate plate2);

string plateToString(license_plate plate);

#endif //HOMEWORK_HW7FUNCTIONS_H
