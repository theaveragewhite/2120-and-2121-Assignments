/*
 * Name: Colton Owenby (coltono)
 * Date Submitted: Submitted 11/28/2023
 * Lab Section: 007
 * Assignment Name: Lab 10
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <bitset>
using namespace std;

// Reflects what each node represents...
// int with each bit == 0 left of river, bit == 1 right of river
typedef int state;

// Bit position representation for wolf/goat/cabbage/me
bool bit(int x, int i) { return (x>>i) & 1; }
const int wolf=0, goat=1, cabbage=2, me=3;

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;

// GENERIC (breadth-first search, outward from curnode)
void search(state source_node)
{
  queue<state> to_visit;
  to_visit.push(source_node);
  visited[source_node] = true;
  dist[source_node] = 0;

  while (!to_visit.empty()) {
    state curnode = to_visit.front();
    to_visit.pop();
    for (state n : nbrs[curnode])
      if (!visited[n]) {
	pred[n] = curnode;
	dist[n] = 1 + dist[curnode];
	visited[n] = true;
	to_visit.push(n);
      }
  }
}

string state_string(state s)
{
  string items[4] = { "wolf", "goat", "cabbage", "you" }, result = "";
  for (int i=0; i<4; i++)
    if (!bit(s, i)) result += items[i] + " ";
  result += " |river| ";
  for (int i=0; i<4; i++)
    if (bit(s, i)) result += items[i] + " ";
  return result;
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t) {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << state_string(t) << "\n";
  } else {
    cout << "Initial state: " << state_string(s) << "\n";
  }
}

string neighbor_label(int s, int t)
{
  string items[3] = { "wolf", "goat", "cabbage" }, which_cross;
  if (bit(s,me) == bit(t,me)) return "";  // must cross river
  int cross_with = 0;
  for (int i=0; i<3; i++) {
    if (bit(s,i) != bit(t,i) && bit(s,i)==bit(s,me)) { cross_with++; which_cross = items[i]; }
    if (bit(s,i) != bit(t,i) && bit(s,i)!=bit(s,me)) return "";
  }
  if (cross_with > 1) return "";
  if (cross_with == 0) return "Cross alone";
  else return "Cross with " + which_cross;
}

//Helper function to validate position
bool validPos(bitset<4> pos)
{

  if(pos[wolf] == pos[goat])
  {

    if(pos[me] == pos[wolf] && pos[me] == pos[goat])
    return true;
  }

  else if(pos[goat] == pos[cabbage])
  {

    if(pos[me] == pos[goat] && pos[me] == pos[cabbage])
    return true;

  }
  else
  return true;
  return false;
}


void build_graph(void)
{
  const int items = 4;
  //Implement this function
  bitset<items> current_state;
  bitset<items> end ("1111");

  while(current_state != end)
  {
    for(int i = 0; i < items; i++)
    {
      if(current_state[me] == current_state[i])
      {

        bitset<items> next_state = current_state;

        next_state[me].flip();
        i != me ? next_state[i].flip() : false;

        //Check for valid next state
        if(validPos(next_state))
        {
          int curr = (int)current_state.to_ulong();
          int next = (int)next_state.to_ulong();
          nbrs[curr].push_back(next);
          edge_label[make_pair(curr,next)] = neighbor_label(curr,next);
        }
      }
    }
    current_state = (int)current_state.to_ulong() + 1;
}


}

int main(void)
{
  build_graph();

  state start = 0, end = 15;

  search(start);
  if (visited[end])
    print_path (start, end);
  else
    cout << "No path!\n";

  return 0;
}
