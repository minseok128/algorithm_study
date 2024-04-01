#include "sorting.hpp"

static void	mi_insertion(vector<int> &arr, int l, int r)
{
	int			key, i, j;

	for (i = l + 1; i <= r; ++i)
	{
		key = arr[i];
		j = i - 1;
		while (j >= l && key < arr[j])
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

static void	mi_conquer(vector<int> &arr, vector<int> &tmp, int left, int right, int mid)
{
	int			i = 0, l = left, r = mid + 1;

	while (l <= mid && r <= right)
	{
		if (arr[l] > arr[r])
			tmp[i++] = arr[r++];
		else
			tmp[i++] = arr[l++];
	}

	if (l > mid)
		while (r <= right)
			tmp[i++] = arr[r++];

	if (r > right)
		while (l <= mid)
			tmp[i++] = arr[l++];

	for (i = left; i <= right; i++)
		arr[i] = tmp[i - left];
}

static void	mi_devide(vector<int> &arr, vector<int> &tmp, int l, int r)
{
	int	m;

	if (r - l <= 10)
	{
		mi_insertion(arr, l, r);
		return ;
	}
	m = (l + r) / 2;
	mi_devide(arr, tmp, l, m);
	mi_devide(arr, tmp, m + 1, r);
	mi_conquer(arr, tmp, l, r, m);
}

void	merge_insertion_sort(vector<int> &base_arr, ofstream &ofile)
{
	auto		start = high_resolution_clock::now();
	int			size = base_arr.size();
	vector<int>	arr(base_arr), tmp(size);

	mi_devide(arr, tmp, 0, size - 1);

	print_array("merge_insertion", arr, ofile, start);
}
