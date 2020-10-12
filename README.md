# SearchingAlgoServer

A Multi-Threaded Server that uses Disk Cache, and implements some Graph Searching Algorithms. It can accept graphs, and respond with best-routes.


## Installation

Compile our code:
```bash
g++ -std=c++14 *.cpp -o paths_server -pthread
```
## Usage

Run our server from the command-line, and telnet into it.
The format for a request is:
1. matrix (in which each cell holds the cost of visiting it, or -1 if it's unvisitable), 
2. source cell.
3. target cell.
4. literally the word 'end'.
5. 
and of course, here's an example of a run:
```bash
./paths_server&  # run server
telnet localhost 5600  # connect using telnet

 1,  9,  2,  1
-1,  3,  8,  2
 7, 20, -1, 31
 4,  3,  5,  4
 
2, 0
1, 3
end

# server responds with (min route and its accumulating cost):
(7) right -> (27) up -> (30) right -> (38) right -> (40) at goal
```
