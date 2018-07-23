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
    int xtraCoins = 0;
    int seed = 1000;
    int numPlayers = 2;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, outpost, minion, mine, cutpurse,
                 sea_hag, tribute, outpost, council_room};
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    newCards = 3;
    xtraCoins = 0;
    printf("----------------- Testing WhoseTurn----------------\n");
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    printf("Testing that internal state of whose turns is properly returned\n");
    asserttrue(G.whoseTurn == whoseTurn(&G));
    printf("\n >>>>>Testing complete <<<<<\n\n");



    return 0;
}


