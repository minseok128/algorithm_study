#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// 두 문자열 X와 Y의 LCS를 구하는 함수
string LCS(const string &X, const string &Y, int strLength)
{
	// 동적 배열 dp를 사용하여 LCS 길이를 저장
	vector<vector<int>> dp(strLength + 1, vector<int>(strLength + 1, 0));

	// dp 배열을 채워나가는 이중 루프
	for (int i = 1; i <= strLength; i++)
	{
		for (int j = 1; j <= strLength; j++)
		{
			if (X[i - 1] == Y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1; // 문자가 같으면 이전 값에 1을 더함
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 다르면 왼쪽 또는 위쪽 값 중 큰 값을 선택
		}
	}

	// LCS 문자열을 역순으로 추적
	int i = strLength, j = strLength;
	string lcs_str = "";
	while (i > 0 && j > 0)
	{
		if (X[i - 1] == Y[j - 1])
		{
			lcs_str = X[i - 1] + lcs_str; // LCS에 문자를 추가
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
			i--; // 위쪽 값이 더 크면 i를 감소
		else
			j--; // 왼쪽 값이 더 크면 j를 감소
	}
	return lcs_str;
}

int main(int ac, char **av)
{
	ifstream ifile(av[1]);	// 입력 파일 스트림
	ofstream ofile(av[2]);	// 출력 파일 스트림
	int strLength;			// 문자열의 길이
	vector<string> strList; // 문자열 목록을 저장할 벡터

	if (ac != 3)
	{
		cout << "Usage: " << av[0] << " <input file> <output file>\n"; // 잘못된 사용법 메시지 출력
		return 1;
	}

	ifile >> strLength;
	string tmp;
	while (ifile >> tmp) // 입력 파일에서 문자열을 읽어 strList에 추가
		strList.push_back(tmp);

	// 각 문자열에 대해
	for (size_t i = 0; i < strList.size(); i++)
	{
		pair<int, string> lcs = {0, ""}; // 가장 긴 LCS를 저장할 pair
		for (size_t j = 0; j < strList.size(); j++)
		{
			if (i == j)
				continue;											// 같은 문자열이면 건너뜀
			string tmpLcs = LCS(strList[i], strList[j], strLength); // LCS 함수 호출
			if (tmpLcs.length() > lcs.second.length())
				lcs = {j, tmpLcs}; // 더 긴 LCS 저장
		}
		ofile << lcs.first + 1 << '\t'
			  << lcs.second.length() << '\t' // LCS의 길이
			  << lcs.second;				 // LCS 문자열
		if (i != strList.size() - 1)
			ofile << '\n';
	}
}
