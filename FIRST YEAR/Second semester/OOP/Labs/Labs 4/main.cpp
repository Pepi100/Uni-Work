#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;



int min(int x1, int x2, int x3, int x4, int x5 ){
    int a1 = min(x1, x2), a2=min(x3,x4);
    a1=min(a1, a2);
    return min(a1, x5);
}

class Coords{
private:
    int x, y;
public:
    Coords(){}
    Coords(int _x, int _y){
        x=_x;
        y=_y;
    }

    int getX(){
        return x;
    }
    int getY(){
        return y;
    }

    void setX(int _x){
        x=_x;
    }

    void setY(int _y){
        y=_y;
    }

    friend istream &operator>>(istream &is, Coords &coord);
    friend ostream &operator<<(ostream &os, Coords &coord);

};

istream &operator>>(istream &is, Coords &coord){
    cout<<"x: ";
    is>>coord.x;
    cout<<"y: ";
    is>>coord.y;

    return is;

}

ostream &operator<<(ostream &os, Coords &coord){
    cout<<"x: ";
    os<<coord.x;
    cout<<"\ny: ";
    os<<coord.y;
    cout<<'\n';

    return os;
}

class Queue{
private:
    vector<Coords> coada;

public:
    Queue(){
        vector<Coords> c;
        coada = c;
    }

    Queue(const vector<Coords> &coada) : coada(coada) {}

    void setCoada(const vector<Coords> &coada) {
        Queue::coada = coada;
    }

    const vector<Coords> &getCoada() const {
        return coada;
    }

    void clear(){
        vector<Coords> c;
        setCoada(c);
    }

    bool isEmpty(){
        return coada.size()==0;
    }

    int size(){
        return coada.size();
    }

    Coords operator[](int i){
        if(i>=0 && i<coada.size()){
            return coada[i];
        }else{
            cout<<"Nu exista un element la acea pozitie in coada\n";
            return Coords(-1,-1);
        }
    }

    Queue operator+=(Coords _new){
        Queue q1(coada);
        q1.coada.push_back(_new);
        setCoada(q1.coada);

        return q1;
    }

    Queue operator--(){
        Queue q1(coada);
        q1.coada.erase(q1.coada.begin());
        setCoada(q1.coada);
        return q1;
    }

    bool exista(Coords c){
        for(int i=0; i< coada.size();i++)
            if(coada[i].getX()==c.getX() && coada[i].getY() == c.getY())
                return true;
        return false;
    }


friend istream &operator>>(istream &is, Queue &queue);
};

istream &operator>>(istream &is, Queue &queue){
    int n;
    Coords x;
    is>>n;

    for(int i=0; i<n;i++){
        is>>x;
        queue+=x;
    }
    return is;
}

class Maze{
private:
    int n;
    Coords start, end;
    Queue obstacole;
public:
    Maze() = default;

    Maze(int n, const Coords &start, const Coords &anEnd, const Queue &obstacole) : n(n), start(start), end(anEnd),
                                                                                    obstacole(obstacole) {}
    int getN() const {
        return n;
    }

    const Coords &getStart() const {
        return start;
    }

    const Coords &getAnEnd() const {
        return end;
    }

    const Queue &getObstacole() const {
        return obstacole;
    }

    friend istream &operator>>(istream &is, Maze &m);
    friend ostream &operator<<(ostream &os, Maze &m);

    void fill(){
        int matrix[101][101];
        for(int i=0; i<=n;i++){
            for(int j=0; j<=n;j++){
                matrix[i][j]=INT_MAX;
            }
        }
        Queue q;
        q+=start;
        matrix[start.getY()][start.getX()] = 0;

        while(q.size() != 0){



        }


    }



};

istream &operator>>(istream &is, Maze &m) {
    cout<<"n=";
    is>>m.n;
    cout<<"Start:\n";
    is>>m.start;
    cout<<"End:\n";
    is>>m.end;
    cout<<"Queue:\n";
    is>>m.obstacole;

    return is;

}

ostream &operator<<(ostream &os, Maze &m){
    cout<<"Matricea asociata maze-ului: \n";
    int matrix[101][101];

    //totul liber;
    for(int i=0; i<m.n;i++){
        for(int j=0; j<m.n;j++){
            matrix[i][j]=1;
        }
    }

    //start si end
    // am observat din exemplu ca y este pentru linie si x pentru coloana

    matrix[m.start.getY()][m.start.getX()] = -2;
    matrix[m.end.getY()][m.end.getX()] = -3;

    //obstacolele
//    cout<<m.obstacole.size();

    for(int i=0; i< m.obstacole.size();i++){
        matrix[m.obstacole[i].getY()][m.obstacole[i].getX()] = 0;
    }

    //afisare matrice

    for(int i=0; i<m.n;i++){
        for(int j=0; j<m.n;j++){
            if(matrix[i][j]<0){
                if(matrix[i][j] == -2) cout<<"s ";
                else cout<<"e ";
            }else{
                cout<<matrix[i][j]<<" ";
            }
        }
        cout<<'\n';
    }


    return os;
}



int main(){
    Maze m;
    cin>>m;
    cout<<m;



    return 0;
}


/*

5
0
0
4
0
5
1
0
1
2
2
2
3
2
4
1
*/
