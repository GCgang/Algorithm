// https://school.programmers.co.kr/learn/courses/30/lessons/1844

function solution(maps) {
  const n = maps.length;
  const m = maps[0].length;
  const dir = [
    [-1, 0],
    [0, -1],
    [1, 0],
    [0, 1],
  ];
  const visited = Array.from(Array(n), () => Array(m).fill(false));
  const dist = {};
  const queue = [];

  visited[0][0] = true;
  dist['0, 0'] = 1;
  queue.push([0, 0]);

  while (queue.length !== 0) {
    const [x, y] = queue.shift();

    if (x === n - 1 && y == m - 1) {
      return dist[`${x}, ${y}`];
    }

    for (let [dx, dy] of dir) {
      let nx = dx + x;
      let ny = dy + y;

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (visited[nx][ny]) continue;
      if (maps[nx][ny] === 0) continue;

      visited[nx][ny] = true;
      queue.push([nx, ny]);
      dist[`${nx}, ${ny}`] = dist[`${x}, ${y}`] + 1;
    }
  }
  return -1;
}

console.log(
  solution([
    [1, 0, 1, 1, 1],
    [1, 0, 1, 0, 1],
    [1, 0, 1, 1, 1],
    [1, 1, 1, 0, 1],
    [0, 0, 0, 0, 1],
  ])
);

console.log(
  solution([
    [1, 0, 1, 1, 1],
    [1, 0, 1, 0, 1],
    [1, 0, 1, 1, 1],
    [1, 1, 1, 0, 0],
    [0, 0, 0, 0, 1],
  ])
);
