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

#define TESTCARD "smithy"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};
    int testK[10];
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    printf("TEST: smithy adds +3 cards\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    memcpy(&testK, &k, sizeof(k));
    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
    printf("Here are hte starting cards %d\n", compareIntegerArray(k, testK, 10));
    newCards = 3;
    xtraCoins = 0;
//printf("after card effect handcount test = %d, G = %d", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    asserttrue(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    asserttrue(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    asserttrue(testG.coins == G.coins + xtraCoins);
    printf("TEST: smithy keeps kindgom piles the same\n");
    asserttrue(compareIntegerArray(k, testK, 10));
    printf("TEST: smithy keeps victory card counts the same\n");
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
