// 10003CuttingSticks.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>

using namespace std;

//int l, nc;
//vector<int> locations;

/*int makeCut(int start, int end, int lStart, int lEnd) {

	if (start > end) {
		return 1;
	}

	float average = (lStart + lEnd / 2) + lStart;

	int low = start, high = end;
	float smallestDifference = l;
	int smallestDifferenceIndex = low;
	while (low <= high) {
		int middle = (low + high) / 2;
		float diff = average - locations.at(middle);
		if (abs(diff) < smallestDifference) {
			smallestDifferenceIndex = middle;
			if (diff < 0) {
				high = middle - 1;
			}
			else if (diff > 0) {
				low = middle + 1;
			}
			else {
				smallestDifferenceIndex = middle;
				break;
			}
		}
		else {
			break;
		}
	}
	
	cout << "cutting at: " << locations.at(smallestDifferenceIndex) << " start: " << start << " end: " << end << " average = " << average << " remaining sticks = (" << (lEnd - lStart) - (locations.at(smallestDifferenceIndex) - lStart) << ", " << (lEnd - lStart) - (lEnd - locations.at(smallestDifferenceIndex)) << ")" << " cost = " << (lEnd - lStart) <<  endl;

	makeCut(start, smallestDifferenceIndex - 1, lStart, locations.at(smallestDifferenceIndex));
	makeCut(smallestDifferenceIndex + 1, end, locations.at(smallestDifferenceIndex), lEnd);

	return 1;
}

int main1()
{
	cin >> l >> nc;

	for (int i = 0; i < nc; i++) {
		int loc;
		cin >> loc;
		locations.push_back(loc);
	}

	makeCut(0, nc - 1, 0, l);

	//l = l - locations.at(smallestDifferenceIndex);

	//cout << "answer is: " << smallestDifferenceIndex << " new length is: " << l << endl;

	cout << endl;

    return 0;
}

*/