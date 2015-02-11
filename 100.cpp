#include <iostream>

using namespace std;

int count_cycle(int num) {
    int count = 1;
    while(num != 1) {
        if ((num % 2) == 0) {
            num = num/2;
        }
        else {
            num = 3*num + 1;
        }
        count++;
    }
    return count;
}

int main(){
    int num1, num2, temp, tmax, max, flag;
    while(cin >> num1 >> num2) {
        flag = 0;
        if (num1 > num2) {
            //swap numbers
            temp = num1;
            num1 = num2;
            num2 = temp;
            flag = 1;
        }
        temp = num1;
        max = count_cycle(temp);
        while(++temp <= num2) {
            tmax = count_cycle(temp);
            if (tmax > max) {
                max = tmax;
            }
        }

        if (flag) {
            cout << num2  << " " << num1 << " " << max << "\n";
        }
        else {
            cout << num1 << " " << num2 << " " << max << "\n";
        }
    }
    return 0;
}
