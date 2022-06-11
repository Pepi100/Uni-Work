#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//count the number of smaller elements than x in a sorted vector v
int smaller(int x, const vector<int>& v, int s, int t){
	if(s > t) return 0;
	int m = (s+t)/2;
	if(v[m] >= x) return smaller(x,v,s,m-1);
	else return (m-s+1)+smaller(x,v,m+1,t);
}

//count the number of larger elements than x in a sorted vector v
int larger(int x, const vector<int>& v, int s, int t){
	if(s > t) return 0;
	int m = (s+t)/2;
	if(v[m] <= x) return larger(x,v,m+1,t);
	else return (t-m+1)+larger(x,v,s,m-1);
}

//counting invertions in a vector between positions s and t
int invertions(vector<int>& v, int s, int t){
	if(s >= t) return 0;

	//s < t
	int m = (s+t)/2;

	int res = invertions(v,s,m); //also sorts the sub-vector
	res += invertions(v,m+1,t);

	int tmp[t-s+1], i = s, j = m+1, k = 0;
	while(i <= m && j <= t){
		if(v[i] <= v[j]){
			res += j-m-1; //number of smaller elements between pos. m+1 and k
			tmp[k++] = v[i++];
		}else tmp[k++] = v[j++];
	}
	//only one of the two loops is executed:
	while(i <= m){
		res += t-m;
		tmp[k++] = v[i++];
	}
	while(j <= t){
		tmp[k++] = v[j++];
	}
	//copy the sorted subvector
	for(k = 0; k <= t-s; k++)
	 v[s+k] = tmp[k];

	//output
	return res;
}

int invertions(const vector<int>& v){
	vector<int> u(v);
	return invertions(u,0,u.size()-1);
}

//Invertions in a given interval


struct Mo {

	vector<int> v; //input vector, to be pre-processed

	private:

		vector<int> w; //sorted blocks
		vector< vector<int> > MEB; //MEB[i][j] = # pos. k such that v[i] and v[k] are NOT in the same block, v[k] is in one of the first j+1 blocks and ( i < k => v[i] > v[k], i > k => v[i] < v[k])
		vector< vector<int> > MBB; //MBB[i][j] = # pairs (x,y) such that x < y, v[x] in block i, v[y] in one of the first j+1 blocks, and v[x] > v[y]

	public:

		void preproc(void){

			int n = v.size();
			cout << "vector of size: " << n << endl;
			cout << '[';
			for(int i =0; i < n; i++){
				cout << v[i];
				if(i != n-1) cout << ',';
				else cout << ']' << endl << endl;
			}

			int b = floor(sqrt(n)); //size of a block
			cout << "size of all blocks (except maybe the last one): " << b << endl;
			int s = n/b;
			if(s*b != n) s++; //number of blocks
			cout << "number of blocks: " << s << endl << endl;

			//initialization of matrices
			MEB = vector< vector<int> >(n);
			for(int i = 0; i < n; i++)
			 MEB[i] = vector<int>(s);
			MBB = vector< vector<int> >(s);
			for(int j = 0; j < s; j++)
			 MBB[j] = vector<int>(s);

			w = v;

			//number of invertions per block
			for(int i = 0; i < s; i++)
			 MBB[i][i] = invertions(w,b*i,min(b*(i+1),n)-1);

			cout << "Sorted blocks: [";
			for(int i = 0; i < n; i++){
				cout << w[i];
				if(i != n-1) cout << ',';
				else cout << ']' << endl << endl;
			}

			for(int i = 0; i < s; i++)
			 cout << "Number of invertions in block " << i << ": " << MBB[i][i] << endl;
			cout << endl;

			//number of invertions with first index in block i and second index in block j (i <= j)
			for(int i = 0; i < s; i++)
			 for(int j = i+1; j < s; j++){
			 	vector<int> tmp;
			 	for(int k = i*b; k < (i+1)*b; k++)
			 	 tmp.push_back(w[k]);
			 	for(int k = j*b; k < min((j+1)*b,n);k++)
			 	 tmp.push_back(w[k]);
			 	MBB[i][j] = invertions(tmp);
			 }

			 cout << "Matrix MBB (before partial sums): " << endl;
			 for(int i = 0; i < s; i++){
			 	cout << "[ ";
			    for(int j = 0; j < s; j++)
				 cout << MBB[i][j] << ' ';
				cout << "]" << endl;
			 }
			 cout << endl;

			 //partial sums
			 for(int i = 0; i < s; i++)
			  for(int j = i+1; j < s; j++)
			   MBB[i][j] += MBB[i][j-1];

			cout << "Matrix MBB (after partial sums): " << endl;
			 for(int i = 0; i < s; i++){
			 	cout << "[ ";
			    for(int j = 0; j < s; j++)
				 cout << MBB[i][j] << ' ';
				cout << "]" << endl;
			 }
			 cout << endl;

			//comparison element-block: number of invertions between v[i] and an element in block j (assuming v[i] is NOT in block j)
			for(int i = 0; i < n; i++)
			 for(int j = 0; j < s; j++)
			  if(b*(j+1) <= i) MEB[i][j] = larger(v[i],w,b*j,b*(j+1)-1);
			  else if(b*j > i) MEB[i][j] = smaller(v[i],w,b*j,min(b*(j+1),n)-1);

			cout << "Matrix MEB (before partial sums): " << endl;
			for(int i = 0; i < n; i++){
				cout << "[ ";
				for(int j = 0; j < s; j++)
				 cout << MEB[i][j] << ' ';
				cout << "]" << endl;
			}
			cout << endl;

			//partial sums
			for(int i =0; i < n; i++)
			 for(int j = 1; j*b < n; j++)
			  MEB[i][j] += MEB[i][j-1];

			cout << "Matrix MEB (after partial sums): " << endl;
			for(int i = 0; i < n; i++){
				cout << "[ ";
				for(int j = 0; j < s; j++)
				 cout << MEB[i][j] << ' ';
				cout << "]" << endl;
			}
			cout << endl;

		}

		int query(int i, int j){
			int n=v.size();
			int b = floor(sqrt(n));

			cout << "QUERY" << endl;
			cout << "i: " << i << ", j: " << j << endl;

			//Case of a smaller interval
			if(j-i <= b){

				cout << "Small range (length " << j-i+1 << " <= sqrt(" << n << "))" << endl;

				vector<int> tmp;
				for(int k = i; k <= j; k++)
				 tmp.push_back(v[k]);

				return invertions(tmp);

			}else{

				cout << "Large range (length " << j-i+1 << " > sqrt(" << n << "))" << endl;

				//first block fully in the range
				int s(0); while(s*b < i) s++;
				//last block fully in the range
				int t(s); while( (t+1)*b < n && min(n-1,(t+2)*b-1) <= j) t++;

				cout << "Blocks in presence: B" << s << ",...,B" << t << endl;

				int res(0);

				//block-to-block
				for(int k = s; k <= t; k++)
				 res += MBB[k][t];

				//element-to-block
				for(int p = i; p < b*s; p++)
				 res += MEB[p][t] - MEB[p][s-1]; //note that if s==0 we do not enter in this for loop
				for(int q = (t+1)*b; q <= j; q++)
				 if(s==0) res += MEB[q][t];
				 else res+= MEB[q][t] - MEB[q][s-1];

				//element-to-element
				vector<int> tmp;
				for(int p = i; p < b*s; p++) tmp.push_back(v[p]);
				for(int q = (t+1)*b; q <= j; q++) tmp.push_back(v[q]);
				res += invertions(tmp);

				return res;
			}
		}
};

int main(){

	vector<int> v = {1,10,2,9,3,8,4,7,5,6};
	//cout << invertions(v) << endl;

	Mo inv;
	inv.v = v;
	inv.preproc();

	cout << inv.query(0,9) << endl << endl;
	cout << inv.query(2,4) << endl << endl;
	cout << inv.query(3,7) << endl << endl;
}