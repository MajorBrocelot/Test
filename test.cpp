/* RANDOM WALK PROBLEM / ROHIT SUNDA */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

// function takes in position on bridge and displays the appropriate string art
void display_position(int position_on_bridge)
{
    switch(position_on_bridge){
    case 1:
        cout << "|* _ _ _ _ _ _ |\n";
        break;
    case 2:
        cout << "|_ * _ _ _ _ _ |\n";
        break;
    case 3:
        cout << "|_ _ * _ _ _ _ |\n";
        break;
    case 4:
        cout << "|_ _ _ * _ _ _ |\n";
        break;
    case 5:
        cout << "|_ _ _ _ * _ _ |\n";
        break;
    case 6:
        cout << "|_ _ _ _ _ * _ |\n";
        break;
    case 7:
        cout << "|_ _ _ _ _ _ * |\n";
        break;
    default:
        cout << "You are finally off the bridge!\n";
        break;
    }
}

int main()
{
    srand(time(NULL));                          // seed random number generator

    int position_on_bridge = 4;                 // default position on bridge is 4 because you start in the middle
    int number_of_steps = 0;                    // stores how many time the RNG will be used to get off the bridge
    int greatest_num_of_steps = 0;              // self explanatory variables
    float average_num_of_steps = 0;

    for (int i = 1; i <= 50; ++i){              // bridge walk will go through 50 trials
        cout << "Trial #" << i << endl;
        number_of_steps = 0;                    // variables go back to default value as the next trial starts
        position_on_bridge = 4;
        display_position(position_on_bridge);   // displays default position on bridge

        while(position_on_bridge >= 1 && position_on_bridge <= 7){
            int zero_or_one = rand() % 2;       // generate random number either zero or one

            if (zero_or_one == 0){              // zero causes movement to the left
                position_on_bridge -= 1;
                display_position(position_on_bridge);
                number_of_steps += 1;
            }

            else if(position_on_bridge == 1){   // one causes movement right
                position_on_bridge += 1;
                display_position(position_on_bridge);
                number_of_steps += 1;
            }
        }                                       // number of steps is recorded every step of the way so...

        cout <<"Number of steps taken: "<< number_of_steps << "\n\n\n";

        if (number_of_steps > greatest_num_of_steps)
            greatest_num_of_steps = number_of_steps;

        average_num_of_steps += number_of_steps;
    }
                                                // so the average and max can be calculated and shown
    cout << "Greatest number of step: " << greatest_num_of_steps << endl;
    cout << "Average number of step: " << average_num_of_steps/50 << endl;
}

