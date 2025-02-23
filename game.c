#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ADD 1
#define MULT 2

const int ARITHMETIC_GAME_OPTION = 1;
const int TOTAL_SCORE_OPTION = 2;
const int QUIT_OPTION = 3;

int menuSystem(void);
int gameTypePrompt(void);
int numQuestionsPrompt(void);
int maxValuePrompt(void);
double arithGame(int max, int quantity, int op);
int numPoints(double timesec);

int main(void) {
    int menuOption;
    int gameType;
    int numQuestions;
    int maxValue;
    int gameScore = 0;
    int totalScore = 0;

    menuOption = menuSystem();    //opens menu system and holds user's chosen option 

    while (menuOption != QUIT_OPTION) {
        if (menuOption == ARITHMETIC_GAME_OPTION) {
            printf("\n");
            gameType = gameTypePrompt();    //prompts user for game type and holds user's chosen type
            printf("\n");    

            numQuestions = numQuestionsPrompt();    //prompts user for number of questions and holds user's chosen number

            maxValue = maxValuePrompt();       //prompts user for max operand value and holds user's chosen value
            printf("\n");

            gameScore = numPoints(arithGame(maxValue, numQuestions, gameType));        //Opens game, calculates points earned, and holds user's score
            totalScore += gameScore;

            printf("\n");
            menuOption = menuSystem();    //Reopens menu and holds user's chosen option
        }
        else if (menuOption == TOTAL_SCORE_OPTION) {
            printf("\n");
            printf("Total score: %d\n", totalScore);
            printf("Previous Game's Score: %d\n", gameScore);

            printf("\n");
            menuOption = menuSystem();
            printf("\n"); 
        }
    }
   
   return 0;
}

int menuSystem(void) {
    int userInput;
    bool isValidOption;

    printf("      --- MENU ---\n");
    printf("1) Play Arithmetic Game\n");
    printf("2) Print Score\n");
    printf("3) Quit\n");

    printf("\nEnter option number: ");

    do {
        scanf("%d", &userInput); 

        if (userInput == ARITHMETIC_GAME_OPTION || userInput == TOTAL_SCORE_OPTION || userInput == QUIT_OPTION) {
            isValidOption = true;
        }
        else {
            printf("Please enter a valid option number (1, 2, or 3): ");
            isValidOption = false;
        }
    } while (isValidOption == false);

    return userInput;
}

int gameTypePrompt(void) {
    bool isValidOption;
    int gameType;

    printf("1. Addition\n");
    printf("2. Multiplication\n");

    do {
        scanf("%d", &gameType);

        if (gameType == ADD || gameType == MULT) {
            isValidOption = true;
        }
        else {
            printf("Please enter a valid option number (1 or 2): ");
            isValidOption = false;
        }
    }
    while (isValidOption == false);

    return gameType;
}

int numQuestionsPrompt(void) {
    int numQuestions;

    printf("Enter number of questions: ");
    scanf("%d", &numQuestions);

    while (numQuestions < 1) {
        printf("Must have at least one question.\n");
        printf("Enter number of questions: ");
        scanf("%d", &numQuestions);
    }

    return numQuestions;
}

int maxValuePrompt(void) {
    int maxValue;

    printf("\nEnter max operand value: ");
    scanf("%d", &maxValue);

    while (maxValue < 1) {
        printf("Max operand value must be at least one.\n");
        printf("Enter max operand value: ");
        scanf("%d", &maxValue);
    }

    return maxValue;
}

double arithGame(int max, int quantity, int op) {
    const int MAX_VALUE = max;
    const int NUM_QUESTIONS = quantity;
    const int NUM_OPERANDS = 2;
    const int firstNum = 0;
    const int secondNum = 1;
    int operand[NUM_OPERANDS][NUM_QUESTIONS];
    int userAnswer[NUM_QUESTIONS];
    double start;
    double end;
    double timeSpent;
    double timeAvg;
    int penaltyTime = 0;
    srand(time(0));

    for (int i = 0; i < NUM_OPERANDS; ++i) {              //Initializes random operands between 1 and max value
        for (int j = 0; j < NUM_QUESTIONS; ++j) {         //each row (i) holds one operand associated w/ each column
            operand[i][j] = (rand() % MAX_VALUE) + 1;     //each column (j) is associated w/ each question
        }
    }

    if (op == ADD) {   //Runs addition version of game
        start = time(0);

        for (int i = 0; i < NUM_QUESTIONS; ++i) {         //Loops to print addition question and scan user's answer 
            printf("%d. %d + %d: ", i + 1, operand[firstNum][i], operand[secondNum][i]);
            scanf("%d", &userAnswer[i]);
        }
        
        end = time(0);
        
        for (int i = 0; i < NUM_QUESTIONS; ++i) {        //Loops to add penalty time for incorrect answers
            if (userAnswer[i] != (operand[firstNum][i] + operand[secondNum][i])) {
                penaltyTime += 10;
            }
        }
    }
    else if (op == MULT) {   //runs multiplication version of game
        start = time(0);

        for (int i = 0; i < NUM_QUESTIONS; ++i) {        //Loops to print multiplication question and scan user's answer 
            printf("%d. %d * %d: ", i + 1, operand[firstNum][i], operand[secondNum][i]);
            scanf("%d", &userAnswer[i]);
        }
        
        end = time(0);
        
        for (int i = 0; i < NUM_QUESTIONS; ++i) {        //Loops to add penalty time for incorrect answers
            if (userAnswer[i] != (operand[firstNum][i] * operand[secondNum][i])) {
                penaltyTime += 10;
            }
        }
    }


    timeSpent = (end - start) + (double)penaltyTime;
    timeAvg = (timeSpent / NUM_QUESTIONS);

    return timeAvg;
}

int numPoints(double timesec) {
    const int MAX_SCORE = 10;
    const int MAX_TIME = 10;
    int score;

    for (int i = 0; i < MAX_TIME; ++i) {            //Loops to determine score by comparing user's time between the initial threshold of
        if ((timesec >= i) && (timesec < i + 1)) {  //0 - 1 second, worth max potential score of 10 points (first loop, i = 0), then
            score = MAX_SCORE - i;                  //subsequent thresholds each loop, subtracting max potential score by i
            break;                  
        }                                           
        else if (timesec >= MAX_TIME) {  //Checks if user's time is 10 seconds or greater, which assigns 0 to score and exits loop
            score = 0;
            break;
        }
   }

   return score;
}