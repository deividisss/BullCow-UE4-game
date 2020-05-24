// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();                                             // Setting Up Game
    PrintLine(TEXT("The HiddenWords is: %s."), *HiddenWord); // Debug Line

    // Welcoming The Player
    PrintLine(TEXT("Welcome to the Bull Cows game"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess and press Enter to continue..."));

    // Set Lives

    // Prompt Player For Guess
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();

    /*   if game is over do ClearScrenn() and SetupGame() the game
    else Checking PlayerGuess */

    if (HiddenWord == Input)
    {
        PrintLine(TEXT("You win"));
        // bGameOver = true;
    }
    else
    {
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The hidden Words is %i characters long, try again!"), HiddenWord.Len()); //Magic number
        }

        PrintLine(TEXT("You loose"));
        // bGameOver = true;
    }
    // Check if it is Isogram
    // Prompt To Guess Again
    // Check Number Of Characters
    // Prompt To Guess Again

    // Remove live

    // Check if lives > 0
    // If Yes GuessyAgain
    // Show Lives Left
    // If No Show GameOver and HiddenWord?
    // Prompt To Play Again, Press Enter To Play Again
    // Ckeck User Input
    // Play Againg or Quit
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("tru");
    Lives = 5;
    PrintLine(TEXT("Givybes: %i"), Lives);
    // bGameOver = true;
    // PrintLine(TEXT("Givybes: %i"), *Lives);
}