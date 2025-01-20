// https://school.programmers.co.kr/learn/courses/30/lessons/12934
function solution(n) {
  const sqrt = Math.sqrt(n);

  if (Number.isInteger(sqrt)) {
    return Math.pow(sqrt + 1, 2);
  } else {
    return -1;
  }
}
