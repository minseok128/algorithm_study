#include "sorting.hpp"

int	print_error(const std::string &msg)
{
	cerr << msg << "\n";
	return (1);
}

void	print_array(vector<int> &arr, ofstream &ofile, steady_clock::time_point start)
{
	int	size = arr.size() - 1;

	cout << "insertion: "
		<< duration_cast<microseconds>(high_resolution_clock::now() - start).count()
		<< "ms\n";
	for (int i = 0; i < size; ++i)
		ofile << arr[i] << " ";
	ofile << arr[size];
}

int main(int ac, char **av)
{
	if (ac != 3)
		return (print_error("usage: ./sorting [file name] [sorting algorithm]"));

	ifstream	ifile(av[1]);
	ofstream	ofile(av[2]);
	string		line;
	vector<int>	base_arr;
	int			size;
	
	if (!ifile.is_open() || !ofile.is_open())
		return (print_error("file open error"));

	ifile >> size;
	base_arr.resize(size);
	for (int i = 0; i < size; ++i)
		ifile >> base_arr[i];
	ifile.close();

	insertion_sort(base_arr, ofile);

	return 0;
}