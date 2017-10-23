/**
 * 最长公共子序列
 */
 
#include <string>  
#include <vector>  
#include <iostream>  
  
using namespace::std;  
  
int lcs(string str1, string str2, vector<vector<int>>& vec) {  
    int len1 = str1.size();  
    int len2 = str2.size();  
    vector<vector<int>> c(len1 + 1, vector<int>(len2 + 1, 0));  
    for (int i = 0; i <= len1; i++) {  
        for (int j = 0; j <= len2; j++) {  
            if (i == 0 || j == 0) {  
                c[i][j] = 0;  
            }  
            else if (str1[i - 1] == str2[j - 1]) {  
                c[i][j] = c[i - 1][j - 1] + 1;  
                vec[i][j] = 0;  
            }  
            else if (c[i - 1][j] >= c[i][j - 1]){  
                c[i][j] = c[i - 1][j];  
                vec[i][j] = 1;  
            }  
            else{  
                c[i][j] = c[i][j - 1];  
                vec[i][j] = 2;  
            }  
        }  
    }  
  
    return c[len1][len2];  
}  
  
void print_lcs(vector<vector<int>>& vec, string str, int i, int j)  
{  
    if (i == 0 || j == 0)  
    {  
        return;  
    }  
    if (vec[i][j] == 0)  
    {  
        print_lcs(vec, str, i - 1, j - 1);  
        printf("%c", str[i - 1]);  
    }  
    else if (vec[i][j] == 1)  
    {  
        print_lcs(vec, str, i - 1, j);  
    }  
    else  
    {  
        print_lcs(vec, str, i, j - 1);  
    }  
}  
  
int main()  
{  
    string str1 = "123456";  
    string str2 = "2456";  
    vector<vector<int>> vec(str1.size() + 1, vector<int>(str2.size() + 1, -1));  
    int result = lcs(str1, str2, vec);  
  
    cout << "result = " << result << endl;  
  
    print_lcs(vec, str1, str1.size(), str2.size());  
  
    getchar();  
    return 0;  
}  