/* Programmer: Nathan Wash
 * User: nawhx8
 * Section: D
 * Description: Krusty citizen lookup utility
 * File: hw7.cpp */

#include "hw7functions.h"

int main()
{
  cout << "Welcome to the Krusty Registration lookup program." << endl;
  cout << "Type \"quit\" at any time to end the program." << endl << endl;

  srand(time(NULL));
  registration database[NUM_REGISTRATIONS];

  generateDatabase(database);

  printDatabase(database);

  while (true)
  {
    cout << endl << endl;

    string inputPlate = getPlateInput();
    if (inputPlate == QUIT)
      break;

    string inputColor = getColorInput();
    if (inputColor == QUIT)
      break;

    applyScores(database, inputPlate, inputColor);

    int minScore = getMinScore();

    printReport(minScore, database);
  }
  return 0;
}