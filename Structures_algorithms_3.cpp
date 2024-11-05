#include <iostream>



using namespace std;

struct Knot {
	int value;
	Knot* left = nullptr;
	Knot* right = nullptr;
	int level = 0;
};



void tree_construction(Knot& vertex, Knot& knot) {
	knot.level++;

	if (knot.value < vertex.value) {
		if (vertex.left == nullptr)
			vertex.left = &knot;
		else
			tree_construction(*vertex.left, knot);
	}

	else {
		if (vertex.right == nullptr)
			vertex.right = &knot;
		else
			tree_construction(*vertex.right, knot);
	}
}



void indents(int n, int index) {
	for (int i = 0; i < n; i++) {
		if (index == 1) cout << " ";
		else cout << "_";
	}
}



void tree_output(Knot sorted_sample[], int size_sample) {
	int i = 0;
	int n = 0;
	Knot knot = sorted_sample[n];

	while (n != size_sample) {
		Knot knot = sorted_sample[n];

		if (n > 0 && sorted_sample[n - 1].level != knot.level) {
			cout << "\n";

			int k = n;
			int level = sorted_sample[n].level;

			while (sorted_sample[k].level == level) {
				cout << "\r";
				indents(sorted_sample[k].value * 2, 1);
				cout << "||";
				k++;
			}

			cout << "\n";
		}

		cout << "\r";

		if (knot.left != nullptr) {
			indents(knot.left->value * 2 + 1, 1);
			indents((knot.value - knot.left->value) * 2 - 1, 2);
		}
		else {
			indents(knot.value * 2, 1);
		}

		cout << knot.value;

		if (knot.right != nullptr) {
			indents((knot.right->value - knot.value) * 2 - 1, 2);
		}

		if (knot.right != nullptr) {
			i++;
			sorted_sample[i] = *knot.right;
		}

		if (knot.left != nullptr) {
			i++;
			sorted_sample[i] = *knot.left;
		}

		n++;
	}
}



void NLR(Knot& knot) {
	cout << knot.value << " ";

	if (knot.left != nullptr)
		NLR(*knot.left);

	if (knot.right != nullptr)
		NLR(*knot.right);
}



void LRN(Knot& knot) {
	if (knot.left != nullptr)
		LRN(*knot.left);

	if (knot.right != nullptr)
		LRN(*knot.right);

	cout << knot.value << " ";
}



int main() {
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	cout << "Откройте окно консоли на весь экран\n";
	system("pause");

	int const size_sample = 26;
	Knot sample[size_sample];
	Knot sorted_sample[size_sample];

	int i = 0;
	while (i < size_sample) {
		int r = (rand() % 9 + 1) * 10 + rand() % 9;

		bool flag = true;

		for (int j = 0; j < i; j++) {
			if (sample[j].value == r) {
				flag = false;
				break;
			}
		}

		if (flag) {
			sample[i].value = r;
			i++;
		}
	}



	cout << "\nПоследовательность сгенерированных чисел:\n";

	for (int i = 0; i < size_sample; i++) {
		if (i != 0)
			tree_construction(sample[0], sample[i]);

		if (i % 10 == 0 && i != 0)
			cout << endl;
		cout << sample[i].value << "\t";
	}



	cout << "\n\nПостроенное дерево:\n";

	sorted_sample[0] = sample[0];
	tree_output(sorted_sample, size_sample);



	cout << "\n\nNLR: ";

	NLR(sample[0]);



	cout << "\n\nLRN: ";

	LRN(sample[0]);
	

	
	cout << "\n\n\n\n";
	system("pause");
}
