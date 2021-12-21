#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>


using namespace std;


	void fcfs(struct node* header);
	void sjfnp(struct node* header);
	void pnp(struct node* header);
	void sm(struct node* header);
	void pm(struct node* header);
	void npm(struct node* header);
	void sr(struct node* header);

void gd();

	struct node {
		int pn;
		int bt;
		int at;
		int py;
	struct node *next;
};

int is_empty_node(struct node * header);
	struct node * sort_list(struct node * header);
	struct node * insert_back(struct node * header, int pn, int btm, int atm, int pyn);
	struct node * check_completion(struct node * header, int count);
	struct node * sort_priority(struct node * header);
	struct node * create_node(int pn, int btm, int atm, int pyn);
	struct node * delete_front(struct node * header);
int main()


{

struct node *header = NULL;

		int pn;
		int btm;
		int atm;
		int pyn;
		ifstream fin;
		bool loop = true;
		
fin.open("input.txt");


if (fin.is_open()) {

		while (fin >> pn >> btm >> atm >> pyn) {
		
		header = insert_back(header, pn, btm, atm, pyn);
		
		}
	}
	
fin.close();
		while (loop) {
	int option;
		
		cout << endl << "\t\t\tCPU SCHEDULER SIMULATOR" << endl;
		cout << endl << "1) Scheduling Method";
		cout << endl << "2) Preemptive Method";
		cout << endl << "3) Non-preemptive Mode";
		cout << endl << "4) Show Result";
		cout << endl << "5) End Program";
		cout << endl << "Option >";
	cin >> option;

		if (option == 1) {
			sm(header);
		}
		else if (option == 2) {
			pm(header);
		}
		else if (option == 3) {
			npm(header);
		}
		else if (option == 4) {
			sr(header);
		}
		else if (option == 5) {
			return 0;
		}
		else {
			cout << endl << "please enter from 1 - 5" << endl;
		}
	}
	cin.ignore();
	return 0;
}


