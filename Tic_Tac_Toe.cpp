#include <ctime>
#include <ctype.h>
#include <iostream>

void selectFormat(); // To select Single / Multi - Player fromat

void resetBoard(char *space); // For New Board
void printBoard(char *space); // Prints  the Board

bool checkWinner_Single(
    char *space, const char PLAYER,
    const char COMPUTER); // Checks winner in Single PLayer Format
bool checkWinner_Multi(
    char *space, const char PLAYER1,
    const char PLAYER2);              // Checks winner in Multi Player Format
bool checkTie(char *space);           // Checks Tie in both formats
bool check_invalid_input(int number); /*Check for input of invalid type
                                      (Program won't break if receives
                                      entry of invalid data type :) )*/
void playerMove(char *space,
                const char PLAYER); // Player Move in Single Player Format
void computerMove(char *space,
                  const char COMPUTER); // Computer Move in Single Player Format

void player1_Move(char *space,
                  const char PLAYER1); // Player1 Move in Multi Player Format
void player2_Move(char *space,
                  const char PLAYER2); // Player2 Move in Multi Player Format

void Single_Player(char format); // Single Player game-flow
void Multi_Player(char format);  // Multi Player game-flow

int main() {
  char response;

  do {

    response = ' ';
    system("clear");
    std::cout << "\n\t\t********* TIC TAC TOE *********\n\n";
    selectFormat();

    // Rematch ... ?
    std::cout << "\nWould you like to play again ? ";
    std::cout << "\n [Y] / [N] : ";

    while (response != 'Y' && response != 'N') {
      std::cin >> response;
      response = toupper(response);

      if (response == 'N') {

        break;
      } else {

        std::cout << "Invalid Input\n";
        std::cout << "Try Again : ";
        std::cin.clear();
        std::cin.ignore();
      }
    }

  } while (response == 'Y' && response != 'N');

  std::cout << "\nThanks for playing;";
  std::cout << "\nBYE!\n;)\n";

  return 0;
}

// For Defintions / uses of following functions refer to funtion declaration :)
void selectFormat() {

  char format;

  std::cout << "Select Format \n[S] -  Single Player / [M] - Multi Player : ";

  while (format != 'S' && format != 'M') {

    std::cin >> format;
    format = toupper(format);

    if (format == 'S') {

      Single_Player(format);
      break;
    } else if (format == 'M') {

      Multi_Player(format);
      break;
    } else {

      std::cout << "Invalid Input!\n";
      std::cout << "Try Again : ";
      std::cin.clear();
      std::cin.ignore();
    }
  }
}

void resetBoard(char *space) {
  for (int i = 0; i < 9; i++) {
    space[i] = ' ';
  }
}
void printBoard(char *space) {
  std::cout << '\n';
  std::cout << "     |     |     " << '\n';
  std::cout << "  " << space[0] << "  |  " << space[1] << "  |  " << space[2]
            << "  " << '\n';
  std::cout << "_____|_____|_____" << '\n';
  std::cout << "     |     |     " << '\n';
  std::cout << "  " << space[3] << "  |  " << space[4] << "  |  " << space[5]
            << "  " << '\n';
  std::cout << "_____|_____|_____" << '\n';
  std::cout << "     |     |     " << '\n';
  std::cout << "  " << space[6] << "  |  " << space[7] << "  |  " << space[8]
            << "  " << '\n';
  std::cout << '\n';
}

void playerMove(char *space, const char PLAYER) {
  int number;

  do {
    std::cout << "Enter a number to place marker: ";
    std::cin >> number;
    number--;

    if (space[number] == ' ') {
      space[number] = PLAYER;
      break;
    } else if ((space[number] != ' ') || (!check_invalid_input(number))) {
      std::cout << "Invalid Input!\n";
      std::cin.clear();
      while (getchar() != '\n')
        ;
    }

  } while ((!number > 0 || !number < 8));
}
void computerMove(char *space, const char COMPUTER) {
  int number;
  srand(time(0));

  while (true) {
    number = rand() % 9;
    if (space[number] == ' ') {
      space[number] = COMPUTER;
      break;
    }
  }
}

bool checkWinner_Single(char *space, const char PLAYER, const char COMPUTER) {
  if ((space[0] != ' ') && (space[0] == space[1]) && (space[1] == space[2])) {
    space[0] == PLAYER ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  } else if ((space[3] != ' ') && (space[3] == space[4]) &&
             (space[4] == space[5])) {
    space[3] == PLAYER ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  } else if ((space[6] != ' ') && (space[6] == space[7]) &&
             (space[7] == space[8])) {
    space[6] == PLAYER ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  } else if ((space[0] != ' ') && (space[0] == space[3]) &&
             (space[3] == space[6])) {
    space[0] == PLAYER ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  } else if ((space[1] != ' ') && (space[1] == space[4]) &&
             (space[4] == space[7])) {
    space[1] == PLAYER ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  } else if ((space[2] != ' ') && (space[2] == space[5]) &&
             (space[5] == space[8])) {
    space[2] == PLAYER ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
  } else if ((space[0] != ' ') && (space[0] == space[4]) &&
             (space[4] == space[8])) {
    space[0] == PLAYER ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE\n";
  } else if ((space[2] != ' ') && (space[2] == space[4]) &&
             (space[4] == space[6])) {
    space[2] == PLAYER ? std::cout << "YOU WIN!!\n" : std::cout << "YOU LOSE\n";
  } else {
    return false;
  }
  return true;
}
bool checkTie(char *space) {
  for (int i = 0; i < 9; i++) {
    if (space[i] == ' ') {
      return false;
    }
  }
  std::cout << "IT'S A TIE!";
  return true;
}
bool checkWinner_Multi(char *space, const char PLAYER1, const char PLAYER2) {
  if ((space[0] != ' ') && (space[0] == space[1]) && (space[1] == space[2])) {
    space[0] == PLAYER1 ? std::cout << "PLAYER 1 (" << PLAYER1 << ") WINS !\n"
                        : std::cout << "PLAYER 2 (" << PLAYER2 << ") WINS !\n";
  } else if ((space[3] != ' ') && (space[3] == space[4]) &&
             (space[4] == space[5])) {
    space[3] == PLAYER1 ? std::cout << "PLAYER 1 (" << PLAYER1 << ") WINS !\n"
                        : std::cout << "PLAYER 2 (" << PLAYER2 << ") WINS !\n";
  } else if ((space[6] != ' ') && (space[6] == space[7]) &&
             (space[7] == space[8])) {
    space[6] == PLAYER1 ? std::cout << "PLAYER 1 (" << PLAYER1 << ") WINS !\n"
                        : std::cout << "PLAYER 2 (" << PLAYER2 << ") WINS !\n";
  } else if ((space[0] != ' ') && (space[0] == space[3]) &&
             (space[3] == space[6])) {
    space[0] == PLAYER1 ? std::cout << "PLAYER 1 (" << PLAYER1 << ") WINS !\n"
                        : std::cout << "PLAYER 2 (" << PLAYER2 << ") WINS !\n";
  } else if ((space[1] != ' ') && (space[1] == space[4]) &&
             (space[4] == space[7])) {
    space[1] == PLAYER1 ? std::cout << "PLAYER 1 (" << PLAYER1 << ") WINS !\n"
                        : std::cout << "PLAYER 2 (" << PLAYER2 << ") WINS !\n";
  } else if ((space[2] != ' ') && (space[2] == space[5]) &&
             (space[5] == space[8])) {
    space[2] == PLAYER1 ? std::cout << "PLAYER 1 (" << PLAYER1 << ") WINS !\n"
                        : std::cout << "PLAYER 2 (" << PLAYER2 << ") WINS !\n";
  } else if ((space[0] != ' ') && (space[0] == space[4]) &&
             (space[4] == space[8])) {
    space[0] == PLAYER1 ? std::cout << "PLAYER 1 (" << PLAYER1 << ") WINS !\n"
                        : std::cout << "PLAYER 2 (" << PLAYER2 << ") WINS !\n";
  } else if ((space[2] != ' ') && (space[2] == space[4]) &&
             (space[4] == space[6])) {
    space[2] == PLAYER1 ? std::cout << "PLAYER 1 (" << PLAYER1 << ") WINS !\n"
                        : std::cout << "PLAYER 2 (" << PLAYER2 << ") WINS !\n";
  } else {
    return false;
  }
  return true;
}

bool check_invalid_input(int number) {
  if (!(std::cin >> number)) {
    return true;
  }

  return false;
}

void player1_Move(char *space, const char PLAYER1) {
  int number;

  do {
    std::cout << "PLAYER 1 : ";
    std::cin >> number;
    number--;

    if (space[number] == ' ') {
      space[number] = PLAYER1;
      break;
    } else if ((space[number] != ' ') || (!check_invalid_input(number))) {
      std::cout << "Invalid Input!\n";
      std::cin.clear();
      while (getchar() != '\n')
        ;
    }
  } while (!(number > 0) || !(number < 8)  || space[number] != ' ');
}
void player2_Move(char *space, const char PLAYER2) {
  int number;

  do {
    std::cout << "PLAYER 2 : ";
    std::cin >> number;
    number--;

    if (space[number] == ' ') {
      space[number] = PLAYER2;
      break;
    } else if ((space[number] != ' ') || (!check_invalid_input(number))) {
      std::cout << "Invalid Input!\n";
      std::cin.clear();
      while (getchar() != '\n')
        ;
    }

  } while (!(number > 0) || !(number < 8) || space[number] != ' ');
}

void Single_Player(char format) {
  char space[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  const char PLAYER = 'X';
  const char COMPUTER = 'O';
  bool running = true;

  system("clear");
  std::cout << "\n\t\t********* TIC TAC TOE *********\n\n";
  resetBoard(space);
  printBoard(space);

  running = true;

  while (running) {
    playerMove(space, PLAYER);
    system("clear");
    std::cout << "\n\t\t********* TIC TAC TOE *********\n\n";
    printBoard(space);
    if (checkWinner_Single(space, PLAYER, COMPUTER)) {
      running = false;
      break;
    } else if (checkTie(space)) {
      running = false;
      break;
    }

    computerMove(space, COMPUTER);
    system("clear");
    std::cout << "\n\t\t********* TIC TAC TOE *********\n\n";
    printBoard(space);
    if (checkWinner_Single(space, PLAYER, COMPUTER)) {
      running = false;
      break;
    } else if (checkTie(space)) {
      running = false;
      break;
    }
  }
}
void Multi_Player(char format) {
  char space[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  char PLAYER1;
  char PLAYER2;
  bool running = true;

  system("clear");
  std::cout << "\n\t\t********* TIC TAC TOE *********\n\n";
  std::cout << "\nEnter a character for PLAYER 1 : ";
  std::cin >> PLAYER1;
  PLAYER1 = toupper(PLAYER1);
  std::cout << "\nEnter a character for PLAYER 2 : ";
  std::cin >> PLAYER2;
  PLAYER2 = toupper(PLAYER2);

  while (PLAYER2 == PLAYER1) {
    std::cout << "\nThat character is taken... ";
    std::cout << "\nSelect a different character : ";
    while (getchar() != '\n')
      ; // Clearing stream buffer
    std::cin >> PLAYER2;
  }

  system("clear");
  std::cout << "\n\t\t********* TIC TAC TOE *********\n\n";
  std::cout << "Enter a number to place the marker\n\n";

  resetBoard(space);
  printBoard(space);

  running = true;

  while (running) {
    player1_Move(space, PLAYER1);
    system("clear");
    std::cout << "\n\t\t********* TIC TAC TOE *********\n\n";
    std::cout << "Enter a number to place the marker\n\n";

    printBoard(space);
    if (checkWinner_Multi(space, PLAYER1, PLAYER2)) {
      running = false;
      break;
    } else if (checkTie(space)) {
      running = false;
      break;
    }

    player2_Move(space, PLAYER2);
    system("clear");
    std::cout << "\n\t\t********* TIC TAC TOE *********\n\n";
    std::cout << "Enter a number to place the marker\n\n";

    printBoard(space);
    if (checkWinner_Multi(space, PLAYER1, PLAYER2)) {
      running = false;
      break;
    } else if (checkTie(space)) {
      running = false;
      break;
    }
  }
}