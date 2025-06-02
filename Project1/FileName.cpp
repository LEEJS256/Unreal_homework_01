#include <iostream>
#include <vector>
#include <map>


using namespace std;

struct Movie {
    string title;
    double rating;
};



int Sum_Num(int a, int b) {
    return a + b;
}

void print_vec(const vector<int>& p_vec){
    //for (int i = 0; i < p_vec.size(); i++)
    //{
    //    if (i == p_vec.size() - 1)
    //    {
    //        cout << p_vec[i] << endl;
    //    }
    //    else
    //    {
    //        cout << p_vec[i] << " ";
    //    }
    //}
    for (size_t i = 0; i < p_vec.size(); ++i) {
        cout << p_vec[i];
        if (i != p_vec.size() - 1)
            cout << " ";
    }
}

 int Sum_vec_Num(const vector<int>&p_vec) {
    int i_sum = 0;
    for (int i = 0; i < p_vec.size(); i++)
    {
        i_sum += p_vec[i];
    }
    return i_sum;
}

float Avg_vec_Num(const vector<int>& p_vec) {
    int i_sum = 0;
    for (int i = 0; i < p_vec.size(); i++)
    {
        i_sum += p_vec[i];
    }
    return i_sum / (float)p_vec.size();
}

void func_02(const vector<int>& p_vec) {
    cout << "===========================================" << endl;
    cout << "합계:" << Sum_vec_Num(p_vec) << endl;
    cout << "평균:" << Avg_vec_Num(p_vec) << endl;
    cout << "===========================================" << endl;

}
//내림차순
void func_sort(vector<int>& p_vec) {
    int i_sort =0;
    cout << "오름차순은 1번, 내림차순은 2번을 입력하세요" << endl;
    cin >> i_sort;
    int i_vec_size = p_vec.size();
    if (i_sort == 1) //오름차순
    {
        
        for (int i = 0; i < i_vec_size - 1; i++)
        {
            for (int j = 0; j < i_vec_size - 1; j++)
            {
                if (p_vec[j] > p_vec[j + 1])
                {
                    int temp = p_vec[j];
                    p_vec[j] = p_vec[j + 1];
                    p_vec[j + 1] = temp;
                }
            }
        }
    }
    else if(i_sort)//내림차순
    {
        for(int i = 0; i < i_vec_size - 1; i++)
        {
            for (int j = 0; j < i_vec_size - 1; j++)
            {
                if (p_vec[j] < p_vec[j + 1])
                {
                    int temp = p_vec[j];
                    p_vec[j] = p_vec[j + 1];
                    p_vec[j+1] = temp;
                }
            }
        }
    }


}



void Input_vec_num(vector<int>& p_vec) { 
    //const 뺀이유 그대로 벡터에 넣을려고
    //cout << "숫자 5개를 하나씩 입력하세요" << endl;

    int input_value = 0;
    int i_size = 0;
    cout << "사이즈 입력:" << endl;
    cin >> i_size;
    for (int i = 1; i <= i_size; ++i)
    {
        cout << i << "번째 숫자를 입력하세요" << endl;
        cin >> input_value;
        p_vec.push_back(input_value);
    }

  
}

int main() {
    vector<int> m_vec_Input_num;

    Input_vec_num(m_vec_Input_num);

    //for (int i = 0; i < m_vec_Input_num.size(); i++)
    //{
    //    cout << "check" << endl;
    //    cout << m_vec_Input_num[i] << endl;
    //}

    func_02(m_vec_Input_num);
    func_sort(m_vec_Input_num);
    print_vec(m_vec_Input_num);

    return 0;
}