// 1 은 벽, 'S'는 시작점, 'E'는 출구
// DFS 알고리즘으로 시작점에서 출구까지의 경로 찾는 함수 구현
// 이동은 상하좌우로만 가능

let maze = [
  ['S', 0, 1, 0, 0],
  [0, 0, 0, 0, 0],
  [0, 1, 1, 1, 1],
  [0, 0, 0, 0, 'E'],
  [1, 1, 1, 0, 1],
];

function dfs(maze, position = [0, 0], path = []) {
  let [x, y] = position;
  if (maze[x][y] === 'E') return [...path, position];

  let dir = [
    [0, -1],
    [1, 0],
    [0, 1],
    [-1, 0],
  ];

  for (let [dx, dy] of dir) {
    let newX = x + dx;
    let newY = y + dy;
    if (newX < 0 || newX >= maze.length || newY < 0 || newY >= maze[0].length) {
      continue;
    }
    if (maze[newX][newY] === 'S' || maze[newX][newY] === 1) {
      continue;
    }
    maze[x][y] = 1;
    let result = dfs(maze, [newX, newY], [...path, position]);
    if (result) return result;
  }
  return null;
}

console.log(dfs(maze));
