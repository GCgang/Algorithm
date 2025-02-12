// https://school.programmers.co.kr/learn/courses/30/lessons/42842
function getDivisors(n) {
  const divisor = [];
  for (let i = 3; i <= Math.sqrt(n); i++) {
    if (n % i === 0) {
      divisor.push([n / i, i]);
    }
  }
  return divisor;
}

function solution(brown, yellow) {
  const total = brown + yellow;
  const divisors = getDivisors(total);

  for (let [width, height] of divisors) {
    if ((width - 2) * (height - 2) === yellow) {
      return [width, height];
    }
  }
}
