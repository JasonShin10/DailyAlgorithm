#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<int> st;
int solution(vector<int> elements) {
    int answer = 0;
    int sum =0;
    // 몇개씩 더할껀지
    for(int k=0; k<elements.size(); k++)
    {
        // 자리수 (0번째 부터 3번째까지, 1번째 부터 4번째까지)
       for(int i=0; i<elements.size(); i++)
       {
           // (0번째 부터 3번째 까지 더하기)
        for(int j=i; j<=i+k; j++)
        {
            int cnt = j;
            if(j >= elements.size())
            {
                cnt = j-elements.size();
            }
            sum += elements[cnt];
        }
        st.insert(sum);
        sum =0;
       }
    }
   
    answer = st.size();
    return answer;
}
