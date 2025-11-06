bool isSquareRoot(unsigned number) {
    for (unsigned i = 0; i <= number / 2; i++) {
        if (i * i == number) {
            return true;
        }
    }
    return number == 1;
}

int main() {
    int n;
    cin >> n;
    cout << isSquareRoot(n) << endl;
}
