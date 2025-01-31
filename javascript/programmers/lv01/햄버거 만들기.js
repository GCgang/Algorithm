// https://school.programmers.co.kr/learn/courses/30/lessons/133502
function solution(ingredient) {
  let result = 0;
  const stack = [];

  for (let item of ingredient) {
    stack.push(item);

    if (
      stack.length >= 4 &&
      stack[stack.length - 4] === 1 &&
      stack[stack.length - 3] === 2 &&
      stack[stack.length - 2] === 3 &&
      stack[stack.length - 1] === 1
    ) {
      result++;
      stack.splice(-4);
    }
  }

  return result;
}
