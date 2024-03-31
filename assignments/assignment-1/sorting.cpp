#include "sorting.hpp"

int	print_error(const std::string &msg)
{
	cerr << msg << "\n";
	return (1);
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


	for (int num : base_arr)
		std::cout << num << ' ';
	std::cout << '\n';

	return 0;
}