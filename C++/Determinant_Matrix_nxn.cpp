/*
    ** This program prompts user a matrix with n x n ordo, then it will
    ** compute its determinant. limit of n is size of (int).
    ** no validation prompts yet
    ** by zukarusan -github
*/

#include <bits/stdc++.h>
using namespace std;

double getDet(vector<vector<double>> elem, int n);

//Create a whole class for matrix itself
class matrix {
    int n;
    vector<vector<double>> elem;
    double det;

public:
    //The beginning constructor, also prompting a new matrix
    matrix() {
        setMatrix();
    }

    // Separated determinant search function
    // beyond class for further purpose
    friend double getDet(vector<vector<double>>elem);

    // Prompt a new matrix
    void setMatrix() {
        cout << "How many is \'n\' in ordo notation nxn: ";
        cin >> n;
        elem.clear();
        elem.resize(n);
        double temp;
        cout << "Input the elements:\n"; 
        for (auto &ele: elem) {
            ele.resize(n);
            for (auto &el : ele) {
                cin >> temp;
                el = temp;
            }
        }
        det = getDet(this->elem, this->n);
    }

    double getDetVal() {
        return det;
    }

    // Print this matrix
    void printMatrix() {
        for (auto row : elem)
        {
            cout << "|";
            size_t counter = 0;
            for (auto el : row)
            {
                cout << fixed << setprecision(1) << el;
                if (counter != n-1)
                    cout << setw(8);
                counter++;
            }
            cout  << "|\n";
        }
    } 
};


int main() {
    matrix ma;
    cout << endl << "Inputted matrix:\n";
    ma.printMatrix();
    cout << endl << "Its determinant: " << ma.getDetVal();
    
}

// Determinant searching using minor methods rather permutation.
// The scheme is to parse the determinant from its submatrix of
// each pivot of the first row.
double getDet(vector<vector<double>>elem, int n) {
    // if just one element, return it
    if (n == 1)
        return elem[0][0];
    else {
        // Create pivots with the amount of the matrix ordo,
        // which is n
        vector<vector<vector<double>>>new_elem(n);
        double det = 0;
        // Parsing the element into submatrix each pivot
        for (size_t i = 0; i < n; i++)
        {
            new_elem[i].resize(n-1);
            for (size_t j = 1; j < n; j++)
            {
                new_elem[i][j-1].resize(n-1);
                for (size_t k = 0, j_= 0; k < n; k++)
                {
                    if (i != k) {
                        new_elem[i][j-1][j_]= elem[j][k];
                        j_++;
                    }
                }
            }
        }

        // Summing/subtracting each pivot times its
        // submatrix's determinant
        // as the minor method suggests 
        for (size_t i = 0; i < n; i++)
        {
            if (i%2 == 0)
                det += ( elem[0][i] * getDet(new_elem[i], n-1 ));
            else
                det -= ( elem[0][i] * getDet(new_elem[i], n-1 ));
        }
        return det;
    }
}