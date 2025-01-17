// https://school.programmers.co.kr/learn/courses/30/lessons/87389
function solution(n) {
  const sqrtN = Math.sqrt(n);

  for (let x = 2; x <= sqrtN; x++) {
    if (n % x === 1) {
      return x;
    }
  }
  return n - 1;
}
