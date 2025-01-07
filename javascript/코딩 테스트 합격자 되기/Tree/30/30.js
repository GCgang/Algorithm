function solution(maps) {
  const row = maps.length;
  const col = maps[0].length;

  const dir = [
    [-1, 0],
    [1, 0],
    [0, -1],
    [0, 1],
  ];

  let start, lever, exit;

  for (let i = 0; i < row; i++) {
    for (let j = 0; j < col; j++) {
      if (maps[i][j] === 'S') start = [i, j];
      else if (maps[i][j] === 'L') lever = [i, j];
      else if (maps[i][j] === 'E') exit = [i, j];
    }
  }

  function bfs(start, target) {
    const visited = Array.from({ length: row }, () => Array(col).fill(false));
    const queue = [[...start, 0]]; // [x, y, dist];
    visited[start[0]][start[1]] = true;

    while (queue.length > 0) {
      const [x, y, dist] = queue.shift();

      if (x === target[0] && y === target[1]) {
        return dist;
      }

      for (const [dx, dy] of dir) {
        const nx = x + dx;
        const ny = y + dy;

        if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
        if (visited[nx][ny] || maps[nx][ny] === 'X') continue;

        visited[nx][ny] = true;
        queue.push([nx, ny, dist + 1]);
      }
    }
    return -1;
  }

  const toLever = bfs(start, lever);
  if (toLever === -1) return -1;

  const toExit = bfs(lever, exit);
  if (toExit === -1) return -1;

  return toLever + toExit;
}
