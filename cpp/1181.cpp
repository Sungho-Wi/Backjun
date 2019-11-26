#include <iostream>
#include <string>

using namespace std;

string *str = NULL;
string *sortStr = NULL;

void sort(int left, int mid, int right) {
	int k = left;
	int i = left;
	int j = mid+1;

	while (i <= mid && j <= right) {
		if (str[i].length() < str[j].length())
			sortStr[k++] = str[i++];
		else if (str[i].length() > str[j].length())
			sortStr[k++] = str[j++];
		else { // ���������� ����
			for (int a = 0; a < str[i].length(); a++) {
				if (str[i][a] < str[j][a]) {
					sortStr[k++] = str[i++];
					break;
				}
				else if (str[i][a] > str[j][a]) {
					sortStr[k++] = str[j++];
					break;
				}
				if(a == str[i].length() - 1) // ������ ���� �Ȱ����� �ƹ��ų�
					sortStr[k++] = str[i++];
			}
		}
	}

	if (i <= mid) {
		while (k <= right)
			sortStr[k++] = str[i++];
	}
	else {
		while (k <= right)
			sortStr[k++] = str[j++];
	}

	for (int i = left; i <= right; i++)
		str[i] = sortStr[i];
}

void merge(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge(left, mid);
		merge(mid + 1, right);
		sort(left, mid, right);
	}
}

int main() {
	int size;
	cin >> size;
	str = new string[size];
	sortStr = new string[size];
	for (int i = 0; i < size; i++) {
		string insert;
		cin >> insert;
		str[i] = insert;
	}

	merge(0, size - 1);

	cout << str[0] << "\n";
	for (int i = 1; i < size; i++) {
		if (str[i - 1] != str[i])
			cout << str[i] << "\n";
		
	}
}