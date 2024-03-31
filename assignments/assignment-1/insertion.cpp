#include "sorting.hpp"

void	insertion_sort(vector<int> arr, ofstream &ofile)
{
	auto	start = high_resolution_clock::now();
	int		size = arr.size();

	for (int i = 1; i < size; ++i)
	{
		int	key = arr[i];
		int	j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}

	print_array(arr, ofile, start);
	ofile << '\n';
}
