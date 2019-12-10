#include <iostream>
#include <ctime>

//void means the function will return no data 
void PrintIntroduction(int Difficulty)
{
   /*
   Printing out the intro message 
   By using \n we can escape the sequence and we no longer need std::endl
   */ 
  std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty; 
  std::cout << " secure server room" << std::endl; 
  std::cout << "Enter the correct code to continue...\n"; 
}

bool PlayGame(int Difficulty)
{
  PrintIntroduction(Difficulty); 

  // declaring three number code 
  const int CodeA = rand() % Difficulty + Difficulty;
  const int CodeB = rand() % Difficulty + Difficulty;
  const int CodeC = rand() % Difficulty + Difficulty;  

  const int CodeSum = CodeA + CodeB + CodeC; 
  const int CodeProduct = CodeA * CodeB * CodeC; 

  //Print sum and product to terminal 
  std::cout << std::endl; 
  std::cout << "+ Three numbers sum up to: " << CodeSum << std::endl; 
  std::cout << "+ And their product equal to: " << CodeProduct << std::endl << std::endl; 

  int GuessA, GuessB, GuessC; 
  std::cout << "+ What are these three numbers?\n"; 
  std::cin >> GuessA >> GuessB >> GuessC; 
  std::cout << "You've guessed: " << GuessA << GuessB << GuessC << std::endl; 

  int GuessSum = GuessA + GuessB + GuessC; 
  int GuessProduct = GuessA * GuessB * GuessC; 

  if (GuessSum == CodeSum && GuessProduct == CodeProduct) 
  {
    std::cout << "\n*** Great Job Agent. You are closer to completing your mission...\n\n"; 
    return true;
  }
  else
  { 
    std::cout << "\n*** Agent, you have been detected. Hurry and try again...\n\n"; 
    return false; 
  }
}

int main()
{
  srand(time(NULL)); // creates a new random sequence based on time of day

  int LevelDifficulty = 1; 
  const int MaxDifficulty = 5; 

  while (LevelDifficulty <= MaxDifficulty)
  { 
    /* Whatever our PlayGame() returns (either true or false), we store it in our bool variable 
    This is to see if we need to increase the game difficulty*/
    bool bLevelComplete = PlayGame(LevelDifficulty); 

    //Two lines below fix our code from entering an endless loop
    std::cin.clear(); //Clears any errors 
    std::cin.ignore(); //Discards the buffer 

    if (bLevelComplete)
    {
      LevelDifficulty++; 
    }
  }
  std::cout << "You have completed your mission. Well done. Let's get you back home!\n\n"; 
  return 0; 
}