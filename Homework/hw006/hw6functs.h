/* Programmer: Nathan Wash
 * User: nawhx8
 * Section: D
 * Description: New and improved Krusty-nigma Masheen
 * File: hw6functs.h */

#ifndef HOMEWORK_HW6FUNCTS_H
#define HOMEWORK_HW6FUNCTS_H

#include<iostream>
using namespace std;

const int DISK_ONE = 1;
const int DISK_TWO = 2;
const int DISK_THREE = 3;
const int DISK_FOUR = 4;
const int DISK_FIVE = 5;

const int EVEN_DIVISOR = 2;
const int TRIPLE_DIVISOR = 3;

/* Description: Uses the shift formula to find the shifted character of input
 * Pre:  New and previous input
 * Post: Shifted output*/
char applyShift(const char input, const char prevInput);

/* Description: Applies the rule for finding output on disk 1
 * Pre:  new input and previous input for applying shift
 * Post: output character */
char diskOne(const char input, const char prevInput);

/* Description: Applies the rule for finding output on disk 2
 * Pre:  new input and previous input for applying shift
 * Post: output character */
char diskTwo(const char input, const char prevInput);

/* Description: Uses a switch statement to apply the rule for finding
 *              output on disk 3
 * Pre:  new input and previous input for applying shift
 * Post: output character */
char diskThree(const char input, const char prevInput);

/* Description: Applies the rule for finding output on disk 4.
 * Pre:  new input and previous input for applying shift
 * Post: output character */
char diskFour(const char input, const char prevInput);

/* Description: Applies the rule for finding output on disk 5.
 * Pre:  now input and previous input for applying shift
 * Post: output character */
char diskFive(const char input, const char prevInput);

/* Description: Checks if an input number is a multiple of "multipleOf"
 * Pre:  Number to check if input is a multiple of, and input number
 * Post: True if input is a multiple of "multipleOf", otherwise returns false */
bool isMultiple(const int multipleOf, const int input);

/* Description: Takes left, middle, and right rotor selections, and decides if
 *              they are valid. Rotors cannot be equal or be outside the range
 *              (1,5) inclusive.
 * Pre:  Rotor selections
 * Post: True if valid, false if invalid */
bool isValidDiskSelection(const int rotorL, const int rotorM, const int rotorR);

/* Description: Finds the output for a given disk.
 * Pre:  Disk number, new input, and previous input
 * Post: Output for the disk number specified*/
char getRotorOutputForDiskNum(const int diskNum, const char input,
                              const char prevInput);

/* Description: Gets integer input from keyboard and validates
 * Pre:  prompt for the user, minimum, and maximum allowed input
 * Post: validated user input */
int getInput(const string prompt, const int minVal, const int maxVal);


#endif //HOMEWORK_HW6FUNCTS_H
