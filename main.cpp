#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {
  while (true) {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    cout << "AUTOMATED BUBBLE SORT";
    cout << "\n";
    cout << "\n";

    int n = 0;
    while (n <= 0) {
      cout << "Input your size of array: ";
      cin >> n;
    }

    vector<int> a(n);

    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<int> d(-2000000000, 2000000000);

    for (int i = 0; i < n; ++i) {
      a[i] = d(g);
    }

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1 - i; j++) {
        if (a[j] > a[j + 1]) {
          int temp = a[j];
          a[j] = a[j + 1];
          a[j + 1] = temp;
        }
      }
    }

    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> duration = end - start;
    cout << "Execution time: " << duration.count() << " seconds.";
    cout << "\n";
    cout << "\n";

    cout << "Do you want to restart?";
    cout << "\n";
    cout << "1) Yes";
    cout << "\n";
    cout << "2) No";
    cout << "\n";

    int quit_or_no = 0;
    while (quit_or_no != 1 && quit_or_no != 2) {
      cout << "Choose between 1 and 2: ";
      cin >> quit_or_no;
    }

    if (quit_or_no == 2) {
      break;
    }
  }

  return 0;
}