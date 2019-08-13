#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "share.h"

int process1(char* input)
{
    int sum = 0;
    int len = strlen(input);
    int i = 0;

    int current = input[i++] - '0';

    int first = current;
    int last = current;

    while(i < len)
    {
        current = input[i++] - '0';
        if (last == current)
        {
            sum += current;
        }
        last = current;
    }

    if (first == current)
    {
        sum += current;
    }

    return sum;
}

int process2(char* input)
{
    int sum = 0;
    int len = strlen(input);
    int half = len / 2;
    for (size_t i = 0; i < half; i++)
    {
        if (input[i] == input[i+half])
        {
            sum += input[i] - '0';
        }
    }

    return sum * 2;
}

void check(int (*func)(char*), char* input, int expected)
{
    int actual = (*func)(input);
    if (expected != actual)
    {
        printf("%s -> %d should be %d\n", input, actual, expected);
    }
    else
    {
        printf("%s -> %d CORRECT\n", input, actual);
    }
}

void main1(char* input)
{
    printf("Part one\n");
    check(&process1, "1122", 3);
    check(&process1, "1111", 4);
    check(&process1, "1234", 0);
    check(&process1, "91212129", 9);
    printf("ANSWER: %d\n", process1(input));
}

void main2(char* input)
{
    printf("Part two\n");
    check(&process2, "1212", 6);
    check(&process2, "1221", 0);
    check(&process2, "123425", 4);
    check(&process2, "123123", 12);
    check(&process2, "12131415", 4);
    printf("ANSWER: %d\n", process2(input));
}

int main()
{
    char* input = read("day1.input");
    main1(input);
    main2(input);
    free(input);
    return 0;
}