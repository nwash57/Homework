/* Programmer: David Pruitt     Date: October 16, 2015

   File: hw4.cpp

   Purpose: Simulate processing of a message through a 
            simplified Enigma machine containing 3 "inter-
            changeable" rotors. 

   To compile: fg++ hw4.cpp -o hw4

   To execute: ./hw4
*/


#include "rotors.h"


//This outputs a greeting to the user
//none
//says hello
void greeting();

//This outputs a sign off message to the user
//none
//says goodbye
void signOff();



//This will apply the shift to change the variables
//Needs the current and previous characters
//This will output a shifted charater
char applyShift(char encryptedChar, char prev_input, bool run);

int main()
{

  const char END_OF_MESSAGE_CHAR = '.';   // signals end of msg
  const char WORD_DELIMITER = '_';        // delimits 2 words in
                                          //  msg
  const short ROTOR_NUM_START = 1;        // range of valid rotor 
  const short ROTOR_NUM_END = 5;          //  numbers
  short firstRotor, secondRotor,          // order that rotors
        thirdRotor;                       //  should be applied
        
  char encryptedChar;                     // encrypted char
                                          //  (user input)

  bool invalidInput;                      // used when validating
                                          //  user input
  short whichRotor;                       // rotor currently
                                          //  being processed
  char prev_input;                        //This will keep the previous input per variable
  char prev_input1;                        //This will keep the previous variable
  char prev_input2;                        //This will keep the previous variable
  char prev_input3;                        //This will keep the previous variable
  char prev_input4;                        //This will keep the previous variable
  char prev_input5;                        //This will keep the previous variable
  bool run;                           //Used for check with applyShift

  // Greeting
  run = 0;
  prev_input1 = 65;
  prev_input2 = 65;
  prev_input3 = 65;
  prev_input4 = 65;
  prev_input5 = 65;
  greeting();
   do
  {
    cout << "Enter first rotor number: ";
    cin >> firstRotor;
    invalidInput = (firstRotor < ROTOR_NUM_START) ||      
                   (firstRotor > ROTOR_NUM_END);
    if (invalidInput)
      cout << "Leftmost rotor must be between "
           << ROTOR_NUM_START << " and "
           << ROTOR_NUM_END << " (inclusive)!\n";
  } while (invalidInput);

  do
  {
    cout << "\nEnter second rotor number: ";
    cin >> secondRotor;
    invalidInput = (secondRotor < ROTOR_NUM_START) || 
                   (secondRotor > ROTOR_NUM_END) ||
                   (secondRotor == firstRotor);
    if (invalidInput)                                             
      cout << "Second rotor must be between "
           << ROTOR_NUM_START << " and "
           << ROTOR_NUM_END << " (inclusive),\n"
           << "and not the same as the first rotor "
           << "(which is " << firstRotor << ")!\n";
  } while (invalidInput);

  do
  {
    cout << "\nEnter third rotor number: ";
    cin >> thirdRotor;
    invalidInput = (thirdRotor < ROTOR_NUM_START) || 
                   (thirdRotor > ROTOR_NUM_END) ||
                   (thirdRotor == firstRotor) ||
                   (thirdRotor == secondRotor);                
    if (invalidInput)
      cout << "Third rotor must be between "
           << ROTOR_NUM_START << " and "
           << ROTOR_NUM_END << " (inclusive),\n"
           << "and not the same as the first rotor "
           << "(which is " << firstRotor << ") "
           << "\nor the second rotor (which is "
           << secondRotor << ")!\n";
  } while (invalidInput);

  cout << endl;

   
  // Get each char in message (until END_OF_MESSAGE_CHAR input)
  // and output the decrypted char

  do
  { do
    {
      cout << "Enter character ('A'..'Z', '_', or '.'): ";
      cin >> encryptedChar;
      invalidInput = ((encryptedChar < 'A') ||
                      (encryptedChar > 'Z')) &&
                     ((encryptedChar != '.') &&
                      (encryptedChar != '_'));
      if (invalidInput)
        cout << "Invalid character entered!\n";
    } while (invalidInput);
    if (encryptedChar != END_OF_MESSAGE_CHAR)
    {
      if (encryptedChar != WORD_DELIMITER)
      {
        cout << "\n\033[F" << encryptedChar << " -> ";

        // Process the char through each of the 3 rotors
        for (int rotorNum = 1; rotorNum <= 3; rotorNum++)
        {
          // Figure out which rotor we're working on
          switch (rotorNum)
          {
           case 1 : whichRotor = firstRotor; break;
           case 2 : whichRotor = secondRotor; break;
           case 3 : whichRotor = thirdRotor; break;
          }
          
          // Do the processing for that rotor
          switch (whichRotor)
          {
           case 1 : prev_input = prev_input1;
                    encryptedChar = applyShift(encryptedChar, prev_input, run); 
                    prev_input1 = encryptedChar;
                    encryptedChar = rotor1(encryptedChar); break;
                    
           case 2 : prev_input = prev_input2;
                    encryptedChar = applyShift(encryptedChar, prev_input, run);
                    prev_input2 = encryptedChar;
                    encryptedChar = rotor2(encryptedChar); break;

           case 3 : prev_input = prev_input3;
              prev_input3 = encryptedChar;
                    encryptedChar = applyShift(encryptedChar, prev_input, run);

                    cout << "Prev" << prev_input3 << endl;
                    encryptedChar = rotor3(encryptedChar); break; 
                    
           case 4 : prev_input = prev_input4;
                    prev_input4 = encryptedChar;
                    encryptedChar = applyShift(encryptedChar, prev_input, run);

                    cout << "Prev" << prev_input4 << endl;
                    encryptedChar = rotor4(encryptedChar); break;
                    
           case 5 : prev_input = prev_input5;
              prev_input5 = encryptedChar;
                    encryptedChar = applyShift(encryptedChar, prev_input, run);

                    cout << "Prev" << prev_input5 << endl;
                    encryptedChar = rotor5(encryptedChar); break;  

          } // end-switch
          
          run = 1;
        } // end-for
        cout << encryptedChar << endl;  // Now decrypted
      }
      else cout << WORD_DELIMITER << endl;  
    }
  } while (encryptedChar != END_OF_MESSAGE_CHAR);
  // Sign-off
  signOff();

  return 0;
}

void greeting()
{
  cout << "Ready to decrypt message...\n\n";
  return;
}

void signOff()
{
    cout << "\nReached end of message...\n"
       << "Decryption completed.\n";
    return;
}



char applyShift (char encryptedChar, char prev_input, bool run)
{
  const short ASCII_A = 65;               // ASCII value of 'A'
  const short NUM_LETTERS = 26;           // # letters in
                                          //  alphabet

  if (run == 1)
  {                            
    encryptedChar = static_cast<int>(((encryptedChar - ASCII_A)+
                             (prev_input - ASCII_A)) % 
                              NUM_LETTERS) + ASCII_A;
  }
  return encryptedChar;
}