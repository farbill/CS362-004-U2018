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

#define TESTCARD "outpost"
/*
 * This unit test is for the getCost function
 */
int main() {
    printf("TEST: curse\n");
    asserttrue(getCost(curse) == 0);
    printf("TEST: estate\n");
    asserttrue(getCost(estate) == 0);
    printf("TEST: duchy\n");
    asserttrue(getCost(duchy) == 5);
    printf("TEST: province\n");
    asserttrue(getCost(province) == 8);
    printf("TEST: copper\n");
    asserttrue(getCost(copper) == 0);
    printf("TEST: silver\n");
    asserttrue(getCost(silver) == 3);
    printf("TEST: gold\n");
    asserttrue(getCost(gold) == 6);
    printf("TEST: council_room\n");
    asserttrue(getCost(council_room) == 5);
    printf("TEST: feast\n");
    asserttrue(getCost(feast) == 4);
    printf("TEST: gardens\n");
    asserttrue(getCost(gardens) == 4);
    printf("TEST: mine\n");
    asserttrue(getCost(mine) == 5);
    printf("TEST: remodel\n");
    asserttrue(getCost(feast) == 4);
    printf("TEST: smithy\n");
    asserttrue(getCost(smithy) == 4);
    printf("TEST: village\n");
    asserttrue(getCost(village) == 3);
    printf("TEST: feast\n");
    asserttrue(getCost(feast) == 4);
    printf("TEST: baron\n");
    asserttrue(getCost(baron) == 4);
    printf("TEST: great_hall\n");
    asserttrue(getCost(great_hall) == 3);
    printf("TEST: minion\n");
    asserttrue(getCost(minion) == 5);
    printf("TEST: steward\n");
    asserttrue(getCost(steward) == 3);
    printf("TEST: tribute\n");
    asserttrue(getCost(tribute) == 5);
    printf("TEST: ambassador\n");
    asserttrue(getCost(ambassador) == 3);
    printf("TEST: cutpurse\n");
    asserttrue(getCost(cutpurse) == 4);
    printf("TEST: embargo\n");
    asserttrue(getCost(embargo) == 2);
    printf("TEST: outpost\n");
    asserttrue(getCost(outpost) == 5);
    printf("TEST: salvager\n");
    asserttrue(getCost(salvager) == 4);
    printf("TEST: sea_hag\n");
    asserttrue(getCost(sea_hag) == 4);
    printf("TEST: treasure_map\n");
    asserttrue(getCost(salvager) == 4);
    printf("\n >>>>>Testing complete %s <<<<<\n\n", TESTCARD);



    return 0;
}
