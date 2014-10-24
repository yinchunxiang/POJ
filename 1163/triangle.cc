#include <iostream>
#include <vector>

using namespace std;


int main(int argc, const char *argv[])
{
    int num_line = 0;
    vector<vector<int> > triangle;
    cin >> num_line;
    for (int i = 0; i < num_line; ++i) {
        vector<int> v(i + 1, 0);
        for (int j = 0; j <= i; ++j) {
            cin >> v[j];
            //cout << v[j] << " ";
        }
        //cout << endl;
        triangle.push_back(v);
    }

    for (int i = num_line - 2; i >= 0; --i) {
        for (int j = i; j >= 0; --j) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
            //cout << "triangle[" << i << "][" << j << "]: " << triangle[i][j] << " ";
        }
        //cout << endl;
    }
    cout << triangle[0][0] << endl;

    return 0;
}



