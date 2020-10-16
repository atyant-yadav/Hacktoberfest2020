#include <iostream>

using namespace std;

void hollowTriangle(int n, bool inverted = false, bool skipExtremeRowMiddleStars = false, bool addExtraSpaceInInverted = false) {
    /*
     * PATTERN - 4
     *
     *      *
     *     * *
     *    *   *
     *   * * * *
     *
     *     or
     *
     *   * * * *
     *    *   *
     *     * *
     *      *
     */

    if (!inverted) {
        for (int i = 0; i < n; ++i) {
            int spaceCount = n - i - 1;
            int starCount = i == 0 ? 1 : i == (n - 1) && !skipExtremeRowMiddleStars ? n : 2;
            int starSpacing = (i == (n - 1) && !skipExtremeRowMiddleStars ? 0 : (2 * i) - 1);
            while (spaceCount > 0) {
                --spaceCount;
                cout << ' ';
            }
            while (starCount > 0) {
                cout << '*';
                if (starCount == 1 || (i == n - 1 && !skipExtremeRowMiddleStars)) {
                    cout << ' ';
                }
                while (starSpacing > 0) {
                    --starSpacing;
                    cout << ' ';
                }
                --starCount;
            }
            cout << endl;
        }
    } else {
        for (int i = n - 1; i >= 0; --i) {
            int spaceCount = n - i - (addExtraSpaceInInverted ? 0 : 1);
            int starCount = i == 0 ? 1 : i == (n - 1) && !skipExtremeRowMiddleStars ? n : 2;
            int starSpacing = (i == (n - 1) && !skipExtremeRowMiddleStars ? 0 : (2 * i) - 1);
            while (spaceCount > 0) {
                --spaceCount;
                cout << ' ';
            }
            while (starCount > 0) {
                cout << '*';
                if (starCount == 1 || (i == (n - 1) && !skipExtremeRowMiddleStars) ) {
                    cout << ' ';
                }

                while (starSpacing > 0) {
                    --starSpacing;
                    cout << ' ';
                }
                --starCount;
            }
            cout << endl;
        }
    }
}

void solidTriangle (int n, bool invert = false, bool addExtraSpaceInInverted = false) {
 /*
 *  PATTERN - 1
 *
 *     *
 *    ***
 *   *****
 *  *******
 *
 *     or
 *
 *  *******
 *   *****
 *    ***
 *     *
 */

    if (!invert) {
        for (int i = 0; i < n ; ++i) {
            int spaceCount = n - i - 1;
            int starCount = 2 * i + 1;
            while (spaceCount > 0) {
                --spaceCount;
                cout << ' ';
            }
            while (starCount > 0) {
                --starCount;
                cout << '*';
            }
            cout << endl;
        }
    } else {
        for (int i = n; i > 0 ; --i) {
            int spaceCount = n - i + (addExtraSpaceInInverted ? 1 : 0); // this extra +1 is used so that this can also be used in pattern2
            int starCount = 2 * i - 1;
            while (spaceCount > 0) {
                --spaceCount;
                cout << ' ';
            }
            while (starCount > 0) {
                --starCount;
                cout << '*';
            }
            cout << endl;
        }
    }
}

void triangleUpsideDown(int n, bool isHollow = false) {

 /*
 *  PATTERN - 2
 *
 *     *
 *    ***
 *   *****
 *  *******
 *   *****
 *    ***
 *     *
 *
 *     or
 *
 *     *
 *    * *
 *   *   *
 *  *     *
 *   *   *
 *    * *
 *     *
 */

    bool is_even = (n % 2 == 0);
    int upperTriangleHeight = is_even ? n / 2 : (n + 1) / 2;
    if (isHollow) {
        hollowTriangle(upperTriangleHeight, false, true);
        hollowTriangle(n - upperTriangleHeight, true, true, !is_even);
    } else{
        solidTriangle(upperTriangleHeight);
        solidTriangle(n - upperTriangleHeight, true, !is_even);
    }
}

void square(int w, int h, bool hollow = false) {
    /*
     * PATTERN - 3
     *
     *    * * * * *
     *    * * * * *
     *    * * * * *
     *    * * * * *
     *
     *      or
     *
     *    * * * * *
     *    *       *
     *    *       *
     *    * * * * *
     */

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (hollow) {
                if (j == 0 || j == (w - 1) || i == 0 || i == (h - 1)) {
                    cout << (j == (w - 1) ? "*" : "* ");
                } else {
                    cout << "  ";
                }
            } else {
                cout << (j == (w - 1) ? "*" : "* ");
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter no. of rows: ";
    cin >> n;
    return 0;
}

