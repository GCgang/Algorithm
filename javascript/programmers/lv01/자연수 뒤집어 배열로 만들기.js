// https://school.programmers.co.kr/learn/courses/30/lessons/12932
function solution(n) {
  // 문자 풀이
  // return n.toString().split('').reverse().map((c) => parseInt(c));

  // 숫자 풀이
  const arr = [];
  while (n > 0) {
    arr.push(n % 10);
    n = Math.floor(n / 10);
  }

  return arr;
}
