#include "State.cpp"
#include <vector>

class Node{
    //ptr to parent
    //depth
    //
    public:
        State state;
        vector<pair<int, int>> moves;
        Node* parent;
        int depth;
        Node(State state):state(state), parent(nullptr), depth(0){
            moves = vector<pair<int, int>>(0);            
        }

        Node(State state, vector<pair<int, int>> moves, Node* parent):state(state), moves(moves), parent(parent){
            depth = parent->depth; 
        }

        int depth(){
            return depth;
        }

};