
void mergeCore(int *arr, int low, int mid, int high)
{
	int i, k;
	int *tmp = new int[high - low + 1];
	// int *tmp = (int *)malloc((high - low + 1) * sizeof(int));
	int left_low = low, left_high = mid;
	int right_low = mid + 1, right_high = high;
	for (k = 0; left_low <= left_high && right_low <= right_high; k++)
		if (arr[left_low] <= arr[right_low])
			tmp[k] = arr[left_low++];
		else
			tmp[k] = arr[right_low++];
	if (left_low <= left_high)
		for (i = left_low; i <= left_high; i++)
			tmp[k++] = arr[i];
	if (right_low <= right_high)
		for (i = right_low; i <= right_high; i++)
			tmp[k++] = arr[i];
	for (i = 0; i < high - low + 1; i++)
		arr[low + i] = tmp[i];
	delete[] tmp;
	// free(tmp); 
}

void merge(int *arr, unsigned int first, unsigned int last)
{
	int mid = 0;
	if (first < last)
	{
		mid = (first + last) / 2;
		merge(arr, first, mid);
		merge(arr, mid + 1, last);
		mergeCore(arr, first, mid, last);
	}
}