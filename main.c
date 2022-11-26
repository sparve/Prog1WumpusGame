/* ---------------------------------------------
Program 1: Wumpus (Fixed Size Array)

Description: The game in this program is similar to the game called "Hunt the Wumpus," a classic text-based adventure game by Gregory Yob from 1972. The Wumpus lives in a completely dark cave of 20 rooms. Each room has 3 tunnels leading to other rooms. You have the following hazards: 1. Two rooms have bottomless pits in them.  If you go there you fall and die. 2. The Wumpus is not bothered by the pits, as he has sucker feet. Usually he is asleep. He will wake up if you enter his room. When you move into the Wumpus' room, then he wakes and moves if he is in an odd-numbered room, but stays still otherwise.  After that, if he is in your room, he snaps your neck and you die!

Course: CS 141, Fall 2022.
System: PC using Replit
Author: Sana Parveen
---------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>		// for srand

// The following array is used to store the adjacent rooms in ascending order.
const int AdjRoomsArr[21][3]= {{0,0,0},{2,5,8},{1,3,10},{2,4,12},{3,5,14},{1,4,6},{5,7,15},{6,8,17},{1,7,9},{8,10,18},{2,9,11},{10,12,19},{3,11,13},{12,14,20},{4,13,15},{6,14,16},{15,17,20},{7,16,18},{9,17,19},{11,18,20},{13,16,19}};

// The game objects are contained in the following struct called gameVars.
struct gameVars {
  int pit1;
  int pit2;
  int Wumpus;
  int person;
  // int bat1;
  // int bat2;
};

// The following function dispays the cave for the game.
void displayCave() {
  printf("\n       ______18______             \n"
         "      /      |       \\           \n"
         "     /      _9__      \\          \n"
         "    /      /    \\      \\        \n"
         "   /      /      \\      \\       \n"
         "  17     8        10     19       \n"
         "  | \\   / \\      /  \\   / |    \n"
         "  |  \\ /   \\    /    \\ /  |    \n"
         "  |   7     1---2     11  |       \n"
         "  |   |    /     \\    |   |      \n"
         "  |   6----5     3---12   |       \n"
         "  |   |     \\   /     |   |      \n"
         "  |   \\       4      /    |      \n"
         "  |    \\      |     /     |      \n"
         "  \\     15---14---13     /       \n"
         "   \\   /            \\   /       \n"
         "    \\ /              \\ /        \n"
         "    16---------------20           \n"
         "\n");
}


// The following function dispays the instructions for the game.
void displayInstructions()
{
    printf( "Hunt the Wumpus:                                             \n"
    		"The Wumpus lives in a completely dark cave of 20 rooms. Each \n"
    		"room has 3 tunnels leading to other rooms.                   \n"
    		"                                                             \n"
    		"Hazards:                                                     \n"
    		"1. Two rooms have bottomless pits in them.  If you go there you fall and die.   \n"
    		"2. The Wumpus is not bothered by the pits, as he has sucker feet. Usually he is \n"
			"   asleep. He will wake up if you enter his room. When you move into the Wumpus'\n"
			"   room, then he wakes and moves if he is in an odd-numbered room, but stays    \n"
			"   still otherwise.  After that, if he is in your room, he snaps your neck and  \n"
			"   you die!                                                                     \n"
    		"                                                                                \n"
    		"Moves:                                                                          \n"
    		"On each move you can do the following, where input can be upper or lower-case:  \n"
    		"1. Move into an adjacent room.  To move enter 'M' followed by a space and       \n"
    		"   then a room number.                                                          \n"
    		"2. Enter 'R' to reset the person and hazard locations, useful for testing.      \n"
    		"3. Enter 'C' to cheat and display current board positions.                      \n"
    		"4. Enter 'D' to display this set of instructions.                               \n"
    		"5. Enter 'P' to print the maze room layout.                                     \n"
    		"6. Enter 'G' to guess which room Wumpus is in, to win or lose the game!         \n"
        "7. Enter 'X' to exit the game.                                                  \n"
    		"                                                                                \n"
    		"Good luck!                                                                      \n"
    		" \n\n");
}// end displayInstructions()


// The following function ends the game if the player is in the same room as any of the pits.
void pitDeath(struct gameVars *Obj){
  if(Obj -> pit1 == Obj -> person || Obj -> pit2 == Obj -> person){
    printf("Aaaaaaaaahhhhhh....   \n");
	  printf("    You fall into a pit and die. \n");
      printf("\nExiting Program ...\n");
    exit(0);
  }
}


// The following function ends the game if the player is in the same even numbered room as the Wumpus or moves the Wumpus to the smallest numered adjacent room if it is an odd numbered room.
void wumpusDeathFunc(struct gameVars *Obj){
  if(Obj -> person == Obj -> Wumpus){
    if (Obj -> Wumpus % 2 == 0){
      printf(	"You briefly feel a slimy tentacled arm as your neck is snapped. \n"
			"It is over.\n");
      printf("\nExiting Program ...\n");
      exit(0);
  }
    else{
      Obj -> Wumpus = AdjRoomsArr[Obj -> Wumpus][0];
      	printf( "You hear a slithering sound, as the Wumpus slips away. \n"
			  "Whew, that was close! \n");
    }
  }
}


// The following function detects harmful objects in the adjacent rooms to the player and lets the player know by print out specific statements accordingly.
void harmsDetectFunc(struct gameVars *Obj){
    if(AdjRoomsArr[Obj -> person][0] == Obj -> Wumpus || AdjRoomsArr[Obj -> person][1] == Obj -> Wumpus || AdjRoomsArr[Obj -> person][2] == Obj -> Wumpus){
	      printf("You smell a stench. ");
    }
    if(AdjRoomsArr[Obj -> person][0] == Obj -> pit1 || AdjRoomsArr[Obj -> person][1] == Obj -> pit1 || AdjRoomsArr[Obj -> person][2] == Obj -> pit1 || AdjRoomsArr[Obj -> person][0] == Obj -> pit2 ||  AdjRoomsArr[Obj -> person][1] == Obj -> pit2 ||  AdjRoomsArr[Obj -> person][2] == Obj -> pit2){
        printf("You feel a draft. ");
    }
}


// The following function randomizes the rooms for the game objects.
void randomFunc(struct gameVars *Obj){
    int randomVar[6];
    randomVar[0] = rand () % 20 +1;
    randomVar[1] = rand () % 20 +1;
    while(randomVar[1] == randomVar[0]){
        randomVar[1] = rand () % 20 +1;
    }
    randomVar[2] = rand () % 20 +1;
    while(randomVar[2] == randomVar[0] || randomVar[2] == randomVar[1]){
        randomVar[2] = rand () % 20 +1;
    }
    randomVar[3] = rand () % 20 +1;
    while(randomVar[3] == randomVar[0] || randomVar[3] == randomVar[2] || randomVar[3] == randomVar[1]){
        randomVar[3] = rand () % 20 +1;
    }
    Obj -> pit1 = randomVar[0];
    Obj -> pit2 = randomVar[1];
    Obj -> Wumpus = randomVar[2];
    Obj -> person = randomVar[3];
}


int main(void){
    srand(1); // seeds the random number generator to 1 so the output remains the same each time.
    struct gameVars Obj;
    char letter; // stores the menu option letter
    int roomNum; // stores the room number the user puts in
    randomFunc(&Obj);
    int moveNum=1; // stores the number for the user's valid move.

// The while loop starts below.
    while (letter != 'X' || letter != 'x'){
        printf( "You are in room %d. ", Obj.person);
        harmsDetectFunc(&Obj);
        printf("\n\n%d. Enter your move (or 'D' for directions): ", moveNum);
        scanf (" %c", &letter);
    
        if (letter == 'M' || letter == 'm') {
            scanf("%d", &roomNum);
            if (AdjRoomsArr[roomNum][0] == Obj.person || AdjRoomsArr[roomNum][1] == Obj.person || AdjRoomsArr[roomNum][2] == Obj.person){
                Obj.person = roomNum;
                moveNum++;
            }
            else{
                printf("Invalid move.  Please retry. \n");
            }
          pitDeath(&Obj);
          wumpusDeathFunc(&Obj);
        }
    
        if (letter == 'R' || letter == 'r'){
          printf("Enter the room locations (1..20) for player, wumpus, pit1, and pit2: \n\n");
          scanf(" %d%d%d%d", &Obj.person, &Obj.Wumpus, &Obj.pit1, &Obj.pit2);
        }
        
        if (letter == 'C' || letter == 'c'){
            printf( "Cheating! Game elements are in the following rooms: \n"
            "Player Wumpus Pit1 Pit2  \n"
            "%4d %7d %5d %5d \n\n", 
            Obj.person,
            Obj.Wumpus,
            Obj.pit1,
            Obj.pit2
    		);
        }
    
        if (letter == 'D' || letter == 'd'){
            displayCave();
            displayInstructions();
        }
    
        if (letter == 'P' || letter == 'p'){
            displayCave();
        }
    
        if(letter == 'G' || letter == 'g'){
            printf("Enter room (1..20) you think Wumpus is in: ");
            scanf(" %d", &roomNum);
            if(roomNum == Obj.Wumpus){
                printf("You won!\n");
                printf("\nExiting Program ...\n");
                exit(0);
            }
            else{
                printf("You lost.\n");
                printf("\nExiting Program ...\n");
                exit(0);
            }
        }
        
        if (letter == 'X' || letter == 'x'){
            printf("\nExiting Program ...\n");
            exit(0);
        }
    } // end while loop
    return 0;
}