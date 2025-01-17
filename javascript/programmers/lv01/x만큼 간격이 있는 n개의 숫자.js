// https://school.programmers.co.kr/learn/courses/30/lessons/12954
function solution(x, n) {
  return Array(n)
    .fill(x)
    .map((v, i) => (i + 1) * v);
}
