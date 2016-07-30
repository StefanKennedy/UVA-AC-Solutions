
/*#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memory;

int findCycleLength(int num) {

	if (num == 1) {
		return 1;
	}

	if (memory.find(num) != memory.end()) {
		return memory[num];
	}

	int originalNum = num;
	int i = 1;

	if (num % 2) {
		i += findCycleLength((num * 3) + 1);
	}
	else {
		i += findCycleLength(num / 2);
	}

	memory[originalNum] = i;

	return i;

}

int main()
{

	int a, b;

	while (scanf("%d%d", &a, &b) != EOF) {

		int start = a;
		int end = b;

		if (start > end) {
			int temp = start;
			start = end;
			end = temp;
		}

		int max = 0;

		for (int i = start; i <= end; i++) {
			int length = findCycleLength(i);
			max = (max > length ? max : length);
		}

		cout << a << " " << b << " " << max << endl;

	}

    return 0;
}
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
int main() {
	int i, j, k, m, counter, max;
	bool ok = true;
	vector<string> vect;
	while (cin >> i && cin >> j) {
		//  cout<<"\n";

		if (i == -10) {
			break;
		}
		if (i>j) {
			counter = i;
			i = j;
			j = counter;
			ok = false;
		}

		max = 0;
		counter = 1;
		for (k = i; k <= j; k++) {
			counter = 1;
			m = k;
			while (m != 1) {
				if (m % 2 == 0)
					m /= 2;
				else if (m % 2 == 1)
					m = (m * 3 + 1);
				counter++;
			}
			if (counter > max)
				max = counter;
		}
		//  cout<<i << " " << j << " " <<max<< "\n";
		if (ok == false) {
			counter = i;
			i = j;
			j = counter;
		}
		vect.push_back(to_string(i) + string(" ") + to_string( j)  + string(" ") + to_string(max));
	}
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << endl;
	}
	cout << endl;
	return 0;
}
