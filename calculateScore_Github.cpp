// Bowling Game
// Please implement a program calculating the score of a single player in Bowling.

// Game Rules
// • A bowling game consists of 10 frames.
// • Each frame, the player has two tries to knock down 10 pins with a bowling ball.
// • The score for the frame is the total of knocked down pins, plus bonuses for strikes and spared.

// • A Spare is when a player knocks down all 10 pins in two tries.
    // o The bonus for this frame is the number of pins knocked down by the next roll.

// • A Strike is when the player knocks down all 10 pins on his first try.
    // o The bonus for this frame is the number of pins knocked down by the next two rolls.

// • In the 10th frame, a player is allowed to throw an extra ball if she/he scores a Spare or a Strike.
    // o No more than three throws are allowed for the 10th frame.
    // o No bonus scores are granted for Strikes and Spares in 10th frame.
    // o If a player hits a Strike / Spare, 10 pins will be available again for the next throw within the 10th frame.

// write an interactive code asking user to input the number of pins knocked down for each roll
// and print out the total score for the game.

// write c++ code below considering above requirements for frames, strikes, spares, and 10th frame.


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

// write class for bowling game
class BowlingGame {
    public:
        std::vector<int>& rolls;
        int currentRoll;
    public:
        BowlingGame() : rolls(*(new std::vector<int>)), currentRoll(0) {
            rolls.reserve(21);
        }

        void roll(int pins) {
            rolls.push_back(pins);
        }
        int score() {
            int score = 0;
            int frameIndex = 0;
            for (int frame = 0; frame < 10; frame++) {
                if (isStrike(frameIndex)) {
                    score += 10 + strikeBonus(frameIndex);
                    frameIndex++;
                } else if (isSpare(frameIndex)) {
                    score += 10 + spareBonus(frameIndex);
                    frameIndex += 2;
                } else {
                    score += sumOfBallsInFrame(frameIndex);
                    frameIndex += 2;
                }
            }
            return score;
        }
        bool isStrike(int frameIndex) {
            return rolls[frameIndex] == 10;
        }
        int sumOfBallsInFrame(int frameIndex) {
            return rolls[frameIndex] + rolls[frameIndex + 1];
        }
        int spareBonus(int frameIndex) {
            return rolls[frameIndex + 2];
        }
        int strikeBonus(int frameIndex) {
            return rolls[frameIndex + 1] + rolls[frameIndex + 2];
        }
        bool isSpare(int frameIndex) {
            return rolls[frameIndex] + rolls[frameIndex + 1] == 10;
        }
};