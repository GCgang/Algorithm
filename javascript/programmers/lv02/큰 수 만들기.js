//https://school.programmers.co.kr/learn/courses/30/lessons/42883
function solution(number, k) {
  const stack = [];

  for (let num of number) {
    while (k > 0 && stack.length > 0) {
      if (stack[stack.length - 1] < num) {
        stack.pop();
        k--;
      } else {
        break;
      }
    }
    stack.push(num);
  }
  return stack.slice(0, stack.length - k).join('');
}
