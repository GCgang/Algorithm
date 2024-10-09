const graph = {
  A: ['B', 'C'],
  B: ['A', 'D'],
  C: ['A', 'E', 'F'],
  D: ['B'],
  E: ['C'],
  F: ['C', 'G'],
  G: ['E', 'H'],
  H: ['G'],
};

function bfs(graph, startNode, targetNode) {
  const visited = {};
  const queue = [];
  const dist = {};

  visited[startNode] = true;
  queue.push(startNode);
  dist[startNode] = 0;

  while (queue.length !== 0) {
    const node = queue.shift();
    console.log(node);
    if (node === targetNode) {
      return dist[node];
    }

    const adjNodes = graph[node];
    for (let adjNode of adjNodes) {
      if (visited[adjNode]) {
        continue;
      }
      visited[adjNode] = true;
      queue.push(adjNode);
      dist[adjNode] = dist[node] + 1;
    }
  }
  return -1;
}

const shortestDist = bfs(graph, 'A', 'H');
console.log(`A -> H 최단 거리는 ${shortestDist}`);
