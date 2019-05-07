//
// Created by HP on 2/05/2019.
//

#include <iostream>
#include <vector>


using namespace std;

struct Node {

    int data;
    int rank;
    Node* father;

    Node(int data) {
        father = this;
        rank = 0;
        this->data = data;
    };

};


class DisjoinSet {

    Node* datos; // puntero a los nodos

    int n;

public:
    DisjoinSet(int n) {
        this->n = n;

        datos = new Node[n];


        MakeSet();
    };

    void MakeSet(){

        for(int i=0;i<n;i++){
            datos[i] = Node(i);
        }
    }

    Node* find(int x){


        Node* fat = (this->datos+x);

        while (fat != fat->father){

            fat = fat->father;
        }



        return fat;
    }

    void Union(int x, int y)
    {
        //hallamos los elementos representativos
        Node* xset = find(x);
        Node* yset = find(y);

        if (xset->data == yset->data)
            return;

        if (xset->rank < yset->rank) {
            xset->father = yset;
        }
        else if (xset->rank > yset->rank) {
            yset->father = xset;
        }

        else {
            yset->father = xset;
            xset->rank = xset->rank + 1;
        }
    }



};


int main(){
    DisjoinSet* S = new DisjoinSet(3);
    S->Union(1,3);

}







