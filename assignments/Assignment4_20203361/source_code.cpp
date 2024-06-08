#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9; // 충분히 큰 값으로 설정

// 최소 힙 구조체 정의
struct MinHeap
{
	vector<pair<int, int>> heap; // (키 값, 정점 번호) 쌍을 저장하는 벡터
	int heap_size;				 // 힙의 크기

	// 생성자: 힙의 용량을 받아서 힙 초기화
	MinHeap(int capacity)
	{
		heap.reserve(capacity); // 힙 용량 예약
		heap_size = 0;			// 초기 힙 크기는 0
	}

	// 부모 인덱스 계산
	int parent(int i) { return (i - 1) / 2; }
	// 왼쪽 자식 인덱스 계산
	int left(int i) { return 2 * i + 1; }
	// 오른쪽 자식 인덱스 계산
	int right(int i) { return 2 * i + 2; }

	// 최소 힙 속성 유지
	void min_heapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int smallest = i; // 가장 작은 값의 인덱스 초기화

		// 왼쪽 자식이 현재 노드보다 작으면 갱신
		if (l < heap_size && heap[l].first < heap[smallest].first)
			smallest = l;
		// 오른쪽 자식이 현재 노드보다 작으면 갱신
		if (r < heap_size && heap[r].first < heap[smallest].first)
			smallest = r;
		// 가장 작은 값이 현재 노드와 다르면 교체하고 재귀 호출
		if (smallest != i)
		{
			swap(heap[i], heap[smallest]);
			min_heapify(smallest);
		}
	}

	// 최소값 추출
	pair<int, int> heap_extract_min()
	{
		if (heap_size < 1)
			throw runtime_error("Heap underflow"); // 힙 언더플로우 예외 처리
		pair<int, int> min = heap[0];			   // 최솟값
		heap[0] = heap[heap_size - 1];			   // 마지막 값을 루트로 이동
		heap_size--;							   // 힙 크기 감소
		min_heapify(0);							   // 최소 힙 속성 유지
		return min;
	}

	// 키 값 감소
	void heap_decrease_key(int i, int key)
	{
		if (key > heap[i].first)
			throw runtime_error("New key is larger than current key"); // 새로운 키가 더 크면 예외 처리
		heap[i].first = key;										   // 키 값 갱신
		while (i > 0 && heap[parent(i)].first > heap[i].first)
		{
			swap(heap[i], heap[parent(i)]); // 부모와 교체
			i = parent(i);					// 부모로 이동
		}
	}

	// 최소 힙 삽입
	void min_heap_insert(pair<int, int> key)
	{
		heap_size++;								 // 힙 크기 증가
		heap[heap_size - 1] = {INF, key.second};	 // 새로운 키를 무한대로 설정
		heap_decrease_key(heap_size - 1, key.first); // 키 값 감소
	}
};

// MST-Prim(G, w, r)
// 1  for each u ∈ G.V
// 2      u.key = ∞
// 3      u.π = NIL
// 4  r.key = 0
// 5  Q = G.V
// 6  while Q ≠ ∅
// 7      u = EXTRACT-MIN(Q)
// 8      for each v ∈ G.Adj[u]
// 9          if v ∈ Q and w(u, v) < v.key
// 10             v.π = u
// 11             v.key = w(u, v)
void mst(ifstream &ifile, ofstream &ofile)
{
	int num_vertex, num_edge, r;

	ifile >> num_vertex >> num_edge >> r;								 // 정점 수, 간선 수, 시작 정점 읽기
	vector<vector<int>> graph(num_vertex, vector<int>(num_vertex, INF)); // 그래프 초기화
	for (int i = 0; i < num_vertex; i++)
		graph[i][i] = 0; // 자기 자신으로의 간선 가중치는 0
	for (int i = 0; i < num_edge; i++)
	{
		int u, v, w;
		ifile >> u >> v >> w;
		graph[u][v] = w; // 무방향 그래프이므로 양쪽에 가중치 설정
		graph[v][u] = w;
	}

	vector<int> key(num_vertex, INF);	   // 각 정점의 키 값
	vector<int> parent(num_vertex, -1);	   // 각 정점의 부모
	vector<bool> inMST(num_vertex, false); // 각 정점이 MST에 포함되었는지 여부

	key[r] = 0;					// 시작 정점의 키 값은 0
	MinHeap pq(num_vertex);		// 우선순위 큐(최소 힙) 생성
	pq.min_heap_insert({0, r}); // 시작 정점 삽입

	while (pq.heap_size != 0)
	{
		int u = pq.heap_extract_min().second; // 최소 키 값을 가진 정점 추출

		inMST[u] = true; // 추출된 정점을 MST에 포함

		for (int v = 0; v < num_vertex; v++)
			if (graph[u][v] != INF && !inMST[v] && graph[u][v] < key[v])
			{
				key[v] = graph[u][v];			 // 키 값 갱신
				pq.min_heap_insert({key[v], v}); // 우선순위 큐에 삽입
				parent[v] = u;					 // 부모 갱신
			}
	}

	for (int i = 0; i < num_vertex; i++)
	{
		if (parent[i] != -1)
			ofile << i << '\t' << parent[i] << '\n'; // 부모가 있으면 출력
		else
			ofile << i << '\t' << "NIL" << '\n'; // 부모가 없으면 NIL 출력
	}
}

// Floyd-Warshall(W)
// 1   n = W.rows
// 2   D^(0) = W
// 3   for k = 1 to n
// 4       let D^(k) = (d^(k)_ij) be a new n x n matrix
// 5       for i = 1 to n
// 6           for j = 1 to n
// 7               d^(k)_ij = min(d^(k-1)_ij, d^(k-1)_ik + d^(k-1)_kj)
// 8   return D^(n)
void sp(ifstream &ifile, ofstream &ofile)
{
	int num_vertex;

	ifile >> num_vertex;												 // 정점 수 읽기
	vector<vector<int>> dist(num_vertex, vector<int>(num_vertex, INF));	 // 거리 행렬 초기화
	vector<vector<int>> parent(num_vertex, vector<int>(num_vertex, -1)); // 부모 행렬 초기화

	for (int i = 0; i < num_vertex; i++)
		dist[i][i] = 0; // 자기 자신으로의 거리는 0

	for (int i = 0; i < num_vertex; i++)
		for (int j = 0; j < num_vertex; j++)
		{
			string weight;
			ifile >> weight; // 가중치 읽기
			if (weight == "INF")
				dist[i][j] = INF; // 무한대 처리
			else
				dist[i][j] = stoi(weight); // 가중치 저장
			if (weight != "INF" && i != j)
				parent[i][j] = i; // 부모 저장
		}

	// Floyd-Warshall Algorithm
	for (int k = 0; k < num_vertex; k++)
		for (int i = 0; i < num_vertex; i++)
			for (int j = 0; j < num_vertex; j++)
				if (dist[i][k] != INF && dist[k][j] != INF)
					if (dist[i][j] > dist[i][k] + dist[k][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j]; // 거리 갱신
						parent[i][j] = parent[k][j];		  // 부모 갱신
					}

	ofile << "D\t" << num_vertex << '\n'; // 거리 행렬 출력
	for (int i = 0; i < num_vertex; i++)
	{
		for (int j = 0; j < num_vertex; j++)
		{
			if (dist[i][j] == INF)
				ofile << "INF\t";
			else
				ofile << dist[i][j] << '\t';
		}
		ofile << '\n';
	}

	ofile << "P\t" << num_vertex << '\n'; // 부모 행렬 출력
	for (int i = 0; i < num_vertex; i++)
	{
		for (int j = 0; j < num_vertex; j++)
		{
			if (dist[i][j] == INF)
				ofile << "INF\t";
			else if (i == j)
				ofile << "NIL\t";
			else
				ofile << parent[i][j] + 1 << '\t'; // 1부터 시작하는 인덱스
		}
		ofile << '\n';
	}
}

int main(int ac, char **av)
{
	ifstream ifile_sp(av[1]);  // sp 입력 파일 스트림
	ifstream ifile_mst(av[2]); // mst 입력 파일 스트림
	ofstream ofile_sp(av[3]);  // sp 출력 파일 스트림
	ofstream ofile_mst(av[4]); // mst 출력 파일 스트림

	if (ac != 5)
	{
		cout << "Usage: " << av[0] << " <input_sp> <input_mst>"
			 << " <output_sp> <output_mst>\n"; // 잘못된 사용법 메시지 출력
		return 1;
	}

	sp(ifile_sp, ofile_sp);
	mst(ifile_mst, ofile_mst);

	ifile_mst.close();
	ofile_mst.close();
	ifile_sp.close();
	ofile_sp.close();
	return 0;
}
