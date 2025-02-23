# Project: An Arithmetic Game Program

## Context

_Text below is the instructions for the Arithmetic Game assignment of my Fall 2024 C Programming course. Code within repository was my submission for this assignment. Uploaded to Github for archival and future reference purposes._

## Learning Outcome

Apply user-defined functions to solve arithmetic problems.

## Description

Imagine you are tasked with creating a fun and educational computer program to assist children in improving their arithmetic skills and logical thinking. This program will serve as a valuable tool for parents and educators alike, offering engaging activities to reinforce mathematical concepts in an interactive way.

### Menu

    Play Arithmetic Game

    Print Score

    Quit

If they choose option 1, then you should prompt them with the following menu choices:

    1) Addition

    2) Multiplication

For option 2, simply report their total score, which is the sum of their scores from each round they play.

### Arithmetic Game

In the arithmetic game, players are presented with a selection of addition or multiplication tasks. They must solve a predetermined number of problems within a given time limit, striving for accuracy and efficiency. Incorrect answers incur a penalty, adding an extra challenge to the gameplay experience.

### Scoring Details

For the arithmetic game, the score the children earns is equal to the total amount of time (in seconds) it took him to finish the problems (including penalty seconds) divided by the number of problems he solved.

The score in seconds then must be converted to an integer number of points in between 0 and 10. In particular, the conversion works as shown in the chart below:

    Time, t, (in seconds)     Corresponding Score

           t < 1                     10

       1 ≤ t < 2                      9

       2 ≤ t < 3                      8

       3 ≤ t < 4                      7

       4 ≤ t < 5                      6

       5 ≤ t < 6                      5

       6 ≤ t < 7                      4

       7 ≤ t < 8                      3

       8 ≤ t < 9                      2

      9 ≤ t < 10                      1

          t ≥ 10                      0

 

### Implementation Details

You will be required to write 3 functions with the prototypes given below. (Note: you may write other functions as well, but these three are required.) Your functions should do what the comments for them below specify:


**double arithGame(int max, int quantity, int op);**

    This function prompts the user with a specified quantity of arithmetic questions,
      where each operand ranges from 1 to max, inclusive.
      
    The operator value determines whether the questions are addition or multiplication problems
      (1 for addition, otherwise multiplication).
      
    The function calculates the time taken by the user to complete the game and
      divides it by the number of problems solved to return the average time per problem.


**int menuSystem( );**

    Displaying the menu options for users.


**int numPoints(double timesec);**

    This function determines the user's score based on the time taken, with scores ranging from 10 for times less than 1,
      decreasing by one point for each additional second, and reaching 0 for times greater than or equal to 10.

### Other Useful Information

Seed the random number generator at the beginning of your program. Do this exactly once. Here is the line of code:

    srand(time(0));

In order to use this you need to include stdlib.h and time.h at the top of the program.


Please use the following constants for ADD and MULT:

    #define ADD 1

    #define MULT 2

In order to calculate how much time something takes, you can use the time function. In particular, the function call time(0) returns a double that represents the number of seconds after some time. In order to effectively use this, you must call the function twice: once right before you start what you want to time, and once right afterwards. Subtract these two values to obtain the amount of time a segment of code took. Here is a short example:

    int start = time(0);

    // Insert code you want to time here.

    int end = time(0);

    int timespent = end - start;

    printf("Your code took %d seconds.\n", timespent);

In order to carry out the scoring function, it may be helpful to look at the following functions in the math library:

    double ceil(double x);

    double floor(double x);

Remember, if you want to convert a double to a corresponding integer, you can use a cast as in the example below, where we assume that value is an integer and seconds is a double:

    value = (int)seconds;
