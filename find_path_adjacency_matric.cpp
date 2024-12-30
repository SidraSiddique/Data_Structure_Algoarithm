#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

bool path(vector<vector<int>>& g, const int &N, int source, int destination){
	queue<int> q;
	vector<bool>	vistited(N, false) ;
	q.push(source);
	vistited[source] = true;
	while (!q.empty()){
		source = q.front();
		q.pop();
		if (g[source][destination] == 1)	return true;
		for (int i = 0 ; i < N ; i++)
			if (i != source && g[source][i] == 1 && !vistited[i]){
				q.push(i);
				vistited[i] = true;
			}
	}
	return false;
} 
vector<vector<int>> readGraph(ifstream &in, const int& N){
	int i, j;
	vector<vector<int>> g(N, vector<int>(N));
	for (i = 0 ; i < N ; i++)
		for (j = 0 ; j < N ; j++)
			in >> g[i][j];
	return g;
}
int main(){
	int i, n, source, destination, queries;
	//ifstream in("graph1.txt");						//In this graph, we have all nodes connected
	ifstream in("graph2.txt");							//In this graph, we have some nodes disconnected
	in >> n;
	vector<vector<int>> g = readGraph(in, n);
	in >> queries;
	for (i = 0 ; i < queries ; i++){
		in >> source >> destination;
		if (path(g, n, source, destination))	cout << "Path exist between " << source << " and " << destination << "\n";
		else									cout << "Path Not exist between " << source << " and " << destination << "\n";
	}
	in.close();	
	return 0;
}
