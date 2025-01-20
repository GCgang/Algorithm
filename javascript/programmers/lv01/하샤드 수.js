//https://school.programmers.co.kr/learn/courses/30/lessons/12947
function solution(x) {
  // 문자 풀이
  //     const sum = x
  //         .toString()
  //         .split('')
  //         .map(Number)
  //         .reduce((acc, cur) => acc + cur, 0)

  //     return x % sum === 0
  // 숫자 풀이
  const original = x;
  let sum = 0;

  while (x > 0) {
    sum += x % 10;
    x = Math.floor(x / 10);
  }

  return original % sum === 0;
}
