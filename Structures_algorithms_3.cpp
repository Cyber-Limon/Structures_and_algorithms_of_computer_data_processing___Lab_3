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
		if (vertex.left == nullptr) {
			vertex.left = &knot;
		}
		else
			tree_construction(*vertex.left, knot);
	}

	else {
		if (vertex.right == nullptr) {
			vertex.right = &knot;
		}
		else
			tree_construction(*vertex.right, knot);
	}
}



void tree_output() {	

	

}



void tree_traversal(Knot& knot) {
	cout << knot.value << " ";
	
	if (knot.left != nullptr) 
		tree_traversal(*knot.left);

	if (knot.right != nullptr)
		tree_traversal(*knot.right);
}



int main() {
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	int const size_sample = 5;
	Knot sample[size_sample];

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

	cout << "Последовательность сгенерированных чисел:\n";

	for (int i = 0; i < size_sample; i++) {
		if (i % 10 == 0 && i != 0)
			cout << endl;
		cout << sample[i].value << "\t";
	}

	for (int i = 1; i < size_sample; i++)
		tree_construction(sample[0], sample[i]);

	cout << "\n\nПрямой обход дерева:\n";

	tree_traversal(sample[0]);



	cout << "\n\n\n\n";
	system("pause");
}