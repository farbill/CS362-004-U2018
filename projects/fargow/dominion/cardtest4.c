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

#define TESTCARD "outpost"

int main() {
    int newCards = 0;

    int xtraCoins = 0;


    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, outpost, minion, mine, cutpurse,
                 sea_hag, tribute, outpost, council_room};
    int testK[10];
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    newCards = 3;
    xtraCoins = 0;
    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    // copy the game state to a test case
    drawCard(thisPlayer, &testG);
    drawCard(thisPlayer, &testG);
    drawCard(thisPlayer, &testG);
    memcpy(&testG, &G, sizeof(struct gameState));


    cardEffect(outpost, choice1, choice2, choice3, &testG, handpos, &bonus);
    printf("TEST: outpost played increments\n");
    asserttrue(testG.outpostPlayed == G.outpostPlayed + 1);
//printf("after card effect handcount test = %d, G = %d", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
    printf("TEST: outpost discards\n");
    asserttrue(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    asserttrue(testG.coins == G.coins + xtraCoins);
    printf("TEST: outpost keeps kindgom piles the same\n");
    asserttrue(compareIntegerArray(k, testK, 10));
    printf("TEST: outpost keeps victory card counts the same\n");
    printf("Estate:\n");
    asserttrue(testG.supplyCount[estate] == G.supplyCount[estate]);
    printf("Duchy:\n");
    asserttrue(testG.supplyCount[duchy] == G.supplyCount[duchy]);
    printf("Province:\n");
    asserttrue(testG.supplyCount[province] == G.supplyCount[province]);
    haveOtherPlayersStatesChanged(testG.whoseTurn, testG, G, numPlayers);
    printf("\n >>>>>Testing complete %s <<<<<\n\n", TESTCARD);



    return 0;
}


