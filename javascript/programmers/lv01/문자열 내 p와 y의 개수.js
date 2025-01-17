// https://school.programmers.co.kr/learn/courses/30/lessons/12916?language=javascript
function solution(s) {
  const pCnt = (s.match(/p/gi) || []).length;
  const yCnt = (s.match(/y/gi) || []).length;

  return pCnt === yCnt;
}
