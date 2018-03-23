#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<fstream>
using namespace std;
const int N=1e5+10;
vector<int> v[N];

class graph
{
	int n,e,i,j;
	int a,b;
	vector <int> :: iterator it;
public:
	graph(char[]);
	
	void dfs(int source);
	void bfs(int source);
	void display();
};
graph::graph(char s[])//to input file_name
{
	ifstream infile;
	infile.open (s);
        infile>>n>>e;
        for(int i=0;i<e;i++)
		{
			infile>>a>>b;//input from file
			v[a].push_back(b);
			v[b].push_back(a);
		}
 
	infile.close();
}




void graph::display()
{
	cout<<endl<<"DISPLAY"<<endl;
	cout<<"ADJACENCY LIST"<<endl;
	for(i=1;i<=n;i++)
    {
    	cout<<i<<":-";
    	for(it=v[i].begin();it!=v[i].end();it++)
	    {
            cout<<*it<<" ";
            
	    }
	    cout<<endl;
	} 
}
void graph::bfs(int source)
{
	int mark[N]={0};
	cout<<"BFS TRAVERSAL"<<endl;
	mark[source]=1;
	queue <int> q;
	q.push(source);
	while(!q.empty())
	{
		source=q.front();
		cout<<source<<"->";
		q.pop();
		for(int i=0;i<v[source].size();++i)
		{
			if(mark[v[source][i]]==0)
			{
				mark[v[source][i]]=1;
				q.push(v[source][i]);
			}
		}

	}
	cout<<endl;
}

void graph::dfs(int source)
{
	int mark[N]={0};
	cout<<endl<<"DFS TRAVERSAL"<<endl;
	mark[source]=1;
	stack <int> s;
	s.push(source);
	while(!s.empty())
	{
		source=s.top();
		cout<<source<<"->";
		s.pop();
		for(int i=0;i<v[source].size();++i)
		{
			if(mark[v[source][i]]==0)
			{
				mark[v[source][i]]=1;
				s.push(v[source][i]);
			}
		}
	}
	cout<<endl;
}





int main(void)
{
	// ifstream
	// Queue *q=new Queue();

	
	char ss[15];
	cin>>ss;
	graph s(ss);
	s.display();
	s.dfs(1);
	s.bfs(1);

	return 0;
}


