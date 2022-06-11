void sort012(int *arr, int n)
{
       //   Write your code here
       int lownot0 = 0, highnot2 = n - 1;
    for (int i = 0; i < n; i++)
    {
        while (arr[lownot0] == 0)
            lownot0++;
        while (arr[highnot2] == 2)
            highnot2--;
        if (arr[i] == 2 && i < highnot2)
            std::swap(arr[i], arr[highnot2]);
        if (arr[i] == 0 && i > lownot0)
            std::swap(arr[i], arr[lownot0]);
    }
}
