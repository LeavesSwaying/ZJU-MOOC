//��Ŀ���⣺����ջ��������� ���еĳ��� �������������� �ж�ÿ�����������Ƿ��ܹ��ɸ�ջ�õ�
//˼·��
//1.ʹ��stl�е�stack stack��size������������ȷ�� ��1����˳��������ջ ��2��ջ��Ԫ�ص��ڵ�ǰ��ջ����Ԫ��ʱ ��ջ��Ԫ�س�ջ ��3���������ʱ��ջ
//2.������ջ������ʱ ��Ԫ��ȫ����ջ ��ջ��Ԫ�ز����ڵ�ǰ��ջԪ��ʱ �ж�ΪNO ��4����ȫ��Ԫ����ջ ��ջ���б������ ջΪ��ʱ �ж�Ϊyes

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

