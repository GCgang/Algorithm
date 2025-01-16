// https://school.programmers.co.kr/learn/courses/30/lessons/12928
function solution(n) {
  const divisors = [];
  for (let i = 1; i <= Math.sqrt(n); i++) {
    if (n % i === 0) {
      divisors.push(i);
      if (i !== n / i) {
        divisors.push(n / i);
      }
    }
  }
  return divisors.reduce((acc, cur) => acc + cur, 0);
}
