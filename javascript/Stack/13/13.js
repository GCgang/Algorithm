function solution(board, moves) {
  let res = 0;
  const stack = [];

  for (let i = 0; i < moves.length; ++i) {
    let cur = moves[i] - 1;
    for (let j = 0; j < board.length; ++j) {
      if (board[j][cur] !== 0) {
        stack.push(board[j][cur]);
        board[j][cur] = 0;
        if (stack.length > 1) {
          if (stack[stack.length - 2] === stack[stack.length - 1]) {
            stack.pop();
            stack.pop();
            res++;
            res++;
          }
        }
        break;
      }
    }
  }
  return res;
}
