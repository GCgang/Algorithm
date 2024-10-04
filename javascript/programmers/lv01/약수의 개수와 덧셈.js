// https://school.programmers.co.kr/learn/courses/30/lessons/77884

function getDivisorCount(n) {
  let count = 0;
  for (let i = 1; i <= Math.sqrt(n); ++i) {
    if (n % i === 0) {
      count += 1;
      if (i !== n / i) count += 1;
    }
  }
  return count;
}

function solution(left, right) {
  let result = 0;
  for (let n = left; n <= right; ++n) {
    let divisorCnt = getDivisorCount(n);
    result += divisorCnt % 2 === 0 ? n : -n;
  }
  return result;
}
