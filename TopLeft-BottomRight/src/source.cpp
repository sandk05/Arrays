#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <queue>
using std::cout;
using std::vector;
using std::make_pair;
using std::pair;
using std::multimap;
using std::map;
using std::queue;
static vector<pair<int, int>> direction = { make_pair( 0,  1),
											make_pair( 0, -1),
											make_pair( 1,  0),
											make_pair(-1,  0),
											/*make_pair( 1,  1),
											make_pair( 1, -1),
											make_pair(-1,  1),
											make_pair(-1, -1)*/};

void findshortestutil(vector<vector<int>> &arr, 
					 vector<vector<int>> &visited, 
					 int i, int j, 
					 vector<pair<int,int>> &result, 
					 map<int, vector<pair<int, int>>>&output,
					 int &minWeight,
					 int &curWeight)
{
	
	if ((i < 0) || (j < 0) ||
		(i >= arr.size()) || (j >= arr[i].size()) ||
		(visited[i][j] == 1) || (arr[i][j] == 0) ||
		(minWeight < curWeight))
	{
		return;
	}
		

	if ((i == arr.size() - 1) && (j == arr[i].size() - 1))
	{
		result.push_back(make_pair(i, j));
		curWeight += arr[i][j];
		if (curWeight < minWeight)
		{
			minWeight = curWeight;
			output.clear();
			output.insert(make_pair(curWeight, result));
		}
		curWeight -= arr[i][j];
		result.pop_back();
		return;
	}
	visited[i][j] = 1;
	result.push_back(make_pair(i,j));
	curWeight += arr[i][j];
	for (int index = 0; index < direction.size(); index++)
	{
		findshortestutil(arr, visited, i + direction[index].first, j + direction[index].second, result, output, minWeight,curWeight);
	}
	curWeight -= arr[i][j];
	result.pop_back();
	visited[i][j] = 0;
}

void findshortestpath(vector <vector <int>> &arr, map<int, vector<pair<int, int>>>&output)
{
	vector<vector<int>> visited(arr.size(), vector<int> (arr[0].size(), 0));

	vector<pair<int,int>> result;
	if (arr[0][0] == 0)
	{
		arr[0][0] = 1;
	}
	if (arr[arr.size() - 1][arr[arr.size() - 1].size() - 1] == 0) {
		arr[arr.size() - 1][arr[arr.size() - 1].size() - 1] = 1;
	}
	int cur_weight = 0, min_weight = INT_MAX;
	findshortestutil(arr, visited, 0, 0 , result, output, min_weight, cur_weight);
}
void findallpathutil(vector<vector<int>>& arr,
	vector<vector<int>>& visited,
	int i, int j,
	vector<pair<int, int>>& result,
	multimap<int, vector<pair<int, int>>>& output)
{
	if ((i < 0) || (j < 0) || (i >= arr.size()) || (j >= arr[i].size()) || (visited[i][j] == 1) || (arr[i][j] == 0))
		return;

	if ((i == arr.size() - 1) && (j == arr[i].size() - 1))
	{
		result.push_back(make_pair(i, j));
		int sum = 0;
		for (auto v : result)
			sum += arr[v.first][v.second];
		output.insert(make_pair(sum, result));
		result.pop_back();
		return;
	}
	visited[i][j] = 1;
	result.push_back(make_pair(i, j));
	for (int index = 0; index < direction.size(); index++)
	{
		findallpathutil(arr, visited, i + direction[index].first, j + direction[index].second, result, output);
	}
	result.pop_back();
	visited[i][j] = 0;
}
void findallpath(vector <vector <int>>& arr, multimap<int, vector<pair<int, int>>>& output)
{
	vector<vector<int>> visited(arr.size(), vector<int>(arr[0].size(), 0));

	vector<pair<int, int>> result;
	if (!arr[0][0])
	{
		arr[0][0] = 1;
	}
	if (!arr[arr.size() - 1][arr[arr.size() - 1].size() - 1]) {
		arr[arr.size() - 1][arr[arr.size() - 1].size() - 1] = 1;
	}
	findallpathutil(arr, visited, 0, 0, result, output);
}
bool isPath(vector<vector<int>> &arr)
{
	queue<pair<int,int>> myqueue;
	vector<vector<int>> visited(arr.size(), vector<int>(arr[0].size(), 0));
	myqueue.push(make_pair(0, 0));
	while (!myqueue.empty())
	{
		pair<int, int> node = myqueue.front();
		myqueue.pop();
		visited[node.first][node.second] = 1;
		if ((node.first == arr.size() - 1) && (node.second == arr[arr.size() - 1].size() - 1))
			return true;
		for (int index = 0; index < direction.size(); index++)
		{
			pair<int,int> data(node.first + direction[index].first , node.second + direction[index].second);
			if ((data.first < 0) || (data.second < 0) ||
				(data.first >= arr.size()) || (data.second >= arr[arr.size() - 1].size())||
				(arr[data.first][data.second] == 0) || (visited[data.first][data.second] == 1))
			{
			}
			else {
				myqueue.push(data);
			}				
		}
	}
	return false;
}

int main()
{
	vector<vector<int>> myvec = { {1,2,3},
								  {4,5,6}};
	multimap<int, vector<pair<int, int>>> output1;
	map<int, vector<pair<int, int>>> output2;
	multimap<int, vector<pair<int, int>>> output3;
	map<int, vector<pair<int, int>>> output4;
	if (isPath(myvec)){
		findallpath(myvec, output1);
			if (output1.size())
			{
				cout << "Paths are " << std::endl;
					for (auto rVec : output1)
					{
						cout << "Size is " << rVec.first << " -> ";
							for (auto r : rVec.second)
							{
								//cout << "(" << r.first << "," << r.second << ") ";
								cout << myvec[r.first][r.second] << " ";
							}
						cout << std::endl;
					}
				cout << std::endl;
			}
		findshortestpath(myvec, output2);
		if (output2.size())
		{
			cout << "Shortest Path is  " << std::endl;
			for (auto rVec : output2)
			{
				cout << "Size is " << rVec.first << " -> ";
				for (auto r : rVec.second)
				{
					//cout << "(" << r.first << "," << r.second << ") ";
					cout << myvec[r.first][r.second] << " ";
				}
				cout << std::endl;
			}
			cout << std::endl;
		}
	}
	myvec = { {1,2,3},
			  {4,5,6},
			  {7,8,9}};
	if(isPath(myvec)) {
		findallpath(myvec, output3);
		if (output3.size())
		{
			cout << "Paths are " << std::endl;
			for (auto rVec : output3)
			{
				cout << "Size is " << rVec.first << " -> ";
				for (auto r : rVec.second)
				{
					//cout << "(" << r.first << "," << r.second << ") ";
					cout << myvec[r.first][r.second] << " ";
				}
				cout << std::endl;
			}
			cout << std::endl;
		}

		findshortestpath(myvec, output4);
		if (output4.size())
		{
			cout << "Shortest Path is  " << std::endl;
			for (auto rVec : output4)
			{
				cout << "Size is " << rVec.first << " -> ";
				for (auto r : rVec.second)
				{
					//cout << "(" << r.first << "," << r.second << ") ";
					cout << myvec[r.first][r.second] << " ";
				}
				cout << std::endl;
			}
			cout << std::endl;
		}
	}
	
	myvec = { {0,1,1},
			 {0,0,0},
			 {0,0,0} };
	cout <<std::boolalpha<< isPath(myvec) << std::endl;
	return 0;
}
