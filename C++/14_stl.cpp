#include<bits/stdc++.h>

void pair_function()
{
    std::pair<int,int> p;
    p.first = 2;
    p.second = 3;
    std::cout<<"pair: "<<p.first<<":"<<p.second<<std::endl;
    std::pair<int,std::pair<int,int>> p2; // storing more then 2 values in array.
    p2.first = 2;
    p2.second.first = 3;
    p2.second.second = 3;
    std::cout<<"pair: "<<p2.first<<":"<<p2.second.first<<std::endl;
    std::pair<int,int> arr[10]={{1,2},{3,4},{5,6},{7,8}} ;//This is pair array.
}

void vector_function()
{

    std::vector<int> v;
    v.push_back(10);
    v.push_back(20); // difference in emplace vs push_back [in emplace_back you can dynamically allocate the emory for netx elelment.]
    v.emplace_back(30);

    std::vector<std::pair<int,int>> v2;
    v2.push_back({1,2});
    v2.emplace_back(1,2);
    
    std::vector<int> v3(v);
    std::vector<std::pair<int,int>> v4(v2);

    std::cout<<"vector print \n";
    std::vector<int> :: iterator vi1;
    std::vector<int> :: iterator vi12;
    vi1=v.begin();
    vi1=v.end();
    //vi12=v.rend();
    //vi12=v.rbegin();
    std::cout<<*vi1<<",";
    vi1++;
    
    std::cout<<"\n";

    for (std::vector<int>::iterator vi3 = v.begin(); vi3!=v.end();vi3++)
    {
        std::cout<<"value"<<" : "<<*vi3<<"\n";
    }

    for (auto vi3 = v.begin(); vi3!=v.end();vi3++)
    {
        std::cout<<"value"<<" : "<<*vi3<<"\n";
    }
    for (auto vi3 : v)
    {
        std::cout<<"value"<<" : "<<vi3<<"\n";
    }

    std::cout<<v.back()<<"\n";
    v.erase(v.begin());   //deletion
    v.erase(v.begin(),v.end()-1);   //deletion
    v.push_back(12);
    v.insert(v.end(),5);
    v.insert(v.end(),3,100);
    
    for (auto vi3 : v)
    {
        std::cout<<"value"<<" : "<<vi3<<"\n";
    }

    v.pop_back();
    for (auto vi3 : v)
    {
        std::cout<<"value"<<" : "<<vi3<<"\n";
    }
}

void list_function()
{
    std::list<int> l1;
    l1.push_back(10);
    l1.push_front(10);
    l1.emplace_front(20);
}


void deque_function()
{
    std::deque<int> d1;
    d1.push_back(10);
    d1.push_front(10);
    d1.emplace_front(20);
}

void satck_function()
{   
    std::stack<int> l1;
    l1.push(10);
    l1.push(20);
    l1.push(30);
    l1.pop();
    std::cout<<l1.top();
    l1.pop();
    std::cout<<l1.size();
    std::cout<<l1.empty();
}

void queue()
{
    std::queue<int> q;
    q.push(10);
    q.push(20);
    std::cout<<q.back();
}

void priority_queue()
{
    std::priority_queue<int> pq;
    pq.push(10);
    pq.push(3);
    pq.push(6);
    pq.emplace(12);
    pq.push(11);
    
    std::cout<<pq.top()<<"\n";
    std::priority_queue<int,std::vector<int>,std::greater<int>> pq1;
    pq1.push(3);
    pq1.push(6);
    pq1.emplace(12);
    pq1.push(11);
    
    std::cout<<pq1.top()<<"\n";
}
void set_function()
{
    std::set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);
    set1.insert(5);

    auto it =  set1.find(4);
    std::cout<<*it<<std::endl;
    
    std::cout<<*it<<std::endl;
    for(auto t : set1)
    {
        std::cout<<t<<"\n";
    }
    set1.erase(it);

    std::multiset<int> set2;
    set2.insert(10);
    set2.insert(20);
    set2.insert(30);
    set2.insert(40);
    set2.insert(10);
    set2.insert(10);
    std::cout<<set2.count(10)<<"\n";
    set2.erase(set2.find(10));

    std::unordered_set<int> set3;
    set3.insert(40);
    set3.insert(10);
    set3.insert(30);
    set3.insert(10);
    set3.insert(10);
    set3.insert(20);

    for(auto t : set3)
    {
        std::cout<<t<<"\n";
    }
}

void map_function()
{
    std::map<int,int> mp1;
    std::map<std::pair<int,int>,int> mp2; //stores key in dsorted order.

    mp2.insert({{1,2},3});
    mp2[{10,4}] =6;
    for (auto t : mp2)
    {
        std::cout<<t.first.first;
    }

    if (mp2.find({2,3}) ==mp2.end())
        std::cout<<"Not found\n";
    
    if (mp2.find({1,2}) !=mp2.end())
        std::cout<<"found\n";

    std::multimap<int,int> mp3;
    std::unordered_map<int,int> map4;


}

bool comp(std::pair<int,int>p1,std::pair<int,int>p2)
{
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    if (p1.first < p2.first) return true;
    return false;
}

void algorithm()
{
    int a[] = {1,2,6,7,2,6};
    std::vector<int> v = {1,2,6,7,2,6};
    std::sort(a,a+6);
    for (auto i : a)
    {
        std::cout<<i;
    }
    std::sort(v.begin(),v.end());
    //std::sort(a,a+6,std::greater<int>);

    std::pair<int,int> arr[] = {{1,2},{3,4},{2,2}};
    std::sort(arr,arr+3,comp) ;
    for (auto i : arr)
    {
        std::cout<<i.first<<i.second;
    }

    int *max = std::max_element(a,a+6);
    int *min = std::min_element(a,a+6);
    std::cout<<max;
    std::cout<<min;

}

void bits_function()
{

    int x = 13584840;
    std::cout<<__builtin_popcount(x);

}

int main()
{   
    
    //pair_function();
    //vector_function();
    //priority_queue();
    //set_function();
    //map_function();
    //algorithm();
    bits_function();


    return 0;
}

