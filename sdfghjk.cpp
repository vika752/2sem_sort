#include <iostream>

//сортировка выбором
int selection_sort(int* a, int n) {
    int max_elem = a[0];
    for (int i = 1; i < n; ++i) {
        max_elem = std::max(max_elem, a[i]);
    }
    int* counter = new int[max_elem + 1];
    for (int i = 0; i < n; ++i) {
        counter[a[i]]++;
    }
    int current_index = 0;
    for (int i = 0; i <= max_elem; ++i) {
        for (int j = 0; j < counter[i]; ++j) {
            a[current_index++] = i;
        }
    }
}

//быстрая сортировка
void quick_sort(int* a, int n) {
    if (n <= 1) {
        return;
    }
    if (!(a[0] <= 10 && 1 <= a[0])) {
        return;
    }
    int p_index = n / 2 + n % 2;
    int p = a[p_index];
    int left_pointer = 0;
    int right_pointer = n - 1;

    while (left_pointer <= right_pointer) {
        if (a[left_pointer] > p) {
            int t = a[left_pointer];
            a[left_pointer] = a[right_pointer];
            a[right_pointer] = t;
            --right_pointer;
        } else {
            ++left_pointer;
        }
    }
    int new_p_place = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == p) {
            new_p_place = i;
            break;
        }
    }
    // left pointer будет указывать на первый, > p ,если такой есть, иначе - на конец массива
    if (left_pointer == n) {
        int t = a[left_pointer - 1];
        a[left_pointer - 1] = a[new_p_place];
        a[new_p_place] = t;
        //ставим p в конец
        quick_sort(a, n - 1);
        return;
    }
    --left_pointer;
    // на посл указывает p
    int t = a[left_pointer];
    a[left_pointer] = a[new_p_place];
    a[new_p_place] = t;
    quick_sort(a, left_pointer);
    quick_sort(a + left_pointer + 1, n - (left_pointer + 1));
}

int main() {
    int n;
    std::cin >> n;
    int* a = new int[n];
    int t, r;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    quick_sort(a, n);
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
}
