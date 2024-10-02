// https://school.programmers.co.kr/learn/courses/30/lessons/147355
function solution(t, p) {
  let result = 0;
  let pVal = parseInt(p);
  for (let i = 0; i <= t.length - p.length; ++i) {
    let tVal = parseInt(t.substring(i, i + p.length));
    if (tVal <= pVal) result++;
  }
  return result;
}
