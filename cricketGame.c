#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

//Declaration Area for my functions
int batting();
int balling();
int userScorecard1();
int comScorecard1();
int userScorecard2();
int comScorecard2();
int results();
int superover();

//Global variables declaration
int max_overs, max_wickets, max_balls, difficulty;
// Toss:
int user_toss_choice, com_toss_choice, toss_results, user_action_choice, com_action_choice;
// Scoring:
int user_run_choice, com_run_choice, ball, user_total_run, com_total_run, user_ball_choice, user_total_wicket, com_total_wicket, o, b;
// Results:
int remaining_run, remaining_ball;

int main()
{

    //For the random number selection
    srand(time(0));

    //Welcome Part
    printf("Welcome to our game.\n This is a cricket game trying to simulate our childhood nostalgia, Head or Tails game.\n");
    sleep(0.5);

    printf("Time for the rules:\n\n");
    printf("The rules are simple. You will choose a number between 1 and 6 while computer will generate a random number too.\n");
    printf("1. If you and computer choose the same number, it's a wicket. Otherwise the chosen number adds to the batting side.\n");
    printf("2. Choosing 0 during batting is allowed. It will count as a dot ball.\n");
    printf("3. Choosing 0 during balling is not allowed.\n");

    sleep(0.5);

    printf("\nLet's get started.\n");
    do
    {
        printf("\nHow many over will there be per innings?(01 to 50)\n");
        printf("Choose:\t");
        scanf("%d", &max_overs);
    } while (0 >= max_overs || max_overs > 50);
    
    max_balls = (max_overs * 6);

    do
    {
        printf("\nHow many wickets there will be? (01 to 10)\n");
        printf("Choose:\t");
        scanf("%d", &max_wickets);
    } while (0 >= max_wickets || max_wickets > 10);
    
    do
    {
        printf("\nSelect a difficulty:\n\t1. Easy\n\t2. Medium\n\t3. Hard\n");
        printf("Choose:\t");
        scanf("%d", &difficulty);
    } while (0 >= difficulty || difficulty > 3);
    
    do
    {
        printf("\nChoose your coin side\n\t1. Heads\n\t2. Tails\n");
        printf("Choose:\t");
        scanf("%d", &user_toss_choice);
    } while (0 >= user_toss_choice || user_toss_choice > 2);
    
    toss_results = (rand() % 2) + 1;

    if (user_toss_choice == toss_results)
    {
        printf("\nYou won the toss. Will you bat first or ball first?\n");
        do
        {
            printf("\t1. Bat\n\t2. Ball\n");
            printf("Choose:\t");
            scanf("%d", &user_action_choice);
        } while (0 >= user_action_choice || user_action_choice > 2);

        if (user_action_choice == 1)
        {
            printf("\nUser Won the toss and decided to Bat first.\n");
            sleep(0.5);

            ball = 0;
            user_total_run = 0;
            com_total_run = 0;
            user_total_wicket = 0;
            com_total_wicket = 0;

            while (ball < max_balls && user_total_wicket < max_wickets)
            {
                batting();
                userScorecard1();
            }
            
            ball = 0;

            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\n Target: %d \n", (user_total_run + 1));
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\nNow Computer's turn to bat.\n");
            while (ball < max_balls && com_total_wicket < max_wickets && com_total_run < user_total_run)
            {
                balling();
                comScorecard2();
            }
        }

        else if(user_action_choice == 2)
        {
            printf("User won the toss and decided to ball first.\n");
            sleep(0.5);

            ball = 0;
            user_total_run = 0;
            com_total_run = 0;
            user_total_wicket = 0;
            com_total_wicket = 0;

            while (ball < max_balls && com_total_wicket < max_wickets)
            {
                balling();
                comScorecard1();
            }
            
            ball = 0;

            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\n Target: %d \n", (com_total_run + 1));
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Now your turn to bat\n");
            while (ball < max_balls && user_total_wicket < max_wickets && com_total_run > user_total_run)
            {
                batting();
                userScorecard2();
            }
        }
    }

    else if (user_toss_choice != toss_results)
    {
        com_action_choice = (rand() % 2) + 1;

        if (com_action_choice == 1)
        {
            printf("Computer won the toss and decided to Bat first.\n");
            sleep(0.5);

            ball = 0;
            user_total_run = 0;
            com_total_run = 0;
            user_total_wicket = 0;
            com_total_wicket = 0;

            while (ball < max_balls && com_total_wicket < max_wickets)
            {
                balling();
                comScorecard1();
            }
            
            ball = 0;

            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\n Target: %d \n", (com_total_run + 1));
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Now your turn to bat.\n");
            while (ball < max_balls && user_total_wicket < max_wickets && user_total_run < com_total_run)
            {
                batting();
                userScorecard2();
            }
        }

        else if (com_action_choice == 2)
        {
            printf("Computer won the toss and decided to ball first.\n");
            sleep(0.5);

            ball = 0;
            user_total_run = 0;
            com_total_run = 0;
            user_total_wicket = 0;
            com_total_wicket = 0;

            while (ball < max_balls && user_total_wicket < max_wickets)
            {
                batting();
                userScorecard1();
            }

            ball = 0;

            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            printf("\n Target: %d \n", (user_total_run + 1));
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Now computer's turn to Bat.\n");
            while (ball < max_balls && com_total_wicket < max_wickets && user_total_run > com_total_run)
            {
                balling();
                comScorecard2();
            }
        }
    }

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    results();
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

// My Functions

//Function to manage batting
int batting()
{
    do
    {
        printf("\nMake your run choice.(0 to 6)\n");
        printf("Choose:\t");
        scanf("%d", &user_run_choice);
    } while (0 > user_run_choice || user_run_choice > 6);
    
    com_run_choice = (rand() % 6) + 1;

    if (difficulty == 1)
    {
        if (user_run_choice == com_run_choice)
        {
            user_total_run += 0;
            user_total_wicket ++;
            ball ++;
        }
        else if (user_run_choice != com_run_choice)
        {
            user_total_run += user_run_choice;
            ball ++;
        }
    }

    else if (difficulty == 2)
    {
        if (user_run_choice == com_run_choice || (user_run_choice + 1) == com_run_choice)
        {
            user_total_run += 0;
            user_total_wicket ++;
            ball ++;
        }
        else if (user_run_choice != com_run_choice || (user_run_choice + 1) != com_run_choice)
        {
            user_total_run += user_run_choice;
            ball ++;
        }
    }

    else if (difficulty == 3)
    {
        if (user_run_choice == com_run_choice || (user_run_choice + 1) == com_run_choice || (user_run_choice - 1) == com_run_choice)
        {
            user_total_run += 0;
            user_total_wicket ++;
            ball ++;
        }
        else
        {
            user_total_run += user_run_choice;
            ball ++;
        }
    }
}

//Function to manage balling
int balling()
{
    do
    {
        printf("\nMake your balling choice.(1 to 6)\n");
        printf("Choose:\t");
        scanf("%d", &user_ball_choice);
    } while (0 >= user_ball_choice || user_ball_choice > 6);

    com_run_choice = (rand() % 7);

    if (user_ball_choice == com_run_choice)
    {
        com_total_run += 0;
        ball ++;
        com_total_wicket ++;
    }
    else if (user_ball_choice != com_run_choice)
    {
        com_total_run += com_run_choice;
        ball ++;
        com_total_wicket += 0;
    }
    
}

// Batting 1st scorecard for user
int userScorecard1()
{
    //over count
    o = ball / 6;
    //Running ball count
    b = ball % 6;

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Score: %d - %d  overs: %d.%d\n", user_total_run, user_total_wicket, o, b);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

//Batting 1st scorecard for computer
int comScorecard1()
{
    //over count
    o = ball / 6;
    //Running ball count
    b = ball % 6;

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Score: %d - %d  overs: %d.%d\n", com_total_run, com_total_wicket, o, b);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

//Batiing 2nd scorecard for user
int userScorecard2()
{
    //over count
    o = ball / 6;
    //Running ball count
    b = ball % 6;
    
    remaining_run = (com_total_run - user_total_run) + 1;
    remaining_ball = max_balls - ball;

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Score: %d - %d  overs: %d.%d\n", user_total_run, user_total_wicket, o, b);
    printf("Target: %d\n", (com_total_run + 1));
    printf("Need %d more runs from %d balls.\n", remaining_run, remaining_ball);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

//Batiing 2nd scorecard for computer
int comScorecard2()
{
    //over count
    o = ball / 6;
    //Running ball count
    b = ball % 6;
    
    remaining_run = (user_total_run - com_total_run) + 1;
    remaining_ball = max_balls - ball;

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Score: %d - %d  overs: %d.%d\n", com_total_run, com_total_wicket, o, b);
    printf("Target: %d\n", (user_total_run + 1));
    printf("Need %d more runs from %d balls.\n", remaining_run, remaining_ball);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

// Determining results
int results()
{
    if (user_total_run > com_total_run)
    {
        printf("Congratulations!! You won the match.\n");

        if (difficulty == 1)
        {
            printf("Try playing Medium difficulty. Or even Hard difficulty.\n");
        }
        else if (difficulty == 2)
        {
            printf("Try playing Hard difficulty.\n");
        }
        else
        {
            printf("You're the master of the game. Keep winning.\n");
        }
    }

    else if (user_total_run < com_total_run)
    {
        printf("Alas!! You lost the match.\n");
        
        if (difficulty == 3)
        {
            printf("Try playing Medium or Easy difficulty.\n");
        }
        else if (difficulty == 2)
        {
            printf("Try playing Easy difficulty.\n");
        }
        else
        {
            printf("Maybe today is you unlucky day. Rest and play later.\n");
        }
    }

    else if (user_total_run == com_total_run)
    {
        printf("Scores are equal. Superover will be played to decide the winner.\n");

        superover();
    }
}

//Function to play superover
int superover()
{
    user_total_run = 0;
    com_total_run = 0;
    user_total_wicket = 0;
    com_total_wicket = 0;
    max_overs = 1;
    max_wickets = 2;

    max_balls = max_overs * 6;

    if (user_toss_choice == toss_results && user_action_choice == 1)
    {
        printf("Computer will bat first for the superover.\n");

        while (ball < max_balls && com_total_wicket < max_wickets)
        {
            balling();
            comScorecard1();
        }
        
        ball = 0;
        printf("Now your turn to bat\n");
        while (ball < max_balls && user_total_wicket < max_wickets && com_total_run > user_total_run)
        {
            batting();
            userScorecard2();
        }
    }

    else if(user_toss_choice == toss_results && user_action_choice == 2)
    {
        printf("You will bat first for the the superover.\n");

        while (ball < max_balls && user_total_wicket < max_wickets)
        {
            batting();
            userScorecard1();
        }
        
        ball = 0;
        printf("Now Computer's turn to bat.\n");
        while (ball < max_balls && com_total_wicket < max_wickets && com_total_run < user_total_run)
        {
            balling();
            comScorecard2();
        }
    }

    else if (user_toss_choice != toss_results && com_action_choice == 1)
    {
        while (ball < max_balls && user_total_wicket < max_wickets)
        {
            batting();
            userScorecard1();
        }
        
        ball = 0;
        printf("Now Computer's turn to bat.\n");
        while (ball < max_balls && com_total_wicket < max_wickets && com_total_run < user_total_run)
        {
            balling();
            comScorecard2();
        }
    }

    else if (user_toss_choice != toss_results && com_action_choice == 2)
    {
        while (ball < max_balls && com_total_wicket < max_wickets)
        {
            balling();
            comScorecard1();
        }
        
        ball = 0;
        printf("Now your turn to bat\n");
        while (ball < max_balls && user_total_wicket < max_wickets && com_total_run > user_total_run)
        {
            batting();
            userScorecard2();
        }
    }

    results();
}