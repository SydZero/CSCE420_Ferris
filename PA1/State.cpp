#include <vector>

using std::vector, std::pair;

class State{
    //need array with path to state
    //configuration of puzzle

    public:
        vector<vector<char>> stacks;
        vector<pair<int, int>> moves;
        State(int numStacks){
            stacks = vector<vector<char>>(numStacks);
        }

        State(vector<vector<char>> stacks, vector<pair<int, int>> moves): stacks(stacks), moves(moves){}

        void AddBlock(int stack, char blockChar){
            stacks.at(stack).push_back(blockChar);
        }

        State move(int start, int end){
            State newState = State(stacks, moves);
            char moving = newState.stacks.at(start).back();
            newState.stacks.at(start).pop_back();
            newState.stacks.at(end).push_back(moving);
            return newState;
        }

        vector<State> successors(){
            vector<State> successors = vector<State>(0);
            for(int i = 0; i < stacks.size(); i++){
                for(int j = 0; j < stacks.size(); j++){
                    if(i != j){
                        successors.push_back(move(i, j));
                    }
                }
            }
            return successors;
        }

};