#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
//这个是Dijkstra，如果把下面的搜索时间变得O(1),时间复杂度就会很好
//The time complexity of the above code/algorithm looks O(V^2) as there are two nested while loops. If we take a closer look, we can observe that the statements in inner loop are executed O(V+E) times (similar to BFS). The inner loop has decreaseKey() operation which takes O(LogV) time. So overall time complexity is O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV)
//Note that the above code uses Binary Heap for Priority Queue implementation. Time complexity can be reduced to O(E + VLogV) using Fibonacci Heap. The reason is, Fibonacci Heap takes O(1) time for decrease-key operation while Binary Heap takes O(Logn) time.
//Adjacency List Node
using namespace std;

struct ListNode
{
    int val;
    int num;
    ListNode* next;
    ListNode(int n,int v):num(n),val(v),next(NULL){}
};
struct VD
{
    int num;
    int dstn;
    VD(int n):num(n),dstn(INT_MAX){}
};
bool MyCompare(VD a,VD b)//max heap, whether a shall be after b
{
    return a.dstn<b.dstn;
}
class Graph
{
    private:
        vector<ListNode*> vertex;
        const bool DEBUG=0;
    public:
        Graph(int n)
        {
            for(int i=0;i<n;i++)
            {
                vertex.push_back(new ListNode(i,0));
            }
        }
        bool AddEdge1(int a,int b,int val)//双方向
        {
            AddEdge(a,b,val);
            AddEdge(b,a,val);
        }
        bool AddEdge(int s,int d,int val)//单方向
        {
            if(s>=vertex.size()) return 0;
            ListNode* cur=vertex[s];
            while(cur->next)
            {
                if(cur->val==val)
                    return 0;
                cur=cur->next;
            }
            cur->next=new ListNode(d,val);
            return 1;
        }
        void PrintGraph()
        {
            for(int i=0;i<vertex.size();i++)
            {
                ListNode* cur=vertex[i];
                while(cur)
                {
                    cout<<cur->num<<":"<<cur->val<<" ";
                    cur=cur->next;
                }
                cout<<endl;
            }
        }
        bool isInHeap(vector<VD> MinHeap,int v)
        {
            for(int i=0;i<MinHeap.size();i++)
            {
                if(MinHeap[i].num==v) return 1;
            }
            return 0;
        }
        vector<VD> Dijkstra(const int src)
        {
            vector<VD> res;
            vector<VD> MinHeap;
            for(int i=0;i<vertex.size();i++)
            {
                VD tmp(i);
                if(i==src)
                    tmp.dstn=0;
                MinHeap.push_back(tmp);
            }
            make_heap(MinHeap.begin(),MinHeap.end(),MyCompare);

            while(MinHeap.size()!=0)
            {
            sort_heap(MinHeap.begin(),MinHeap.end(),MyCompare);
            if(DEBUG)
            {
                for(int i=0;i<MinHeap.size();i++)
                {
                    cout<<MinHeap[i].num<<":"<<MinHeap[i].dstn<<" ";
                }
                cout<<endl;
            }
                pop_heap(MinHeap.begin(),MinHeap.end(),MyCompare);
                VD tmp=MinHeap.back();
                MinHeap.pop_back();
                res.push_back(tmp);
                int no = tmp.num;
                if(DEBUG)
                {
                    cout<<"pop "<<tmp.num<<" "<<tmp.dstn<<endl;
                }

                ListNode* cur=vertex[no];
                cur=cur->next;
                while(cur)
                {
                    int next=cur->num;
                    int pos=-1;
                    for(int i=0;i<MinHeap.size();i++)//这个查找操作可以更优，但是要通过自己来实现heap做到，no time
                    {
                        if(MinHeap[i].num==next)
                        {
                            pos=i;
                            break;
                        }
                    }
                    if(pos!=-1)
                    {
                        MinHeap[pos].dstn=min(MinHeap[pos].dstn,tmp.dstn+cur->val);
                    }
                    cur=cur->next;
                }
            }

            for(int i=0;i<res.size();i++)
            {
                cout<<res[i].num<<"\t";
            }
            cout<<endl;
            for(int i=0;i<res.size();i++)
            {
                cout<<res[i].dstn<<"\t";
            }
            cout<<endl;
            return res;
        }
};




int main()
{
    Graph gh(9);
    gh.AddEdge1( 0, 1, 4);//无向图
    gh.AddEdge1( 0, 7, 8);
    gh.AddEdge1( 1, 2, 8);
    gh.AddEdge1( 1, 7, 11);
    gh.AddEdge1( 2, 3, 7);
    gh.AddEdge1( 2, 8, 2);
    gh.AddEdge1( 2, 5, 4);
    gh.AddEdge1( 3, 4, 9);
    gh.AddEdge1( 3, 5, 14);
    gh.AddEdge1( 4, 5, 10);
    gh.AddEdge1( 5, 6, 2);
    gh.AddEdge1( 6, 7, 1);
    gh.AddEdge1( 6, 8, 6);
    gh.AddEdge1( 7, 8, 7);
    gh.PrintGraph();
    gh.Dijkstra(0);
    return 0;
}
