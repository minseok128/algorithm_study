// 20203361 장민석
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void	insertion_sort(vector<int>  &base_arr, ofstream &ofile);
void	merge_sort(vector<int>  &base_arr, ofstream &ofile);
void	merge_insertion_sort(vector<int>  &base_arr, ofstream &ofile);
static void	print_array(string type, vector<int> &arr,
	ofstream &ofile, high_resolution_clock::time_point &start);

// --------insertion sort--------
void	insertion_sort(vector<int> &base_arr, ofstream &ofile)
{
	auto		start = high_resolution_clock::now();
	vector<int>	arr(base_arr); // base_arr의 복사본을 생성
	int			size = arr.size();
	int			key, i, j;

	for (i = 1; i < size; ++i)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && key < arr[j]) // key보다 큰 원소들을 오른쪽으로 이동시키며 적절한 위치 찾기
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}

	print_array("insertion", arr, ofile, start);
	ofile << '\n';
}

// --------merge_sort--------
static void	m_conquer(vector<int> &arr, vector<int> &tmp, int left, int right, int mid)
{
	int			i = 0, l = left, r = mid + 1;

	while (l <= mid && r <= right) // 왼쪽 및 오른쪽 서브어레이를 순회하며 임시 배열에 정렬
	{
		if (arr[l] > arr[r])
			tmp[i++] = arr[r++];
		else
			tmp[i++] = arr[l++];
	}

	if (l > mid) // 각 서브어레이의 남은 요소를 임시 배열에 복사
		while (r <= right)
			tmp[i++] = arr[r++];

	if (r > right)
		while (l <= mid)
			tmp[i++] = arr[l++];

	for (i = left; i <= right; ++i) // 임시 배열의 요소를 원래 배열에 복사
		arr[i] = tmp[i - left];
}

static void	m_devide(vector<int> &arr, vector<int> &tmp, int l, int r)
{
	int	m;

	if (l >= r)
		return ;
	m = (l + r) / 2;
	m_devide(arr, tmp, l, m); // 서브어레이를 재귀적으로 분할
	m_devide(arr, tmp, m + 1, r);
	m_conquer(arr, tmp, l, r, m); // 분할된 서브어레이 병합
}

void	merge_sort(vector<int> &base_arr, ofstream &ofile)
{
	auto		start = high_resolution_clock::now();
	int			size = base_arr.size();
	vector<int>	arr(base_arr), tmp(size);

	m_devide(arr, tmp, 0, size - 1);

	print_array("merge", arr, ofile, start);
	ofile << '\n';
}

// --------merge_insertion_sort--------
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

	for (i = left; i <= right; ++i)
		arr[i] = tmp[i - left];
}

static void	mi_devide(vector<int> &arr, vector<int> &tmp, int l, int r)
{
	int	m;

	if (r - l <= 10) // insertion sort가 더욱 효율적이게 되는 시점에서 insertion sort 호출
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

	insertion_sort(base_arr, ofile);
	merge_sort(base_arr, ofile);
	merge_insertion_sort(base_arr, ofile);

	ofile.close();
	return (0);
}
