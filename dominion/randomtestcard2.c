//
// Created by William Fargo on 21/7/2018. TEST FOR SMITHY CARD
//

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "great_hall"


    int main() {
        srand(time(NULL));
        int newCards = 0;
        int discarded = 1;
        int xtraCoins = 0;
        int shuffledCards = 0;



        int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
        int seed = 1000;
        int numPlayers = 2;
        int thisPlayer = 0;
        clock_t t;
        t = clock();
        for(int i = 0; i < 25; i++) {
            if (((clock() - t) / CLOCKS_PER_SEC) > (5.0 * 60.0 * ((double) t) / CLOCKS_PER_SEC)) {
                printf("Hitting 5 minutes\n");
                break;
            }
            seed = rand() % 1000;

            printf("Running new random test with seed %d\n", seed);
            struct gameState G, testG;
            int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                         sea_hag, tribute, smithy, council_room};
            int testK[10];
            // initialize a game state and player cards
            //generate a random game state through playing the game, where an adventurer card can be played
            handpos = oracle(&G, seed, great_hall);
            printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
            // copy the game state to a test case
            memcpy(&testG, &G, sizeof(struct gameState));
            cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
            printf("TEST: great_hall adds +1 action\n");
            asserttrue(testG.numActions == G.numActions + 1);
//printf("after card effect handcount test = %d, G = %d", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
            printf("TEST: great_hall is handcount neutral\n");

            asserttrue(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
            printf("Test Great call has the correct deck count\n");
            asserttrue(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - 1);
            printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
            asserttrue(testG.coins == G.coins + xtraCoins);
            printf("TEST: great_hall keeps kindgom piles the same\n");
            asserttrue(compareIntegerArray(k, testK, 10));
            printf("TEST: great_hall keeps victory card counts the same\n");
            printf("Estate:\n");
            asserttrue(testG.supplyCount[estate] == G.supplyCount[estate]);
            printf("Duchy:\n");
            asserttrue(testG.supplyCount[duchy] == G.supplyCount[duchy]);
            printf("Province:\n");
            asserttrue(testG.supplyCount[province] == G.supplyCount[province]);
            haveOtherPlayersStatesChanged(testG.whoseTurn, testG, G, numPlayers);
        }
            printf("\n >>>>>Testing complete %s <<<<<\n\n", TESTCARD);


            return 0;
        }

