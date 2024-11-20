# This is to make error squiggles go away
from typing import List

class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        # Step 1: Initialize the adjacency list as a list of empty lists
        graph = [[] for _ in range(n + 1)]

        # Step 2: Build the graph, p is the person, dp is the disliked person
        for p, dp in dislikes:
            graph[p].append(dp)
            graph[dp].append(p)

        # Step 3: Initialize a color array. 0 = unvisited, 1 = group1, -1 = group2
        color = [0] * (n + 1)

        # Step 4: BFS function to color the graph
        def bfs(start):
            # Use a list as a queue
            queue = [start]
            # Assign group 1 to the start node
            color[start] = 1

            while queue:
                # Remove the first element to simulate a queue
                node = queue.pop(0)
                for neighbor in graph[node]:
                    # If not colored, color with opposite group
                    if color[neighbor] == 0:
                        color[neighbor] = -color[node]
                        # Add neighbor to the end of the queue
                        queue.append(neighbor)
                    # If conflict, return False
                    elif color[neighbor] == color[node]:
                        return False
            return True

        # Step 5: Check each node (to handle disconnected components)
        for i in range(1, n + 1):
            # Not visited
            if color[i] == 0:
                if not bfs(i):
                    return False

        return True