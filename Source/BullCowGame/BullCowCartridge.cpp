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
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{

    // Welcoming The Player
    PrintLine(TEXT("Welcome to the Bull Cows game"));

    HiddenWord = TEXT("tru");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Givybes: %i"), Lives);
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess. \nPress Enter to continue...")); // Prompt Player For Guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;

    PrintLine(TEXT("\nPress Enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (HiddenWord == Guess)
    {
        PrintLine(TEXT("You have won"));
        EndGame();
        return;
    }

    // Check if it is Isogram
    // if (!IsIsogram)
    // {
    //     /* code */
    //     PrintLine(TEXT("No repeating letters, guess again"));
    // }

    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
        PrintLine(TEXT("Sorry, try guessing again \nYou have %i lives remaining"), Lives);
        return;
    }
    // Prompt To Guess Again

    // Remove live
    PrintLine(TEXT("Lost a life!!!"));
    --Lives;

    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!!"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
    }

    //Show the player Bulls and Cows
    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);
}