// https://school.programmers.co.kr/learn/courses/30/lessons/12906?language=javascript

function solution(arr) {
  const stack = [];

  for (let num of arr) {
    if (stack.length === 0 || stack[stack.length - 1] !== num) {
      stack.push(num);
    }
  }
  return stack;
}

// function solution(arr) {
//     return arr.filter((num, i) => num !== arr[i - 1])
// }
