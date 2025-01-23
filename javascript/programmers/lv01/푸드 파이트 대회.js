// https://school.programmers.co.kr/learn/courses/30/lessons/134240

function solution(food) {
  const result = [];

  for (let i = 1; i < food.length; i++) {
    const count = Math.floor(food[i] / 2);
    result.push(String(i).repeat(count));
  }

  const left = result.join('');
  const right = left.split('').reverse().join('');
  return left + '0' + right;
}
