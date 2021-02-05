// main.cpp
#include <cstdio>
#include <iostream>

using namespace std;

void showOption()
{
    cout << "?????¨´??????????" << endl;
    cout << "1--?????????????" << endl; // input(int a[], int *n)  //??????
    cout << "2--?????????" << endl; // output(int a[], int n)  //?????
    cout << "3--?????????????????" << endl; // bubbleUP(int a[], int n)  //???
    cout << "4--???????????§³???????" << endl; // maxmin(int a[], int n) //????????
    //??????????????????????
    cout << "5--??????????????"
         << endl; // maxOnce(int a[], int n)  //lh&rh??? ?›¥max ????????????????
    cout << "6--??????????????" << endl; // maxMore(int a[], int n)
    cout << "7--???" << endl;
}

// Your code here
void input(int a[], int* n);
void output(int a[], int n);
void bubbleUP(int a[], int n);
void maxmin(int a[], int n);
void maxOnce(int a[], int n);
void maxMore(int a[], int n);

int main()
{
    int stockPrice[10] = {}, d = 0;
    int option = 0;

    showOption();
    // Your code here
    while (1) {
        cin >> option;
        switch (option) {
        case 1: {
            input(stockPrice, &d);
            // cout << "__" << d;
            // for(int i = 0; i < 10; i++)
            //     cout << stockPrice[i];
            break;
        }
        case 2: {
            output(stockPrice, d);
            break;
        }
        case 3: {
            bubbleUP(stockPrice, d);
            break;
        }
        case 4: {
            maxmin(stockPrice, d);
            break;
        }
        case 5: {
            maxOnce(stockPrice, d);
            break;
        }
        case 6: {
            maxMore(stockPrice, d);
            break;
        }
        case 7:
            return 0;
        }
    }
}

void input(int a[], int* n) // option 1
{
    //??????????????????????
    if (a[0]) {
        for (int i = 0; i < 10; i++) {
            a[i] = 0;
        }
    }
    //????
    int in, i = 0;
    cin >> in;
    while (in != -1) {
        a[i] = in;
        i++;
        cin >> in;
        // cout << i << endl;
    }
    *n = i;
}

void output(int a[], int n) // option 2
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void bubbleUP(int a[], int n) // option 3
{
    int b[10] = {};
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    // bubble
    for (int rh = n - 1; rh > 0; rh--) {
        for (int lh = 0; lh < rh; lh++) {
            if (b[lh] > b[lh + 1]) {
                int tmp = b[lh + 1];
                b[lh + 1] = b[lh];
                b[lh] = tmp;
            }
        }
    }
    // print b
    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << endl;
}

void maxmin(int a[], int n) // option 4
{
    int max = 0, min = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[max])
            max = i;
        if (a[i] < a[min])
            min = i;
    }

    cout << max << ' ' << min << endl;
}

void maxOnce(int a[], int n) // option 5
{
    int max = 0;
    for (int lh = 0; lh < n - 1; lh++) {
        for (int rh = lh + 1; rh < n; rh++) {
            if (max < a[rh] - a[lh])
                max = a[rh] - a[lh];
        }
    }

    cout << max << endl;
}

void maxMore(int a[], int n)
{
    int max = 0; //???????????
    int rst = 0;
    // C2 n first
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            rst = a[j] - a[i];
            if (rst > max)
                max = rst;
        }
    }

    // C4 n then
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            for (int p = j + 1; p < n - 1; p++) {
                for (int q = p + 1; q < n; q++) {
                    rst = a[q] - a[p] + a[j] - a[i];
                    if (rst > max)
                        max = rst;
                }
            }
        }
    }

    cout << max << endl;
}