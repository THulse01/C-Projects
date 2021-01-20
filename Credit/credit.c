#include <stdio.h>
#include <cs50.h>
#include <math.h>

bool Verify_Card(long CNum, long length);

/*
    51-55 - Mastercard
    34/37 - American Express
    4 - Visa
*/

int main(void)
{
    long CNum;
    long length = 0;
    long templength;
    string card;
    bool validity;
    bool cardtypecheck = false;

    // Get Card Number
    do
    {
        CNum = get_long("Card Number: ");
        templength = CNum;
    }
    while (CNum < 0);

    //Get Card Number Length
    while (templength > 0)
    {
        templength = templength / 10;
        length++;
    }

    // Get card type
    int nums = CNum / pow(10, length - 2);

    if (nums >= 51 && nums <= 55)
    {
        card = "MASTERCARD";
        cardtypecheck = true;
    }
    else if (nums == 34 || nums == 37)
    {
        card = "AMEX";
        cardtypecheck = true;
    }
    else if (nums / 10 == 4)
    {
        card = "VISA";
        cardtypecheck = true;
    }

    if (length != 13 && length != 15 && length != 16)
    {
        validity = false;
    }
    else
    {
        if (!cardtypecheck)
        {
            validity = false;
        }
        else
        {
            validity = Verify_Card(CNum, length);
        }
    }
    if (validity)
    {
        printf("%s\n", card);
    }
    else
    {
        printf("INVALID\n");
    }
}

/*
    Every other digit starting from right side. (Multiply by 2 + add product DIGITS e.g. 12+2+36 = 1+2+2+3+6)
    Add sum of rest of values
*/

bool Verify_Card(long CNum, long length)
{
    long arr[length];
    long temparr[15];
    long temp = CNum;
    int count = 0;
    long total = 0;
    for (int i = 0; i <= 15; i++)
    {
        temparr[i] = 0;
    }

    // Push all card numbers to an array for use.
    for (int i = 0; temp != 0; i++)
    {
        arr[i] = temp % 10;
        temp /= 10;
    }

    //printf("CARD NUM: %li", CNum);
    //printf("TOTAL ATM: %ld", total);

    // Add all numbers into an array & multiply by 2
    for (int i = 1; i <= length; i = i + 2)
    {
        long val = arr[i];
        long vald = arr[i] * 2;
        if (vald >= 10)
        {
            total = total + vald / 10;
            total = total + vald % 10;
            count = count + 2;
        }
        else
        {
            temparr[count] = arr[i] * 2;
            count++;
        }
    }

    // Add Up Numbers
    for (int i = 0; i <= 15; i++)
    {
        //printf("TEMPARR[%i]: %li\n",i,temparr[i]);
        total = total + temparr[i];
    }

    // Add up other numbers
    for (int i = 0; i <= 15; i = i + 2)
    {
        //printf("ARR[%i]: %li\n",i,arr[i]);
        total = total + arr[i];
    }

    printf("TOTAL: %ld\n", total);

    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 4012888888881881
// 41888818
