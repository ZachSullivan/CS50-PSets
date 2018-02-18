#include <cs50.h>
#include <stdio.h>

int main (void)
{
    long long ccNumber;
    long long tempCC;

    int lenCounter;
    const int MAX_CC_LENGTH = 16;
    const int MIN_CC_LENGTH = 13;

    // Set length to half the largest CC number (so 16/2 = 8)
    long long evenCCDigits [MAX_CC_LENGTH];
    long long oddCCDigits [MAX_CC_LENGTH];

    int evenSum = 0;
    int totalSum = 0;
    int firstDigit = 0;
    int secondDigit = 0;
    // Records the corresponding card type: AMEX, VISA, ETC.
    string cardType;
    //long long tempCCDigits [MAX_CC_LENGTH];

    // Records "evenCCDigits" products' digits. longest possible len is double evenCCDigits's len (8*2 = 16)
    //long long evenCCSubDigits [MAX_CC_LENGTH];

    do
    {
        lenCounter = 0;
        // TODO ensure that cardnumber length is correct
        ccNumber = get_long_long("Card Number: ");
        tempCC = ccNumber;
        while(tempCC != 0) {
            tempCC /= 10;
            lenCounter++;
        }
    }
    while (lenCounter > MAX_CC_LENGTH || lenCounter < MIN_CC_LENGTH);   // REDO this while loop ccNumber > MAX_CC_LENGTH || ccNumber < MIN_CC_LENGTH

    printf("LenCounter: %i \n", lenCounter);

    // Obtain the second last CC digit and assign the CC number to a temp variable
    tempCC = ccNumber / 10;

    for (int i = 1; i <= lenCounter / 2; i++) {

        // Obtain the current last digit and assign that to the according array
        evenCCDigits[i] = tempCC % 10;
        //Discard the last 2 digits
        tempCC = tempCC / 100;

        if(i == lenCounter / 2) {
            secondDigit = evenCCDigits[i];
        }
        printf("Array %i: %lld \n", i, evenCCDigits[i]);

        //Mulitply all second last digits by 2
        evenCCDigits[i] = evenCCDigits[i] * 2;

        printf("Array * 2: %lld \n", evenCCDigits[i]);

    }



    for (int i = 1; i <= lenCounter / 2; i++) {

        //Add the products digits together
        if(evenCCDigits[i] < 9){
            evenSum += evenCCDigits[i];
        } else {
            while (evenCCDigits[i] > 0){
                evenSum += evenCCDigits[i] % 10;
                evenCCDigits[i] /= 10;
            }
        }
        printf("EvenSum: %i \n", evenSum);
    }

    totalSum += evenSum;



    // Obtain the second last CC digit and assign the CC number to a temp variable
    tempCC = ccNumber;

    // TODO CHECK THAT (lenCounter + 1) / 2 is correct for ALL
    for (int i = 0; i <= lenCounter / 2; i++) {

        oddCCDigits[i] = tempCC % 10;
        tempCC /= 100;

        totalSum += oddCCDigits[i];

        if (i == lenCounter / 2) {
            firstDigit = oddCCDigits[i];
        }

        printf("Array ODD %lld \n", oddCCDigits[i]);

    }

    printf("firstDigit: %i \n", firstDigit);
    printf("secondDigit: %i \n", secondDigit);
    printf("Total SUM: %i \n", totalSum);

    //Obtain the first two digits
    // tempCC = ccNumber;
    // if(tempCC > 99) {
    //     tempCC /= 10;
    // } else {
    //     startingNum = tempCC % 100;
    // }

    //printf("Starting Num: %i \n", startingNum);

    if ((totalSum % 10) == 0) {
        if (firstDigit == 3) {
            cardType = "American Express\n";
        } else if () {
            cardType = "OTHER\n";
        }
    } else {
        cardType = "INVALID\n";
    }

    printf("%s", cardType);

    //DEBUG
    // printf("Array: ");
    // for (int i = 0; i < ceil(lenCounter / 2); i++) {
    //     printf("[ %lld ] ", evenCCDigits[i]);
    // }

    // for (int i = 0; i < lenCounter / 2; i++) {
    //     for (int j = 0; j < lenCounter; j++) {
    //         while (evenCCDigits[i] > 0) {
    //             evenCCSubDigits[j] = evenCCDigits[i] % 10;
    //             evenCCDigits[i] = evenCCDigits[i] / 10;
    //         }
    //     }

    // }

    // //DEBUG
    // printf("Sub Array: ");
    // for (int i = 0; i < lenCounter; i++) {
    //     printf("[ %lld ] \n", evenCCSubDigits[i]);
    // }


    // tempCC = ccNumber / 10;

    // for (int i = 0; i < lenCounter / 2; i++) {

    //     evenCCNums[i] = tempCC % 10;
    //     tempCC = tempCC / 100;
    //     printf("TempCC: %lld \n", tempCC);
    //     printf("Array: %i \n", evenCCNums[i]);
    // }
}