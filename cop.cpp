#include <iostream>

using namespace std;

int limit, total = 1;

int CheckSplitter(int x) {
	if (x%2 == 0 && (x/2-2)%3 == 0){
		return 1;
	} else {
		return 0;
	}
}

struct num {
	int n;
	num *even;
	num *odd;
};

num *newnum(int x=1) {
	num *t = new num;
	t->n =x;
	t->even=NULL;
	t->odd=NULL;

	return t;
}

num *start = newnum();

void generator (num *front = start) {
		
	while (front -> n < limit) {
		if ( CheckSplitter(front->n) ) {
			num *en = newnum(2*(front->n));
			num *on = newnum((front->n -1)/3);
			
            front -> even = en;
			front -> odd = on;
			
            total +=2;
			
            cout << "splitter = " << front -> n << endl;
			generator(en);
			generator(on);
			
            break;
		} else {
		    num *t = newnum(2 *(front->n));
			front -> even = t;
			cout << "normal = " << front -> n << endl;
			front = t;
            total++;
		}

	}
}
int main() {
	limit = 20;
			
	generator();		
			
    cout << total;

	return 0;
}
