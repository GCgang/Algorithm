// https://school.programmers.co.kr/learn/courses/30/lessons/77484

function solution(lottos, win_nums) {
  const rank = [6, 6, 5, 4, 3, 2, 1];
  const winSet = new Set(win_nums);

  let zeroCnt = lottos.filter((num) => num === 0).length;
  let matchCnt = lottos.filter((num) => winSet.has(num)).length;

  return [rank[zeroCnt + matchCnt], rank[matchCnt]];
}
