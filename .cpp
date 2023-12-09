#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    int n;
    cout << "Введiть кiлькiсть елементiв масиву: ";
    cin >> n;

    if (n <= 0) {
        cout << "Розмiр масиву повинен бути бiльше 0" << endl;
        return 1;
    }

    vector<int> array(n);

    cout << "Введiть елементи масиву:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Елемент " << i + 1 << ": ";
        cin >> array[i];
    }

    auto minModElement = min_element(array.begin(), array.end(),
        [](int a, int b) {
            return abs(a) < abs(b);
        }
    );

    int minModIndex = distance(array.begin(), minModElement);
    cout << "Номер елемента з мiнiмальним модулем: " << minModIndex + 1 << endl;

    auto negElement = find_if(array.begin(), array.end(),
        [](int a) {
            return a < 0;
        }
    );

    if (negElement != array.end()) {
        int sumOfMods = 0;
        for (auto it = negElement + 1; it != array.end(); ++it) {
            sumOfMods += abs(*it);
        }
        cout << "Сума модулiв елементiв пiсля першого вiд'ємного: " << sumOfMods << endl;
    }
    else {
        cout << "В масивi вiдсутнi вiд'ємнi елементи" << endl;
    }

    int a, b;
    cout << "Введiть iнтервал [a, b] для видалення елементiв: ";
    cin >> a >> b;

    auto removeCondition = [a, b](int elem) {
        return elem >= a && elem <= b;
        };

    auto newEnd = remove_if(array.begin(), array.end(), removeCondition);
    fill(newEnd, array.end(), 0);

    cout << "Масив пiсля видалення елементiв:\n";
    for (const auto& elem : array) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
