//
// Created by William Fargo on 22/7/2018.
//
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


    int *testK = kingdomCards(adventurer, embargo, outpost, minion, mine, cutpurse,
                         sea_hag, tribute, outpost, council_room);
    int k[10] = {adventurer, embargo, outpost, minion, mine, cutpurse,
                 sea_hag, tribute, outpost, council_room};
    // initialize a game state and player cards

    printf("----------------- Testing WhoseTurn----------------\n");
    // copy the game state to a test case
    printf("Testing that numHandCards returns properly\n");
    for(int z = 0; z < 10; z++){
        printf("Testing kingdom card number %d is correct\n", z);
        asserttrue(k[z] == testK[z]);
    }
    printf("\n >>>>>Testing complete <<<<<\n\n");



    return 0;
}
