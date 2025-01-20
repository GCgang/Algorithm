// https://school.programmers.co.kr/learn/courses/30/lessons/12933
function solution(n) {
  // 문자 풀이
  // return Number(n.toString().split('').sort((a,b) => b-a).join(''))

  // 숫자 풀이
  const arr = [];
  while (n > 0) {
    arr.push(n % 10);
    n = Math.floor(n / 10);
  }

  arr.sort((a, b) => b - a);

  return arr.reduce((acc, cur) => acc * 10 + cur, 0);
}
