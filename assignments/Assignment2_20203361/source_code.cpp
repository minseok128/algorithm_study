// 20203361 장민석
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

static void	print_array(string type, vector<int> &arr,
	ofstream &ofile, high_resolution_clock::time_point &start);

int	q1_partition(vector<int> &arr, int l, int r)
{
	int	pivot = arr[r];
	int	i = l - 1;

	for (int j = l; j < r; ++j)
		if (arr[j] <= pivot)
		{
			++i;
			swap(arr[i], arr[j]);
		}
	swap(arr[i + 1], arr[r]);
	return (i + 1);
}

void	q1_divied(vector<int> &arr, int l, int r)
{
	int	p;

	if (l >= r)
		return ;
	p = q1_partition(arr, l, r);
	q1_divied(arr, l, p - 1);
	q1_divied(arr, p + 1, r);
}

void	quick_sort_1(vector<int> & base_arr, ofstream &ofile)
{
	auto		start = high_resolution_clock::now();
	int			size = base_arr.size();
	vector<int>	arr(base_arr), tmp(size);

	q1_divied(arr, 0, size - 1);

	print_array("quick_sort_1", arr, ofile, start);
}

// --------utils--------
static int	print_error(const std::string &msg)
{
	cerr << msg << "\n";
	return (1);
}

static void	print_array(string type, vector<int> &arr,
	ofstream &ofile, high_resolution_clock::time_point &start)
{
	int	size = arr.size() - 1;

	cout << type << ": "
		<< duration_cast<microseconds>(high_resolution_clock::now() - start).count() << "ms\n";
	for (int i = 0; i < size; ++i)
		ofile << arr[i] << " ";
	ofile << arr[size];
}

// -------- main--------
int main(int ac, char **av)
{
	if (ac != 3)
		return (print_error("usage: ./sorting [input file] [output file]"));

	ifstream	ifile(av[1]);
	ofstream	ofile(av[2]);
	vector<int>	base_arr;
	int			size;
	
	if (!ifile.is_open() || !ofile.is_open())
		return (print_error("file open error"));

	ifile >> size;
	base_arr.resize(size);
	for (int i = 0; i < size; ++i)
		ifile >> base_arr[i];
	ifile.close();

	quick_sort_1(base_arr, ofile);

	ofile.close();
	return (0);
}
