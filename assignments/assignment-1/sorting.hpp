#ifndef SORTING_HPP
# define SORTING_HPP
# include <iostream>
# include <fstream>
# include <vector>
# include <sstream>
# include <chrono>

using namespace std;
using namespace std::chrono;

void	insertion_sort(vector<int> arr, ofstream &ofile);
void	merge_sort(vector<int> arr, ofstream &ofile);
void	merge_insertion_sort(vector<int> arr, ofstream &ofile);
void	print_array(vector<int> &arr, ofstream &ofile, steady_clock::time_point &start);

#endif