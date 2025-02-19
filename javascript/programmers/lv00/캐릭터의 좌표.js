// https://school.programmers.co.kr/learn/courses/30/lessons/120861
function solution(keyinput, board) {
  const move = {
    up: [0, 1],
    down: [0, -1],
    left: [-1, 0],
    right: [1, 0],
  };

  let x = 0;
  let y = 0;
  const maxX = Math.floor(board[0] / 2);
  const maxY = Math.floor(board[1] / 2);

  for (let key of keyinput) {
    let [dx, dy] = move[key];
    let nx = x + dx;
    let ny = y + dy;

    if (Math.abs(nx) <= maxX && Math.abs(ny) <= maxY) {
      x = nx;
      y = ny;
    }
  }

  return [x, y];
}
