// 땅은 1, 0은 바다
// 주변이 상하좌우로 1이 연결되어 있을 때 하나의 섬이 된다.(대각선으로 연결된 1은 연결된 것으로 판단하지 않는다)
// 주어진 지도의 섬의 개수를 반환하는 함수 구현

let map = [
  [1, 1, 0, 0, 0],
  [1, 1, 0, 0, 0],
  [0, 0, 1, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
];

function dfs(map, x, y) {
  let dir = [
    [-1, 0],
    [0, -1],
    [1, 0],
    [0, 1],
  ];

  map[x][y] = 0;

  for (let [dx, dy] of dir) {
    const newX = dx + x;
    const newY = dy + y;

    if (newX < 0 || newX >= map.length || newY < 0 || newY >= map[0].length) {
      continue;
    }
    if (map[newX][newY] === 0) {
      continue;
    }
    dfs(map, newX, newY);
  }
}

function solution(map) {
  let result = 0;
  for (let x = 0; x < map.length; ++x) {
    for (let y = 0; y < map[x].length; ++y) {
      if (map[x][y] === 1) {
        result++;
        dfs(map, x, y);
      }
    }
  }
  return result;
}

console.log(solution(map));
