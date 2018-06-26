int bin_search(int *arr, int size, int target) {
    int l, r, p;
    l = 0;
    r = size - 1;
    while (l <= r) {
        p = (l + r) / 2;
        if (arr[p] < target)
            l = p + 1;
        else if (arr[p] > target)
            r = p - 1;
        else
            return p;
    }
    return -1;
}
