// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    // Welcoming The Player
    PrintLine(TEXT("Welcome to the Bull Cows game"));
    PrintLine(TEXT("Guess the 4 letter word!")); // Magic Number Remove!!
    PrintLine(TEXT("Enter something and press Enter..."));

    SetupGame(); // Setting Up Game

    // Set Lives

    // Prompt Player For Guess
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();

    // PrintLine(HiddenWord);

    // Checking Player Guesss
    // PrintLine(Input);
    if (HiddenWord == Input)
    {
        PrintLine(TEXT("You win"));
    }
    else
    {
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The hidden char is 5 symbol long")); //Magic number
        }

        PrintLine(TEXT("You loose"));
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
    HiddenWord = TEXT("table");
    Lives = 5;
}