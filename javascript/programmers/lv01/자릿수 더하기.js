// https://school.programmers.co.kr/learn/courses/30/lessons/12931
function solution(n) {
  let sum = 0;
  while (n > 0) {
    sum += n % 10;
    n = Math.floor(n / 10);
  }
  return sum;
}
