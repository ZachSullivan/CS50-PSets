#include <cs50.h>
#include <stdio.h>

int main (void)
{
    long long ccNumber; // Records the CC#
    long long tempCC;   // Records the CC#, used when operating on CC#

    const int MAX_CC_LENGTH = 16;   // Records max possible length of CC#
    const int MIN_CC_LENGTH = 13;   // Records min possible length of CC#

    long long evenCCDigits [MAX_CC_LENGTH]; // Stores every 2nd digit in CC#
    long long oddCCDigits [MAX_CC_LENGTH];  // Stores all other digits in CC#

    int lenCounter = 0;     // Records number of digits in CC#
    int evenLen = 0;        // Records the max number of 2nd digits in CC#
    int oddLen = 0;         // Records the max number of all other digits in CC#
    int evenSum = 0;        // Records the sum of 2nd digits in CC#
    int totalSum = 0;       // Records the total sum of evenSum + all other digits
    int firstDigit = 0;     // Records the first digit in CC#
    int secondDigit = 0;    // Records the second digit in CC#

    // Records the corresponding card type: AMEX, VISA, ETC.
    string cardType;

    // Prompt the user to enter a CC #, prompt again if the number is greater than 16
    do
    {
        lenCounter = 0;
        ccNumber = get_long_long("Card Number: ");
        tempCC = ccNumber;

        // Record the number of digits in the CC #
        while (tempCC != 0)
        {
            tempCC /= 10;
            lenCounter++;
        }
    }
    while (lenCounter > MAX_CC_LENGTH);

    // Check if the len of CC# is even or odd, determine if even odd lens should be equal or offset
    if (lenCounter % 2 == 0)
    {
        // Then the even & odd lengths are equal
        evenLen = oddLen = lenCounter / 2;
    }
    else
    {
        // Then the even & odd lengths are NOT equal
        // .. so offset the oddLen by 1
        evenLen = lenCounter / 2;
        oddLen = (lenCounter / 2) + 1;
    }

    // Obtain the second last CC digit and assign the CC number to a temp variable
    tempCC = ccNumber / 10;

    for (int i = 1; i <= evenLen; i++)
    {

        // Obtain the current last digit and assign that to the according array
        evenCCDigits[i] = tempCC % 10;
        //Discard the last 2 digits
        tempCC = tempCC / 100;

        //Mulitply all second last digits by 2
        evenCCDigits[i] = evenCCDigits[i] * 2;
    }

    for (int i = 1; i <= evenLen; i++)
    {

        //Add the products digits together
        if (evenCCDigits[i] < 9)
        {
            evenSum += evenCCDigits[i];
        }
        else
        {
            while (evenCCDigits[i] > 0)
            {
                evenSum += evenCCDigits[i] % 10;
                evenCCDigits[i] /= 10;
            }
        }
    }

    // Update the total sum
    totalSum += evenSum;

    // Obtain the second last CC digit and assign the CC number to a temp variable
    tempCC = ccNumber;

    // Obtain the digits that weren’t multiplied by 2
    for (int i = 1; i <= oddLen; i++)
    {

        oddCCDigits[i] = tempCC % 10;
        tempCC /= 100;

        totalSum += oddCCDigits[i];

    }


    tempCC = ccNumber;

    // Obtain the first digit in the CC #
    while (tempCC >= 10)
    {
        tempCC /= 10;
        firstDigit = tempCC;
    }

    tempCC = ccNumber;

    // Obtain the second digit in the CC#
    while (tempCC >= 100)
    {

        tempCC /= 10;
        secondDigit = tempCC % 10;
    }


    // Filter through the CC Len and CC check sum, determine if card is valid
    if (lenCounter < MIN_CC_LENGTH || totalSum % 10 != 0)
    {
        cardType = "INVALID\n";
    }

    // Filter the first digit then the second digit in CC# to determine card type
    else
    {
        if ((totalSum % 10) == 0)
        {
            if (firstDigit == 3)
            {
                if (secondDigit == 4 || secondDigit == 7)
                {
                    cardType = "AMEX\n";
                }
                else
                {
                    cardType = "INVALID\n";
                }
            }
            else if (firstDigit == 5)
            {
                if (secondDigit == 1 || secondDigit == 2
                    || secondDigit == 3 || secondDigit == 4
                    || secondDigit == 5)
                {
                    cardType = "MASTERCARD\n";
                }
                else
                {
                    cardType = "INVALID\n";
                }
            }
            else if (firstDigit == 4)
            {
                cardType = "VISA\n";
            }
            else
            {
                cardType = "INVALID\n";
            }
        }
        else
        {
            cardType = "INVALID\n";
        }
    }

    // Print the correct card type for the user
    printf("%s", cardType);

}