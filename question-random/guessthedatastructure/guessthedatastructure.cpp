#include <bits/stdc++.h>
using namespace std;

int main() {
    while (!(std::cin >> std::ws).eof()){
            int t;
            cin>>t;
            vector<bool> cmd(t);
            vector<int> result(t);
            for(int i=0; i<t; i++){
                int a,b;
                cin>>a>>b;
                cmd[i] = (a==1) ? true : false ;
                result[i]=b;
            }
            stack <int> s;
            queue <int> q;
            priority_queue<int> pq;
            bool isStk=true, isQue=true, isPriQue=true, flag = false;
            
            for(int i=0; i<t; i++){
                if(cmd[i]){
                    s.push(result[i]);
                    q.push(result[i]);
                    pq.push(result[i]);
                }else{
                    if(s.size()>0 && q.size()>0 && pq.size()>0){
                        if(isStk &&  s.top() != result[i])
                            isStk=false;
                        
                        if(isQue && q.front() != result[i])
                            isQue=false;
                            
                        if(isPriQue && pq.top() != result[i])
                        isPriQue=false;
                    
                        s.pop();
                        q.pop();
                        pq.pop();
                    }else{
                        flag = true;
                    }
                }
            }
            
            if(flag || (!isStk && !isQue && !isPriQue))
                cout<<"impossible"<<endl;
                
            else if((isStk && isQue) || (isPriQue && isStk) || (isQue && isPriQue))
                cout<<"not sure"<<endl;
            
            else if(isStk) cout<<"stack"<<endl;
            else if(isQue) cout<<"queue"<<endl;
            else if(isPriQue) cout<<"priority queue"<<endl;
    }
    return 0;
}