// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();                                            // Setting Up Game
    PrintLine(TEXT("The HiddenWords is: %s"), *HiddenWord); // Debug Line
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{

    /*   if game is over do ClearScrenn() and SetupGame() the game
    else Checking PlayerGuess */

    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        if (HiddenWord == Input)
        {
            PrintLine(TEXT("You win"));
            EndGame();
        }
        else
        {
            if (Input.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The hidden Words is %i characters long. \nYou have lost!"), HiddenWord.Len()); //Magic number
                EndGame();
            }
        }
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

    // Welcoming The Player
    PrintLine(TEXT("Welcome to the Bull Cows game"));

    HiddenWord = TEXT("tru");
    Lives = 5;
    bGameOver = false;

    PrintLine(TEXT("Givybes: %i"), Lives);
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess. \nPress Enter to continue...")); // Prompt Player For Guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press Enter to play again."));
}