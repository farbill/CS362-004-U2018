//
// Created by William Fargo on 22/7/2018.
//
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

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, outpost, minion, mine, cutpurse,
                 sea_hag, tribute, outpost, council_room};
    int testK[10];
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    newCards = 3;
    xtraCoins = 0;
    printf("----------------- Testing WhoseTurn----------------\n", TESTCARD);
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    printf("Testing that numHandCards returns properly\n");
    asserttrue(G.handCount[ whoseTurn(&G) ] == numHandCards(&G));
    printf("\n >>>>>Testing complete %s <<<<<\n\n", TESTCARD);



    return 0;
}