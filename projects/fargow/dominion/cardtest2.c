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

#define TESTCARD "adventurer"

int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
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
    printf("TEST: adventurer  adds 2  cards\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    memcpy(&testK, &k, sizeof(k));

    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
    newCards = 3;
    xtraCoins = 0;
//printf("after card effect handcount test = %d, G = %d", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 2);
    asserttrue(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
    int treasures = 0, numDrawnCards = 0, deckCounter, cardNum;
    deckCounter = G.deckCount[G.whoseTurn];
    while(treasures < 2){
        cardNum = G.deck[G.whoseTurn][deckCounter];
        deckCounter--;
        numDrawnCards++;
        if (cardNum == copper || cardNum == silver || cardNum == gold){
            treasures++;
        }
    }
    printf("number of drawn cards %d\n", numDrawnCards);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - numDrawnCards);
    asserttrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - numDrawnCards);
    printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + numDrawnCards);
    asserttrue(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + numDrawnCards);

    printf("TEST: adventurer keeps kindgom piles the same\n");
    asserttrue(compareIntegerArray(k, testK, 10));
    printf("TEST: adventurer keeps victory card counts the same\n");
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

