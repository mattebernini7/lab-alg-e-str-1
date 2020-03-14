#include <iostream>
#include <vector>
using namespace std;

/*int k_piu_frequente(std::vector<int> & v)
{
    int max = 0;
    int k = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        int conta = 0;
        for (int j = 0; j < v.size() ; ++j) {
            if(v[i] == v[j])
                conta++;
        }
        if(conta > max)
        {
            max = conta;
            k = v[i];
        }
    }
    return k;
}*/
//***********************************************************************************
void sort(vector<int> & bar);
void mergeSort(vector<int>&left, vector<int>& right, vector<int>& bars);

void sort(vector<int> & bar) {
    if (bar.size() <= 1) return;

    int mid = bar.size() / 2;
    vector<int> left;
    vector<int> right;

    for (size_t j = 0; j < mid;j++)
        left.push_back(bar[j]);
    for (size_t j = 0; j < (bar.size()) - mid; j++)
        right.push_back(bar[mid + j]);

    sort(left);
    sort(right);
    mergeSort(left, right, bar);
}

void mergeSort(vector<int>&left, vector<int>& right, vector<int>& bars)
{
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR)
    {
        if (left[j] < right[k]) {
            bars[i] = left[j];
            j++;
        }
        else {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL) {
        bars[i] = left[j];
        j++; i++;
    }
    while (k < nR) {
        bars[i] = right[k];
        k++; i++;
    }
}
//************************************************************************************

int k_piu_frequente(std::vector<int> & v)
{
    sort(v);
    int max = 0;
    int k = 0;
    int conta = 0;
    for (int i = 1; i <= v.size(); ++i)
    {
        if(v[i] == v[i-1])
            conta++;
        else
        {
            if(conta > max)
            {
                max = conta;
                k = v[i];
            }
            conta = 0;
        }
    }
    return k;
}

int main()
{
    int len;
    std::vector<int> arr;
    cout << "numero elementi?  ";
    cin >> len;
    cout << "inserisci valori:\n";
    int val;
    for( int i = 0 ; i < len ; ++i )
    {
        cin >> val;
        arr.push_back(val);
    }
    cout << "\n\n\n" << k_piu_frequente(arr);
}