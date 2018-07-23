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

    int seed = 1000;
    int numPlayers = 2;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, outpost, minion, mine, cutpurse,
                 sea_hag, tribute, outpost, council_room};
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    printf("----------------- Testing WhoseTurn----------------\n");
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    printf("Testing that numHandCards returns properly\n");
    asserttrue(G.handCount[ whoseTurn(&G) ] == numHandCards(&G));
    printf("\n >>>>>Testing complete <<<<<\n\n");



    return 0;
}