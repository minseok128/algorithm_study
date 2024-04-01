#include "sorting.hpp"

void	insertion_sort(vector<int> arr, ofstream &ofile)
{
	auto	start = high_resolution_clock::now();
	int		size = arr.size();
	int		key, i, j;

	for (i = 1; i < size; ++i)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && key < arr[j])
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}

	print_array(arr, ofile, start);
	ofile << '\n';
}
