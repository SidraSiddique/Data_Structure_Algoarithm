#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

bool isPath(int n, vector<vector<int>> &e, int s, int d, set<int> &v){
    if (v.size()==n)  return false;
    v.insert(s);
    for (int i = 0 ; i < e[s].size() ; i++ ){
        if (e[s][i] == d) return true;
        if (v.find(e[s][i]) != v.end())   continue;
        bool res = isPath(n, e, e[s][i], d, v);
        if (res == true)    return true;
    }
    return false;
}
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    cout << source << ' ' << destination << '\n';
    if (source == destination)  return true;
    set<int> visited;
    vector<vector<int>> e;
    int i;
    for (i = 0 ; i < n ; i++)
        e.push_back(*(new vector<int>));
    for ( i = 0 ; i < edges.size() ; i++){
        e[edges[i][0]].push_back(edges[i][1]);
        e[edges[i][1]].push_back(edges[i][0]);
    }
    return isPath(n, e, source, destination, visited); 
}
int main(){
	vector<vector<int>> v1 = {{0,1},{1,2},{2,0}};
	int source = 0, destination = 2;
	if (validPath(3, v1, source, destination))	cout << "Path exist between " << source << " and " << destination << "\n";
	else										cout << "Path not exist between " << source << " and " << destination << "\n";
	vector<vector<int>> v2 = {{0,1},{0,2},{3,5},{5,4},{4,3}};
	source = 0, destination = 5;
	if (validPath(6, v2, source, destination))	cout << "Path exist between " << source << " and " << destination << "\n";
	else										cout << "Path not exist between " << source << " and " << destination << "\n";
	return 0;
}
