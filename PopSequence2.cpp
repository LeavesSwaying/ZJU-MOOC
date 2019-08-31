//题目大意：给出栈的最大容量 数列的长度 测试样例的数量 判断每个测试序列是否能够由该栈得到
//思路：
//1.使用stl中的stack stack的size按照题设条件确定 （1）按顺序将数字入栈 （2）栈顶元素等于当前出栈序列元素时 将栈中元素出栈 （3）当不相等时入栈
//2.当超过栈的容量时 当元素全部入栈 而栈顶元素不等于当前出栈元素时 判断为NO （4）当全部元素入栈 出栈序列遍历完后 栈为空时 判断为yes

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int m, n, k;
    cin >> m >> n >> k;

    while (k--) {
        int flag = 1;
        stack<int> st;
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            cin >> temp[i];
        }
        int t = 0;
        for (int i = 0; i < n; i++) {
            st.push(i+1);
            if (st.size() > m) {
                flag = 0;
                break;
            }
            while(st.top() == temp[t]) {
                st.pop();
                t++;
                if (st.empty()) {
                    break;
                }
            }
        }
        if (!st.empty()) {
            flag = 0;
        }
        if (flag) {
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

    }

}

