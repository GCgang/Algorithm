// https://school.programmers.co.kr/learn/courses/30/lessons/68644

function solution(numbers) {
  let result = [];
  for (let i = 0; i < numbers.length; ++i) {
    for (let j = 0; j < i; ++j) {
      result.push(numbers[i] + numbers[j]);
    }
  }
  result = [...new Set(result)].sort((a, b) => a - b);
  return result;
}
