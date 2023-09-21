#include <stdio.h>

void exercise1(void)
{
    printf("Gustav Mahler\n");
    printf("Gustav\nMahler\n");
    printf("Gustav ");
    printf("Mahler\n");
}

void exercise2(void)
{
    printf("My name is Gustav Mahler.\n");
    printf("My address is 1234 Main Street.\n");
}

void exercise3(void)
{
    int age = 0;
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Your age in days is %d\n", age * 365);
}

void jolly(void)
{
    printf("For he's a jolly good fellow!\n");
}

void deny(void)
{
    printf("Which nobody can deny!");
}

void exercise4(void)
{
    jolly();
    jolly();
    jolly();
    deny();
}
int main(void)
{
    exercise1();
    printf("------------------\n");
    exercise2();
    printf("------------------\n");
    exercise3();
    printf("------------------\n");
    exercise4();

    return 0;
}