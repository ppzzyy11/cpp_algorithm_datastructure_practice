#include<iostream>
#include<climits>
#include<vector>

using namespace std;

class MinHeap{
    private:
        vector<int> heap;
    public:
        MinHeap(){heap.resize(0);}
        MinHeap(vector<int>&nums)
        {
            for(int i=0;i<nums.size();i++)
            {
                insert(nums[i]);
            }
        }

        int getMin()
        {
            if(heap.size()==0) return INT_MAX;
            return heap[0];
        }

        int extractMin()
        {
            if(heap.size()==0) return INT_MIN;
            swap(heap[0],heap.back());
            int res=heap.back();
            heap.pop_back();
            Heapify(0);
            return res;
        }

        int insert(int key)
        {
            heap.push_back(key);
            Heapify(heap.size()-1);
            return key;
        }

        int del(int key)
        {
            int pos=-1;
            for(int i=0;i<heap.size();i++)
            {
                if(heap[i]==key)
                {
                    pos=i;
                    break;
                }
            }
            if(pos==-1) return INT_MIN;
            else
            {
                swap(heap[pos],heap.back());
                heap.pop_back();
                Heapify(pos);
            }
            return key;
        }

        void Heapify(int index)
        {
            if(index<0||index>=heap.size()) return ;
            if(index!=0)
            {
                int p=(index-1)/2;
                if(heap[p]>heap[index])
                {
                    while(index!=0&&heap[p]>heap[index])
                    {
                        swap(heap[p],heap[index]);
                        index=p;
                        p=(index-1)/2;
                    }
                    return ;
                }
            }
            while(index<heap.size())
            {
                int l=index*2+1;
                int r=index*2+2;

                if(l>=heap.size()&&r>=heap.size())
                {
                    return ;
                }else
                {
                    if(r>=heap.size()&&l<heap.size())
                    {
                        if(heap[index]>heap[l])
                        {
                            swap(heap[index],heap[l]);
                            index=l;
                        }else return ;
                    }else
                    {
                        if(heap[index]<heap[l]&&heap[index]<heap[r])
                            return ;
                        else
                        {
                            if(heap[l]<heap[r])
                            {
                                swap(heap[l],heap[index]);
                                index=l;
                            }else
                            {
                                swap(heap[index],heap[r]);
                                index=r;
                            }
                        }
                    }
                }
            }
            return ;
        }
        void DumpContent()
        {
            for(int i=0;i<heap.size();i++)
            {
                cout<<heap[i]<<" ";
            }
            cout<<endl;
        }
        bool DecreaseKey(int index,int val)
        {
            if(index<0||index>=heap.size()) return 0;
            heap[index]=val;
            Heapify(index);
        }
};
int main()
{
    vector<int> nums{10,2,4,5,12,42,131,32,1,23,6,78,9};
    MinHeap hp;
    for(int i=0;i<nums.size();i++)
    {
        if(i%6==1)
        {
            cout<<"extractMin:"<<hp.extractMin()<<endl;
            hp.DumpContent();
        }
        if(i%7==0)
        {
            cout<<"DecreaseKey:"<< i-5 <<" to "<<1<<endl;
            hp.DecreaseKey(i-5,1);
            hp.DumpContent();
        }
        cout<<"insert:"<<hp.insert(nums[i])<<endl;
        cout<<"Min:"<<hp.getMin()<<endl;
        hp.DumpContent();
    }
    return 0;
}
