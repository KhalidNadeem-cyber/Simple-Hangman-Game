#include <iostream>
#include <cstring>
using namespace std;

void drawHangman(int attemptsLeft) {
    if (attemptsLeft == 5) {
        cout << "   ___" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
    }
    if (attemptsLeft == 4) {
        cout << "   ___" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |     |" << endl;
    }
    if (attemptsLeft == 3) {
        cout << "   ___" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |    /|" << endl;
    }
    if (attemptsLeft == 2) {
        cout << "   ___" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |    /|\\" << endl;
    }
    if (attemptsLeft == 1) {
        cout << "   ___" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |    /|\\" << endl;
        cout << "  |    /" << endl;
    }
    if (attemptsLeft == 0) {
        cout << "   ___" << endl;
        cout << "  |     |" << endl;
        cout << "  |     O" << endl;
        cout << "  |    /|\\" << endl;
        cout << "  |    / \\" << endl;
    }
    cout << endl;
}
//This function shows the current state of our guessed word
void Worddisplay(const char* secretword, const bool guessedLetters[]) {
    for (int i = 0; secretword[i] != '\0'; ++i) {
        if (guessedLetters[i]) {
            cout << secretword[i];
        }
        else {
            cout << "_";
        }
        cout << " ";
    }
    cout << endl;
}
//This function checks if all letters in the a word have been guessed correctly or not
bool isWordGuessed(const bool guessedLetters[], int wordLength) {
    for (int i = 0; i < wordLength; ++i) {
        if (!guessedLetters[i]) {
            return false;
        }
    }
    return true;
}
//providing the main hangman game logic
bool playHangman(const char* secretWord) {
    int wordLength = strlen(secretWord);

    bool guessedLetters[50] = { false }; // To track guessed letters
    int attemptsLeft = 6;             // Number of incorrect guesses allowed
    char guessedcharacter;
    bool correctGuess;

    cout << "Try to guess the word one letter at a time." << endl;
    cout << "You have " << attemptsLeft << " incorrect guesses allowed.\n" << endl;
    //main game loop
    while (attemptsLeft > 0) {
        cout << "Word: ";
        Worddisplay(secretWord, guessedLetters);

        cout << "Enter a letter: ";
        cin >> guessedcharacter;

        // Check if the guessed character is in the word
        correctGuess = false;
        for (int i = 0; i < wordLength; ++i) {
            if (secretWord[i] == guessedcharacter) {
                guessedLetters[i] = true;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            attemptsLeft--;
            cout << "Incorrect guess. You have " << attemptsLeft << " attempts left." << endl;
            drawHangman(attemptsLeft);
        }
        else {
            cout << "Correct guess!" << endl;
        }

        if (isWordGuessed(guessedLetters, wordLength)) {
            cout << "\nCongratulations! You've guessed the word: " << secretWord << endl;
            return true;
        }
    }

    drawHangman(0);
    cout << "\nGame over! The word was: " << secretWord << endl;
    return false;
}

int main() {
    cout << "Welcome to Hangman!" << endl;
    cout << "Level 1: The secret word has been set. Good luck!" << endl;

    // Level 1: Secret word is "elephant"
    if (playHangman("elephant")) {
        cout << "\nGreat job! You have completed Level 1. Proceeding to Level 2\n" << endl;

        // Level 2: Secret word is "flamingo"
        cout << "Level 2: The secret word has been set. Good luck!" << endl;
        if (playHangman("flamingo")) {
            cout << "\nCongradulations! You have completed all levels.\n" << endl;
        }
        else {
            cout << "Better luck next time on Level 2!" << endl;
        }
    }
    else {
        cout << "Better luck next time on Level 1!" << endl;
    }

    cout << "Thank you for playing Hangman. Goodbye!" << endl;
    return 0;
}

