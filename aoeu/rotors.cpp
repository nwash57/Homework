#include "rotors.h"

char rotor1(char encryptedChar)
{
   const short NUM_LETTERS = 26;           // # letters in
                                           //  alphabet
   const short ASCII_A = 65;               // ASCII value of 'A'   
   
   encryptedChar =                                        //Make a function for each part and put it all under the for loop so it goes through each once. 
             static_cast<int>
             (((encryptedChar + 3) % NUM_LETTERS) + 
             ASCII_A);
  return encryptedChar;
}

char rotor2(char encryptedChar)
{
    const short NUM_LETTERS = 26;           // # letters in
                                          //  alphabet
    const short ASCII_A = 65;               // ASCII value of 'A'
  encryptedChar = 
            static_cast<int>
            (((encryptedChar + 17) % NUM_LETTERS) + 
            ASCII_A);
  
  return encryptedChar;
}

char rotor3(char encryptedChar)
{
  switch (encryptedChar)
    {
     case 'A' : encryptedChar = 'H'; break;
     case 'B' : encryptedChar = 'U'; break;
     case 'C' : encryptedChar = 'I'; break;
     case 'D' : encryptedChar = 'P'; break;
     case 'E' : encryptedChar = 'N'; break;
     case 'F' : encryptedChar = 'W'; break;
     case 'G' : encryptedChar = 'C'; break;
     case 'H' : encryptedChar = 'K'; break;
     case 'I' : encryptedChar = 'E'; break;
     case 'J' : encryptedChar = 'X'; break;
     case 'K' : encryptedChar = 'Q'; break;
     case 'L' : encryptedChar = 'Z'; break;
     case 'M' : encryptedChar = 'O'; break;
     case 'N' : encryptedChar = 'V'; break;
     case 'O' : encryptedChar = 'S'; break;
     case 'P' : encryptedChar = 'B'; break;
     case 'Q' : encryptedChar = 'L'; break;
     case 'R' : encryptedChar = 'J'; break;
     case 'S' : encryptedChar = 'D'; break;
     case 'T' : encryptedChar = 'Y'; break;
     case 'U' : encryptedChar = 'F'; break;
     case 'V' : encryptedChar = 'R'; break;
     case 'W' : encryptedChar = 'A'; break;
     case 'X' : encryptedChar = 'G'; break;
     case 'Y' : encryptedChar = 'T'; break;
     case 'Z' : encryptedChar = 'M'; break;
    }
    
  return encryptedChar;  
}

char rotor4(char encryptedChar)
{
    switch (encryptedChar)
    {
     case 'A' : encryptedChar = 'B'; break;
     case 'B' : encryptedChar = 'A'; break;
     case 'C' : encryptedChar = 'D'; break;
     case 'D' : encryptedChar = 'C'; break;
     case 'E' : encryptedChar = 'F'; break;
     case 'F' : encryptedChar = 'E'; break;
     case 'G' : encryptedChar = 'H'; break;
     case 'H' : encryptedChar = 'G'; break;
     case 'I' : encryptedChar = 'J'; break;
     case 'J' : encryptedChar = 'I'; break;
     case 'K' : encryptedChar = 'L'; break;
     case 'L' : encryptedChar = 'K'; break;
     case 'M' : encryptedChar = 'N'; break;
     case 'N' : encryptedChar = 'M'; break;
     case 'O' : encryptedChar = 'P'; break;
     case 'P' : encryptedChar = 'O'; break;
     case 'Q' : encryptedChar = 'R'; break;
     case 'R' : encryptedChar = 'Q'; break;
     case 'S' : encryptedChar = 'T'; break;
     case 'T' : encryptedChar = 'S'; break;
     case 'U' : encryptedChar = 'V'; break;
     case 'V' : encryptedChar = 'U'; break;
     case 'W' : encryptedChar = 'X'; break;
     case 'X' : encryptedChar = 'W'; break;
     case 'Y' : encryptedChar = 'Z'; break;
     case 'Z' : encryptedChar = 'Y'; break;
    }
  
  return encryptedChar;
}

char rotor5(char encryptedChar)
{
    switch (encryptedChar)
    {
     case 'A' : encryptedChar = 'A'; break;
     case 'B' : encryptedChar = 'E'; break;
     case 'C' : encryptedChar = 'D'; break;
     case 'D' : encryptedChar = 'C'; break;
     case 'E' : encryptedChar = 'H'; break;
     case 'F' : encryptedChar = 'G'; break;
     case 'G' : encryptedChar = 'F'; break;
     case 'H' : encryptedChar = 'K'; break;
     case 'I' : encryptedChar = 'J'; break;
     case 'J' : encryptedChar = 'I'; break;
     case 'K' : encryptedChar = 'N'; break;
     case 'L' : encryptedChar = 'M'; break;
     case 'M' : encryptedChar = 'L'; break;
     case 'N' : encryptedChar = 'Q'; break;
     case 'O' : encryptedChar = 'P'; break;
     case 'P' : encryptedChar = 'O'; break;
     case 'Q' : encryptedChar = 'T'; break;
     case 'R' : encryptedChar = 'S'; break;
     case 'S' : encryptedChar = 'R'; break;
     case 'T' : encryptedChar = 'W'; break;
     case 'U' : encryptedChar = 'V'; break;
     case 'V' : encryptedChar = 'U'; break;
     case 'W' : encryptedChar = 'Z'; break;
     case 'X' : encryptedChar = 'Y'; break;
     case 'Y' : encryptedChar = 'X'; break;
     case 'Z' : encryptedChar = 'B'; break;
    }
    
  return encryptedChar;
}