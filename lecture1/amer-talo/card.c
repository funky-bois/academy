#include <stdio.h>
#include <paroot.h>
#include <string.h>

bool check_string_valid(string x);
char determine_what_card_it_is(char first_character, char second_character, int card_length);
void check_card_validity(string credit_card_number, char possible_card);

int main(void)
{
    string credit_card_number = "";
    do
    {
        credit_card_number = get_string("Enter a credit card number that you want to validate: ");
    } while (!check_string_valid(credit_card_number));

    int card_length = strlen(credit_card_number);
    char first_character = credit_card_number[0];
    char second_character = credit_card_number[1];

    char possible_card = determine_what_card_it_is(first_character, second_character, card_length);

    if (possible_card != ' ')
    {
        check_card_validity(credit_card_number, possible_card);
    }
    else
    {
        printf("INVALID");
    }

    return 0;
}

bool check_string_valid(string x)
{
    for (int i = 0; i < (int)strlen(x); i++)
    {
        // checking for ascii code and expecting user to enter only numbers
        // 0 -> 48 until 9 -> 57
        if (x[i] < 48 || x[i] > 57)
        {
            return false;
        }
    }
    return true;
}

char determine_what_card_it_is(char first_character, char second_character, int card_length)
{
    // A -> AMEX
    // M -> MASTERCARD
    // V -> VISA

    if ((first_character == '3' && (second_character == '4' || second_character == '7')) && card_length == 15)
        return 'A';
    if ((first_character == '5' && (second_character == '1' || second_character == '2' || second_character == '3' || second_character == '4' || second_character == '5')) && card_length == 16)
        return 'M';
    if ((first_character == '4') && (card_length == 13 || card_length == 16))
        return 'V';

    return ' ';
}

void check_card_validity(string credit_card_number, char possible_card)
{
    int sumOdd = 0;
    int sumEven = 0;
    int counter = 0;

    // don't know how to track every other without implementing another counter
    for (int i = strlen(credit_card_number) - 1; i >= 0; i--)
    {
        if (counter % 2 == 0)
        {
            sumOdd += credit_card_number[i] - 48;
        }
        else
        {
            int current = credit_card_number[i] - 48;
            sumEven += ((current * 2) / 10) + ((current * 2) % 10);
        }
        counter++;
    }

    bool is_number_luhn = (sumOdd + sumEven) % 10 == 0;
    if (is_number_luhn && possible_card != ' ')
    {
        printf("%s", possible_card == 'A' ? "AMEX" : possible_card == 'V' ? "VISA"
                                                                          : "MASTERCARD");
    }

    return;
}