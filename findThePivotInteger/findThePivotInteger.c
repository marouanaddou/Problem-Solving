
# include <stdio.h>
# include <stdlib.h>

int pivotInteger(int n) 
{
    if (n == 1)
        return 1;
    int arr[n];
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    for ( int i = 0; i < n; i++ )
    {
        left = 0; 
        right = 0;
        for (int j = 0; j <= i; j++)
            left += arr[j];
        for (int j = i; j < n; j++)
            right += arr[j];
        if (left == right)
            return i + 1;
    }
    return -1;
}

int main()
{
    printf("%d\n",pivotInteger(4)); // -1
    printf("%d",pivotInteger(8)); // 6
}