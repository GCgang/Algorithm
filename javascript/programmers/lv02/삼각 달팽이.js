// https://school.programmers.co.kr/learn/courses/30/lessons/68645
function solution(n) {
  // 삼각형 배열 초기화
  const triangle = Array.from({ length: n }, (_, i) => Array(i + 1).fill(0));

  // 방향: 아래, 오른쪽, 왼쪽 위 대각선
  const directions = [
    [1, 0],
    [0, 1],
    [-1, -1],
  ];
  let [x, y] = [0, 0];
  let dir = 0;

  for (let num = 1; num <= (n * (n + 1)) / 2; num++) {
    triangle[x][y] = num;

    let [dx, dy] = directions[dir];
    let nx = x + dx;
    let ny = y + dy;

    if (nx >= n || ny >= triangle[nx].length || triangle[nx][ny] !== 0) {
      dir = (dir + 1) % 3;
      [dx, dy] = directions[dir];
      nx = x + dx;
      ny = y + dy;
    }

    x = nx;
    y = ny;
  }

  return triangle.flat();
}
