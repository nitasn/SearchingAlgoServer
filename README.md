# SearchingAlgoServer

A Parallel Server, File Cache Manager, and some Graph Searching Algorithms,
Combined into a kicking-a$$ server that yields best paths in a given matrix .



It's a second-year CS project, by Nitsan and Hodaya, students at Bar-Ilan University.

[Link to GitHub](https://github.com/nitasn/SearchingAlgoServer)

## Installation

Compile our code:
```bash
g++ -std=c++14 *.cpp -o paths_server -pthread
```
## Usage

Run the Server, and ask a question via telnet.
Questions are composed of a Matrix (in which each cell has the cost of visiting it, or -1 for a "wall"), 
Followed by Coordinates of where to Start and where to End,
Then the word "end".
```bash
./paths_server&  # run server
telnet localhost 5400  # connect using telnet
 1,  9,  2,  1
-1,  3,  8,  2
 7, 20, -1, 31
 4,  3,  5,  4
2, 0
1, 3
end
# yields:
# (7) right -> (27) up -> (30) right -> (38) right -> (40) at goal
```
