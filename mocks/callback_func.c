/**
 * @file      : 
 * @brief     : 
 * @Author    : S.Deepa (deepa.s@vvdntech.in)
 * @Copyright : (c) 2019-2020 , VVDN Technologies Pvt. Ltd.
 *              Permission is hereby granted to everyone in VVDN Technologies
 *              to use the Software without restriction, including without
 *              limitation the rights to use, copy, modify, merge, publish,
 *              distribute, distribute with modifications.
 */

#include <stdio.h>
int (*call_back)(char *input);


#define FAIL 1
#define SUCCESS 0
#define SIZE 10

int arrithmatic(char *input)
{
    int ret_val;                     /* call back function */
    float a,b;
    char c;

    ret_val = sscanf(input,"%f%c%f",&a,&c,&b);
    if (ret_val < 0) {
        perror("sscanf failed\n");
        return FAIL;
    }
    switch (c) {
        case '+':
            return (a+b);
        case '-':
            return (a-b);
        case '*':
            return (a*b);
        case '/':
            return (a/b);
        default:
            return -1;
    }
}

int fun(int (*call_back)(),char *exp)
{
    float result;
    result = (*call_back)(exp);
    return result;
}

int main(void)
{
    float res;
    int ret_val;
    char expression[SIZE];
    printf("enter the expression\n");
    ret_val = scanf("%s",expression);
    if (ret_val < 0) {
        perror("scanf function failed\n");
        return FAIL;
    }
    call_back = arrithmatic;
    res = fun(call_back,expression);
    if (res == -1) {
        printf("invalid expression\n");
        return FAIL;
    }
    printf ("the value of %s is %f\n",expression,res);
    return SUCCESS;
}

