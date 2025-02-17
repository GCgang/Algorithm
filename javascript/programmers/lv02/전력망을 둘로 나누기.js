// https://school.programmers.co.kr/learn/courses/30/lessons/86971
function solution(n, wires) {
  let minDiff = Infinity;

  const buildGraph = (wires) => {
    const graph = Array.from({ length: n + 1 }, () => []);
    for (let [a, b] of wires) {
      graph[a].push(b);
      graph[b].push(a);
    }
    return graph;
  };

  const bfs = (start, graph, removeEdge) => {
    let queue = [start];
    let visited = new Set();
    let cnt = 0;

    visited.add(start);

    while (queue.length > 0) {
      let node = queue.shift();
      cnt++;

      for (let neighbor of graph[node]) {
        if (visited.has(neighbor)) {
          continue;
        }

        if (
          (node === removeEdge[0] && neighbor === removeEdge[1]) ||
          (node === removeEdge[1] && neighbor === removeEdge[0])
        ) {
          continue;
        }

        visited.add(neighbor);
        queue.push(neighbor);
      }
    }
    return cnt;
  };

  for (let [a, b] of wires) {
    let graph = buildGraph(wires);
    let subTreeSize = bfs(a, graph, [a, b]);
    let diff = Math.abs(subTreeSize - (n - subTreeSize));
    minDiff = Math.min(minDiff, diff);
  }
  return minDiff;
}
