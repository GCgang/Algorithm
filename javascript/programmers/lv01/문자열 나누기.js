// https://school.programmers.co.kr/learn/courses/30/lessons/140108
function solution(s) {
  let result = 0;
  let xCnt = 0;
  let otherCnt = 0;
  let x = '';

  for (let i = 0; i < s.length; i++) {
    if (xCnt === 0) x = s[i];

    if (x === s[i]) xCnt++;
    else otherCnt++;

    if (xCnt === otherCnt) {
      result++;
      xCnt = 0;
      otherCnt = 0;
    }
  }
  if (xCnt !== 0 || otherCnt !== 0) result++;

  return result;
}
