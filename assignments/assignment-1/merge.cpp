#include "sorting.hpp"

void	conquer(vector<int> &arr, int left, int right, int mid)
{
	vector<int>	tmp(right - left + 1);
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

void	devide(vector<int> &arr, int l, int r)
{
	int	m;

	if (l >= r)
		return ;
	m = (l + r) / 2;
	devide(arr, l, m);
	devide(arr, m + 1, r);
	conquer(arr, l, r, m);
}

void	merge_sort(vector<int> arr, ofstream &ofile)
{
	auto	start = high_resolution_clock::now();
	int		size = arr.size();

	devide(arr, 0, size - 1);

	print_array("merge", arr, ofile, start);
	ofile << '\n';
}
