#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "share.h"

int process1(char* input)
{
    int sum = 0;
    char* start = input;
    int min = INT_MAX;
    int max = INT_MIN;
    for (size_t i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
        {
            int num = atoi(start);
            if (min > num) min = num;
            if (max < num) max = num;
            start = input + i;
        }
        if (input[i] == '\n')
        {
            sum += max - min;
            min = INT_MAX;
            max = INT_MIN;
        }
    }

    return sum;
}

int process2(char* input)
{
    int sum = 0;
    char* starti = input;
    size_t lineStart = 0;
    int rowResult = 0;
    for (size_t i = 0; i < strlen(input); i++)
    {
        if (input[i] != '\n' && input[i] != '\r' && lineStart == -1)
        {
            lineStart = i;
        }
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
        {
            int num1 = atoi(starti);
            char* startj = input + lineStart;
            for (size_t j = lineStart; true; j++)
            {
                if (input[j] == ' ' || input[j] == '\t' || input[j] == '\n')
                {
                    int num2 = atoi(startj);
                    if (num1 != num2 && num1 % num2 == 0)
                    {
                        rowResult = num1 / num2;
                    }
                    startj = input + j;
                }
                if (input[j] == '\n' || input[j] == '\0') break;
            }
            starti = input + i;
        }
        if (input[i] == '\n')
        {
            sum += rowResult;
            lineStart = -1;
        }
    }

    return sum;
}

int main()
{
    printf("Part one\n");

    char* input = read("day2.test1");
    printf("%d should be 18\n", process1(input));
    free(input);

    input = read("day2.input");
    printf("ANSWER: %d (should be 45158)\n", process1(input));
    free(input);

    printf("Part two\n");

    input = read("day2.test2");
    printf("%d should be 9\n", process2(input));
    free(input);

    input = read("day2.input");
    printf("ANSWER: %d (should be 294)\n", process2(input));
    free(input);

    return 0;
}