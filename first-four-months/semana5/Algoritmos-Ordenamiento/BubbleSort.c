#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillMatrix(int size, int nums[])
{
    for (int i = 0; i < size; i++)
    {
        nums[i] = rand() % 101;
    }
}

void showMatrix(int size, int nums[], int option)
{
    if (option == 1)
    {
        printf("Array original\n");
    }
    else
    {
        printf("Array ordenado\n");
    }

    for (int i = 0; i < size; i++)
    {
        printf("%5d", nums[i]);
    }

    printf("\n");
}

void sort(int size, int nums[])
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag != 1)
        {
            break;
        }
    }
}
int main()
{
    srand(time(NULL));
    int size = 10;
    int numbers[size];
    fillMatrix(size, numbers);
    showMatrix(size, numbers, 1);
    sort(size, numbers);
    showMatrix(size, numbers, 0);
    return 0;
}