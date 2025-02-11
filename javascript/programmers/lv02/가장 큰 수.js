// https://school.programmers.co.kr/learn/courses/30/lessons/42746
// O(N log N)
function solution(numbers) {
  let result = numbers
    .map(String)
    .sort((a, b) => b + a - (a + b))
    .join('');

  return result[0] === '0' ? '0' : result;
}
